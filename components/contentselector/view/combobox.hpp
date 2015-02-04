#ifndef COMBOBOX_HPP
#define COMBOBOX_HPP

#include <qcombobox.h>
#include <qobjectdefs.h>
#include <qstring.h>
#include <QComboBox>
#include <QStylePainter>

class QPaintEvent;
class QRegExpValidator;
class QString;
class QWidget;

namespace ContentSelectorView
{
    class ComboBox : public QComboBox
    {
        Q_OBJECT

    public:
        explicit ComboBox (QWidget *parent = 0);

        void setPlaceholderText(const QString &text);

    private:
        QString mPlaceholderText;

    protected:
        void paintEvent(QPaintEvent *);
        QRegExpValidator *mValidator;
    };
}

#endif // COMBOBOX_HPP
