#ifndef MAIN_MENU_H
#define MAIN_MENU_H

struct Essentials;
namespace mainMenu{ struct Elements; }

namespace mainMenu{
	void context(Essentials& essentials);

	void mainLoop(Essentials& essentials, mainMenu::Elements& elements, bool& quitContext);

	void updateButtons(const Essentials& essentials, mainMenu::Elements& elements);

	void drawEverything(Essentials& essentials, const mainMenu::Elements& elements);

	void quitMenu(Essentials& essentials, bool& quitContext);
	
	void runGame(Essentials& essentials, const mainMenu::Elements& elements);
	
	void runOptions(Essentials& essentials, mainMenu::Elements& elements);
	
	void runCustomGame(Essentials& essentials, mainMenu::Elements& elements);
}

#endif //MAIN_MENU_H