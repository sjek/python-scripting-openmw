
#include <fstream>

#include "components/esm/esmwriter.hpp"
#include "components/to_utf8/to_utf8.hpp"
#include "document.hpp"
#include "operation.hpp"
#include "savingstate.hpp"

CSMDoc::SavingState::SavingState (Operation& operation, const boost::filesystem::path& projectPath,
    ToUTF8::FromType encoding)
: mOperation (operation), mEncoder (encoding),  mProjectPath (projectPath), mProjectFile (false)
{
    mWriter.setEncoder (&mEncoder);
}

bool CSMDoc::SavingState::hasError() const
{
    return mOperation.hasError();
}

void CSMDoc::SavingState::start (Document& document, bool project)
{
    mProjectFile = project;

    if (mStream.is_open())
        mStream.close();

    mStream.clear();

    mSubRecords.clear();

    if (project)
        mPath = mProjectPath;
    else
        mPath = document.getSavePath();

    boost::filesystem::path file (mPath.filename().string() + ".tmp");

    mTmpPath = mPath.parent_path();

    mTmpPath /= file;
}

const boost::filesystem::path& CSMDoc::SavingState::getPath() const
{
    return mPath;
}

const boost::filesystem::path& CSMDoc::SavingState::getTmpPath() const
{
    return mTmpPath;
}

boost::filesystem::ofstream& CSMDoc::SavingState::getStream()
{
    return mStream;
}

ESM::ESMWriter& CSMDoc::SavingState::getWriter()
{
    return mWriter;
}

bool CSMDoc::SavingState::isProjectFile() const
{
    return mProjectFile;
}

std::map<std::string, std::vector<int> >& CSMDoc::SavingState::getSubRecords()
{
    return mSubRecords;
}
