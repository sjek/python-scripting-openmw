#include "MyGUI_Platform.h"
#include "MyGUI_PluginManager.h"
#include "MyGUI_Prerequest.h"
#include "plugin.hpp"

MyGUIPlugin::ResourcePlugin* plugin_item = nullptr;

extern "C" MYGUI_EXPORT_DLL void dllStartPlugin(void)
{
    plugin_item = new MyGUIPlugin::ResourcePlugin();
    MyGUI::PluginManager::getInstance().installPlugin(plugin_item);
}

extern "C" MYGUI_EXPORT_DLL void dllStopPlugin(void)
{
    MyGUI::PluginManager::getInstance().uninstallPlugin(plugin_item);
    delete plugin_item;
    plugin_item = nullptr;
}
