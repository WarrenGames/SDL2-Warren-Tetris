#include "fileSystem/copyFilesAndDirectories.h"
#include "logging/logFile.h"
#include "fileSystem/fileSystem.h"

unsigned copyFs::fileWithLogNoErase(LogFile& log, const std::string& srcFilePath, const std::string& destFilePath)
{
	if( !fs::exists(destFilePath) )
	{
		if( fs::exists(srcFilePath) )
		{
			std::error_code errorCode;
			if( fs::copy_file(srcFilePath, destFilePath, errorCode) )
			{
				log.wrSimpleMessage("Copying file: " + srcFilePath + " to " + destFilePath + " done with success");
				return FS_COPY_CREATED;
			}
			else{
				log.wrPrefixAndSimpleMessage("couldn't copy '" + srcFilePath + "' to '" + destFilePath + "' because " + errorCode.message() );
				return FS_COPY_ERROR;
			}
		}
		else{
			log.wrPrefixAndSimpleMessage("the source file: '" + srcFilePath + "' doesn't exist. Reinstall that file to carry on.");
			return FS_COPY_ERROR;
		}
	}
	else{
		return FS_COPY_EXIST;
	}
}

void copyFs::directoriesRecursively(LogFile& log, const std::string& srcPath, const std::string& destPath)
{
	log.wrSimpleMessage("Info: Copying '" + srcPath + "' directory to " + destPath);
	std::error_code errorCode;
	fs::copy(srcPath, destPath, fs::copy_options::recursive, errorCode);
	if( errorCode )
	{
		log.wrRessourceCreationError(srcPath + " to " + destPath, errorCode.message() );
	}
}