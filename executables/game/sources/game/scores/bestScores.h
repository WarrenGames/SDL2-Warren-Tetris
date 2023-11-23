#ifndef BEST_SCORES_H
#define BEST_SCORES_H

#include <string>

struct Essentials;
class ScoresGraphics;
class PlayerScore;
namespace sdl2{ class TextTexture; }

namespace bestScores{

void bestScoresContext(Essentials& essentials, const PlayerScore& playerScore, unsigned skill);

void mainLoop(Essentials& essentials, const ScoresGraphics& scores, bool& quitContext);

void quitWInp(Essentials& essentials, bool& quitContext);

void drawAll(Essentials& essentials, const ScoresGraphics& scores);

void createScoresFilesIfMissing(Essentials& essentials);

void createSingleScoreFile(Essentials& essentials, const std::string& fileFullPath);

void loadScores(Essentials& essentials, const std::string& fileFullPath);

}

#endif //BEST_SCORES_H