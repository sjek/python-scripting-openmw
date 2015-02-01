
#include <qabstractitemmodel.h>
#include <qnamespace.h>
#include <qstring.h>
#include <qundostack.h>
#include <qvariant.h>
#include <stddef.h>
#include <stdexcept>
#include <string>

#include "../../model/world/columns.hpp"
#include "../../model/world/commands.hpp"
#include "apps/opencs/view/world/enumdelegate.hpp"
#include "components/esm/variant.hpp"
#include "vartypedelegate.hpp"

class QObject;
namespace CSMDoc {
class Document;
}  // namespace CSMDoc

void CSVWorld::VarTypeDelegate::addCommands (QAbstractItemModel *model, const QModelIndex& index, int type)
    const
{
    QModelIndex next = model->index (index.row(), index.column()+1);

    QVariant old = model->data (next);

    QVariant value;

    switch (type)
    {
        case ESM::VT_Short:
        case ESM::VT_Int:
        case ESM::VT_Long:

            value = old.toInt();
            break;

        case ESM::VT_Float:

            value = old.toFloat();
            break;

        case ESM::VT_String:

            value = old.toString();
            break;

        default: break; // ignore the rest
    }

    getUndoStack().beginMacro (
        "Modify " + model->headerData (index.column(), Qt::Horizontal, Qt::DisplayRole).toString());

    getUndoStack().push (new CSMWorld::ModifyCommand (*model, index, type));
    getUndoStack().push (new CSMWorld::ModifyCommand (*model, next, value));

    getUndoStack().endMacro();
}

CSVWorld::VarTypeDelegate::VarTypeDelegate (const std::vector<std::pair<int, QString> >& values,
    CSMDoc::Document& document, QObject *parent)
: EnumDelegate (values, document, parent)
{}


CSVWorld::VarTypeDelegateFactory::VarTypeDelegateFactory (ESM::VarType type0,
    ESM::VarType type1, ESM::VarType type2, ESM::VarType type3)
{
    if (type0!=ESM::VT_Unknown)
        add (type0);

    if (type1!=ESM::VT_Unknown)
        add (type1);

    if (type2!=ESM::VT_Unknown)
        add (type2);

    if (type3!=ESM::VT_Unknown)
        add (type3);
}

CSVWorld::CommandDelegate *CSVWorld::VarTypeDelegateFactory::makeDelegate (
    CSMDoc::Document& document, QObject *parent) const
{
    return new VarTypeDelegate (mValues, document, parent);
}

void CSVWorld::VarTypeDelegateFactory::add (ESM::VarType type)
{
    std::vector<std::string> enums =
        CSMWorld::Columns::getEnums (CSMWorld::Columns::ColumnId_ValueType);

    if (static_cast<size_t>(type) >= enums.size())
        throw std::logic_error ("Unsupported variable type");

    mValues.push_back (std::make_pair (type, QString::fromUtf8 (enums[type].c_str())));
}
