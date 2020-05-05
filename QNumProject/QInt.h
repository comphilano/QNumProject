#pragma once
#include<iostream>

using namespace std;
class QInt
{
private:
	int data[4];

public:
	QInt();
	QInt(int a);
	int getBit(int pos);
	void setBit(int value, int pos);

	 
	void ScanQInt();
	void PrintQInt();
	//Hàm xử lý
	int HalfString(string& a);


};

