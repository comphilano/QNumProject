﻿#pragma once
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
	//shift left, shift right, rotate left, rotate right
	QInt operator<<(int value);
	QInt operator>>(int value);
	QInt rol(int value);
	QInt ror(int value);
	//operator +, -
	QInt operator+(QInt a);
	QInt operator-(QInt a);

	//Chuan hoa chuoi
	int ChuanHoa(string& s);
	//Hàm xử lý
	int HalfString(string& a);
};

