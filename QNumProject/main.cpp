#include "QInt.h"
#include "QFloat.h"
#include "Menu.h"
#include <Windows.h>
#include<conio.h>
void main()
{
	bool* bit = new bool;
	QInt a;
	bit[0] = true;
	bit[1] = false;
	bit[2] = false;
	bit[3] = true;
	a.ScanQInt();
	cout << a.BinToHex(bit);
	_getch();
}