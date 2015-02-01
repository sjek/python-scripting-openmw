#ifndef CSV_WORLD_INFOCREATOR_H
#define CSV_WORLD_INFOCREATOR_H

#include <qobjectdefs.h>
#include <string>

#include "apps/opencs/view/world/../../model/world/universalid.hpp"
#include "genericcreator.hpp"

class QLineEdit;
class QUndoStack;
namespace CSMWorld {
class CreateCommand;
class Data;
}  // namespace CSMWorld

namespace CSMWorld
{
    class InfoCollection;
}

namespace CSVWorld
{
    class InfoCreator : public GenericCreator
    {
            Q_OBJECT

            QLineEdit *mTopic;

            virtual std::string getId() const;

            virtual void configureCreateCommand (CSMWorld::CreateCommand& command) const;

        public:

            InfoCreator (CSMWorld::Data& data, QUndoStack& undoStack,
                const CSMWorld::UniversalId& id);

            virtual void cloneMode (const std::string& originId,
                const CSMWorld::UniversalId::Type type);

            virtual void reset();

            virtual std::string getErrors() const;
            ///< Return formatted error descriptions for the current state of the creator. if an empty
            /// string is returned, there is no error.

        private slots:

            void topicChanged();
    };
}

#endif
