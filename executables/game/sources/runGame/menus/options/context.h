#ifndef OPTIONS_CONTEXT_H
#define OPTIONS_CONTEXT_H

struct Essentials;
struct OptionsMenuElements;

namespace options{

void context(Essentials& essentials);

void mainLoop(Essentials& essentials, OptionsMenuElements& optionMenu, bool& quitMenu);

void drawEverything(Essentials& essentials, const OptionsMenuElements& optionMenu);

void quitMenu(Essentials& essentials, bool& quitMenu);

}

#endif //OPTIONS_CONTEXT_H