#include "QInt.h"

#include<conio.h>
void main()
{
	QInt a;
	a.ScanQInt();
	QInt b;
	b.ScanQInt();
	QInt c;
	c = a % b;
	cout << c.PrintQInt();
	_getch();
}