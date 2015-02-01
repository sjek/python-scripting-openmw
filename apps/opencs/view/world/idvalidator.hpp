#ifndef CSV_WORLD_IDVALIDATOR_H
#define CSV_WORLD_IDVALIDATOR_H

#include <qchar.h>
#include <qvalidator.h>
#include <QValidator>
#include <string>

class QObject;
class QString;

namespace CSVWorld
{
    class IdValidator : public QValidator
    {
            bool mRelaxed;
            std::string mNamespace;
            mutable std::string mError;

        private:

            bool isValid (const QChar& c, bool first) const;

        public:

            IdValidator (bool relaxed = false, QObject *parent = 0);
            ///< \param relaxed Relaxed rules for IDs that also functino as user visible text

            virtual State validate (QString& input, int& pos) const;

            void setNamespace (const std::string& namespace_);

            /// Return a description of the error that resulted in the last call of validate
            /// returning QValidator::Intermediate. If the last call to validate returned
            /// a different value (or if there was no such call yet), an empty string is
            /// returned.
            std::string getError() const;

    };
}

#endif
