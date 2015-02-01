#include <qglobal.h>
#include <qlineedit.h>
#include <qvariant.h>

#include "spinbox.hpp"

class QWidget;

CSVSettings::SpinBox::SpinBox(QWidget *parent)
    : mValueList(QStringList()), QSpinBox(parent)
{
    setRange (0, 0);
}

QString CSVSettings::SpinBox::textFromValue(int val) const
{
    if (mValueList.isEmpty())
        return QVariant (val).toString();

    QString value;

    if (val < mValueList.size())
        value = mValueList.at (val);

    return value;
}

int CSVSettings::SpinBox::valueFromText(const QString &text) const
{
    if (mValueList.isEmpty())
        return text.toInt(); // TODO: assumed integer, untested error handling for alpha types

    if (mValueList.contains (text))
        return mValueList.indexOf(text);

    return -1;
}

void CSVSettings::SpinBox::setValue (const QString &value)
{
    if (!mValueList.isEmpty())
    {
        lineEdit()->setText (value);
        QSpinBox::setValue(valueFromText(value));
    }
    else
        QSpinBox::setValue (value.toInt());
}

void CSVSettings::SpinBox::setValueList (const QStringList &list)
{
    mValueList = list;
    setMaximum (list.size() - 1);
}
