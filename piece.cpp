#include"piece.h"
#include"board.h"
#include<iostream>

using namespace std;
piece::piece()
{
	this->p = '-';
	pos.ri = -1;
	pos.ci = -1;
	b = nullptr;
}
piece::piece(char a, int ri, int ci,Board *B)
{
	this->p = 'a';
	pos.ri = ri;
	pos.ci = ci;
	this->b = B;                         //b is *Board

}
piece::piece(const piece& a)
{
	this->p = a.p;
	this->pos.ri = a.pos.ri;
	this->pos.ci = a.pos.ci;
	this->b = a.b;
	this->isSmall = a.isSmall;
}
void piece::change_alive()
{
	this->p = '-';
	pos.ri = -1;
	pos.ci = -1;
}
void piece::print_Piece()
{
	cout << this->p;
}
bool piece::IsmyPiece(int Turn)
{
	if (Turn != this->isSmall)
	{
		if (Turn ==1 && this->p == '-')
			return 0;
		else
		return 1;
	}
	return 0;
}

bool piece::Isnot_my_piece(int T)
{
	if (T==this->isSmall)
	{
		return 1;
	}
	return 0;

}




