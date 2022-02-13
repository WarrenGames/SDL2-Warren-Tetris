#include "runGame/menus/customModeMenu/customMenuContext.h"
#include "runGame/menus/customModeMenu/interface.h"
#include "commonFiles/types/essentials.h"
#include "game/structs/timeOptionsStruct.h"
#include "game/contexts/gameContext.h"
#include "game/consts/sdlColors.h"

void customMenu::mainContext(Essentials& essentials)
{
	bool quitContext{false};
	Interface interface{essentials};
	TimeOptions timeOptions{1000};
	customMenu::mainLoop(essentials, interface, timeOptions, quitContext);
}

void customMenu::mainLoop(Essentials& essentials, Interface& interface, TimeOptions& timeOptions, bool& quitContext)
{
	while( false == quitContext )
	{
		essentials.inp.updateMouse();
		customMenu::update(essentials, interface, quitContext);
		customMenu::drawEverything(essentials, interface);
		essentials.inp.setMouseLeftButtonFalse();
		startCustomGame(essentials, EASY_GAME, timeOptions, interface, quitContext);
		startCustomGame(essentials, INTERMEDIATE_GAME, timeOptions, interface, quitContext);
		startCustomGame(essentials, HARD_GAME, timeOptions, interface, quitContext);
	}
}

void customMenu::update(Essentials& essentials, Interface& interface, bool& quitContext)
{
	interface.update(essentials, essentials.inp.getMousePosition(), essentials.inp.getMouseLeftButton() );
	customMenu::quitWithEscape(essentials, quitContext);
	customMenu::quitMenu(interface, quitContext);
}

void customMenu::quitWithEscape(Essentials& essentials, bool& quitContext)
{
	if( essentials.inp.getEscapeState() )
	{
		quitContext = true;
		essentials.inp.setEscapeKeyFalse();
	}
}

void customMenu::drawEverything(Essentials& essentials, Interface& interface)
{
	if( essentials.drawFrequency.hasTimeElapsed( std::chrono::milliseconds{16} ) )
	{
		essentials.rndWnd.clearScreen(BLACK_COL);
		interface.drawEverything(essentials);
		essentials.rndWnd.displayRenderer();
		essentials.drawFrequency.joinTimePoints();
	}
}

void customMenu::startCustomGame(Essentials& essentials, unsigned skill, TimeOptions& timeOptions, Interface& interface, bool& quitContext)
{
	if( interface.letsStartCustomGame(skill) )
	{
		interface.setOptionForCustomGame(timeOptions);
		timeOptions.setPieceFallChangeDelay();
		runTetrisGame(essentials, skill, timeOptions);
		quitContext = true;
	}
}

void customMenu::quitMenu(const Interface& interface, bool& quitContext)
{
	if( interface.goBackClicked() )
	{
		quitContext = true;
	}
}