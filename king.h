#pragma once

#include"piece.h"
class Board;

class king :public piece
{
	bool first_mov;
public:
	king(int Turn,Board *B);
	virtual void drawPiece();
	virtual bool isLegal(Position S, Position D,int T);
	virtual void operator = (const piece& A);
	virtual void move(Position S, Position D);
};
