#ifndef CSVSETTINGS_PAGE_HPP
#define CSVSETTINGS_PAGE_HPP

#include <qlist.h>
#include <qobjectdefs.h>
#include <qstring.h>
#include <QList>
#include <QMap>
#include <QWidget>

#include "../../model/settings/support.hpp"
#include "frame.hpp"

namespace CSMSettings {
class Setting;
}  // namespace CSMSettings
template <class Key, class T> class QMap;

namespace CSVSettings
{
    class IViewFactory;
    class SettingWindow;
    class View;

    class Page : public Frame
    {
        Q_OBJECT

        QList<View *> mViews;
        SettingWindow *mParent;
        static QMap <ViewType, IViewFactory *> mViewFactories;
        bool mIsEditorPage;
        QString mLabel;

    public:
        Page (const QString &pageName, QList <CSMSettings::Setting *> settingList,
            SettingWindow *parent, const QString& label);

        ///Creates a new view based on the passed setting and adds it to
        ///the page.
        void addView (CSMSettings::Setting *setting);

        ///Iterates the views created for this page based on the passed setting
        ///and returns it.
        View *findView (const QString &page, const QString &setting) const;

        ///returns the list of views associated with the page
        const QList <View *> &views () const              { return mViews; }

        QString getLabel() const;

    private:

        ///Creates views based on the passed setting list
        void setupViews (QList <CSMSettings::Setting *> &settingList);

        ///Creates factory objects for view construction
        void buildFactories();
    };
}
#endif // CSVSETTINGS_PAGE_HPP
