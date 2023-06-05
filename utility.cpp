#include"utility.h"
#include"board.h"
#include<cstdlib>
#include<iostream>
#include<windows.h>

using namespace sf;

bool up(Position S, Position D)
{
	if (D.ri - 1 == S.ri && D.ci == S.ci)
	return true;
	return false;

}
bool down(Position S, Position D)
{
	if (D.ri + 1 == S.ri && D.ci == S.ci)
		return true;
	return false;

}
bool left(Position S, Position D)
{
	if (D.ri == S.ri && D.ci - 1 == S.ci)
		return true;
	return false;

}
bool right(Position S, Position D)
{
	if (D.ri == S.ri && D.ci + 1 == S.ci)
		return true;
	return false;
}
bool upleft(Position S, Position D)
{
	if (D.ri == S.ri - 1 && D.ci == S.ci - 1)
		return true;
	return 0;

}
bool upright(Position S, Position D)
{
	if (D.ri == S.ri - 1 && D.ci == S.ci + 1)
		return true;
	return 0;

}
bool downright(Position S, Position D)
{
	if (D.ri == S.ri + 1 && D.ci == S.ci + 1)
		return true;
	return 0;

}
bool downleft(Position S, Position D)
{
	if (D.ri == S.ri + 1 && D.ci == S.ci - 1)
		return true;
	return false;

}
bool hori_move(Position So, Position D)
{
	if (So.ri == D.ri)
		return true;
	return false;

}
bool vert_move(Position So, Position D)
{

	if (So.ci == D.ci)
		return true;
	return false;
}
bool isDig_mov(Position So, Position D)
{
	return (abs(So.ri - D.ri) == abs(So.ci - D.ci));
}
bool choice_RL(Position S, Position D)
{
	if (S.ri > D.ri && S.ci > D.ci)
	{
		return 1;
	}
	if (S.ri < D.ri && S.ci < D.ci)
	{
		return 1;
	}
	return 0;
}
bool SNotEqualD(Position S, Position D)
{
	if (S.ci == D.ri)
	{
		if (S.ci == D.ci)
			return 1;
	}
	return 0;
}
bool Legal_knight(Position S, Position D)
{
	if (abs(S.ri - D.ri) == 1 && abs(S.ci - D.ci) == 2)
		return 1;
	if (abs(S.ri - D.ri) == 2 && abs(S.ci - D.ci) == 1)
		return 1;
	return 0;
}

bool clearV(Board B, Position So, Position D)
{
	int st;
	int en;
	if (So.ri < D.ri)///////////////////////////left
	{
		st = So.ri;
		en = D.ri;
	}
	else
	{
		st = D.ri;
		en = So.ri;
	}
	for (int i = st + 1; i < en; i++)
	{

		if (!(B.pie[i][D.ci]->p == '-'))
			return false;
	}
	return true;
}
bool clearH(Board B, Position So, Position D)
{
	int st;
	int en;
	if (So.ci < D.ci)
	{
		st = So.ci;
		en = D.ci;
	}
	else
	{
		st = D.ci;
		en = So.ci;
	}
	for (int i = st + 1; i < en; i++)
	{
	
		if (!(B.pie[D.ri][i]->p == '-'))
			return false;
	}
	return true;
}
bool clearDiLR(Board B, Position S, Position D)
{
	if (S.ri == D.ri && S.ci == D.ci)
		return 0;
	if (S.ri < D.ri)
	{
		int dr = D.ri - S.ri - 1;
		for (int i = 1; dr >= i; i++)
		{
			if (B.pie[S.ri + i][S.ci + i]->p != '-')
				return false;
		}
		return true;
	}
	else
	{
		int dr = S.ri - D.ri - 1;
		for (int i = 1; dr >= i; i++)
		{
			if (B.pie[S.ri - i][S.ci - i]->p != '-')
				return false;
		}
		return true;
	}

}
bool clearDiRL(Board B, Position S, Position D)
{
	if (S.ri == D.ri && S.ci == D.ci)
		return 0;
	if (S.ri < D.ri)
	{
		int dr = abs(D.ri - S.ri - 1);
		for (int i = 1; dr >=i; i++)
		{
			if (B.pie[S.ri + i][S.ci - i]->p != '-')
				return false;
		}
		return true;
	}
	else
	{
		int dr = abs(S.ri - D.ri - 1);
		for (int i = 1; dr >= i; i++)
		{
			if (B.pie[S.ri - i][S.ci + i]->p != '-')
				return false;
		}
		return true;
	}

}
void SetClr(int clr)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
}
void getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}
void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}

void Box2(int sr, int sc, int er, int ec, int colour, char sym)
{
	for (int r = 0; r < er; r++)
	{
		for (int c = 0; c < er; c++)
		{
			gotoRowCol(sr + r, sc + c);
			SetClr(colour);
			cout << sym;
		}
	}
}
void BoxH(int sr, int sc, int er, int ec, int colour)
{
	char ch = -37;
	for (int r = 0; r < er; r++)
	{
		for (int c = 0; c < er; c++)
		{
			gotoRowCol(sr + r, sc + c);
			if (r == 0 || r == er - 1 || c == 0 || c == er - 1)
			{
				SetClr(colour);
				cout << ch;
			}
		}
	}
}
void Box(int sr, int sc, int er, int ec, int colour, char sym)
{
	char ch = -37;
	for (int r = 0; r < er; r++)
	{
		for (int c = 0; c < er; c++)
		{
			gotoRowCol(sr + r, sc + c);
			SetClr(colour);
			if (r == er / 2 && c == ec / 2)
			{
				SetClr(11);
				cout << sym;
			}
			else
			{
				SetClr(colour);
				cout << ch;
			}
		}
	}
}

void Dbishop(int sr, int sc, int Len, int col1, int col2, char ch)
{
	for (int r = 0; Len > r; r++)
	{
		for (int c = 0; Len > c; c++)
		{

			gotoRowCol(sr + r, sc + c);
			if ((r == 5 && c - 1 == 2) || (r == 4) && (c - 1 == 2) || ((r == 5) && (c - 1 == 1)) || ((r == 5) && (c - 1 == 5)) || ((r == 4) && (c - 1 == 4)) || ((r == 1) && (c - 1 == 3)) || ((r == 2) && (c - 1 == 2)) || ((r == 2) && (c - 1 == 3)) || ((r == 2) && (c - 1 == 4)) || ((r == 3) && (c - 1 == 2)) || ((r == 3) && (c - 1 == 3)) || ((r == 3) && (c - 1 == 4)) || ((r == 2) && (c - 1 == 2)) || ((r == 5) && (c - 1 == 3)) || ((r == 5) && (c - 1 == 4)) || (r == 4 && c - 1 == 3))
				SetClr(col1);
			else
				SetClr(col2);
			cout << ch;
		}
	}
}
void Dking(int sr, int sc, int Len, int col1, int col2, char ch)
{
	for (int r = 0; Len > r; r++)
	{
		for (int c = 0; Len > c; c++)
		{

			gotoRowCol(sr + r, sc + c);

			if ((r == 6) && (c == 2 || c == 6) || ((r >= 4 && r <= 6) && (c >= 3 && c < 6)) || (r == 3 || r == 7) && (c >= 1 && c < 8) || r == 7 && (c >= 2 && c <= 7) || (r == 1 || r == 2) && (c == 1 || c == 2 || c == 6 || c == 4 || c == 7))
				SetClr(col1);
			else
				SetClr(col2);
			cout << ch;
		}
	}
}
void Dnight(int sr, int sc, int Len, int col1, int col2, char ch)
{
	for (int r = 0; Len > r; r++)
	{
		for (int c = 0; Len > c; c++)
		{
			gotoRowCol(sr + r, sc + c);
			if (((r == 3 && c == 2)) || ((r == 3 && c == 5)) || ((r == 3 && c == 1)) || ((c == 3) && (r <= 5 && r >= 1)) || (r == 5 && c == 2) || (r == 5 && c == 4) || (r == 2 && c == 2) || (r == 2 && c == 4))
				SetClr(col1);
			else if ((r == 5 && c == 5) || (r == 5 && c == 1))
				SetClr(col1);
			else
				SetClr(col2);
			cout << ch;
		}
	}
}
void Dqueen(int sr, int sc, int Len, int col1, int col2, char ch)
{
	for (int r = 0; Len > r; r++)
	{
		for (int c = 0; Len > c; c++)
		{
			gotoRowCol(sr + r, sc + c);
			if (((r == 2 && c - 1 == 4) || (r == 2 && c - 1 == 2) || (r == 3 && c - 1 == 4) || (r == 3 && c - 1 == 2)) || ((c - 1 == 3) && (r <= 5 && r > 1)) || (r == 5 && c - 1 == 2) || (r == 5 && c - 1 == 4) || (r == 6 && (c - 1 >= 1 && c - 1 < 6)))
				SetClr(col1);
			else if (c == 4 && r == 1)
				SetClr(col1);
			else
				SetClr(col2);
			cout << ch;
		}
	}
}
void Drook(int sr, int sc, int Len, int col1, int col2, char ch)
{
	for (int r = 0; Len > r; r++)
	{
		for (int c = 0; Len > c; c++)
		{
	
			//|| (r == 4) && (c-1 == 2) || ((r == 4) && (c-1 == 4)) ||((r == 2) && (c-1 == 2)) || ((r == 2) && (c-1 == 3)) || ((r == 2) && (c-1 == 4)) || ((r == 3) && (c-1 == 2)) || ((r == 3) && (c-1 == 3)) || ((r == 3) && (c -1== 4)) || ((r == 2) && (c-1 == 2)) || ((r == 5) && (c-1 == 3)) || ((r == 5) && (c-1 == 4)) || (r == 4 && c -1== 3))
			gotoRowCol(sr + r, sc + c);
			if ((r < 8 && r>3) && (c < 6 && c >= 3))
				SetClr(col1);
			else if ((r == 3 || r == 4 || r == 7) && (c == 2 || c == 6 || c == 4))
				SetClr(col1);
			else
				SetClr(col2);
			cout << ch;
		}
	}
}

void Dpawn(int sr, int sc, int Len, int col1, int col2, char ch)
{
	for (int r = 0; Len > r; r++)
	{
		for (int c = 0; Len > c; c++)
		{
			gotoRowCol(sr + r, sc + c);
			if (((r == 2) && (c == 4)) || ((r == 3) && (c == 3)) || ((r == 3) && (c == 4)) || ((r == 3) && (c == 5)) || ((r == 5) && (c == 3)) || ((r == 5) && (c == 4)) || ((r == 5) && (c == 5) || (r == 4 && c == 4)))
				SetClr(col1);
			else
				SetClr(col2);
			cout << ch;
		}
	}
}

void mouse_position69(Position& P, int len)
{
	getRowColbyLeftClick(P.ri, P.ci);
	P.ri = P.ri / len; P.ci = P.ci / len;
}

Position CalRiCi(sf::RenderWindow& window)
{
	{

		Position M = MouseClick(window);
		M.ri -= 27;
		M.ci -= 380;
		M.ri /= 70;
		M.ci /= 70;
		cout << " R C" << M.ri << " " << M.ci<<endl;
		return M;
	}
}

Position MouseClick(RenderWindow &window) {


	Position raw{-1,-1};
	Event event;
		while (window.waitEvent(event)) {
			switch (event.type) {
			case Event::Closed:
				window.close();
				exit(0);
				break;
			case Event::MouseButtonReleased:
				if (event.mouseButton.button == Mouse::Left) {
					raw.ri = event.mouseButton.y;
					raw.ci= event.mouseButton.x;
					return raw;
				}
				break;
			default:
				break;
			}
		}
	return raw;
}