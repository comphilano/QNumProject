#pragma once
#include<iostream>
#include "QInt.h"
using namespace std;

class QFloat
{
private:
	int data[4];
public:
	QFloat();
	int getBit(int pos);
	void setBit(int value, int pos);
	void ScanQFloat();
	string PrintQFloat(QFloat x);


	//Hàm xử lý
	void ChiaChuoi(string a, string& nguyen, string& thuc);
	//Hàm trả về số dạng chuỗi được nhân 2
	string DoubleString(string a);
	string SumString(string a, string b);
	//Hàm trả về số dạng chuỗi được nhân 2
	
	//Hàm chuẩn hóa chuỗi
	int ChuanHoaChuoi(string& s);
};


