#ifndef TEXT_SLOT_MSG_BOX
#define TEXT_SLOT_MSG_BOX

#include <qmessagebox.h>
#include <qobjectdefs.h>
#include <qstring.h>
#include <QMessageBox>

namespace Launcher
{
    class TextSlotMsgBox : public QMessageBox
    {
    Q_OBJECT
        public slots:
            void setTextSlot(const QString& string);
    };
}
#endif
