
#include <qboxlayout.h>
#include <qlayoutitem.h>
#include <qmargins.h>
#include <qnamespace.h>
#include <qshortcut.h>

#include "scenetool.hpp"
#include "scenetoolbar.hpp"

class QFocusEvent;

void CSVWidget::SceneToolbar::focusInEvent (QFocusEvent *event)
{
    QWidget::focusInEvent (event);

    if (mLayout->count())
        dynamic_cast<QWidgetItem&> (*mLayout->itemAt (0)).widget()->setFocus();
}

CSVWidget::SceneToolbar::SceneToolbar (int buttonSize, QWidget *parent)
: QWidget (parent), mButtonSize (buttonSize), mIconSize (buttonSize-6)
{
    setFixedWidth (mButtonSize);

    mLayout = new QVBoxLayout (this);
    mLayout->setAlignment (Qt::AlignTop);

    mLayout->setContentsMargins (QMargins (0, 0, 0, 0));

    setLayout (mLayout);

    /// \todo make shortcut configurable
    QShortcut *focusScene = new QShortcut (Qt::Key_T, this, 0, 0, Qt::WidgetWithChildrenShortcut);
    connect (focusScene, SIGNAL (activated()), this, SIGNAL (focusSceneRequest()));
}

void CSVWidget::SceneToolbar::addTool (SceneTool *tool, SceneTool *insertPoint)
{
    if (!insertPoint)
        mLayout->addWidget (tool, 0, Qt::AlignTop);
    else
    {
        int index = mLayout->indexOf (insertPoint);
        mLayout->insertWidget (index+1, tool, 0, Qt::AlignTop);
    }
}

void CSVWidget::SceneToolbar::removeTool (SceneTool *tool)
{
    mLayout->removeWidget (tool);
}

int CSVWidget::SceneToolbar::getButtonSize() const
{
    return mButtonSize;
}

int CSVWidget::SceneToolbar::getIconSize() const
{
    return mIconSize;
}
