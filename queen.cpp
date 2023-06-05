#include<iostream>
using namespace std;
#include"queen.h"
#include"board.h"




queen::queen(int Turn,Board *B)
{
	this->b = B;
	if (Turn == 0) {
		isSmall = 1;
		this->p = 'q';
	}
	else {
		this->p = 'Q';
		isSmall = 0;
	}
}
void queen:: drawPiece()
{
	cout << this->p;
}

bool queen::isLegal(Position S, Position D,int T)
{

	if ((vert_move(S, D) && clearV(*b, S, D)) || (hori_move(S, D) && clearH(*b, S, D)))
		return true;

	if (isDig_mov(S, D)) {
		if (choice_RL(S, D))
		{
			if (clearDiLR(*b, S, D))
			{
				return true;
			}
		}
		else if (clearDiRL(*b, S, D))
			return true;
	}
	return false;

}

void queen::operator=(const piece& A)
{
	this->b = A.b;
	this->pos.ri = A.pos.ri;
	this->pos.ci = A.pos.ci;
	this->p = A.p;
	this->isSmall = A.isSmall;
}

void queen::move(Position S, Position D)
{
	b->pie[D.ri][D.ci] = b->pie[S.ri][S.ci];
	b->pie[S.ri][S.ci] = new em();
}
