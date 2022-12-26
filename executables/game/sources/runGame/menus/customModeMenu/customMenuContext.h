#ifndef CUSTOM_MODE_MENU_CONTEXT_H
#define CUSTOM_MODE_MENU_CONTEXT_H

struct Essentials;
struct TimeOptions;

namespace customMenu{

class Interface;
	
void mainContext(Essentials& essentials);

void mainLoop(Essentials& essentials, Interface& interface, TimeOptions& timeOptions, bool& quitContext);

void update(Essentials& essentials, Interface& interface, bool& quitContext);

void quitWithEscape(Essentials& essentials, bool& quitContext);

void drawEverything(Essentials& essentials, Interface& interface);

void startCustomGame(Essentials& essentials, unsigned skill, TimeOptions& timeOptions, Interface& interface, bool& quitContext);

void quitMenu(const Interface& interface, bool& quitContext);

}

#endif //CUSTOM_MODE_MENU_CONTEXT_H