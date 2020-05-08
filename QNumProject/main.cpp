#include "QInt.h"

#include<conio.h>
void main()
{
	QInt a;
	a.ScanQInt();
	QInt b;
	b.ScanQInt();
	if (a >= b)
	{
		cout << "true";
	}
	else cout << "false";
	_getch();
}