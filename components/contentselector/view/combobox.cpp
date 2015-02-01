#include <qpalette.h>
#include <qregexp.h>
#include <qstyle.h>
#include <qstyleoption.h>
#include <qstylepainter.h>
#include <qvalidator.h>

#include "combobox.hpp"

class QPaintEvent;
class QWidget;

ContentSelectorView::ComboBox::ComboBox(QWidget *parent) :
    QComboBox(parent)
{
    mValidator = new QRegExpValidator(QRegExp("^[a-zA-Z0-9_]*$"), this); // Alpha-numeric + underscore
    setValidator(mValidator);
    setCompleter(0);
    setEnabled (true);

    setInsertPolicy(QComboBox::NoInsert);
}

void ContentSelectorView::ComboBox::paintEvent(QPaintEvent *)
{
    QStylePainter painter(this);
    painter.setPen(palette().color(QPalette::Text));

    // draw the combobox frame, focusrect and selected etc.
    QStyleOptionComboBox opt;
    initStyleOption(&opt);
    painter.drawComplexControl(QStyle::CC_ComboBox, opt);

    // draw the icon and text
    if (!opt.editable && currentIndex() == -1) // <<< we adjust the text displayed when nothing is selected
        opt.currentText = mPlaceholderText;
    painter.drawControl(QStyle::CE_ComboBoxLabel, opt);
}

void ContentSelectorView::ComboBox::setPlaceholderText(const QString &text)
{
    mPlaceholderText = text;
}
