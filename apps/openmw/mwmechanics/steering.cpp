#include "steering.hpp"

#include "../mwworld/class.hpp"

#include "../mwbase/environment.hpp"

#include "movement.hpp"

namespace MWMechanics
{

bool smoothTurn(const MWWorld::Ptr& actor, float targetAngleRadians, int axis, float epsilonRadians)
{
    float currentAngle (actor.getRefData().getPosition().rot[axis]);
    float diff (targetAngleRadians - currentAngle);
    if (diff >= osg::DegreesToRadians(180.f))
    {
        // Turning the other way would be a better idea
        diff = diff-osg::DegreesToRadians(360.f);
    }
    else if (diff <= osg::DegreesToRadians(-180.f))
    {
        diff = osg::DegreesToRadians(360.f)-diff;
    }
    float absDiff = std::abs(diff);

    // The turning animation actually moves you slightly, so the angle will be wrong again.
    // Use epsilon to prevent jerkiness.
    if (absDiff < epsilonRadians)
        return true;

    float limit = MAX_VEL_ANGULAR_RADIANS * MWBase::Environment::get().getFrameDuration();
    if (absDiff > limit)
        diff = osg::sign(diff) * limit;

    actor.getClass().getMovementSettings(actor).mRotation[axis] = diff;
    return false;
}

bool zTurn(const MWWorld::Ptr& actor, float targetAngleRadians, float epsilonRadians)
{
    return smoothTurn(actor, targetAngleRadians, 2, epsilonRadians);
}

}
