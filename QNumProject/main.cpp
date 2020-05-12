#include "QInt.h"
#include "QFloat.h"
#include "Menu.h"
#include <Windows.h>
#include<conio.h>
void main()
{
	string temp;
	QInt a;
	temp = "ABC";
	a = a.HexToDec(temp);
	cout << a.PrintQInt();
	_getch();
}