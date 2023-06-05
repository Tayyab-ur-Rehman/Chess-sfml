#pragma once
#include "board.h"
#include "player.h"


#include <SFML/Graphics.hpp>
using namespace sf;
class chess
{
public:
	int Turn;
	Board* B;
	chess();
	void TurnCH();
	void TurnMsg(RenderWindow& window);

	void WindowPrt(RenderWindow& window);
	void WindowHigh(RenderWindow& window, bool** U);
	bool Window(sf::RenderWindow& window);
	void checkMsG(int Turn , RenderWindow& window );
	
	void checkmate(RenderWindow & window,int Turn);
	bool capture(Position source_Pos, Position des_Pos)
	{
		if (this->B->pie[des_Pos.ri][des_Pos.ci]->p == '-')
			return false;
		return 1;

	}
	chess(string name);
	void print1();
	void Play();
	chess(int a);

};