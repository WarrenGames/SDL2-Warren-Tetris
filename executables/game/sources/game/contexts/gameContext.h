#ifndef GAME_CONTEXT_H
#define GAME_CONTEXT_H

struct Essentials;
struct TimeOptions;
struct GameObject;

void runTetrisGame(Essentials& essentials, unsigned skillLevel, TimeOptions timeOpt);

void gameMainLoop(Essentials& essentials, TimeOptions& timeOpt, GameObject& gameObj, bool& quitGame);

void makeCurrentPieceGoDowner(GameObject& gameObj, TimeOptions& timeOpt, bool& quitGame);

void drawEverything(Essentials& essentials, GameObject& gameObj);

void quitGameIfWindClose(Essentials& essentials, bool& quitGame);

void modifyTimeData(TimeOptions& timeOpt);

#endif //GAME_CONTEXT_H