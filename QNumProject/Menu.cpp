#include "Menu.h"
#include <conio.h>

int Menu::MainMenu()
{
	int chon = 0;
	while (true)
	{
		if (chon == 0)
		{
			system("cls");
			cout << "LUA CHON CHUC NANG" << endl <<endl;
			setColor(31);
			cout << "So nguyen lon (QInt)." << endl <<endl;
			setColor(15);
			cout << "So cham dong chinh xac cao (QFloat)." <<endl<<endl;
			cout << "Thoat.";
		}
		else if (chon == 1)
		{
			system("cls");
			cout << "LUA CHON CHUC NANG" << endl <<endl;
			cout << "So nguyen lon (QInt)." << endl <<endl;
			setColor(31);
			cout << "So cham dong chinh xac cao (QFloat)." <<endl<<endl;
			setColor(15);
			cout << "Thoat.";
		}
		else if (chon == 2)
		{
			system("cls");
			cout << "LUA CHON CHUC NANG" << endl <<endl;
			cout << "So nguyen lon (QInt)." << endl << endl;
			cout << "So cham dong chinh xac cao (QFloat)." << endl << endl;
			setColor(31);
			cout << "Thoat.";
			setColor(15);
		}
		char c = _getch();
		if (c == 13)
		{
			break;
		}
		else if (c == 72)
		{
			chon--;
		}
		else if (c == 80)
		{
			chon++;
		}
		if (chon == 3)
		{
			chon = 0;
		}
		else if (chon == -1)
		{
			chon = 2;
		}
	}
	return chon;
}

int Menu::QIntMenu()
{
	return 0;
}




//Hàm xử lý
void Menu::gotoXY(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

void Menu::setColor(int x)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}