#include "runGame/menus/mainMenu.h"
#include "runGame/menus/mainMenuElements.h"
#include "commonFiles/types/essentials.h"
#include "time/accurateTime.h"
#include "game/structs/timeOptionsStruct.h"
#include "runGame/menus/options/context.h"
#include "runGame/menus/customModeMenu/customMenuContext.h"
#include "game/contexts/gameContext.h"
#include "game/consts/sdlColors.h"

void mainMenu::context(Essentials& essentials)
{	
	mainMenu::Elements elements{essentials};
	bool quitContext{false};
	mainMenu::mainLoop(essentials, elements, quitContext);
}

void mainMenu::mainLoop(Essentials& essentials, mainMenu::Elements& elements, bool& quitContext)
{
	while( false == quitContext )
	{
		essentials.inp.updateMouse();
		mainMenu::quitMenu(essentials, quitContext);
		mainMenu::updateButtons(essentials, elements);
		mainMenu::runGame(essentials, elements);
		mainMenu::runOptions(essentials, elements);
		mainMenu::runCustomGame(essentials, elements);
		mainMenu::drawEverything(essentials, elements);
	}
}

void mainMenu::updateButtons(const Essentials& essentials, mainMenu::Elements& elements)
{
	elements.updateButtons(essentials.inp.getMousePosition(), essentials.inp.getMouseLeftButton() );
	elements.optionsButton.updateButton(essentials.inp.getMousePosition(), essentials.inp.getMouseLeftButton() );
	elements.customGame.updateButton(essentials.inp.getMousePosition(), essentials.inp.getMouseLeftButton() );
}

void mainMenu::drawEverything(Essentials& essentials, const mainMenu::Elements& elements)
{
	essentials.rndWnd.clearScreen(BLACK_COL);
	elements.drawEverything(essentials);
	essentials.rndWnd.displayRenderer();
	SDL_Delay(10);
}

void mainMenu::quitMenu(Essentials& essentials, bool& quitContext)
{
	if( essentials.inp.getEscapeState() || essentials.inp.getWindowClose() )
	{
		quitContext = true;
	}
}

void mainMenu::runGame(Essentials& essentials, const mainMenu::Elements& elements)
{
	for( size_t skill{0} ; skill < GAME_MAX ; ++skill )
	{
		if( elements.isButtonClicked(skill) )
		{	
			TimeOptions timeOptions{1000};
			runTetrisGame(essentials, static_cast<unsigned>(skill), timeOptions);
		}
	}
}

void mainMenu::runOptions(Essentials& essentials, mainMenu::Elements& elements)
{
	if( elements.optionsButton.buttonClicked() )
	{
		options::context(essentials);
		elements.resetKeycodesInfos(essentials);
		essentials.inp.setMouseLeftButtonFalse();
	}
}

void mainMenu::runCustomGame(Essentials& essentials, mainMenu::Elements& elements)
{
	if( elements.customGame.buttonClicked() )
	{
		customMenu::mainContext(essentials);
		essentials.inp.setMouseLeftButtonFalse();
	}
}