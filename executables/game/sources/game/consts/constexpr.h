#ifndef CONSTEXPR_H
#define CONSTEXPR_H

#include <cstddef>

enum ROT_IND{NORTH, EAST, SOUTH, WEST, MAX};

constexpr std::size_t BIGMAT_WIDTH = 10;
constexpr std::size_t BIGMAT_HEIGHT = 24;

constexpr int SQR_SIZE = 32; //Size in pixels

constexpr int INFOS_PANEL_WIDTH = SQR_SIZE * 12;

constexpr int SCREENW = BIGMAT_WIDTH * SQR_SIZE + 2 * SQR_SIZE + INFOS_PANEL_WIDTH;
constexpr int SCREENH = BIGMAT_HEIGHT * SQR_SIZE + SQR_SIZE;

constexpr std::size_t SQR_COLOR_NUM = 10;

enum{EASY_GAME, INTERMEDIATE_GAME, HARD_GAME, GAME_MAX};

constexpr char ARIALFONTPATH[] = "fonts/arial.ttf"; 

constexpr char EASY_FILE_NAME[] = "easyScores.txt";
constexpr char INTERM_FILE_NAME[] = "intermediateScores.txt";
constexpr char HARD_FILE_NAME[] = "hardScores.txt";

constexpr char ORGANIZATION[] = "The games of the warren";
constexpr char GAME_NAME[] = "SDL2 Tetris";
constexpr char ERR_LOG_FILE_NAME[] = "errorLog.txt";
constexpr char WARN_LOG_FILE_NAME[] = "warningLog.txt";

#endif //CONSTEXPR_H