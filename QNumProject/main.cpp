#include "QInt.h"
#include "QFloat.h"
#include<conio.h>
void main()
{
	QFloat a;
	a.ScanQFloat();
	for (int i = 127; i >= 0; i--)
	{
		cout << a.getBit(i);
		if (i % 32 == 0)
		{
			cout << endl;
		}
	}

}