#ifndef CSV_WORLD_REFERENCEABLECREATOR_H
#define CSV_WORLD_REFERENCEABLECREATOR_H

#include <qobjectdefs.h>
#include <string>

#include "apps/opencs/view/world/../../model/world/universalid.hpp"
#include "genericcreator.hpp"

class QComboBox;
class QUndoStack;
namespace CSMWorld {
class CreateCommand;
class Data;
}  // namespace CSMWorld

namespace CSVWorld
{
    class ReferenceableCreator : public GenericCreator
    {
            Q_OBJECT

            QComboBox *mType;

        private:

            virtual void configureCreateCommand (CSMWorld::CreateCommand& command) const;

        public:

            ReferenceableCreator (CSMWorld::Data& data, QUndoStack& undoStack,
                const CSMWorld::UniversalId& id);

            virtual void reset();

            virtual void cloneMode (const std::string& originId,
                const CSMWorld::UniversalId::Type type);

            virtual void toggleWidgets(bool active = true);

    };
}

#endif
