#pragma once
#include<iostream>

class Error{};
class DividedByZero : public Error{};
using namespace std;
class QInt
{
private:
	int data[4];

public:
	QInt();
	QInt(int a);
	QInt(string a);
	int getBit(int pos);
	void setBit(int value, int pos);

	//Hàm nhập xuất
	void ScanQInt();
	string PrintQInt();
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
	//operator /, %
	QInt operator/(QInt);
	QInt operator%(QInt);
	//Chuan hoa chuoi
	int ChuanHoa(string& s);
	//Hàm xử lý
	int HalfString(string& a);
	string SumString(string a, string b);
	//Hàm trả về số dạng chuỗi được nhân 2
	string DoubleString(string a);
	//hàm trả về số dạng chuỗi lũy thừa 2^n
	string ExpString(string a, int n);
	QInt operator*(QInt a);
	//Cộng số QInt vào chuỗi
	void plusInMulti(char*& a);
	//Dịch phải chuỗi
	void shrInMulti(char*& a);
	//Đảo bit trong chuỗi
	void transBit(char*& a);
	//Hàm chuyển hệ 10 sang hệ 2
	bool* DecToBin(QInt x);
	//Hàm chuyển hệ 2 sang hệ 10
	QInt BinToDeC(bool* a);
	//Hàm chuyển hệ 2 sang hệ 16
	string BinToHex(bool* bit);
	//Ham chuyen he 10 sang he 16
	string DecToHex(QInt a);
	//Hàm chia nhỏ
	string Split(QInt a,int i);
	//Hàm chuyển string đến bool
	bool* StringToBool(string a);
	//Hàm chuyển bool đến string
	string BoolToString(bool* a);
	//Hàm chia 16
	char DevHex(string& a);
	//Hàm chuyển từ hệ 16 sang hệ 10
	QInt HexToDec(string a);
};

