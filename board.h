#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<string.h>

#include "piece.h"
#include "pawn.h"
#include "king.h"
#include "bishop.h"
#include "queen.h"
#include "rook.h"
#include "knight.h"
#include "empty.h"

#include "player.h"


static char** Load(string name)
{
	ifstream Rdr(name);
	char** A; A = new char* [8];
	for (int i = 0; i < 8; i++)
	{
		A[i] = new char[8];
		for (int c = 0; c < 8; c++)
		{
			Rdr >> A[i][c];
		}
	}
	return A;
}

class Board
{
public:
	int rows;
	int cols;
	piece*** pie;
	int dim = 8;
	Player player[2];
	Position Source_Pos;
	Position des_Pos;
    //functions\\	
	
	Board();
	Board(string name);
	Board(const Board &A);
	void init();
	void copyToNewBoard(Board &N);
	Position FindKing(int Turn);
	void printBoard();
	void drawMsg();
	void checkMateMsg(int Turn);
	void printHighBoard(bool **H);
	void SeletSource(Position source_Pos);
	void SeletDes(Position source_Pos);
	bool isBasicLegal(Position s);
	void move(Position source_Pos,Position des_Pos );
	bool iSMY_PIECE(int Turn1, Position S);
	void LoadToFile(string A);
	bool isCheck(int Turn);
	void CheckMsg(int Turn);
	bool Selfcheck(int Turn);
	bool Stalement(int Turn);
	bool checkMate(int Turn);
	friend ostream & operator <<(ostream& co, const Board &a);
	bool Castling(Position S, Position D, int Turn);
	bool** findHight(int Turn);
	void undo( Board  A);
	void Update_only(Position S, Position D);
	void mouse_position(Position& P, int len);
	void PBoard2_R();
	void Hilighter(bool** Hilght);
	void UHilighter(bool** Hilight);
	char choice();

	~Board();
};
