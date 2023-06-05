#pragma once
class Board;
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

struct Position
{
	int ri; int ci;   

};





Position MouseClick(sf::RenderWindow &window);
Position CalRiCi(sf::RenderWindow& window);

void SetClr(int clr);
void getRowColbyLeftClick(int& rpos, int& cpos);
void gotoRowCol(int rpos, int cpos);

bool up(Position S, Position D);
bool down(Position S, Position D);
bool left(Position S, Position D);
bool right(Position S, Position D);
bool upleft(Position S, Position D);
bool upright(Position S, Position D);
bool downright(Position S, Position D);
bool downleft(Position S, Position D);
bool hori_move(Position So, Position D);
bool vert_move(Position So, Position D);
bool isDig_mov(Position So, Position D);

bool choice_RL(Position S, Position D);
bool SNotEqualD(Position S, Position D);
bool Legal_knight(Position S, Position D);
bool clearV(Board B, Position So, Position D);
bool clearH(Board B, Position So, Position D);
bool clearDiLR(Board B, Position S, Position D);
bool clearDiRL(Board B, Position S, Position D);

void Box2(int sr, int sc, int er, int ec, int colour, char sym);
void BoxH(int sr, int sc, int er, int ec, int colour);

void Dpawn(int sr, int sc, int Len, int col1, int col2, char ch);
void Dqueen(int sr, int sc, int Len, int col1, int col2, char ch);
void Dking(int sr, int sc, int Len, int col1, int col2, char ch);
void Dnight(int sr, int sc, int Len, int col1, int col2, char ch);
void Dbishop(int sr, int sc, int Len, int col1, int col2, char ch);
void Drook(int sr, int sc, int Len, int col1, int col2, char ch);
void BoxH(int sr, int sc, int er, int ec, int colour);
void Box(int sr, int sc, int er, int ec, int colour, char sym);
void mouse_position69(Position& P, int len);