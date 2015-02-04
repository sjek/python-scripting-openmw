#ifndef OPENCS_VIEW_PREVIEWWIDGET_H
#define OPENCS_VIEW_PREVIEWWIDGET_H

#include <qobjectdefs.h>
#include <string>

#include "navigationorbit.hpp"
#include "object.hpp"
#include "scenewidget.hpp"

class QModelIndex;
class QWidget;

namespace CSMWorld
{
    class Data;
}

namespace CSVRender
{
    class PreviewWidget : public SceneWidget
    {
            Q_OBJECT

            CSMWorld::Data& mData;
            CSVRender::NavigationOrbit mOrbit;
            Object mObject;

        public:

            PreviewWidget (CSMWorld::Data& data, const std::string& id, bool referenceable,
                QWidget *parent = 0);

        signals:

            void closeRequest();

            void referenceableIdChanged (const std::string& id);

        private slots:

            void referenceableDataChanged (const QModelIndex& topLeft,
                const QModelIndex& bottomRight);

            void referenceableAboutToBeRemoved (const QModelIndex& parent, int start, int end);

            void referenceDataChanged (const QModelIndex& topLeft, const QModelIndex& bottomRight);

            void referenceAboutToBeRemoved (const QModelIndex& parent, int start, int end);
    };
}

#endif
