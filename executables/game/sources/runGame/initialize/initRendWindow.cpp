#include "runGame/initialize/initRendWindow.h"
#include "commonFiles/types/essentials.h"
#include "runGame/menus/mainMenu.h"
#include "game/consts/constexpr.h"

void initRenderer::context(AppLogFiles& logs, const PrefPathFinder& prefPath)
{
	sdl2::RendererWindow rndWnd{logs.error, SCREENW, SCREENH, GAME_NAME, ""};
	
	if( rndWnd.wasInitializationPerfect() )
	{
		Essentials essentials{logs, prefPath, rndWnd };
		mainMenu::context(essentials);
	}
}