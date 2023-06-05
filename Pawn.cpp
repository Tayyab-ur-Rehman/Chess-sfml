#include"Pawn.h"
#include<iostream>

#include"board.h"

using namespace std;

void Pawn ::drawPiece()
{
	cout << this->p;
}
bool Pawn::isLegal(Position S, Position D,int T)
{
	
	if (this->isSmall)
	{
		if (S.ri + 2 == D.ri && S.ri==1)
		{
			if (S.ci == D.ci)
			{
				if (S.ri==1)
				{
					return 1;
				}
			}
		}
		if (S.ri + 1 == D.ri )
		{
			if (S.ci == D.ci && (b->pie[D.ri][D.ci]->p == '-'))
				return 1;
			if (downleft(S, D) && !(b->pie[D.ri][D.ci]->p == '-') )
			{
				return true;
			}
			if (downright(S, D) && !(b->pie[D.ri][D.ci]->p == '-'))
			{
				return true;
			}
		}
			return false;
	}
	else
	{
		if (S.ri - 2 == D.ri &&S.ri==6)
		{
			if (S.ci == D.ci)
			{
				if (S.ri == 6)
				{
					return 1;
				}
			}
		}
		if (S.ri -1 == D.ri)
		{
			if (S.ci == D.ci && (b->pie[D.ri][D.ci]->p == '-'))
				return 1;
			if (upleft(S, D) && !(b->pie[D.ri][D.ci]->p == '-') )//&& this->b->pie[D.ri][D.ci]->Isnot_my_piece(T))
				return 1;
			if (upright(S, D) && !(b->pie[D.ri][D.ci]->p == '-' ))//&& !this->b->pie[D.ri][D.ci]->Isnot_my_piece(T))
			{
				return 1;
			}
		}
	}
	return false;
}
void Pawn::operator=(const piece& A)
{
	this->b = A.b;
	this->pos.ri = A.pos.ri;
	this->pos.ci = A.pos.ci;
	this->p = A.p;
	this->isSmall = A.isSmall;
}
void Pawn::move(Position S, Position D)
{
	this->first_mov=false;
	b->pie[D.ri][D.ci] = b->pie[S.ri][S.ci];
	b->pie[S.ri][S.ci] = new em();

}
Pawn::Pawn(int Turn,Board *B)
{
	this->b = B;
	if (Turn == 0) {
		isSmall = 1;
		this->p = 'p';
	}
	else {
		this->p = 'P';
		isSmall = 0;
	}
	this->first_mov = 1;
}
