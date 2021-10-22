#ifndef PIECE_COLLISION_TEST_H
#define PIECE_COLLISION_TEST_H

bool isPieceInCollisionWithMat(const GameObject& gameObj, int xmove, int ymove);

bool isPieceInCollisionWithMatSquare(const GameObject& gameObj, int sqr_x, int sqr_y, int xdecal, int ydecal);

bool isPieceInCollisionWVerticalBorders(const GameObject& gameObj, int xmove);

bool hasPieceReachedBottom(const GameObject& gameObj);

#endif //PIECE_COLLISION_TEST_H