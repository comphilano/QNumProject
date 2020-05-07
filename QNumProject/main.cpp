#include "QInt.h"

#include<conio.h>
void main()
{
	QInt a;
	//a.ScanQInt();
	//for (int i = 127; i >= 0; i--)
	//{
	//	cout << a.getBit(i);
	//	if ((i) % 32 == 0)
	//	{
	//		cout << endl;
	//	}
	//}
	string x;
	cin >> x;
	string y;
	cin >> y;
	string z;
	z = a.SumString(x, y);
	cout << z;
	_getch();
}