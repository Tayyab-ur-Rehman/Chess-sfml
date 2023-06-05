#include"board.h"
#include<conio.h>
#include"utility.h"


Board::Board()
{
	rows = 0;
	cols = 0;
	pie = nullptr;
	dim = 0;
	player[0] = Player();
	player[1] = Player();
	Source_Pos.ci = 0;
	Source_Pos.ri = 0;
	des_Pos.ri = 0;
	des_Pos.ci = 0;
}
Board::Board (string name)
{
	player[0].p1("Tayyab", 0);
	player[1].p1("Dushman", 15);
	rows = 160;
	cols = 250;
	dim = 8;
	char** A = Load(name);
	
	pie = new piece * *[dim];
	for (int i = 0; i < dim; i++)
	{
		pie[i] = new piece * [dim];
		for (int c = 0; c < dim; c++)
		{
			if (A[i][c] == 'p') {

				pie[i][c] = new Pawn(0, this);
				//pie[i][c]->print_Piece();
			}
			else if (A[i][c] == 'P')
				pie[i][c] = new Pawn(15, this);

			else if (A[i][c] == 'k')
				pie[i][c] = new king(0, this);
			else if (A[i][c] == 'K')
				pie[i][c] = new king(15, this);

			else if (A[i][c] == 'b')
				pie[i][c] = new bishop(0, this);
			else if (A[i][c] == 'B')
				pie[i][c] = new bishop(15, this);

			else if (A[i][c] == 'q')
				pie[i][c] = new queen(0,this);
			else if (A[i][c] == 'Q')
				pie[i][c] = new queen(15,this);

			else if (A[i][c] == 'r')
				pie[i][c] = new rook(0,this);
			else if (A[i][c] == 'R')
				pie[i][c] = new rook(15,this);

			else if (A[i][c] == 'n')
				pie[i][c] = new knight(0,this);
			else if (A[i][c] == 'N')
				pie[i][c] = new knight(15, this);
			else
				pie[i][c] = new em();

		}
	}
}
Board::Board(const Board& A)
{
	dim = 8;
	pie = new piece**[8];
	for (int i = 0; i < dim; i++)
	{
		pie[i] = new piece * [dim];
		for (int c = 0; c < dim; c++)
		{
			switch (A.pie[i][c]->p)
			{
			case'p':
				pie[i][c] = new Pawn(0, this);
				break;
			case 'P':
				pie[i][c] = new Pawn(15, this);
				break;

			case'k':
				pie[i][c] = new king(0, this);
				break;

			case'K':
				pie[i][c] = new king(15, this);
				break;


			case'b':
				pie[i][c] = new bishop(0, this);
				break;

			case'B':
				pie[i][c] = new bishop(15, this);
				break;

			case'q':
				pie[i][c] = new queen(0, this);
				break;

			case'Q':
				pie[i][c] = new queen(15, this);
				break;


			case'r':
				pie[i][c] = new rook(0, this);
				break;

			case'R':
				pie[i][c] = new rook(15, this);
				break;


			case'n':
				pie[i][c] = new knight(0, this);
				break;

			case'N':
				pie[i][c] = new knight(15, this);
				break;

			default:
				pie[i][c] = new em();
			}
		}
	}
	player[0].p1("Tayyab", 0);
	player[1].p1("Dushman", 15);
}
void Board::init()
{
	rows = 160;
	cols = 250;
	dim = 8;
	pie = new piece * *[dim];
	for (int i = 0; i < dim; i++)
	{
		pie[i] = new piece * [dim];
		for (int c = 0; c < dim; c++)
		{
			pie[i][c] = new Pawn(0, this);
		}
	}
}
void Board:: PBoard2_R()
{
	int Dim = 8;
	int colour, col1 = 0, col2 = 4, col_p1 = 8, col_p2 = 9;
	for (int r = 0; Dim > r; r++)
	{
		for (int c = 0; Dim > c; c++)
		{
			char sym = this->pie[r][c]->p;
			if ((r + c) % 2 == 0)
				colour = 15;
			else
				colour = 7;
			if (sym == 'p' || sym == 'P')
			{
				if (sym == 'p')
					Dpawn(r * 9, c * 9, 9, col1, colour, -37);
				else if (sym == 'P')
					Dpawn(r * 9, c * 9, 9, col2, colour, -37);
			}
			else if (sym == 'r' || sym == 'R')
			{
				if (sym == 'r')
					Drook(r * 9, c * 9, 9, col1, colour, -37);
				else if (sym == 'R')
					Drook(r * 9, c * 9, 9, col2, colour, -37);
			}
			else if (sym == 'b' || sym == 'B')
			{
				if (sym == 'b')
					Dbishop(r * 9, c * 9, 9, col1, colour, -37);
				else if (sym == 'B')
					Dbishop(r * 9, c * 9, 9, col2, colour, -37);
			}
			else if (sym == 'k' || sym == 'K')
			{
				if (sym == 'k')
					Dking(r * 9, c * 9, 9, col1, colour, -37);
				else if (sym == 'K')
					Dking(r * 9, c * 9, 9, col2, colour, -37);
			}
		
			else if (sym == 'n' || sym == 'N')
			{
				if (sym == 'n')
					Dnight(r * 9, c * 9, 9, col1, colour, -37);
				else if (sym == 'N')
					Dnight(r * 9, c * 9, 9, col2, colour, -37);
			}
			else if(sym=='q'||sym=='Q')
			{
				if (sym == 'q')
					Dqueen(r * 9, c * 9, 9, col1, colour, -37);
				else if (sym == 'Q')
					Dqueen(r * 9, c * 9, 9, col2, colour, -37);
			}
			//////////////////////////////////////////////
			
			
			
			else
			{
				Box2(r * 9, c * 9, 9, 9, colour, -37);
			}
		}
		cout << endl;
	}

	Box(5 * 9, 12 * 9, 9, 9, 2, 'U');
	Box(5 * 9, 14 * 9, 9, 9, 14, 'R');
}
void Board::Hilighter(bool** Hilght)
{
	
		int Dim = 8;
		for (int r = 0; Dim > r; r++)
		{
			for (int c = 0; Dim > c; c++)
			{
				if (Hilght[r][c] == 1)
					BoxH(r * 9, c * 9, 9, 9, 9);
			}
		}
}
void Board::UHilighter(bool** Hilight)
{
	
		int Dim = 8;
		for (int r = 0; Dim > r; r++)
		{
			for (int c = 0; Dim > c; c++)
			{
				if (Hilight[r][c] == 1)
				{
					if ((r + c) % 2 == 0)
						BoxH(r * 9, c * 9, 9, 9, 15);
					else
						BoxH(r * 9, c * 9, 9, 9, 7);
				}
			}
		}

}
void Board::copyToNewBoard(Board &N)
{
	N.pie = new piece **[8];
	for (int i = 0; i < 8; i++)
	  N.pie[i] = new piece * [8];

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			//piece tmp = *(this->pie[i][j]);
			N.pie[i][j] = this->pie[i][j];
			/*N.pie[i][j]->p = this->pie[i][j]->p;
			N.pie[i][j]->isSmall = this->pie[i][j]->isSmall;
			N.pie[i][j]->b = this->pie[i][j]->b;*/
		}
	}
}
Position Board::FindKing(int Turn)
{
	Position A;
	char ch;
	if (Turn == 0)
		ch = 'k';
	else
		ch = 'K';
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{

			if (this->pie[i][j]->p == ch)
			{
				 A.ri = i; A.ci = j;
			}
		}
	}
	return A;

}
void Board::printBoard()
{
	dim = 8;
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			pie[i][j]->print_Piece();
		}
		cout << endl;
	}
}
void Board::drawMsg()
{
	cout << "Draw"; _getche(); exit(1);
}
void Board::checkMateMsg(int Turn)
{
	cout << this->player[(Turn + 1) % 2].getname() << " CHECKMATEFD   NOOB   :^)";
}
void Board::printHighBoard(bool** H)
{
	dim = 8;
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (H[i][j] == 1)
				SetClr(1);
		else
				SetClr(15);

			pie[i][j]->print_Piece();
		}
		cout << endl;
	}
	SetClr(15);

}
void Board::SeletSource(Position source_Pos)
{
	cin >> source_Pos.ri >> source_Pos.ci;
}
void Board::SeletDes(Position source_Pos)
{
	cin >> source_Pos.ri >> source_Pos.ci;

}
bool Board::isBasicLegal(Position s)
{
	if (s.ri < 8 && s.ri >= 0 && s.ci < 8 && s.ci >= 0)
		return 1;
	return 0;
}
void Board::move(Position Source_Pos, Position des_Pos)
{
	this->pie[Source_Pos.ri][Source_Pos.ci]->move(Source_Pos,des_Pos);
	if (pie[des_Pos.ri][des_Pos.ci]->p == 'p' || pie[des_Pos.ri][des_Pos.ci]->p == 'P')
	{
		if (pie[des_Pos.ri][des_Pos.ci]->isSmall && des_Pos.ri == 6)
		{
			pie[des_Pos.ri][des_Pos.ci] = new queen(0, this);
		}
		else if (!pie[des_Pos.ri][des_Pos.ci]->isSmall && des_Pos.ri == 1)
		{
			pie[des_Pos.ri][des_Pos.ci] = new queen(15, this);

		}
	}
}
bool Board::iSMY_PIECE(int Turn1, Position S)
{
	return this->pie[S.ri][S.ci]->IsmyPiece(Turn1);
}
void Board::LoadToFile(string A)
{
	ofstream wrt(A);
	wrt << *this;
}
bool Board::isCheck(int Turn)
{
	int Dim = 8;
	int T = (Turn + 1) % 2;
	this->des_Pos = this->FindKing(T);
	for (int i = 0; Dim > i; i++)
	{
		for (int j = 0; Dim > j; j++)
		{
			this->Source_Pos.ri = i;  this->Source_Pos.ci = j;
			if (iSMY_PIECE(Turn, this->Source_Pos))
			{
				if(pie[this->Source_Pos.ri][this->Source_Pos.ci]->isLegal(this->Source_Pos, this->des_Pos,Turn))
				    return true;
			}
		}
	}
	return false;
}
void Board::CheckMsg(int Turn)
{
	cout << this->player[(Turn+1)%2].getname()<<" is in CHECK";
}
bool Board::Selfcheck(int Turn)
{
	int T = (Turn + 1) % 2;
	return isCheck(T);
    
}
bool Board::Stalement(int Turn)
{
	int T = (Turn + 1) % 2;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			this->Source_Pos.ri = i;
			this->Source_Pos.ci = j;
			if (this->iSMY_PIECE(T, this->Source_Pos)) {
				bool** U = this->findHight(T);
				
				for (int a = 0; a < 8; a++)
				{
					for (int b = 0; b < 8; b++)
					{
						//cout << U[a][b];
						if (U[a][b])
							return false;
					}
				}
			}
		}
	}
	return true;
}
bool Board::checkMate(int Turn)
{
	if (this->isCheck(Turn))
	{
		if (Stalement(Turn))
		{
			return 1;
		}
	}
	return 0;
}
bool Board::Castling(Position S,Position D,int Turn)
{
	if (S.ri == D.ri && S.ci == D.ci)
		return 0;
	if (this->pie[S.ri][S.ci]->isSmall == this->pie[D.ri][D.ci]->isSmall) {

		if (this->pie[S.ri][S.ci]->isSmall &&(S.ri == 0 && S.ci == 4) && pie[D.ri][D.ci]->p == 'r' && ((D.ri == 0 && D.ci == 0) || (D.ri == 0 && D.ci == 7)))
		{
			return (hori_move(S,D) && clearH(*this, S, D));
		}
		else if ((S.ri == 7 && S.ci == 4) && pie[D.ri][D.ci]->p == 'R' && ((D.ri == 7 && D.ci == 0) || (D.ri == 7 && D.ci == 7)))
		{
			return (hori_move(S,D)&&  clearH(*this, S, D));
		}
	}
	return false;
	
}
ostream& operator<<(ostream& co, const Board& A)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++) {
			co << A.pie[i][j]->p << " ";
		}
		co << endl;

}
	return co;
}
bool** Board::findHight(int Turn)
{
	Board N;
	bool** U; U = new bool* [8];
	for (int i = 0; i < 8; i++) {
		U[i] = new bool[8];
		for (int j = 0; j < 8; j++)
		{
			des_Pos.ri = i;
			des_Pos.ci = j;
			if ((!this->iSMY_PIECE(Turn, des_Pos) || Castling(this->Source_Pos, this->des_Pos, Turn)) && this->isBasicLegal(des_Pos) && this->pie[Source_Pos.ri][Source_Pos.ci]->isLegal(Source_Pos, des_Pos, Turn) )//&& !B->Selfcheck(Turn))
			{
				if(this->pie[Source_Pos.ri][Source_Pos.ci]->isSmall!= this->pie[i][j]->isSmall|| this->pie[i][j]->p=='-'|| Castling(this->Source_Pos, this->des_Pos, Turn))
				{
					Board N(*this);
					N.move(Source_Pos, des_Pos);
					if (N.Selfcheck(Turn))
						U[i][j] = false;
					else
						U[i][j] = true;
				}
			}
			else
				U[i][j] = false;
		}
	}
	return U;
}
void Board::undo( Board A)
{
	A.copyToNewBoard(*this);
}
void Board::Update_only(Position S, Position D)
{
	int Dim = 8;
	int colour, col1 = 0, col2 = 4, col_p1 = 8, col_p2 = 9;
	for (int r = 0; Dim > r; r++)
	{
		for (int c = 0; Dim > c; c++)
		{
			if((S.ri==r&&S.ci==c) ||(D.ri == r && D.ci == c))
			{
				char sym = this->pie[r][c]->p;
				if ((r + c) % 2 == 0)
					colour = 15;
				else
					colour = 7;
				if (sym == 'p' || sym == 'P')
				{
					if (sym == 'p')
						Dpawn(r * 9, c * 9, 9, col1, colour, -37);
					else if (sym == 'P')
						Dpawn(r * 9, c * 9, 9, col2, colour, -37);
				}
				else if (sym == 'r' || sym == 'R')
				{
					if (sym == 'r')
						Drook(r * 9, c * 9, 9, col1, colour, -37);
					else if (sym == 'R')
						Drook(r * 9, c * 9, 9, col2, colour, -37);
				}
				else if (sym == 'b' || sym == 'B')
				{
					if (sym == 'b')
						Dbishop(r * 9, c * 9, 9, col1, colour, -37);
					else if (sym == 'B')
						Dbishop(r * 9, c * 9, 9, col2, colour, -37);
				}
				else if (sym == 'k' || sym == 'K')
				{
					if (sym == 'k')
						Dking(r * 9, c * 9, 9, col1, colour, -37);
					else if (sym == 'K')
						Dking(r * 9, c * 9, 9, col2, colour, -37);
				}

				else if (sym == 'n' || sym == 'N')
				{
					if (sym == 'n')
						Dnight(r * 9, c * 9, 9, col1, colour, -37);
					else if (sym == 'N')
						Dnight(r * 9, c * 9, 9, col2, colour, -37);
				}
				else if (sym == 'q' || sym == 'Q')
				{
					if (sym == 'q')
						Dqueen(r * 9, c * 9, 9, col1, colour, -37);
					else if (sym == 'Q')
						Dqueen(r * 9, c * 9, 9, col2, colour, -37);
				}
				else
				{
					Box2(r * 9, c * 9, 9, 9, colour, -37);
				}
			}
		}
		cout << endl;
	}
}
void Board::mouse_position(Position& P,int len)
{

	getRowColbyLeftClick(P.ri, P.ci);
	P.ri = P.ri / len; P.ci = P.ci / len;
}
Board::~Board()
{
	//cout << "Abat Destr           do nothing else print";
}
















































//ifstream& operator<<(ifstream& wr, const Board& a)
//{
//	wr << a;
//	return wr;
//}
//}
//legalities
//bool Board::LegalMove(Board B, Position S, Position D)
//{
//	switch (B.pie[S.ri][S.ci]->p)
//	{
//	case'R':
//	case 'r':
//	{
//		if (vert_move(S, D) && clearV(B, S, D) || hori_move(S, D) && clearH(B, S, D))
//			return true;
//		return false;
//	}
//	case 'b':
//	case 'B':
//	{
//		if (isDig_mov(S, D))
//			if (choice_RL(S, D))
//			{
//				if (clearDiLR(B, S, D))
//				{
//					return 1;
//				}
//			}
//			else if (clearDiRL(B, S, D))
//				return true;
//		return 0;
//	}
//
//	case'n':
//	case'N':
//	{
//		if (abs(S.ri - D.ri) == 1 && abs(S.ci - D.ci) == 2)
//			return 1;
//		if (abs(S.ri - D.ri) == 2 && abs(S.ci - D.ci) == 1)
//			return 1;
//		return 0;
//	}
//	case'k':
//	case'K':
//	{
//		if (abs(S.ri - D.ri) == 1 || abs(S.ci - D.ci) == 1)
//			return 1;
//	}
//	case 'p':
//	{
//		if (down(S, D))
//			return 1;
//		return 0;
//	}
//	case 'P':
//	{
//
//		if (up(S, D))
//			return 1;
//		return 0;
//	}
//	case 'Q':
//	case 'q':
//	{
//
//		if (vert_move(S, D) && clearV(B, S, D) || hori_move(S, D) && clearH(B, S, D))
//			return true;
//		if (isDig_mov(S, D))
//			if (choice_RL(S, D))
//			{
//				if (clearDiLR(B, S, D))
//				{
//					return 1;
//				}
//			}
//			else if (clearDiRL(B, S, D))
//				return true;
//		return false;
//
//	}
//	}
//}


