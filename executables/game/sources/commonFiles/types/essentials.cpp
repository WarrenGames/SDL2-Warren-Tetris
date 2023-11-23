#include "commonFiles/types/essentials.h"

Essentials::Essentials(AppLogFiles& logs_, const PrefPathFinder& prefPath_, sdl2::RendererWindow& rndWnd_):
	prefPath{prefPath_},
	logs{logs_},
	rndWnd{rndWnd_},
	inp{},
	drawFrequency{}
{
	
}