#include <qatomic_i386.h>
#include <qglobal.h>
#include <qlineedit.h>
#include <qlist.h>
#include <qstringlist.h>
#include <qtextedit.h>
#include <qvariant.h>

#include "../../model/settings/setting.hpp"
#include "apps/opencs/view/settings/view.hpp"
#include "textview.hpp"

namespace CSVSettings {
class Page;
}  // namespace CSVSettings

CSVSettings::TextView::TextView(CSMSettings::Setting *setting, Page *parent)
    : mDelimiter (setting->delimiter()), View (setting, parent)

{
    if (setting->isMultiLine())
        mTextWidget = new QTextEdit ("", this);
    else
        mTextWidget = new QLineEdit ("", this);

    if (setting->widgetWidth() > 0)
        mTextWidget->setFixedWidth (widgetWidth (setting->widgetWidth()));

    connect (mTextWidget, SIGNAL (textEdited (QString)),
           this, SLOT (slotTextEdited (QString)));

    addWidget (mTextWidget, setting->viewRow(), setting->viewColumn());
}

bool CSVSettings::TextView::isEquivalent
                                (const QString &lhs, const QString &rhs) const
{
    return (lhs.trimmed() == rhs.trimmed());
}

void CSVSettings::TextView::slotTextEdited (QString value)
{
    QStringList values = value.split (mDelimiter, QString::SkipEmptyParts);

    QStringList returnValues;

    foreach (const QString &splitValue, values)
        returnValues.append (splitValue.trimmed());

    setSelectedValues (returnValues, false);

    View::updateView();
}

void CSVSettings::TextView::updateView(bool signalUpdate) const
{
    QString values = selectedValues().join (mDelimiter);

    if (isEquivalent (mTextWidget->property("text").toString(), values))
        return;

    mTextWidget->setProperty("text", values);

    View::updateView (signalUpdate);
}

CSVSettings::TextView *CSVSettings::TextViewFactory::createView
                                    (CSMSettings::Setting *setting,
                                     Page *parent)
{
    return new TextView (setting, parent);
}

