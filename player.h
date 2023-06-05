#pragma once
#include<string.h>
#include<iostream>
#include"utility.h"

using namespace std;
class Player
{
public:

	string name;
	long long Time;
	int col;
	Position pos;
	Player();
	void p1(string na, int cl);
	string getname();
	Position SelectCoordinate();

};