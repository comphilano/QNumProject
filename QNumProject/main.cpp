#include "QInt.h"

#include<conio.h>
void main()
{
	QInt a;
	a.ScanQInt();
	QInt b;
	b.ScanQInt();
	QInt c;
	c = a - b;
	for (int i = 127; i >= 0; i--)
	{
		cout << c.getBit(i);
		if ((i) % 32 == 0)
		{
			cout << endl;
		}
	}
	_getch();
}