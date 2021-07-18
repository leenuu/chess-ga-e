#pragma once
int map[8][8];
std::string chess_piece_whilte[13] = {"", "▽", "♤", "○", "◇", "♡", "☆", "▲", "♠", "●", "◆", "♥", "★" };


void re_map();
void set_piece();

void step_up()
{
	re_map();
	set_piece();
}

void cursorview(bool show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void scolor(unsigned short text = 15, unsigned short back = 0)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}

void gotoxy(int x, int y)
{

	COORD cur;
	cur.X = x;
	cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}

void re_map()
{
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			map[y][x] = 0;
		}
	}
}

void set_piece()
{
	for (int xl = 0; xl < 5; xl++)
	{	
		int x = xl + 2;
		map[0][xl] = x;
		map[7][xl] = x + 6;
		map[0][7 - xl] = x;
		map[7][7 - xl] = x + 6;
	}
	
	for (int x = 0; x < 8; x++)
	{
		map[1][x] = 1;
		map[6][x] = 7;
	}
}

void print_map()
{
	std::cout << "    1    2    3    4    5    6    7    8";
	
	for (int yl = 1; yl < 17; yl +=2)
	{
		int y = (yl - 1) / 2;
		gotoxy(3, yl);
		std::cout << " ---- ---- ---- ---- ---- ---- ---- ---- ";
		gotoxy(1, yl + 1);
		std::cout << y+1;
		gotoxy(3, yl + 1);
		std::cout << "| ";
		
		for (int x = 0; x < 8; x++)
		{	
			if (map[y][x] == 0)
			{
				int i = x + y;

				if (i % 2 == 0)
				{
					std::cout << "□";
				}
				else
				{
					std::cout << "■";
				}
			}
			else if(map[y][x] == 1)
			{
				std::cout << "▽";
			}
			else if (map[y][x] == 2)
			{
				std::cout << "♤";
			}
			else if (map[y][x] == 3)
			{
				std::cout << "○";
			}
			else if (map[y][x] == 4)
			{
				std::cout << "◇";
			}
			else if (map[y][x] == 5)
			{
				std::cout << "♡";
			}
			else if (map[y][x] == 6)
			{
				std::cout << "☆";
			}
			else if (map[y][x] == 7)
			{
				std::cout << "▲";
			}
			else if (map[y][x] == 8)
			{
				std::cout << "♠";
			}
			else if (map[y][x] == 9)
			{
				std::cout << "●";
			}
			else if (map[y][x] == 10)
			{
				std::cout << "◆";
			}
			else if (map[y][x] == 11)
			{
				std::cout << "♥";
			}
			else if (map[y][x] == 12)
			{
				std::cout << "★";
			}

			std::cout << " | ";
		}
	}
	gotoxy(3, 17);
	std::cout << " ---- ---- ---- ---- ---- ---- ---- ---- ";
}

void test()
{

}
