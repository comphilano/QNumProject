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

	//Hàm nhập xuất
	void ScanQInt();
	void PrintQInt();
	//operator
	bool operator>(QInt a);
	bool operator<(QInt a);
	bool operator==(QInt a);
	bool operator>=(QInt a);
	bool operator<=(QInt a);
	void operator=(QInt a);
	//operator And, Or, Xor, Not
	QInt operator&(QInt a);
	QInt operator|(QInt a);
	QInt operator^(QInt a);
	QInt operator~();
	//Hàm xử lý
	int HalfString(string& a);


};

