#pragma once
#include<iostream>
#include<Windows.h>
#include"QInt.h"
#include"QFloat.h"
using namespace std;
class Menu
{
private:

public:
	int MainMenu();
	//Menu Qint
	int QIntMenu();
	void ChuyenDoiQInt();
	void TinhToanQInt();
	void DichDoiQInt();
	//Menu QFloat
	int QFloatMenu();
	void ChuyenDoiQFloat();
	//Hàm xử lý
	void gotoXY(int x, int y);
	void setColor(int x);
	//Hàm xuất màn hình chính
	void HomeScreen();
};

