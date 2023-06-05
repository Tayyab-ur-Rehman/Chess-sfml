#pragma once
#include"chess.h"
#include"utility.h"
#include<conio.h>
#include<string>

using namespace sf;

chess::chess()
{
	Turn = rand() % 2;
}
chess::chess(string name)
{
	Turn = rand() % 2;
	this->B = new Board(name);
}
void chess::print1()
{
	this->B->printBoard();
}
void  chess::TurnCH()
{
	this->Turn = (this->Turn + 1) % 2;
}
void  chess::TurnMsg(RenderWindow& window)
{
	int Total_rows = 770, Total_cols = 1360;

	String A = this->B->player[Turn].getname(); A += " Time = "; int a = this->B->player[Turn].Time; A += " "; String T = to_string(a); A += T;

	Font font; font.loadFromFile("letters.ttf");
	Text text; text.setFont(font); text.setCharacterSize(12); text.setFillColor(Color::Black); text.setString(A);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setPosition(1100.f, 420.f);
	window.draw(text); 
	
}
void chess:: WindowPrt(RenderWindow& window)
{
	window.clear(sf::Color::White);
	
	int Dim = 8;
	int Total_rows = 770, Total_cols = 1360;


	String A = this->B->player[Turn].getname(); A += " Time = "; int p = this->B->player[Turn].Time; A += " "; String T = to_string(p); A += T;

	Font font; font.loadFromFile("letters.ttf");
	

	Texture temp; temp.loadFromFile("B.png");
	Sprite a(temp);
	int increse_c = 380 + 16, increse_r = 27 + 10;

	Text text; text.setCharacterSize(10); text.setFont(font); text.setCharacterSize(12); text.setFillColor(Color::Black); text.setString(A);
	text.setStyle(sf::Text::Underlined);
	text.setPosition(1100.f, 400.f);
	window.draw(text);

	
	

	Texture temp67; temp67.loadFromFile("undu.png");
	Sprite undu(temp67);
	undu.setScale(.5, .5); undu.setPosition(30, Total_rows - 150); window.draw(undu);

	Texture temp675; temp675.loadFromFile("redu.png");
	Sprite redu(temp675);
	redu.setScale(.5, .5); redu.setPosition(Total_cols - 155, Total_rows - 140); window.draw(redu);


	a.setScale(2.5, 2.5); a.setPosition(Total_cols / 3 - 100, 0); window.draw(a);
	float mul_r = 70.3;
	float mul_c = 70.9;
	for (int ri = 0; Dim > ri; ri++)
	{
		for (int c = 0; Dim > c; c++)
		{


			char sym = this->B->pie[ri][c]->p;
			if (sym == 'p' || sym == 'P')
			{
				if (sym == 'p')
				{
					Texture pawn; pawn.loadFromFile("pawn.png");
					Sprite s(pawn);
					s.setScale(1, 1); s.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(s);
				}
				else if (sym == 'P')
				{
					Texture pawn1; pawn1.loadFromFile("pawn1.png");
					Sprite a(pawn1);
					a.setScale(1, 1); a.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(a);
				}

			}
			else if (sym == 'r' || sym == 'R')
			{
				if (sym == 'r')
				{
					Texture r; r.loadFromFile("rook.png");
					Sprite rook(r);
					rook.setScale(1, 1); rook.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook);
				}
				else if (sym == 'R')
				{
					Texture r; r.loadFromFile("rook1.png");
					Sprite rook1(r);
					rook1.setScale(1, 1); rook1.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook1);
				}
			}
			else if (sym == 'b' || sym == 'B')
			{
				if (sym == 'b')
				{
					Texture r; r.loadFromFile("bishop.png");
					Sprite rook(r);
					rook.setScale(1, 1); rook.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook);
				}
				else if (sym == 'B')
				{
					Texture r; r.loadFromFile("bishop1.png");
					Sprite rook(r);
					rook.setScale(1, 1); rook.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook);
				}
			}
			else if (sym == 'k' || sym == 'K')
			{
				if (sym == 'k')
				{
					Texture r; r.loadFromFile("king.png");
					Sprite rook(r);
					rook.setScale(1, 1); rook.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook);
				}
				else if (sym == 'K')
				{
					Texture r; r.loadFromFile("king1.png");
					Sprite rook(r);
					rook.setScale(1, 1); rook.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook);
				}
			}
			else if (sym == 'n' || sym == 'N')
			{
				if (sym == 'n')
				{
					Texture r; r.loadFromFile("Knight.png");
					Sprite rook(r);
					rook.setScale(1, 1); rook.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook);
				}
				else if (sym == 'N')
				{
					Texture r; r.loadFromFile("Knight1.png");
					Sprite rook(r);
					rook.setScale(1, 1); rook.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook);

				}
			}
			else if (sym == 'q' || sym == 'Q')
			{
				if (sym == 'q')
				{
					Texture r; r.loadFromFile("queen.png");

					Sprite rook(r);
					rook.setScale(1, 1); rook.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook);
				}
				else if (sym == 'Q')
				{
					Texture r; r.loadFromFile("queen1.png");

					Sprite rook(r);
					rook.setScale(1, 1); rook.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook);
				}
			}
		}
	}
}
void chess::WindowHigh(RenderWindow& window, bool**U)
{
	int Dim = 8;
	int Total_rows = 770, Total_cols = 1360;

	String A = this->B->player[Turn].getname(); A += " Time = "; int p = this->B->player[Turn].Time; A += " "; String T = to_string(p); A += T;

	Font font; font.loadFromFile("letters.ttf");
	Text text; text.setCharacterSize(10); text.setFont(font); text.setCharacterSize(12); text.setFillColor(Color::Black); text.setString(A);
	text.setStyle( sf::Text::Underlined);
	text.setPosition(1100.f, 400.f);
	window.draw(text);


	/////////////////////////////////////////////////////////
	Texture temp; temp.loadFromFile("B.png");
	Sprite a(temp);

	Texture temp67; temp67.loadFromFile("undu.png");
	Sprite undu(temp67);
	undu.setScale(.5, .5); undu.setPosition(30, Total_rows - 150); window.draw(undu);

	Texture temp675; temp675.loadFromFile("redu.png");
	Sprite redu(temp675);
	redu.setScale(.5, .5); redu.setPosition(Total_cols - 155, Total_rows - 140); window.draw(redu);



	int increse_c = 380 + 16, increse_r = 27 + 10;
	a.setScale(2.5, 2.5); a.setPosition(Total_cols / 3 - 100, 0); window.draw(a);
	Texture q; q.loadFromFile("black.png"); Sprite aa(q);  aa.setScale(0.9,0.9);
	float mul_r = 70.3;
	float mul_c = 70.9;
	for (int ri = 0; Dim > ri; ri++)
	{
		for (int c = 0; Dim > c; c++)
		{
			if (U[ri][c] == 1) {
				aa.setPosition(increse_c -12+ (c * 70.9), (ri * 70.3) -6+ increse_r);
				window.draw(aa);
			}
		}
	}
	for (int ri = 0; Dim > ri; ri++)
	{
		for (int c = 0; Dim > c; c++)
		{


			char sym = this->B->pie[ri][c]->p;
			if (sym == 'p' || sym == 'P')
			{
				if (sym == 'p')
				{
					Texture pawn; pawn.loadFromFile("pawn.png");
					Sprite s(pawn);
					s.setScale(1, 1); s.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(s);
				}
				else if (sym == 'P')
				{
					Texture pawn1; pawn1.loadFromFile("pawn1.png");
					Sprite a(pawn1);
					a.setScale(1, 1); a.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(a);
				}

			}
			else if (sym == 'r' || sym == 'R')
			{
				if (sym == 'r')
				{
					Texture r; r.loadFromFile("rook.png");
					Sprite rook(r);
					rook.setScale(1, 1); rook.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook);
				}
				else if (sym == 'R')
				{
					Texture r; r.loadFromFile("rook1.png");
					Sprite rook1(r);
					rook1.setScale(1, 1); rook1.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook1);
				}
			}
			else if (sym == 'b' || sym == 'B')
			{
				if (sym == 'b')
				{
					Texture r; r.loadFromFile("bishop.png");
					Sprite rook(r);
					rook.setScale(1, 1); rook.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook);
				}
				else if (sym == 'B')
				{
					Texture r; r.loadFromFile("bishop1.png");
					Sprite rook(r);
					rook.setScale(1, 1); rook.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook);
				}
			}
			else if (sym == 'k' || sym == 'K')
			{
				if (sym == 'k')
				{
					Texture r; r.loadFromFile("king.png");
					Sprite rook(r);
					rook.setScale(1, 1); rook.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook);
				}
				else if (sym == 'K')
				{
					Texture r; r.loadFromFile("king1.png");
					Sprite rook(r);
					rook.setScale(1, 1); rook.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook);
				}
			}
			else if (sym == 'n' || sym == 'N')
			{
				if (sym == 'n')
				{
					Texture r; r.loadFromFile("Knight.png");
					Sprite rook(r);
					rook.setScale(1, 1); rook.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook);
				}
				else if (sym == 'N')
				{
					Texture r; r.loadFromFile("Knight1.png");
					Sprite rook(r);
					rook.setScale(1, 1); rook.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook);

				}
			}
			else if (sym == 'q' || sym == 'Q')
			{
				if (sym == 'q')
				{
					Texture r; r.loadFromFile("queen.png");

					Sprite rook(r);
					rook.setScale(1, 1); rook.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook);
				}
				else if (sym == 'Q')
				{
					Texture r; r.loadFromFile("queen1.png");

					Sprite rook(r);
					rook.setScale(1, 1); rook.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook);
				}
			}
		}
	}
}
bool chess::Window(sf::RenderWindow& window)
{

	Texture temp; temp.loadFromFile("home1.png");
	Sprite s(temp);
	int Total_rows = 770, Total_cols = 1360;
	s.setScale(1.2,1.2); s.setPosition(100, 50); window.draw(s);
	Font font; font.loadFromFile("letters.ttf");




	Text text; text.setFont(font); text.setCharacterSize(12); text.setFillColor(Color::White); text.setString("PREVIOUS WORLD CUP");
	text.setStyle(sf::Text::Underlined);
	text.setPosition(350.f, 55.f);
	window.draw(text);

	Text text1; text1.setFont(font); text1.setCharacterSize(12); text1.setFillColor(Color:: Black); text1.setString("NEW WORLD CUP");
	text1.setStyle(sf::Text::Underlined);
	text1.setPosition(885.f, 55.f);
	window.draw(text1);

	window.display();
	Position A=CalRiCi(window);

	if (A.ci > 3)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void chess::checkMsG(int Turn, RenderWindow& window)
{
	int Dim = 8;
	int Total_rows = 770, Total_cols = 1360;


	String A = this->B->player[Turn].getname(); A += " Time = "; int p = this->B->player[Turn].Time; A += " "; String T = to_string(p); A += T;

	Font font; font.loadFromFile("letters.ttf");


	Texture temp; temp.loadFromFile("B.png");
	Sprite a(temp);
	int increse_c = 380 + 16, increse_r = 27 + 10;

	Text text; text.setCharacterSize(10); text.setFont(font); text.setCharacterSize(12); text.setFillColor(Color::Black); text.setString(A);
	text.setStyle(sf::Text::Underlined);
	text.setPosition(1300.f, 400.f);
	window.draw(text);




	Texture temp67; temp67.loadFromFile("undu.png");
	Sprite undu(temp67);
	undu.setScale(.5, .5); undu.setPosition(30, Total_rows - 150); window.draw(undu);

	Texture temp675; temp675.loadFromFile("redu.png");
	Sprite redu(temp675);
	redu.setScale(.5, .5); redu.setPosition(Total_cols - 155, Total_rows - 140); window.draw(redu);


	a.setScale(2.5, 2.5); a.setPosition(Total_cols / 3 - 100, 0); window.draw(a);
	float mul_r = 70.3;
	float mul_c = 70.9;
	for (int ri = 0; Dim > ri; ri++)
	{
		for (int c = 0; Dim > c; c++)
		{


			char sym = this->B->pie[ri][c]->p;
			if (sym == 'p' || sym == 'P')
			{
				if (sym == 'p')
				{
					Texture pawn; pawn.loadFromFile("pawn.png");
					Sprite s(pawn);
					s.setScale(1, 1); s.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(s);
				}
				else if (sym == 'P')
				{
					Texture pawn1; pawn1.loadFromFile("pawn1.png");
					Sprite a(pawn1);
					a.setScale(1, 1); a.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(a);
				}

			}
			else if (sym == 'r' || sym == 'R')
			{
				if (sym == 'r')
				{
					Texture r; r.loadFromFile("rook.png");
					Sprite rook(r);
					rook.setScale(1, 1); rook.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook);
				}
				else if (sym == 'R')
				{
					Texture r; r.loadFromFile("rook1.png");
					Sprite rook1(r);
					rook1.setScale(1, 1); rook1.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook1);
				}
			}
			else if (sym == 'b' || sym == 'B')
			{
				if (sym == 'b')
				{
					Texture r; r.loadFromFile("bishop.png");
					Sprite rook(r);
					rook.setScale(1, 1); rook.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook);
				}
				else if (sym == 'B')
				{
					Texture r; r.loadFromFile("bishop1.png");
					Sprite rook(r);
					rook.setScale(1, 1); rook.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook);
				}
			}
			else if (sym == 'k' || sym == 'K')
			{
				if (sym == 'k')
				{
					Texture r; r.loadFromFile("king.png");
					Sprite rook(r);
					rook.setScale(1, 1); rook.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook);
				}
				else if (sym == 'K')
				{
					Texture r; r.loadFromFile("king1.png");
					Sprite rook(r);
					rook.setScale(1, 1); rook.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook);
				}
			}
			else if (sym == 'n' || sym == 'N')
			{
				if (sym == 'n')
				{
					Texture r; r.loadFromFile("Knight.png");
					Sprite rook(r);
					rook.setScale(1, 1); rook.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook);
				}
				else if (sym == 'N')
				{
					Texture r; r.loadFromFile("Knight1.png");
					Sprite rook(r);
					rook.setScale(1, 1); rook.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook);

				}
			}
			else if (sym == 'q' || sym == 'Q')
			{
				if (sym == 'q')
				{
					Texture r; r.loadFromFile("queen.png");

					Sprite rook(r);
					rook.setScale(1, 1); rook.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook);
				}
				else if (sym == 'Q')
				{
					Texture r; r.loadFromFile("queen1.png");

					Sprite rook(r);
					rook.setScale(1, 1); rook.setPosition(increse_c + (c * mul_c), (ri * mul_r) + increse_r); window.draw(rook);
				}
			}
		}
	}


	string c; c += B->player[(Turn + 1) % 2].getname(); c += " in CHECK";
	Text text12; text12.setFont(font); text12.setCharacterSize(15); text12.setFillColor(Color::Black); text12.setString(c);
	text12.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text12.setPosition(1120.f, 300.f);
	window.draw(text12);
}
void chess::Play()
{
	static int Total_rows = 770, Total_cols = 1360;
	RenderWindow window(VideoMode(Total_cols, Total_rows), "                             CHESS                      "); window.clear(sf::Color::White);
	if (this->Window(window))
	{
		this->B = new Board("piece.txt");
	}
	else
	{
		this->B = new Board("pieces.txt");

	}
	window.clear(sf::Color::White);
	long long inti = time(0);
	Board RedO;
	bool canUndo = 0;
	bool canRedo = 0;
	bool** U; U = new bool* [8];
	Board Previous(*this->B);
	Position A, F; A.ri = 0; A.ci = 0; F.ri = 7; F.ci = 7;
	
	Music m,u,r,c,cm;
	this->B->Source_Pos.ri = 1;
	this->B->Source_Pos.ci = 1;
	this->WindowPrt(window); window.display();
	//window.clear(sf::Color::White);

	Event event;
	while (window.isOpen() )
	{
			while (window.waitEvent(event) &&!B->checkMate(Turn) )
			{
				{
					if (B->isCheck(Turn))
					{
						c.openFromFile("check.ogg"); c.play();
						checkMsG(Turn, window);
						 window.display();
				    }
					else if (B->Stalement(Turn))
					{
						B->drawMsg();
					}
				}
				this->B->player[Turn].Time += time(0) - inti;
				inti = time(0);
				if (this->B->player[Turn].Time >= 300)
				{
					system("cls");
					cout << this->B->player[(Turn + 1) % 2].getname() << " PLAYER WIN"; exit(1);
				}
				TurnCH();
				do {
					do
					{
						//TurnMsg(window);
						B->Source_Pos = CalRiCi(window);
						if ((B->Source_Pos.ri == 9|| B->Source_Pos.ri == 8) && (B->Source_Pos.ci == 11 || B->Source_Pos.ci == 12 || B->Source_Pos.ci == 13) && canRedo == 1)
						{
							r.openFromFile("sound.ogg");
							r.play();
							canUndo = 0;
							canRedo = 0;
							RedO.copyToNewBoard(*B);

							goto lable11;

							/////////////////////
							
						}
						if ((B->Source_Pos.ri == 9 || B->Source_Pos.ri == 8) && (B->Source_Pos.ci == -4 || B->Source_Pos.ci == -3) && canUndo == 1)
						{
							u.openFromFile("notify.ogg");
							u.play();
							B->copyToNewBoard(RedO);
							Previous.copyToNewBoard(*B);
							canUndo = 0;
							canRedo = 1;
							goto lable11;
						}
					} while (!(B->isBasicLegal(B->Source_Pos) && B->iSMY_PIECE(Turn, B->Source_Pos)));
					U = B->findHight(Turn);
					window.clear(sf::Color::White);
					this->WindowHigh(window, U); window.display();
					B->des_Pos= CalRiCi(window);
					window.clear(sf::Color::White);
					this->WindowPrt(window); window.display();
					//TurnMsg(window);

				} while (!U[B->des_Pos.ri][B->des_Pos.ci]);                                 //!(B->pie[Source_Pos.ri][Source_Pos.ci]->isLegal(Source_Pos, des_Pos) && B->isBasicLegal(des_Pos) && !B->iSMY_PIECE(Turn, des_Pos)));


				{
					B->copyToNewBoard(Previous);
					cout << Previous;
					if (this->capture(B->Source_Pos, B->des_Pos))
					{
						c.openFromFile("cap.ogg");
						c.play();
					}
					B->move(B->Source_Pos, B->des_Pos);
					
					///////////////////////////////////////////////////////////
					m.openFromFile("move.ogg");

					m.play();
					///////////////////////////////////////////////////////////
					canUndo = 1;
				lable11:
					{

					}
					window.clear(sf::Color::White);

					this->WindowPrt(window); window.display();
					B->LoadToFile("piece.txt");
				}
			
			}
			
			checkmate(window,Turn);
			_getche();
			window.close();
	}


}
chess::chess(int a)
{
	if (a==1)
		*this = chess("pieces.txt");
	else
		*this = chess("piece.txt");
		
}
//for (int i = 0; i < 8; i++) {
			//	U[i] = new bool[8];
			//	for (int j = 0; j < 8; j++)
			//	{
			//		des_Pos.ri = i;
			//		des_Pos.ci = j;
			//	  if (B->pie[Source_Pos.ri][Source_Pos.ci]->isLegal(Source_Pos, des_Pos) && B->isBasicLegal(des_Pos) && !B->iSMY_PIECE(Turn, des_Pos) )//&& !B->Selfcheck(Turn))
			//			U[i][j]=true;
			//		else
			//			U[i][j] = false;
			//	}
			//}
/*cout << endl;
cout << endl;
cout << endl;

for (int i = 0; i < 8; i++) {

	for (int j = 0; j < 8; j++)
	{
		cout << U[i][j];
	}
	cout<<endl;
}*/
void chess::checkmate(RenderWindow & window,int Turn )
{
	Music cm;
	cm.openFromFile("cm.ogg");
	cm.play();

	window.clear(sf::Color::White);
	String A = this->B->player[(Turn+1)%2].getname(); A+=" CHECK MATE   :) ;)";

	Font font; font.loadFromFile("letters.ttf");

	Text text; text.setCharacterSize(10); text.setFont(font); text.setCharacterSize(25); text.setFillColor(Color::Red); text.setString(A);
	text.setStyle(sf::Text::Underlined);
	text.setPosition(460.f, 19.f);
	window.draw(text);

	Texture temp; temp.loadFromFile("checkmate.png");
	Sprite a(temp);
	int Total_rows = 770, Total_cols = 1360;
	a.setScale(1,1); a.setPosition(580, 200); window.draw(a); window.display();
	for (int i = 0;i<100000000000000; i++)
	{
		i++;
	}
}
