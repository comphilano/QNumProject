#include "QInt.h"

#include<conio.h>
void main()
{
	QInt a;
	bool* bit = new bool;
	char* b = new char;
	a.ScanQInt();
	cout << a.BinToHex(bit);
	_getch();
}