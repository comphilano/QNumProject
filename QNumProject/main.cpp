#include "QInt.h"

#include<conio.h>
void main()
{
	QInt a;
	a.ScanQInt();
	QInt b;
	b.ScanQInt();
	cout<<a.PrintQInt();
	cout<<b.PrintQInt();
	_getch();
}