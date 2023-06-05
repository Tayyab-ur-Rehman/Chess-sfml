#pragma once


#include"utility.h"



class piece
{
public:
	char p;
	Position pos;
	bool isSmall;
	Board* b;

	piece();
	piece(char a, int ri, int ci,Board *B);
	piece(const piece & a);
	virtual void operator = (const piece & A)=0;
	void change_alive();
	virtual bool isLegal(Position S, Position D,int T)=0;
	//virtual bool LegalMove(Board B, Position S, Position D)=0;
	virtual void print_Piece();
	bool IsmyPiece(int Turn);
	virtual void move(Position S,Position D) = 0;
	bool Isnot_my_piece(int T);
};