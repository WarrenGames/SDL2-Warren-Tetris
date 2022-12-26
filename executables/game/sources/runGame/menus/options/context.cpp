#include "runGame/menus/options/context.h"
#include "runGame/menus/options/optionsMenuElements.h"
#include "commonFiles/types/essentials.h"
#include "game/consts/sdlColors.h"

void options::context(Essentials& essentials)
{
	OptionsMenuElements optionMenu{essentials};
	bool quitMenu{false};
	options::mainLoop(essentials, optionMenu, quitMenu);
	optionMenu.keycodesData.writeKeycodesInFile(essentials.logs, essentials.prefPath);
}

void options::mainLoop(Essentials& essentials, OptionsMenuElements& optionMenu, bool& quitMenu)
{
	while( false == quitMenu )
	{
		essentials.inp.updateMouse();
		options::quitMenu(essentials, quitMenu);
		optionMenu.updateButtons(essentials);
		optionMenu.changeGameInput(essentials);
		options::drawEverything(essentials, optionMenu);
	}
}

void options::drawEverything(Essentials& essentials, const OptionsMenuElements& optionMenu)
{
	essentials.rndWnd.clearScreen(BLACK_COL);
	optionMenu.drawButtons(essentials);
	optionMenu.drawInfoTexts(essentials);
	essentials.rndWnd.displayRenderer();
	SDL_Delay(16);
}

void options::quitMenu(Essentials& essentials, bool& quitMenu)
{
	if( essentials.inp.getEscapeState() || essentials.inp.getWindowClose() )
	{
		quitMenu = true;
		essentials.inp.setEscapeKeyFalse();
	}
}