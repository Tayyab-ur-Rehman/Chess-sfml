#include"empty.h"
#include"board.h"
#include<iostream>
using namespace std;

em::em()
{
	this->p = '-';
}
void em::drawPiece()
{
	cout << this->p;
}
bool em::isLegal(Position S, Position D,int T)
{
	return 1;
}
void em::print_Piece()
{
	cout << p;
}
void em::operator=(const piece& A)
{
	this->b = A.b;
	this->pos.ri = A.pos.ri;
	this->pos.ci = A.pos.ci;
	this->p = A.p;
	this->isSmall = A.isSmall;
}
void em::move(Position S, Position D)
{
	
}
