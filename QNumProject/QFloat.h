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
	QFloat(string a);
	int getBit(int pos);
	void setBit(int value, int pos);
	void ScanQFloat();


	//Hàm xử lý
	void ChiaChuoi(string a, string& nguyen, string& thuc);
	//Hàm trả về số dạng chuỗi được nhân 2
	string DoubleString(string a);
	string SumString(string a, string b);
	//Hàm trả về số dạng chuỗi được nhân 2
	
	//Hàm chuẩn hóa chuỗi
	int ChuanHoaChuoi(string& s);
	//Hàm chuyển đổi hệ 2 sang hệ 10
	QFloat BinToDec(bool* bit);
	//Hàm chuyển bool đến string
	string BoolToString(bool* a);
	//Hàm chuyển đổi hệ 10 sang hệ 2
	bool* DecToBin(QFloat a);

	//LV
	string PrintQFloat();
	string ExpString(string a, int n);

	// Hàm x mũ n
	int PowInt(int x, int n);
	// Hàm tính phần thực
	string DivDecimal(int n);
	// Hàm tính tổng của 2 phần thực
	string SumDecimal(string a, string b);

	int ZeroNumber(string sign, string exp);
	int Denormalized(string sign, string exp);
	int Infinity(string sign, string exp);
	int NotANumber(string sign, string exp);

	string PrintBin(QFloat a);
	void DaoChuoi(string& a);

	//Hàm làm tròn số
	string LamTron();
};


