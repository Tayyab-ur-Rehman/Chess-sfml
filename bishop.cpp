#include"bishop.h"
#include<iostream>
#include"board.h"


using namespace std;

bishop::bishop(int Turn,Board *B)
{
	this->b = B;
	if (Turn == 0) {
		isSmall = 1;
		this->p = 'b';
	}
	else {
		this->p = 'B';
		isSmall = 0;
	}
}
void bishop::drawPiece()
{
	cout << this->p;
}
bool bishop::isLegal(Position S, Position D,int T)
{
	if (downright(S, D) || upleft(S, D)||upright(S,D)||downleft(S,D))
		return true;
	if (isDig_mov(S, D))
		if (choice_RL(S, D))
		{
			if (clearDiLR(*b, S, D))
			{
				return true;
			}
			
		}
		else if (clearDiRL(*b, S, D))
			return true;
	return false;
}

void bishop::operator=(const piece& A)
{
	this->b = A.b;
	this->pos.ri = A.pos.ri;
	this->pos.ci = A.pos.ci;
	this->p = A.p;
	this->isSmall = A.isSmall;
}

void bishop::move(Position S, Position D)
{
	b->pie[D.ri][D.ci] = b->pie[S.ri][S.ci];
	b->pie[S.ri][S.ci] = new em();
}

