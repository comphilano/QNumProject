#include "QInt.h"

#include<conio.h>
void main()
{
	QInt a;
	a.ScanQInt();
	for (int i = 127; i >= 0; i--)
	{
		cout << a.getBit(i);
		if ((i) % 32 == 0)
		{
			cout << endl;
		}
	}
	_getch();
}