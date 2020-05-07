#include "QInt.h"

int QInt::getBit(int pos)
{
	int a = pos / 32; //xác định bit nằm trong phần tử nào của mảng QInt
	int b = pos % 32; //xác định bit nằm ở trị trí thứ mấy trong phần tử vừa tìm 
	return (data[a] >> (31 - b)) & 1;
}

void QInt::setBit(int value, int pos)
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

QInt::QInt()
{
	//Khởi tạo bằng 0
	for (int i = 0; i < 128; i++)
	{
		setBit(0, i);
	}
}

//Hàm này để test trong phạm vi số int
QInt::QInt(int a)
{
	for (int i = 0; i < 128; i++)
	{
		setBit(0, i);
	}
	int pos = 0;//vị trí gán bit tiếp theo
	int tam = a;
	while (tam != 0)
	{
		int value = tam % 2;
		setBit(value, pos);
		tam /= 2;
		pos++;

	}

}

//Operator
bool QInt::operator>(QInt a)
{
	for (int i = 127; i >= 0; i--)
	{
		int x = getBit(i);
		int y = a.getBit(i);
		if (x > y)
		{
			return true;
		}
		else if (x < y)
		{
			return false;
		}
	}
	return false;
}

bool QInt::operator<(QInt a)
{
	for (int i = 127; i >= 0; i--)
	{
		int x = getBit(i);
		int y = a.getBit(i);
		if (x < y)
		{
			return true;
		}
		else if (x > y)
		{
			return false;
		}
	}
	return false;
}

bool QInt::operator==(QInt a)
{
	for (int i = 127; i >= 0; i--)
	{
		int x = getBit(i);
		int y = a.getBit(i);
		if (x > y)
		{
			return false;
		}
		else if (x < y)
		{
			return false;
		}
	}
	return true;
}

bool QInt::operator>=(QInt a)
{
	for (int i = 127; i >= 0; i--)
	{
		int x = getBit(i);
		int y = a.getBit(i);
		if (x > y)
		{
			return true;
		}
		else if (x < y)
		{
			return false;
		}
	}
	return true;
}

bool QInt::operator<=(QInt a)
{
	for (int i = 127; i >= 0; i--)
	{
		int x = getBit(i);
		int y = a.getBit(i);
		if (x < y)
		{
			return true;
		}
		else if (x > y)
		{
			return false;
		}
	}
	return true;
}

void QInt::operator=(QInt a)
{
	for (int i = 0; i < 128; i++)
	{
		int bit = a.getBit(i);
		setBit(bit, i);
	}
}

//Operator AND, OR, XOR, NOT
QInt QInt::operator&(QInt a)
{
	QInt ans;
	for (int i = 0; i < 128; i++)
	{
		int x = getBit(i);
		int y = a.getBit(i);
		if (x == 1 && y == 1)
		{
			ans.setBit(1, i);
		}
		else
		{
			ans.setBit(0, i);
		}
	}
	return ans;
}

QInt QInt::operator|(QInt a)
{
	QInt ans;
	for (int i = 0; i < 128; i++)
	{
		int x = getBit(i);
		int y = a.getBit(i);
		if (x == 0 && y == 0)
		{
			ans.setBit(0, i);
		}
		else
		{
			ans.setBit(1, i);
		}
	}
	return ans;
}

QInt QInt::operator^(QInt a)
{
	QInt ans;
	for (int i = 0; i < 128; i++)
	{
		int x = getBit(i);
		int y = a.getBit(i);
		if (x == y)
		{
			ans.setBit(0, i);
		}
		else
		{
			ans.setBit(1, i);
		}
	}
	return ans;
}

QInt QInt::operator~()
{
	QInt ans;
	for (int i = 0; i < 128; i++)
	{
		int x = getBit(i);
		if (x == 0)
		{
			ans.setBit(1, i);
		}
		else
		{
			ans.setBit(0, i);
		}
	}
	return ans;
}
//Hàm nhập
void QInt::ScanQInt()
{
	int am = 0;
	string a;
	cout << "Nhap so: ";
	cin >> a;
	int pos = 0;
	if (a[0] == '-')
	{
		a.erase(a.begin());
		am = 1;
	}
	while (a[0] != '0')
	{
		int du = HalfString(a);
		setBit(du, pos);
		pos++;
	}
	if (am == 1)
	{
		//Đảo bit ra số bù 1
		data[0] = ~data[0];
		data[1] = ~data[1];
		data[2] = ~data[2];
		data[3] = ~data[3];
		//Cộng 1 ra số bù 2
		for (int j = 0; j < 128; j++)
		{
			int bit = this->getBit(j);
			if (bit == 1)
			{
				setBit(0, j);
			}
			else
			{
				setBit(1, j);
				break;
			}
		}
		
	}
}

//>>, <<, rol, ror
QInt QInt::operator<<(int value)
{
	QInt ans;
	for (int i = 127; i >= value; i--)
	{
		int bit = getBit(i - value);
		ans.setBit(bit, i);
	}
	return ans;
}

QInt QInt::operator>>(int value)
{
	QInt ans;
	for (int i = 0; i < 128 - value; i++)
	{
		int bit = getBit(i + value);
		ans.setBit(bit, i);
	}
	return ans;
}

QInt QInt::rol(int value)
{
	QInt ans;
	for (int i = 0; i < value; i++)
	{
		int bit = getBit(127);
		ans = *this << 1;
		ans.setBit(bit, 0);
		*this = ans;
	}
	return ans;
}

QInt QInt::ror(int value)
{
	QInt ans;
	for (int i = 0; i < value; i++)
	{
		int bit = getBit(0);
		ans = *this >> 1;
		ans.setBit(bit, 127);
		*this = ans;
	}
	return ans;
}

int QInt::HalfString(string& a)
{
	string ans;
	int sodu = a[a.length() - 1] % 2;
	if (a.length() == 1 && a[0] == 49)
	{
		a = '0';
		return 1;
	}
	if (a.length() == 1 && a[0] == 48)
	{
		a = '0';
		return 0;
	}
	while (a.length() > 1 || (a[0] != 48 && a[0] != 49))
	{
		if (a[0] > '1' )
		{
			int value = a[0] - 48;
			int du = value % 2;
			value /= 2;

			ans.push_back(value + 48);
			if (du == 0)
			{
				if (a[1] == '1')
				{
					a[0] = 48;
				}
				else if (a[1] == '0')
				{
					a[0] = 48;
				}
				else
				{
					a.erase(a.begin());
				}
			}
			else
			{
				a[0] = 49;
			}
		}
		else
		{
			int value = (a[0] - 48) * 10 + (a[1] - 48);
			int du = value % 2;
			value /= 2;
			ans.push_back(value + 48);
			if (du == 0)
			{

				a[1] = '0';
				a.erase(a.begin());

			}
			else
			{
				a.erase(a.begin());
				a[0] = 49;
			}
		}
		if (a.length() == 0)
		{
			break;
		}
	}
	a = ans;
	return sodu;
}

//Chuan hoa chuoi
int QInt::ChuanHoa(string& s)
{
	int Dau;
	string temp = "";
	if (s[0] == '-') {
		Dau = 1;
		s = s.substr(1, s.length());
	}
	else Dau = 0;
	do {
		if (s[0] == '0') s = s.substr(1, s.length());
		if (s[0] != '0') break;
	} while (true);
	if (Dau == 1) temp = temp + "-" + s;
	if (temp != "") s = temp;
	for (int i = Dau; i < s.length(); i++) {
		if (s[i] < 47 || s[i] > 58)
			return -1;
	}
	return 0;
}


QInt QInt::operator+(QInt a)
{
	QInt c;
	int nho = 0;
	for (int i = 0; i <= 127; i++) {
		int t = getBit(i) + a.getBit(i) + nho;
		if (t == 3) {
			c.setBit(1, i);
			nho = 1;
		}
		else
		{
			if (t == 2) {
				c.setBit(0, i);
				nho = 1;
			}
			else {
				c.setBit(t, i);
				nho = 0;
			}
		}
	}
	return c;
}

QInt QInt::operator-(QInt a)
{
	QInt c;
	a.data[0] = ~a.data[0];
	a.data[1] = ~a.data[1];
	a.data[2] = ~a.data[2];
	a.data[3] = ~a.data[3];
	//Cộng 1 ra số bù 2
	for (int j = 0; j < 128; j++)
	{
		int bit = a.getBit(j);
		if (bit == 1)
		{
			a.setBit(0, j);
		}
		else
		{
			a.setBit(1, j);
			break;
		}
	}
	int nho = 0;
	for (int i = 0; i <= 127; i++) {
		int t = getBit(i) + a.getBit(i) + nho;
		if (t == 3) {
			c.setBit(1, i);
			nho = 1;
		}
		else
		{
			if (t == 2) {
				c.setBit(0, i);
				nho = 1;
			}
			else {
				c.setBit(t, i);
				nho = 0;
			}
		}
	}
	return c;
}

