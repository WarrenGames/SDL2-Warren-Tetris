#ifndef KEYCODES_INFOS_DATA_H
#define KEYCODES_INFOS_DATA_H

#include "game/input/inputsConsts.h"
#include "SDL.h"
#include <array>
#include <string>

struct AppLogFiles;
class PrefPathFinder;

struct KeycodesInfos
{
	std::array< SDL_Keycode, KEY::INP_MAX > keycodes;

	explicit KeycodesInfos(AppLogFiles& logs, const PrefPathFinder& prefPath);
	~KeycodesInfos() = default;
	KeycodesInfos( const KeycodesInfos& ) = delete;
	KeycodesInfos& operator= ( const KeycodesInfos& ) = delete;
	
	void writeKeycodesInFile(AppLogFiles& logs, const PrefPathFinder& prefPath) const;
	
	std::string getStr(size_t keycodeIndex) const;
};

#endif //KEYCODES_INFOS_DATA_H