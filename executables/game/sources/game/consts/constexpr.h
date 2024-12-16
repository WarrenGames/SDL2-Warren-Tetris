#ifndef CONSTEXPR_H
#define CONSTEXPR_H

#include <cstddef>

enum RotationIndex{North, East, South, West, Max};

constexpr std::size_t BigMatrixWidth = 10;
constexpr std::size_t BigMatrixHeight = 24;

constexpr int SQR_SIZE = 32; //Size in pixels

constexpr int InfosPanelWidth = SQR_SIZE * 12;

constexpr int GameWindowWidth = BigMatrixWidth * SQR_SIZE + 2 * SQR_SIZE + InfosPanelWidth;
constexpr int GameWindowHeight = BigMatrixHeight * SQR_SIZE + SQR_SIZE;

constexpr std::size_t SquareColorNumber = 10;

enum{ SkillEasyGame, SkillIntermediateGame, SkillHardGame, SkillGameMax };

constexpr char GameFontPath[] = "fonts/FreeSans.ttf"; 

constexpr char ScoreEasyFileName[] = "easyScores.txt";
constexpr char ScoreIntermediateFileName[] = "intermediateScores.txt";
constexpr char ScoreHardFileName[] = "hardScores.txt";

constexpr char Organization[] = "The games of the warren";
constexpr char GameName[] = "SDL2 Tetris";
constexpr char ErrorLogFileName[] = "errorLog.txt";
constexpr char WarningLogFileName[] = "warningLog.txt";

#endif //CONSTEXPR_H