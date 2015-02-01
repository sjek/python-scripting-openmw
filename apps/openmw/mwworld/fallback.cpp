#include <sstream>
#include <utility>

#include "OgreColourValue.h"
#include "boost/lexical_cast.hpp"
#include "fallback.hpp"

namespace MWWorld
{
    Fallback::Fallback(const std::map<std::string,std::string>& fallback):mFallbackMap(fallback)
    {}

    std::string Fallback::getFallbackString(const std::string& fall) const
    {
        std::map<std::string,std::string>::const_iterator it;
        if((it = mFallbackMap.find(fall)) == mFallbackMap.end())
        {
            return "";
        }
        return it->second;
    }
    float Fallback::getFallbackFloat(const std::string& fall) const
    {
        std::string fallback=getFallbackString(fall);
        if(fallback.empty())
            return 0;
        else
            return boost::lexical_cast<float>(fallback);
    }
    bool Fallback::getFallbackBool(const std::string& fall) const
    {
        std::string fallback=getFallbackString(fall);
        if(fallback.empty())
            return false;
        else
            return boost::lexical_cast<bool>(fallback);
    }
    Ogre::ColourValue Fallback::getFallbackColour(const std::string& fall) const
    {
        std::string sum=getFallbackString(fall);
        if(sum.empty())
            return Ogre::ColourValue(0,0,0);
        else
        {
            std::string ret[3];
            unsigned int j=0;
            for(unsigned int i=0;i<sum.length();++i){
                if(sum[i]==',') j++;
                else if (sum[i] != ' ') ret[j]+=sum[i];
            }

            return Ogre::ColourValue(boost::lexical_cast<int>(ret[0])/255.f,boost::lexical_cast<int>(ret[1])/255.f,boost::lexical_cast<int>(ret[2])/255.f);
        }
    }
}
