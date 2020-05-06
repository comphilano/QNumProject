#include "QInt.h"
#include<conio.h>

void main()
{
	QInt a;
	a.ScanQInt();
	QInt b;
	b.ScanQInt();
	QInt c;
	c = ~a;
	QInt d;
	d = ~b;
	QInt e;
	e = a + b;
	cout << "\nKet qua phep cong:\n";
	for (int i = 127; i >= 0; i--)
	{
		cout << e.getBit(i);
		if ((i) % 32 == 0)
		{
			cout << endl;
		}
	}
	QInt f;
	f = a - b;
	cout << "\nKet qua phep tru:\n";
	for (int i = 127; i >= 0; i--)
	{
		cout << f.getBit(i);
		if ((i) % 32 == 0)
		{
			cout << endl;
		}
	}
	_getch();
}