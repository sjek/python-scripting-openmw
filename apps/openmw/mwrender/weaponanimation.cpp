#include <OgreBone.h>
#include <OgreEntity.h>
#include <OgreMath.h>
#include <OgreNode.h>
#include <OgreQuaternion.h>
#include <OgreSharedPtr.h>
#include <OgreSkeletonInstance.h>
#include <OgreVector3.h>
#include <stdexcept>
#include <vector>

#include "../mwbase/environment.hpp"
#include "../mwbase/world.hpp"
#include "../mwmechanics/creaturestats.hpp"
#include "../mwworld/class.hpp"
#include "../mwworld/esmstore.hpp"
#include "../mwworld/inventorystore.hpp"
#include "animation.hpp"
#include "apps/openmw/mwrender/../mwworld/../mwmechanics/stat.hpp"
#include "apps/openmw/mwrender/../mwworld/containerstore.hpp"
#include "apps/openmw/mwrender/../mwworld/livecellref.hpp"
#include "apps/openmw/mwrender/../mwworld/ptr.hpp"
#include "apps/openmw/mwrender/../mwworld/refdata.hpp"
#include "apps/openmw/mwrender/../mwworld/store.hpp"
#include "components/esm/defs.hpp"
#include "components/esm/loadgmst.hpp"
#include "components/esm/loadweap.hpp"
#include "components/nifogre/ogrenifloader.hpp"
#include "weaponanimation.hpp"

namespace MWRender
{

float WeaponAnimationTime::getValue() const
{
    if (mWeaponGroup.empty())
        return 0;
    float current = mAnimation->getCurrentTime(mWeaponGroup);
    if (current == -1)
        return 0;
    return current - mStartTime;
}

void WeaponAnimationTime::setGroup(const std::string &group)
{
    mWeaponGroup = group;
    mStartTime = mAnimation->getStartTime(mWeaponGroup);
}

void WeaponAnimationTime::updateStartTime()
{
    setGroup(mWeaponGroup);
}

void WeaponAnimation::attachArrow(MWWorld::Ptr actor)
{
    MWWorld::InventoryStore& inv = actor.getClass().getInventoryStore(actor);
    MWWorld::ContainerStoreIterator weaponSlot = inv.getSlot(MWWorld::InventoryStore::Slot_CarriedRight);
    if (weaponSlot != inv.end() && weaponSlot->get<ESM::Weapon>()->mBase->mData.mType == ESM::Weapon::MarksmanThrown)
        showWeapon(true);
    else
    {
        NifOgre::ObjectScenePtr weapon = getWeapon();
        if (!weapon.get())
            return;

        MWWorld::ContainerStoreIterator ammo = inv.getSlot(MWWorld::InventoryStore::Slot_Ammunition);
        if (ammo == inv.end())
            return;
        std::string model = ammo->getClass().getModel(*ammo);

        if (!weapon->mSkelBase)
            throw std::runtime_error("Need a skeleton to attach the arrow to");

        const std::string bonename = "ArrowBone";
        mAmmunition = NifOgre::Loader::createObjects(weapon->mSkelBase, bonename, bonename, weapon->mSkelBase->getParentSceneNode(), model);
        configureAddedObject(mAmmunition, *ammo, MWWorld::InventoryStore::Slot_Ammunition);
    }
}

void WeaponAnimation::releaseArrow(MWWorld::Ptr actor)
{
    MWWorld::InventoryStore& inv = actor.getClass().getInventoryStore(actor);
    MWWorld::ContainerStoreIterator weapon = inv.getSlot(MWWorld::InventoryStore::Slot_CarriedRight);
    if (weapon == inv.end())
        return;

    // The orientation of the launched projectile. Always the same as the actor orientation, even if the ArrowBone's orientation dictates otherwise.
    Ogre::Quaternion orient = Ogre::Quaternion(Ogre::Radian(actor.getRefData().getPosition().rot[2]), Ogre::Vector3::NEGATIVE_UNIT_Z) *
            Ogre::Quaternion(Ogre::Radian(actor.getRefData().getPosition().rot[0]), Ogre::Vector3::NEGATIVE_UNIT_X);

    const MWWorld::Store<ESM::GameSetting> &gmst =
        MWBase::Environment::get().getWorld()->getStore().get<ESM::GameSetting>();

    // Reduce fatigue
    // somewhat of a guess, but using the weapon weight makes sense
    const float fFatigueAttackBase = gmst.find("fFatigueAttackBase")->getFloat();
    const float fFatigueAttackMult = gmst.find("fFatigueAttackMult")->getFloat();
    const float fWeaponFatigueMult = gmst.find("fWeaponFatigueMult")->getFloat();
    MWMechanics::CreatureStats& attackerStats = actor.getClass().getCreatureStats(actor);
    MWMechanics::DynamicStat<float> fatigue = attackerStats.getFatigue();
    const float normalizedEncumbrance = actor.getClass().getNormalizedEncumbrance(actor);
    float fatigueLoss = fFatigueAttackBase + normalizedEncumbrance * fFatigueAttackMult;
    if (!weapon->isEmpty())
        fatigueLoss += weapon->getClass().getWeight(*weapon) * attackerStats.getAttackStrength() * fWeaponFatigueMult;
    fatigue.setCurrent(fatigue.getCurrent() - fatigueLoss);
    attackerStats.setFatigue(fatigue);

    if (weapon->get<ESM::Weapon>()->mBase->mData.mType == ESM::Weapon::MarksmanThrown)
    {
        // Thrown weapons get detached now
        NifOgre::ObjectScenePtr objects = getWeapon();

        Ogre::Vector3 launchPos(0,0,0);
        if (objects->mSkelBase)
        {
            launchPos = objects->mSkelBase->getParentNode()->_getDerivedPosition();
        }
        else if (objects->mEntities.size())
        {
            objects->mEntities[0]->getParentNode()->needUpdate(true);
            launchPos = objects->mEntities[0]->getParentNode()->_getDerivedPosition();
        }

        float fThrownWeaponMinSpeed = gmst.find("fThrownWeaponMinSpeed")->getFloat();
        float fThrownWeaponMaxSpeed = gmst.find("fThrownWeaponMaxSpeed")->getFloat();
        float speed = fThrownWeaponMinSpeed + (fThrownWeaponMaxSpeed - fThrownWeaponMinSpeed) *
                actor.getClass().getCreatureStats(actor).getAttackStrength();

        MWBase::Environment::get().getWorld()->launchProjectile(actor, *weapon, launchPos, orient, *weapon, speed);

        showWeapon(false);

        inv.remove(*weapon, 1, actor);
    }
    else
    {
        // With bows and crossbows only the used arrow/bolt gets detached
        MWWorld::ContainerStoreIterator ammo = inv.getSlot(MWWorld::InventoryStore::Slot_Ammunition);
        if (ammo == inv.end())
            return;

        if (!mAmmunition.get())
            return;

        Ogre::Vector3 launchPos(0,0,0);
        if (mAmmunition->mSkelBase)
        {
            launchPos = mAmmunition->mSkelBase->getParentNode()->_getDerivedPosition();
        }
        else if (mAmmunition->mEntities.size())
        {
            mAmmunition->mEntities[0]->getParentNode()->needUpdate(true);
            launchPos = mAmmunition->mEntities[0]->getParentNode()->_getDerivedPosition();
        }

        float fProjectileMinSpeed = gmst.find("fProjectileMinSpeed")->getFloat();
        float fProjectileMaxSpeed = gmst.find("fProjectileMaxSpeed")->getFloat();
        float speed = fProjectileMinSpeed + (fProjectileMaxSpeed - fProjectileMinSpeed) * actor.getClass().getCreatureStats(actor).getAttackStrength();

        MWBase::Environment::get().getWorld()->launchProjectile(actor, *ammo, launchPos, orient, *weapon, speed);

        inv.remove(*ammo, 1, actor);
        mAmmunition.setNull();
    }
}

void WeaponAnimation::pitchSkeleton(float xrot, Ogre::SkeletonInstance* skel)
{
    if (mPitchFactor == 0)
        return;

    float pitch = xrot * mPitchFactor;
    Ogre::Node *node;

    // In spherearcher.nif, we have spine, not Spine. Not sure if all bone names should be case insensitive?
    if (skel->hasBone("Bip01 spine2"))
        node = skel->getBone("Bip01 spine2");
    else
        node = skel->getBone("Bip01 Spine2");
    node->pitch(Ogre::Radian(-pitch/2), Ogre::Node::TS_WORLD);

    if (skel->hasBone("Bip01 spine1")) // in spherearcher.nif
        node = skel->getBone("Bip01 spine1");
    else
        node = skel->getBone("Bip01 Spine1");
    node->pitch(Ogre::Radian(-pitch/2), Ogre::Node::TS_WORLD);
}

}
