#include "runGame/initialize/initErrorLog.h"
#include "prefPath/prefPathFinder.h"
#include "logging/logsStruct.h"
#include "runGame/initialize/initSDL2Comp.h"
#include "game/consts/constexpr.h"
#include <fstream>
#include <iostream>

void initLogs::initPrefPath()
{
	if( const PrefPathFinder prefPath{ORGANIZATION, GAME_NAME} )
	{
		initLogs::openLogFile(prefPath);
	}
	else{
		std::cout << prefPath.getError() << std::endl;
	}
}

void initLogs::openLogFile(const PrefPathFinder& prefPath)
{
	if( AppLogFiles logs{prefPath.getPath(), ERR_LOG_FILE_NAME, WARN_LOG_FILE_NAME} )
	{
		initSDL2Comp::context(logs, prefPath);
	}
	else{
		std::cout << "Error: couldn't open '" << prefPath.getPath() + ERR_LOG_FILE_NAME << "' file for logging errors." << std::endl;
	}
}