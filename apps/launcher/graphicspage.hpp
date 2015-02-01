#ifndef GRAPHICSPAGE_H
#define GRAPHICSPAGE_H

#include <components/ogreinit/ogreinit.hpp>
#include <qobjectdefs.h>
#include <qrect.h>
#include <qstring.h>
#include <qstringlist.h>
#include <qwidget.h>
#include <QWidget>

#include "ui_graphicspage.h"

namespace Files {
struct ConfigurationManager;
}  // namespace Files
namespace Ogre {
class Root; class RenderSystem;
}  // namespace Ogre

namespace Launcher
{
    class GraphicsSettings;

    class GraphicsPage : public QWidget, private Ui::GraphicsPage
    {
        Q_OBJECT

    public:
        GraphicsPage(Files::ConfigurationManager &cfg, GraphicsSettings &graphicsSettings, QWidget *parent = 0);

        void saveSettings();
        bool loadSettings();

    public slots:
        void rendererChanged(const QString &renderer);
        void screenChanged(int screen);

    private slots:
        void slotFullScreenChanged(int state);
        void slotStandardToggled(bool checked);

    private:
        OgreInit::OgreInit mOgreInit;
        Ogre::Root *mOgre;
        Ogre::RenderSystem *mSelectedRenderSystem;
        Ogre::RenderSystem *mOpenGLRenderSystem;
        Ogre::RenderSystem *mDirect3DRenderSystem;

        Files::ConfigurationManager &mCfgMgr;
        GraphicsSettings &mGraphicsSettings;

        QStringList getAvailableOptions(const QString &key, Ogre::RenderSystem *renderer);
        QStringList getAvailableResolutions(int screen);
        QRect getMaximumResolution();

        bool setupOgre();
        bool setupSDL();
    };
}
#endif
