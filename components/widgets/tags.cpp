#include <MyGUI_Colour.h>
#include <stddef.h>
#include <ostream>
#include <stdexcept>
#include <utility>

#include "MyGUI_StringUtility.h"
#include "MyGUI_UString.h"
#include "tags.hpp"

namespace Gui
{

bool replaceTag(const MyGUI::UString& tag, MyGUI::UString& out, const std::map<std::string,std::string>& fallbackSettings)
{
    std::string fontcolour = "fontcolour=";
    size_t fontcolourLength = fontcolour.length();

    std::string fontcolourhtml = "fontcolourhtml=";
    size_t fontcolourhtmlLength = fontcolourhtml.length();

    if (tag.compare(0, fontcolourLength, fontcolour) == 0)
    {
        std::string fallbackName = "FontColor_color_" + tag.substr(fontcolourLength);
        std::map<std::string, std::string>::const_iterator it = fallbackSettings.find(fallbackName);
        if (it == fallbackSettings.end())
            throw std::runtime_error("Unknown fallback name: " + fallbackName);
        std::string str = it->second;

        std::string ret[3];
        unsigned int j=0;
        for(unsigned int i=0;i<str.length();++i){
            if(str[i]==',') j++;
            else if (str[i] != ' ') ret[j]+=str[i];
        }
        MyGUI::Colour col (MyGUI::utility::parseInt(ret[0])/255.f,MyGUI::utility::parseInt(ret[1])/255.f,MyGUI::utility::parseInt(ret[2])/255.f);
        out = col.print();
        return true;
    }
    else if (tag.compare(0, fontcolourhtmlLength, fontcolourhtml) == 0)
    {
        std::string fallbackName = "FontColor_color_" + tag.substr(fontcolourhtmlLength);
        std::map<std::string, std::string>::const_iterator it = fallbackSettings.find(fallbackName);
        if (it == fallbackSettings.end())
            throw std::runtime_error("Unknown fallback name: " + fallbackName);
        std::string str = it->second;

        std::string ret[3];
        unsigned int j=0;
        for(unsigned int i=0;i<str.length();++i){
            if(str[i]==',') j++;
            else if (str[i] != ' ') ret[j]+=str[i];
        }
        std::stringstream html;
        html << "#" << std::hex << MyGUI::utility::parseInt(ret[0]) << MyGUI::utility::parseInt(ret[1]) << MyGUI::utility::parseInt(ret[2]);
        out = html.str();
        return true;
    }
    return false;

}

}
