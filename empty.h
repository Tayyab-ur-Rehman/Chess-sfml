#pragma once

#include"piece.h"





class Board;


class em :public piece
{
public:
	em();
	virtual void drawPiece();
	virtual bool isLegal(Position S, Position D,int T);
	virtual void print_Piece();
	virtual void operator = (const piece& A);
	virtual void move(Position S, Position D);


};

