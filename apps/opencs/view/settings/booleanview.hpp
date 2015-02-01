#ifndef CSVSETTINGS_BOOLEANVIEW_HPP
#define CSVSETTINGS_BOOLEANVIEW_HPP

#include <qmap.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qstring.h>
#include <qwidget.h>
#include <QAbstractButton>
#include <QWidget>

#include "../../model/settings/support.hpp"
#include "view.hpp"

class QAbstractButton;
class QStringListModel;
namespace CSMSettings {
class Setting;
}  // namespace CSMSettings
namespace CSVSettings {
class Page;
}  // namespace CSVSettings

namespace CSVSettings
{
    class BooleanView : public View
    {
        Q_OBJECT

        QMap <QString, QAbstractButton *> mButtons;
        enum CSMSettings::SettingType mType;

    public:
        explicit BooleanView (CSMSettings::Setting *setting,
                              Page *parent);

    protected:
        void updateView (bool signalUpdate = true) const;

    private slots:
        void slotToggled (bool state);
    };

    class BooleanViewFactory : public QObject, public IViewFactory
    {
        Q_OBJECT

    public:
        explicit BooleanViewFactory (QWidget *parent = 0)
            : QObject (parent)
        {}

        BooleanView *createView (CSMSettings::Setting *setting,
                                 Page *parent);
    };
}
#endif // CSVSETTINGS_BOOLEANVIEW_HPP
