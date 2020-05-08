#include "QInt.h"

#include<conio.h>
void main()
{
	while (true)
	{
		system("cls");
		QInt a;
		QInt b;
		a.ScanQInt();
		b.ScanQInt();
		QInt c;
		c = a * b;
		cout << c.PrintQInt();
		_getch();
	}
	_getch();
}