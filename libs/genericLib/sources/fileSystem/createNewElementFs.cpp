#include "fileSystem/createNewElementFs.h"
#include <fstream>

unsigned createFs::mkDirectoryIfMissing(const fs::path& baseDir, const fs::path& newDir)
{
	if( false == fs::exists(baseDir / newDir) )
	{
		std::error_code errorCode;
		if( fs::create_directory(baseDir / newDir, errorCode) )
			return FS_NEW_CREATED;
		else{
			return FS_NEW_ERROR;
		}
	}
	else{
		return FS_NEW_EXIST;
	}
}

unsigned createFs::mkNewFileIfMissing(const fs::path& fileDirectory, const fs::path& fileName)
{
	if( false == fs::exists(fileDirectory / fileName) )
	{
		if( std::ofstream newFile{ fileDirectory / fileName } )
			return FS_NEW_CREATED;
		else
			return FS_NEW_ERROR;
	}
	else{
		return FS_NEW_EXIST;
	}
}

unsigned createFs::mkNewFileIfMissing(const fs::path& fileFullPath)
{
	if( false == fs::exists(fileFullPath) )
	{
		if( std::ofstream newFile{ fileFullPath } )
		{
			return FS_NEW_CREATED;
		}
		else{
			return FS_NEW_ERROR;
		}
	}
	else{
		return FS_NEW_EXIST;
	}
}