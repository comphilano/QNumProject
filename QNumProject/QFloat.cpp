#include "QFloat.h"

int QFloat::getBit(int pos)
{
	int a = pos / 32; //xác định bit nằm trong phần tử nào của mảng QInt
	int b = pos % 32; //xác định bit nằm ở trị trí thứ mấy trong phần tử vừa tìm 
	return (data[a] >> (31 - b)) & 1;
}

void QFloat::setBit(int value, int pos)
{
	int a = pos / 32; //xác định bit nằm trong phần tử nào của mảng QInt
	int b = pos % 32; //xác định bit nằm ở trị trí thứ mấy trong phần tử vừa tìm 
	if (value == 0) //Trường hợp set bit 0
	{
		data[a] = ~(1 << (31 - b)) & data[a];
	}
	else //Trường hợ set bit 1
	{
		data[a] = (1 << (31 - b)) | data[a];
	}

}

QFloat::QFloat()
{
	//Khởi tạo bằng 0
	for (int i = 0; i < 128; i++)
	{
		setBit(0, i);
	}
}

void QFloat::ChiaChuoi(string a, string& nguyen, string& thuc)
{
	nguyen = "";
	thuc = "";
	int i;
	for (i = 0; i < a.length(); i++)
	{
		if (a[i] != '.')
		{
			nguyen.push_back(a[i]);
		}
		else
		{
			break;
		}
	}
	for (i; i < a.length(); i++)
	{
		thuc.push_back(a[i]);
	}
	thuc[0] = '0';
}

//Hàm cộng 2 số nguyên dạng string

string QFloat::SumString(string a, string b)
{
	string ans;
	if (a.length() > b.length())
	{
		int x = a.length() - b.length();
		string temp;
		for (int i = 0; i < x; i++)
		{
			temp.push_back('0');
		}
		temp += b;
		b = temp;
	}
	else if (a.length() < b.length())
	{
		int x = b.length() - a.length();
		string temp;
		for (int i = 0; i < x; i++)
		{
			temp.push_back('0');
		}
		temp += a;
		a = temp;
	}
	int nho = 0;
	for (int i = a.length() - 1; i >= 0; i--)
	{
		int sum = (a[i] - 48) + (b[i] - 48) + nho;
		if (sum < 10)
		{
			ans.insert(ans.begin(), sum + 48);
			nho = 0;
		}
		else
		{
			ans.insert(ans.begin(), sum + 48 - 10);
			nho = 1;
		}
	}
	if (nho == 1)
	{
		ans.insert(ans.begin(), '1');
	}
	return ans;
}

string QFloat::DoubleString(string a)
{
	string ans;
	ans = SumString(a, a);
	return ans;
}

void QFloat::ScanQFloat()
{
	int am = 0;
	string x;
	cout << "Nhap so: ";
	cin >> x;
	string nguyen;
	string thuc;
	ChiaChuoi(x, nguyen, thuc);
	if (nguyen[0] == '-')
	{
		am = 1;
		nguyen.erase(nguyen.begin());
	}
	QInt a(nguyen);
	int i = 127;
	while (a.getBit(i) == 0)
	{
		i--;
	}
	int tam = i;
	i--;
	int j = 127 - 16;
	for (i; i >= 0; i--)
	{
		int bit = a.getBit(i);
		setBit(bit, j);
		j--;
	}
	while (j >= 0)
	{
		if (thuc == DoubleString(thuc))
		{
			break;
		}
		else
		{
			thuc = DoubleString(thuc);
			if (thuc[0] == '1')
			{
				setBit(1, j);
				thuc[0] = '0';
			}
			else
			{
				setBit(0, j);
			}
		}
		j--;
	}
	QInt exp(tam + 16383);
	int pos = 126;
	for (int i = 14; i >= 0; i--)
	{
		int bit = exp.getBit(i);
		setBit(bit, pos);
		pos--;
	}
	if (am == 1)
	{
		setBit(1, 127);
	}
	else
	{
		setBit(0, 127);
	}
}