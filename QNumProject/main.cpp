#include "QInt.h"

#include<conio.h>
void main()
{
	QInt a;
	a.ScanQInt();
	QInt b;
	b.ScanQInt();
	QInt c;
	try {
	  c = a / b;
	  cout << "a / b = " << c.PrintQInt();
	} catch (DividedByZero e) {
	  cout << "Loi chia cho 0";
	}
	_getch();
}