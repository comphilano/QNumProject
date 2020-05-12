#include "QInt.h"
#include "QFloat.h"
#include "Menu.h"
#include <Windows.h>
#include<conio.h>
void main()
{
	Menu m;
	m.HomeScreen();
	cout << "Nhan Enter de ket thuc." << endl;
	//QInt a;
	//a.ScanQInt();
	//for (int i = 127; i >= 0; i--)
	//{
	//	cout << a.getBit(i);
	//	if (i % 32 == 0)
	//	{
	//		cout << "\n";
	//	}
	//}
	_getch();
}