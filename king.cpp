#include"king.h"
#include<iostream>
using namespace std;
#include"board.h"

king::king(int Turn,Board *B)
{
	this->b = B;
	if (Turn == 0) {
		this->p = 'k';
		this->isSmall = 1;
	}
	else
		this->p = 'K';
	this->first_mov = true;

}
void king:: drawPiece()
{
	cout << this->p;
}
bool king::isLegal(Position S, Position D,int Turn)
{
	if (this->isSmall) {
		if ((S.ri == 0 && S.ci == 4)&&b->pie[D.ri][D.ci]->p == 'r'&& (( D.ri == 0 && D.ci == 0)||(D.ri == 0 && D.ci == 7) ))
		{
			if (clearH(*b, S, D))
				return 1;
		}
	}
	else if((S.ri == 7 && S.ci == 4) && b->pie[D.ri][D.ci]->p == 'R' && ((D.ri == 7 && D.ci == 0) || (D.ri == 7 && D.ci == 7)))
	{
		if (clearH(*b, S, D))
			return true;
	}
	if ((abs(S.ri - D.ri) == 1 && abs(S.ci - D.ci) == 0) || (abs(S.ci - D.ci) == 1 && abs(S.ri - D.ri) == 0))
	{
		return 1;
	}
	if(upright(S,D)||upleft(S,D)||downleft(S,D)||downright(S,D))
		return 1;

	return 0;
}
void king::operator=(const piece& A)
{
	this->b = A.b;
	this->pos.ri = A.pos.ri;
	this->pos.ci = A.pos.ci;
	this->p = A.p;
	this->isSmall = A.isSmall;
}

void king::move(Position S, Position D)
{
	this->first_mov = false;
		if (this->isSmall&&(S.ri == 0 && S.ci == 4) &&b->pie[D.ri][D.ci]->p == 'r' && ((D.ri == 0 && D.ci == 0) || (D.ri == 0 && D.ci == 7)))
		{
			if (D.ri == 0 && D.ci == 0)
			{
				b->pie[D.ri][D.ci +3] = b->pie[D.ri][D.ci];
				b->pie[S.ri][S.ci -2] = b->pie[S.ri][S.ci];
				b->pie[D.ri][D.ci]= new em();
				b->pie[S.ri][S.ci] = new em();
			}
			else if (D.ri == 0 && D.ci == 7)
			{
				b->pie[D.ri][D.ci-2]=b->pie[D.ri][D.ci];
				b->pie[S.ri][S.ci+2]=b->pie[S.ri][S.ci];
				b->pie[D.ri][D.ci] = new em();
				b->pie[S.ri][S.ci] = new em();
			}
		}
	else if ((S.ri == 7 && S.ci == 4)  && b->pie[D.ri][D.ci]->p == 'R' && ((D.ri == 7 && D.ci == 0) || (D.ri == 7 && D.ci == 7)))
	{
		if (D.ri == 7 && D.ci == 0)
		{
			b->pie[D.ri][D.ci + 3] = b->pie[D.ri][D.ci];
			b->pie[S.ri][S.ci - 2] = b->pie[S.ri][S.ci];
			b->pie[D.ri][D.ci] = new em();
			b->pie[S.ri][S.ci] = new em();
		}
		else if (D.ri == 7 && D.ci == 7)
		{
			b->pie[D.ri][D.ci - 2] = b->pie[D.ri][D.ci];
			b->pie[S.ri][S.ci + 2] = b->pie[S.ri][S.ci];
			b->pie[D.ri][D.ci] = new em();
			b->pie[S.ri][S.ci] = new em();
		}
	}
	else 
	{
		b->pie[D.ri][D.ci] = b->pie[S.ri][S.ci];
		b->pie[S.ri][S.ci] = new em();
	}
}
