#ifndef CSV_DOC_NEWGAME_H
#define CSV_DOC_NEWGAME_H

#include <boost/filesystem/path.hpp>
#include <qdialog.h>
#include <qmetatype.h>
#include <qobjectdefs.h>
#include <QDialog>
#include <QMetaType>

#ifndef CS_QT_BOOST_FILESYSTEM_PATH_DECLARED
#define CS_QT_BOOST_FILESYSTEM_PATH_DECLARED
Q_DECLARE_METATYPE (boost::filesystem::path)
#endif

class QPushButton;

namespace CSVDoc
{
    class AdjusterWidget;
    class FileWidget;

    class NewGameDialogue : public QDialog
    {
            Q_OBJECT

            QPushButton *mCreate;
            FileWidget *mFileWidget;
            AdjusterWidget *mAdjusterWidget;

        public:

            NewGameDialogue();

            void setLocalData (const boost::filesystem::path& localData);

        signals:

            void createRequest (const boost::filesystem::path& file);

        private slots:

            void stateChanged (bool valid);

            void create();
    };
}

#endif
