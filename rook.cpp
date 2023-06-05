#include<iostream>
#include"rook.h"
#include"board.h"
using namespace std;





rook ::rook(int Turn,Board *B)
{
	this->b = B;
	if (Turn == 0) {
		isSmall = 1;
		this->p = 'r';
	}
	else {
		this->p = 'R';
		isSmall = 0;
	}
	this->first_mov = true;
}
void rook::drawPiece()
{
	cout << this->p;
}

bool rook::isLegal(Position S, Position D,int T) 
{
	if ((vert_move(S, D) && clearV(*b, S, D)) || (hori_move(S, D) && clearH(*b, S, D)))
	{
		return true;
	}
	return false;
}

void rook::operator=(const piece& A)
{
	this->b = A.b;
	this->pos.ri = A.pos.ri;
	this->pos.ci = A.pos.ci;
	this->p = A.p;
	this->isSmall = A.isSmall;
}

void rook::move(Position S, Position D)
{
	this->first_mov = false;

	b->pie[D.ri][D.ci] = b->pie[S.ri][S.ci];
	b->pie[S.ri][S.ci] = new em();

}

bool rook::isFirstMov(Position A)
{
	if (b->pie[A.ri][A.ci]->p == 'r' || b->pie[A.ri][A.ci]->p == 'R')
	{
		return this->first_mov;
	}
}
