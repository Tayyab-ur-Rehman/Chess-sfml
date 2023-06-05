#include"player.h"


Player::Player()
{
	name = "no name";
	this->Time = 0;
}
void Player:: p1(string na, int cl)
{
	name = na;
	if (cl == 0)
		col = 0;
	else
		col = 1;
}
string Player::getname()
{
	return name;
}
Position Player::SelectCoordinate()
{
	cout << "Row  Col "; cin >> pos.ri;
	cin >> pos.ci;
	pos.ri--;
	pos.ci--;
	return pos;
}