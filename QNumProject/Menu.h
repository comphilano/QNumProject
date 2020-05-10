#pragma once
#include<iostream>
#include<Windows.h>
using namespace std;
class Menu
{
private:

public:
	int MainMenu();
	int QIntMenu();


	//Hàm xử lý
	void gotoXY(int x, int y);
	void setColor(int x);
};

