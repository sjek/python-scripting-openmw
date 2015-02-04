
#include "apps/opencs/view/widget/pushbutton.hpp"
#include "modebutton.hpp"

class QWidget;

CSVWidget::ModeButton::ModeButton (const QIcon& icon, const QString& tooltip, QWidget *parent)
: PushButton (icon, Type_Mode, tooltip, parent)
{}

void CSVWidget::ModeButton::activate (SceneToolbar *toolbar) {}

void CSVWidget::ModeButton::deactivate (SceneToolbar *toolbar) {}
