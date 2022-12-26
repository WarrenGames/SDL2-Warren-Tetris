#include "runGame/initialize/initErrorLog.h"
#include "SDL_main.h"

int main( int argc, char *argv[] )
{
	(void) argc;
	(void) argv;
	
	initLogs::initPrefPath();
	return 0;
}
