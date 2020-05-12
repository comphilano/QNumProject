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
	if (nguyen == "0" && thuc == "00")
	{
		return;
	}
	QInt a(nguyen);
	if (nguyen == "0")
	{
		string x;
		int dem = 1;
		while (dem <= 112)
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
					x.push_back('1');
					thuc[0] = '0';
					break;
				}
				else
				{
					x.push_back('0');
				}
			}
			dem++;
		}
		int dodoi = dem;
		int j = 111;
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
		//if (j == -1)
		//{
		//	setBit(1, 0);
		//}
		QInt exp(16383 - dodoi);
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
	else
	{
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
		//if (j == -1)
		//{
		//	setBit(1, 0);
		//}
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

}

//Hàm chuẩn hóa chuỗi
int QFloat::ChuanHoaChuoi(string& s)
{
	int Dau;
	int k = 0;
	if (s == "-") return -1;

	//Kiểm tra dấu của dãy số
	if (s[0] == '-') {
		Dau = 1;
		s = s.substr(1, s.length()); //Cắt dấu đi để chuẩn hóa lại chuỗi
	}
	else Dau = 0;

	if (s[0] == '.' || s[s.length() - 1] == '.') return -1;

	do	//Loại bỏ các số 0 ở đầu phần nguyên
	{
		if (s[0] == '0' && s[1] == '.') break;
		if (s.length() == 1 && s[0] == '0') break;
		if (s[0] == '0') s = s.substr(1, s.length());
	} while (s[0] == '0');

	if (Dau == 1) s = "-" + s;	//Thêm lại dấu vào chuỗi nếu chuỗi ban đầu chứa dấu
	
	for (int i = Dau; i < s.length(); i++) {
		if ((s[i] < 47 || s[i] > 58) && s[i] != '.')
			return -1;
		if (s[i] == '.') k += 1;	//Trường hợp chuỗi có hơn một dấu '.'
		if (k > 1) return -1;
		if (s[i] == '.') {		//Loại bỏ các số 0 ở cuối phần thực
			for (int j = s.length() - 1; j > (i + 1); j--) {
				if (s[j] == '0') s = s.substr(0, s.length() - 1);
				else break;
			}
		}
	}
	if (k == 0) s = s + ".0";
	if (s == "-0.0" || s == "-0") s = "0.0"; 
	return 0;
}
//Hàm chuyển đổi hệ 2 sang hệ 10
QFloat QFloat::BinToDec(bool* bit)
{
	string source = BoolToString(bit);
	for (int i = 0; i < source.length(); i++)
	{
		if (bit[127 - i] == true)
		{
			setBit(1, i);
		}
		else
		{
			setBit(0, i);
		}
	}
	return *this;
}
//Hàm chuyển đổi hệ 10 sang 2
bool* QFloat::DecToBin(QFloat a)
{
	bool* det = new bool[128];
	for (int i = 0; i < 128; i++)
	{
		int bit = a.getBit(i);
		if (bit == 1)
			det[i] = true;
		else
			det[i] = false;
	}
	return det;
}



//Hàm chuyển bool đến string
string QFloat::BoolToString(bool* a)
{
	string det;
	int length = 0;
	bool* temp = new bool;
	int j = 0;
	temp = a;
	while ((temp[j] == false) || (temp[j] == true))
	{
		j++;
	}
	for (int i = 0; i < j; i++)
	{
		if (a[i] == true)
			det.push_back('1');
		else
			det.push_back('0');
	}
	for(int i = j;i < 128;i++)
		det.push_back('0');
	return det;
}

///////////////////////////////////////////////////////
string QFloat::PrintQFloat()
{
	string bit, phanNguyen, phanThuc;
	for (int i = 127; i >= 0; i--)			// Chuyển các bit của data vào string bit
	{
		if (getBit(i) == 0)
			bit = bit + '0';
		else
			bit = bit + '1';
	}

	string ktExp, ktSign;

	ktSign = ktSign + bit[0];
	for (int i = 1; i <= 15; i++)
	{
		ktExp = ktExp + bit[i];
	}

	if (ZeroNumber(ktSign, ktExp) == 1)
		return "0.0";
	else
		if (Denormalized(ktSign, ktExp) == 1)
			return "Denormalized";
		else
			if (Infinity(ktSign, ktExp) == 1)
				return "Infinity";
			else
				if (NotANumber(ktSign, ktExp) == 1)
					return "Not a Number";

	int exp = 0;							// Tính số E từ exp 
	for (int i = 15; i >= 1; i--)
	{
		if (bit[i] == '1')
		{
			exp = exp + PowInt(2, 15 - i);
		}
	}
	exp = exp - 16383;

	string frac;   // chu y xu ly frac bang 0
	for (int i = 16; i <= 127; i++)
	{
		frac = frac + bit[i];
	}



	if (exp == 0)		//Trường hợp E = 0
	{
		phanNguyen = phanNguyen + '1';
		phanThuc = phanThuc + frac;
	}
	else
		if (exp > 0)			// Trường hợp E > 0
		{
			phanNguyen = phanNguyen + '1';
			for (int i = 1; i <= exp; i++)
			{
				if (frac.length() > 0)
				{
					phanNguyen = phanNguyen + frac[0];
					frac.erase(frac.begin());
				}
				else
				{
					phanNguyen = phanNguyen + '0';
				}
			}
		}
		else
			if (exp < 0)		// Trường hợp E < 0
			{
				if (exp == -1)
				{
					phanNguyen = phanNguyen + '0';
					frac = '1' + frac;
				}
				else
				{
					phanNguyen = phanNguyen + '0';
					frac = '1' + frac;

					for (int i = 1; i < abs(exp); i++)
					{
						frac = '0' + frac;
					}
				}
			}


	string ans = "0";

	int count = 0;
	for (int i = phanNguyen.length() - 1; i >= 0; i--)		// Chuyển phần nguyên từ hệ 2 sang 10
	{
		if (phanNguyen[i] == '1')
		{
			ans = SumString(ans, ExpString("2", count));
		}
		count++;
	}


	if (bit[0] == '1')
		ans = '-' + ans;

	string tongPhanThuc = "0";			// Tính tổng phần thực từ hệ 2 sang 10
	if (frac.length() != 0)
	{
		for (int i = 0; i < frac.length(); i++)
		{
			if (frac[i] == '1')
			{
				tongPhanThuc = SumDecimal(tongPhanThuc, DivDecimal(i + 1));
			}
		}
	}

	ans = ans + '.';				// Kết quả cuối
	while (tongPhanThuc.length() > 15) // Lấy 15 số sau dấu phẩy
	{
		tongPhanThuc.pop_back();
	}
	ans = ans + tongPhanThuc;
	cout << ans << endl;

	return ans;
}

string QFloat::ExpString(string a, int n)
{
	string ans = a;
	if (n == 0)
	{
		return "1";
	}
	for (int i = 1; i < n; i++)
	{
		ans = DoubleString(ans);
	}
	return  ans;
}

int QFloat::PowInt(int x, int n)
{
	if (n == 0)
		return 1;

	int num = 1;
	for (int i = 1; i <= n; i++)
		num = num * x;

	return num;
}

string QFloat::DivDecimal(int n)
{
	string ans = "0";
	if (n == 1)
	{
		ans = SumString(ans, "5");
		return ans;
	}

	string temp = "5";
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			ans = SumString(ans, temp);
		}
		temp = ans;
		ans = "0";
	}

	while (temp.length() != n)
	{
		temp = '0' + temp;
	}
	return temp;
}

string QFloat::SumDecimal(string a, string b)
{
	string ans;

	if (a.length() > b.length())
	{
		string temp;
		for (int i = 0; i < b.length(); i++)
		{
			temp = temp + a[i];
		}
		ans = SumString(temp, b);
		for (int i = b.length(); i < a.length(); i++)
		{
			ans = ans + a[i];
		}
	}
	else
		if (a.length() < b.length())
		{
			string temp;
			for (int i = 0; i < a.length(); i++)
			{
				temp = temp + b[i];
			}
			ans = SumString(temp, a);
			for (int i = a.length(); i < b.length(); i++)
			{
				ans = ans + b[i];
			}
		}
		else
		{
			ans = SumString(a, b);
		}

	return ans;
}

int QFloat::ZeroNumber(string sign, string exp)
{
	if (sign[0] != '0')
		return 0;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] != '0')
			return 0;
	}
	return 1;
}

int QFloat::Denormalized(string sign, string exp)
{
	if (sign[0] == '0')
		return 0;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] != '0')
			return 0;
	}
	return 1;
}

int QFloat::Infinity(string sign, string exp)
{

	if (sign[0] == '1')
		return 0;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '0')
			return 0;
	}
	return 1;
}

int QFloat::NotANumber(string sign, string exp)
{
	if (sign[0] == '0')
		return 0;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '0')
			return 0;
	}
	return 1;
}
/////////////////////////////////




//Hàm khởi tạo với giá trị string

QFloat::QFloat(string x)
{
	for (int i = 127; i >= 0; i--)
	{
		setBit(0, i);
	}
	int am = 0;
	string nguyen;
	string thuc;
	ChiaChuoi(x, nguyen, thuc);
	if (nguyen[0] == '-')
	{
		am = 1;
		nguyen.erase(nguyen.begin());
	}
	if (nguyen == "0" && thuc == "00")
	{
		return;
	}
	QInt a(nguyen);
	if (nguyen == "0")
	{
		string x;
		int dem = 1;
		while (dem <= 112)
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
					x.push_back('1');
					thuc[0] = '0';
					break;
				}
				else
				{
					x.push_back('0');
				}
			}
			dem++;
		}
		int dodoi = dem;
		int j = 111;
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
		//if (j == -1)
		//{
		//	setBit(1, 0);
		//}
		QInt exp(16383 - dodoi);
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
	else
	{
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
		//if (j == -1)
		//{
		//	setBit(1, 0);
		//}
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

}

string QFloat::PrintBin(QFloat a)
{
	bool* bit = new bool[128];
	bit = a.DecToBin(a);
	string dec;
	for (int i = 0; i < 128; i++)
	{
		if (bit[i] == true)
			dec.push_back('1');
		else
			dec.push_back('0');
	}
	DaoChuoi(dec);
	return dec;
}

//Hàm đảo chuỗi

void QFloat::DaoChuoi(string& a)
{
	string b;
	for (int i = a.length() - 1; i >= 0; i--)
	{
		b.push_back(a[i]);
	}
	a = b;
}
