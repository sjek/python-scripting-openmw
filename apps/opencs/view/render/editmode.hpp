#ifndef CSV_RENDER_EDITMODE_H
#define CSV_RENDER_EDITMODE_H

#include <qicon.h>
#include <qobjectdefs.h>
#include <qstring.h>

#include "../widget/modebutton.hpp"

class QWidget;
namespace CSVWidget {
class SceneToolbar;
}  // namespace CSVWidget

namespace CSVRender
{
    class WorldspaceWidget;

    class EditMode : public CSVWidget::ModeButton
    {
            Q_OBJECT

            WorldspaceWidget *mWorldspaceWidget;
            unsigned int mMask;

        public:

            EditMode (WorldspaceWidget *worldspaceWidget, const QIcon& icon, unsigned int mask,
                const QString& tooltip = "", QWidget *parent = 0);

            unsigned int getInteractionMask() const;

            virtual void activate (CSVWidget::SceneToolbar *toolbar);
    };
}

#endif
