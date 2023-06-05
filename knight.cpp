#include<iostream>
#include"knight.h"
using namespace std;
#include"board.h"

knight::knight(int Turn,Board *B)
{
	this->b = B;
	if (Turn == 0) {
		isSmall = 1;
		this->p = 'n';
	}
	else {
		this->p = 'N';
		isSmall = 0;
	}
}
void knight:: drawPiece()
{
	cout << this->p;
}

bool knight::isLegal(Position S, Position D,int T)
{
	if (abs(S.ri - D.ri) == 1 && abs(S.ci - D.ci) == 2)
		return 1;
	if (abs(S.ri - D.ri) == 2 && abs(S.ci - D.ci) == 1)
		return 1;
	return 0;
}

void knight::operator=(const piece& A)
{

}

void knight::move(Position S, Position D)
{
	b->pie[D.ri][D.ci] = b->pie[S.ri][S.ci];
	b->pie[S.ri][S.ci] = new em();
}
