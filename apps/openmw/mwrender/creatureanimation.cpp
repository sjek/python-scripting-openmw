#include "creatureanimation.hpp"

#include <components/esm/loadcrea.hpp>

#include <osg/PositionAttitudeTransform>

#include <components/resource/resourcesystem.hpp>
#include <components/resource/scenemanager.hpp>
#include <components/sceneutil/attach.hpp>
#include <components/sceneutil/visitor.hpp>


#include "../mwworld/class.hpp"

namespace MWRender
{

CreatureAnimation::CreatureAnimation(const MWWorld::Ptr &ptr,
                                     const std::string& model, Resource::ResourceSystem* resourceSystem)
  : Animation(ptr, osg::ref_ptr<osg::Group>(ptr.getRefData().getBaseNode()), resourceSystem)
{
    MWWorld::LiveCellRef<ESM::Creature> *ref = mPtr.get<ESM::Creature>();

    if(!model.empty())
    {
        setObjectRoot(model, false, false);

        if((ref->mBase->mFlags&ESM::Creature::Bipedal))
            addAnimSource("meshes\\xbase_anim.nif");
        addAnimSource(model);
    }
}


CreatureWeaponAnimation::CreatureWeaponAnimation(const MWWorld::Ptr &ptr, const std::string& model, Resource::ResourceSystem* resourceSystem)
    : Animation(ptr, osg::ref_ptr<osg::Group>(ptr.getRefData().getBaseNode()), resourceSystem)
    , mShowWeapons(false)
    , mShowCarriedLeft(false)
{
    MWWorld::LiveCellRef<ESM::Creature> *ref = mPtr.get<ESM::Creature>();

    if(!model.empty())
    {
        setObjectRoot(model, true, false);

        if((ref->mBase->mFlags&ESM::Creature::Bipedal))
            addAnimSource("meshes\\xbase_anim.nif");
        addAnimSource(model);

        mPtr.getClass().getInventoryStore(mPtr).setListener(this, mPtr);

        updateParts();
    }

    mWeaponAnimationTime = boost::shared_ptr<WeaponAnimationTime>(new WeaponAnimationTime(this));
}

void CreatureWeaponAnimation::showWeapons(bool showWeapon)
{
    if (showWeapon != mShowWeapons)
    {
        mShowWeapons = showWeapon;
        updateParts();
    }
}

void CreatureWeaponAnimation::showCarriedLeft(bool show)
{
    if (show != mShowCarriedLeft)
    {
        mShowCarriedLeft = show;
        updateParts();
    }
}

void CreatureWeaponAnimation::updateParts()
{
    mWeapon.reset();
    mShield.reset();

    if (mShowWeapons)
        updatePart(mWeapon, MWWorld::InventoryStore::Slot_CarriedRight);
    if (mShowCarriedLeft)
        updatePart(mShield, MWWorld::InventoryStore::Slot_CarriedLeft);
}

void CreatureWeaponAnimation::updatePart(PartHolderPtr& scene, int slot)
{
    if (!mObjectRoot)
        return;

    MWWorld::InventoryStore& inv = mPtr.getClass().getInventoryStore(mPtr);
    MWWorld::ContainerStoreIterator it = inv.getSlot(slot);

    if (it == inv.end())
    {
        scene.reset();
        return;
    }
    MWWorld::Ptr item = *it;

    std::string bonename;
    if (slot == MWWorld::InventoryStore::Slot_CarriedRight)
        bonename = "Weapon Bone";
    else
        bonename = "Shield Bone";

    osg::ref_ptr<osg::Node> node = mResourceSystem->getSceneManager()->createInstance(item.getClass().getModel(item));
    osg::ref_ptr<osg::Node> attached = SceneUtil::attach(node, mObjectRoot, bonename, bonename);
    mResourceSystem->getSceneManager()->notifyAttached(attached);

    scene.reset(new PartHolder(attached));

    if (!item.getClass().getEnchantment(item).empty())
        addGlow(attached, getEnchantmentColor(item));

    // Crossbows start out with a bolt attached
    // FIXME: code duplicated from NpcAnimation
    if (slot == MWWorld::InventoryStore::Slot_CarriedRight &&
            item.getTypeName() == typeid(ESM::Weapon).name() &&
            item.get<ESM::Weapon>()->mBase->mData.mType == ESM::Weapon::MarksmanCrossbow)
    {
        MWWorld::ContainerStoreIterator ammo = inv.getSlot(MWWorld::InventoryStore::Slot_Ammunition);
        if (ammo != inv.end() && ammo->get<ESM::Weapon>()->mBase->mData.mType == ESM::Weapon::Bolt)
            attachArrow();
        else
            mAmmunition.reset();
    }
    else
        mAmmunition.reset();

    boost::shared_ptr<SceneUtil::ControllerSource> source;

    if (slot == MWWorld::InventoryStore::Slot_CarriedRight)
        source = mWeaponAnimationTime;
    else
        source.reset(new NullAnimationTime);

    SceneUtil::AssignControllerSourcesVisitor assignVisitor(source);
    attached->accept(assignVisitor);
}

void CreatureWeaponAnimation::attachArrow()
{
    WeaponAnimation::attachArrow(mPtr);
}

void CreatureWeaponAnimation::releaseArrow(float attackStrength)
{
    WeaponAnimation::releaseArrow(mPtr, attackStrength);
}

osg::Group *CreatureWeaponAnimation::getArrowBone()
{
    if (!mWeapon)
        return NULL;

    SceneUtil::FindByNameVisitor findVisitor ("ArrowBone");
    mWeapon->getNode()->accept(findVisitor);

    return findVisitor.mFoundNode;
}

osg::Node *CreatureWeaponAnimation::getWeaponNode()
{
    return mWeapon ? mWeapon->getNode().get() : NULL;
}

Resource::ResourceSystem *CreatureWeaponAnimation::getResourceSystem()
{
    return mResourceSystem;
}

void CreatureWeaponAnimation::addControllers()
{
    Animation::addControllers();
    WeaponAnimation::addControllers(mNodeMap, mActiveControllers, mObjectRoot.get());
}

osg::Vec3f CreatureWeaponAnimation::runAnimation(float duration)
{
    osg::Vec3f ret = Animation::runAnimation(duration);

    WeaponAnimation::configureControllers(mPtr.getRefData().getPosition().rot[0]);

    return ret;
}

}
