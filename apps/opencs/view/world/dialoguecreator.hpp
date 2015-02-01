#ifndef CSV_WORLD_DIALOGUECREATOR_H
#define CSV_WORLD_DIALOGUECREATOR_H

#include "apps/opencs/view/world/../../model/world/universalid.hpp"
#include "apps/opencs/view/world/creator.hpp"
#include "genericcreator.hpp"

class QUndoStack;
namespace CSMWorld {
class CreateCommand;
class Data;
}  // namespace CSMWorld

namespace CSVWorld
{
    class DialogueCreator : public GenericCreator
    {
            int mType;

        protected:

            virtual void configureCreateCommand (CSMWorld::CreateCommand& command) const;

        public:

            DialogueCreator (CSMWorld::Data& data, QUndoStack& undoStack,
                const CSMWorld::UniversalId& id, int type);
    };

    class TopicCreatorFactory : public CreatorFactoryBase
    {
        public:

            virtual Creator *makeCreator (CSMWorld::Data& data, QUndoStack& undoStack,
                const CSMWorld::UniversalId& id) const;
            ///< The ownership of the returned Creator is transferred to the caller.
    };

    class JournalCreatorFactory : public CreatorFactoryBase
    {
        public:

            virtual Creator *makeCreator (CSMWorld::Data& data, QUndoStack& undoStack,
                const CSMWorld::UniversalId& id) const;
            ///< The ownership of the returned Creator is transferred to the caller.
    };
}

#endif
