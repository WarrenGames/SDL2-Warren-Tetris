#include "runGame/menus/keycodesInfos.h"
#include "logging/logsStruct.h"
#include "prefPath/prefPathFinder.h"
#include "commonFiles/pathsLoadings/pathsLoadings.h"
#include <cassert>

KeycodesInfos::KeycodesInfos(AppLogFiles& logs, const PrefPathFinder& prefPath):
	keycodes{SDLK_LEFT, SDLK_RIGHT, SDLK_DOWN, SDLK_x, SDLK_w}
{
	if( std::ifstream keycodesFile{ paths::getKeycodesControl(prefPath) } )
	{
		logs.error << "Opening '" << paths::getKeycodesControl(prefPath) << "' file in order to read player inputs.\n";
		for( auto &keycode : keycodes )
		{
			if( keycodesFile >> keycode )
			{
				logs.error << "  Reading keycode number " << keycode << " .\n";
			}
			else
			{
				logs.error << "Error: couldn't read a keycode in '" << paths::getKeycodesControl(prefPath) << "' file.\n";
				break;
			}
		}
	}
	else{
		logs.error << "Error: couldn't open '" << paths::getKeycodesControl(prefPath) << "' file. Sorry.\n";
		writeKeycodesInFile(logs, prefPath);
	}
}

void KeycodesInfos::writeKeycodesInFile(AppLogFiles& logs, const PrefPathFinder& prefPath) const
{
	if( std::ofstream keycodeFile{ paths::getKeycodesControl(prefPath) } )
	{
		for( auto const key : keycodes )
		{
			keycodeFile << key << " ";
		}
		keycodeFile << std::endl;
	}
	else{
		logs.error << "Error: couldn't open '" << paths::getKeycodesControl(prefPath) << "' file.\n";
	}
}

std::string KeycodesInfos::getStr(std::size_t keycodeIndex) const
{
	assert( keycodeIndex < keycodes.size() );
	return std::string{SDL_GetKeyName(keycodes[keycodeIndex]) };
}