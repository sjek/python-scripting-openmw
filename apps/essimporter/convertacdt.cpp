#include "convertacdt.hpp"

namespace ESSImport
{

    int translateDynamicIndex(int mwIndex)
    {
        if (mwIndex == 1)
            return 2;
        else if (mwIndex == 2)
            return 1;
        return mwIndex;
    }

    void convertACDT (const ACDT& acdt, ESM::CreatureStats& cStats)
    {
        for (int i=0; i<3; ++i)
        {
            int writeIndex = translateDynamicIndex(i);
            cStats.mDynamic[writeIndex].mBase = acdt.mDynamic[i][1];
            cStats.mDynamic[writeIndex].mMod = acdt.mDynamic[i][1];
            cStats.mDynamic[writeIndex].mCurrent = acdt.mDynamic[i][0];
        }
        for (int i=0; i<8; ++i)
        {
            cStats.mAttributes[i].mBase = acdt.mAttributes[i][1];
            cStats.mAttributes[i].mMod = acdt.mAttributes[i][0];
            cStats.mAttributes[i].mCurrent = acdt.mAttributes[i][0];
        }
        cStats.mGoldPool = acdt.mGoldPool;
        cStats.mTalkedTo = acdt.mFlags & TalkedToPlayer;
    }

    void convertNpcData (const ActorData& actorData, ESM::NpcStats& npcStats)
    {
        for (int i=0; i<ESM::Skill::Length; ++i)
        {
            npcStats.mSkills[i].mRegular.mMod = actorData.mSkills[i][1];
            npcStats.mSkills[i].mRegular.mCurrent = actorData.mSkills[i][1];
            npcStats.mSkills[i].mRegular.mBase = actorData.mSkills[i][0];
        }

        npcStats.mTimeToStartDrowning = actorData.mACDT.mBreathMeter;
    }

}
