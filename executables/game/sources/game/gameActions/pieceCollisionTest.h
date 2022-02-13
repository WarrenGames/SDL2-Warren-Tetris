#ifndef PIECE_COLLISION_TEST_H
#define PIECE_COLLISION_TEST_H

#include <cstdlib>

struct GameObject;

bool isPieceInCollisionWithMat(const GameObject& gameObj, int xmove, int ymove);

bool isPieceInCollisionWithMatSquare(const GameObject& gameObj, size_t sqr_x, size_t sqr_y, int xdecal, int ydecal);

bool isPieceInCollisionWVerticalBorders(const GameObject& gameObj, int xmove);

bool hasPieceReachedBottom(const GameObject& gameObj);

#endif //PIECE_COLLISION_TEST_H