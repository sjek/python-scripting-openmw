
#include "apps/opencs/view/render/../widget/modebutton.hpp"
#include "editmode.hpp"
#include "worldspacewidget.hpp"

class QWidget;
namespace CSVWidget {
class SceneToolbar;
}  // namespace CSVWidget

CSVRender::EditMode::EditMode (WorldspaceWidget *worldspaceWidget, const QIcon& icon,
    unsigned int mask, const QString& tooltip, QWidget *parent)
: ModeButton (icon, tooltip, parent), mWorldspaceWidget (worldspaceWidget), mMask (mask)
{}

unsigned int CSVRender::EditMode::getInteractionMask() const
{
    return mMask;
}

void CSVRender::EditMode::activate (CSVWidget::SceneToolbar *toolbar)
{
    mWorldspaceWidget->setInteractionMask (mMask);
}
