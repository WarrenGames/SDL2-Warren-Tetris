#include "fileSystem/createNewElementFs.h"
#include "fileSystem/fileSystem.h"
#include <fstream>

unsigned createFs::mkDirectoryIfMissing(const std::string& baseDir, const std::string& newDir)
{
	if( !fs::exists(baseDir + "/" + newDir) )
	{
		std::error_code errorCode;
		if( fs::create_directory(baseDir + "/" + newDir, errorCode) )
			return FS_NEW_CREATED;
		else{
			return FS_NEW_ERROR;
		}
	}
	else{
		return FS_NEW_EXIST;
	}
}

unsigned createFs::mkNewFileIfMissing(const std::string& fileDirectory, const std::string& fileName)
{
	if( !fs::exists(fileDirectory + "/" + fileName) )
	{
		if( std::ofstream newFile{ fileDirectory + "/" + fileName } )
			return FS_NEW_CREATED;
		else
			return FS_NEW_ERROR;
	}
	else{
		return FS_NEW_EXIST;
	}
}

unsigned createFs::mkNewFileIfMissing(const std::string& fileFullPath)
{
	if( !fs::exists(fileFullPath) )
	{
		if( std::ofstream newFile{ fileFullPath } )
			return FS_NEW_CREATED;
		else
			return FS_NEW_ERROR;
	}
	else{
		return FS_NEW_EXIST;
	}
}