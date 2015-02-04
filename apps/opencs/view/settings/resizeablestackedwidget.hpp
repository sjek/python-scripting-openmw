#ifndef CSVSETTINGS_RESIZEABLESTACKEDWIDGET_HPP
#define CSVSETTINGS_RESIZEABLESTACKEDWIDGET_HPP

#include <qobjectdefs.h>
#include <qstackedwidget.h>
#include <QStackedWidget>

class QListWidgetItem;
class QWidget;

namespace CSVSettings
{
    class ResizeableStackedWidget : public QStackedWidget
    {
        Q_OBJECT

    public:
        explicit ResizeableStackedWidget(QWidget *parent = 0);

        ///add a widget to the stacked widget
        void addWidget(QWidget* pWidget);

        ///called whenever the stacked widget page is changed
        void changePage (int, int);
    };
}

#endif // CSVSETTINGS_RESIZEABLESTACKEDWIDGET_HPP
