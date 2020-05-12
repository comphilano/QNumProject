#include "Menu.h"
#include <conio.h>

int Menu::MainMenu()
{
	int chon = 0;
	while (true)
	{
		if (chon == 0)
		{
			system("cls");
			cout << "LUA CHON CHUC NANG" << endl << endl;
			setColor(31);
			cout << "So nguyen lon (QInt)." << endl << endl;
			setColor(15);
			cout << "So cham dong chinh xac cao (QFloat)." << endl << endl;
			cout << "Thoat.";
		}
		else if (chon == 1)
		{
			system("cls");
			cout << "LUA CHON CHUC NANG" << endl << endl;
			cout << "So nguyen lon (QInt)." << endl << endl;
			setColor(31);
			cout << "So cham dong chinh xac cao (QFloat)." << endl << endl;
			setColor(15);
			cout << "Thoat.";
		}
		else if (chon == 2)
		{
			system("cls");
			cout << "LUA CHON CHUC NANG" << endl << endl;
			cout << "So nguyen lon (QInt)." << endl << endl;
			cout << "So cham dong chinh xac cao (QFloat)." << endl << endl;
			setColor(31);
			cout << "Thoat.";
			setColor(15);
		}
		char c = _getch();
		if (c == 13)
		{
			break;
		}
		else if (c == 72)
		{
			chon--;
		}
		else if (c == 80)
		{
			chon++;
		}
		if (chon == 3)
		{
			chon = 0;
		}
		else if (chon == -1)
		{
			chon = 2;
		}
	}
	return chon;
}

int Menu::QIntMenu()
{
	int chon = 0;
	while (true)
	{
		if (chon == 0)
		{
			system("cls");
			cout << "LUA CHON CHUC NANG" << endl << endl;
			setColor(31);
			cout << "Chuyen doi." << endl << endl;
			setColor(15);
			cout << "Tinh toan, so sanh." << endl << endl;
			cout << "Dich, xoay." << endl << endl;
			cout << "File" << endl << endl;
			cout << "Thoat.";
		}
		else if (chon == 1)
		{
			system("cls");
			cout << "LUA CHON CHUC NANG" << endl << endl;
			cout << "Chuyen doi." << endl << endl;
			setColor(31);
			cout << "Tinh toan, so sanh." << endl << endl;
			setColor(15);
			cout << "Dich, xoay." << endl << endl;
			cout << "File" << endl << endl;
			cout << "Thoat.";
		}
		else if (chon == 2)
		{
			system("cls");
			cout << "LUA CHON CHUC NANG" << endl << endl;
			cout << "Chuyen doi." << endl << endl;
			cout << "Tinh toan, so sanh." << endl << endl;
			setColor(31);
			cout << "Dich, xoay." << endl << endl;
			setColor(15);
			cout << "File" << endl << endl;
			cout << "Thoat.";
		}
		else if (chon == 3)
		{
			system("cls");
			cout << "LUA CHON CHUC NANG" << endl << endl;
			cout << "Chuyen doi." << endl << endl;
			cout << "Tinh toan, so sanh." << endl << endl;
			cout << "Dich, xoay." << endl << endl;
			setColor(31);
			cout << "File" << endl << endl;
			setColor(15);
			cout << "Thoat.";
		}
		else if (chon == 4)
		{
			system("cls");
			cout << "LUA CHON CHUC NANG" << endl << endl;
			cout << "Chuyen doi." << endl << endl;
			cout << "Tinh toan, so sanh." << endl << endl;
			cout << "Dich, xoay." << endl << endl;
			cout << "File" << endl << endl;
			setColor(31);
			cout << "Thoat.";
			setColor(15);
		}
		char c = _getch();
		if (c == 13)
		{
			break;
		}
		else if (c == 72)
		{
			chon--;
		}
		else if (c == 80)
		{
			chon++;
		}
		if (chon == 5)
		{
			chon = 0;
		}
		else if (chon == -1)
		{
			chon = 4;
		}
	}
	return chon;
}

void Menu::ChuyenDoiQInt()
{
	//chon he co so goc
	int chon = 0;
	int coso1 = 2;
	char c = '0';
	while (c != 13)
	{
		system("cls");
		cout << "CHUYEN DOI HE CO SO" << endl << endl;
		cout << "Chon he co so goc (mui ten trai, phai): " << coso1;
		c = _getch();
		if (c == 75)
		{
			chon--;
		}
		if (c == 77)
		{
			chon++;
		}
		if (chon == -1)
		{
			chon = 2;
		}
		if (chon == 3)
		{
			chon = 0;
		}
		if (chon == 0)
		{
			coso1 = 2;
		}
		if (chon == 1)
		{
			coso1 = 10;
		}
		if (chon == 2)
		{
			coso1 = 16;
		}
	}
	//Nhap so thứ nhất 
	string so1;
	cout << "\nNhap so can chuyen doi: ";
	cin >> so1;
	QInt x1;
	if (coso1 == 2)
	{
		bool* a = new bool;
		a = x1.StringToBool(so1);
		x1 = x1.BinToDeC(a);
	}
	if (coso1 == 10)
	{
		x1 = so1;
	}
	if (coso1 == 16)
	{
		x1 = x1.HexToDec(so1);
	}
	c = 0;
	chon = 0;
	int coso2 = 2;
	while (c != 13)
	{
		system("cls");
		cout << "CHUYEN DOI HE CO SO" << endl << endl;
		cout << "Chon he co so goc (mui ten trai, phai): " << coso1;
		cout << "\nNhap so can chuyen doi: " << so1;
		cout << "\nChon he co so chuyen doi (mui ten trai, phai): " << coso2;
		c = _getch();
		if (c == 75)
		{
			chon--;
		}
		if (c == 77)
		{
			chon++;
		}
		if (chon == -1)
		{
			chon = 2;
		}
		if (chon == 3)
		{
			chon = 0;
		}
		if (chon == 0)
		{
			coso2 = 2;
		}
		if (chon == 1)
		{
			coso2 = 10;
		}
		if (chon == 2)
		{
			coso2 = 16;
		}
	}
	cout << "\nSau khi chuyen doi: ";
	if (coso2 == 2)
	{
		bool* he2;
		he2 = x1.DecToBin(x1);
		string a;
		a = x1.PrintBin(x1);
		cout << a;
	}
	if (coso2 == 10)
	{
		cout << x1.PrintQInt();
	}
	if (coso2 == 16)
	{
		string a;
		a = x1.DecToHex(x1);
		cout << a;
	}
}

void Menu::TinhToanQInt()
{
	//chon he co so goc
	int chon = 0;
	int coso1 = 2;
	char c = '0';
	while (c != 13)
	{
		system("cls");
		cout << "TINH TOAN & SO SANH" << endl << endl;
		cout << "Chon he co so goc (mui ten trai, phai): " << coso1;
		c = _getch();
		if (c == 75)
		{
			chon--;
		}
		if (c == 77)
		{
			chon++;
		}
		if (chon == -1)
		{
			chon = 2;
		}
		if (chon == 3)
		{
			chon = 0;
		}
		if (chon == 0)
		{
			coso1 = 2;
		}
		if (chon == 1)
		{
			coso1 = 10;
		}
		if (chon == 2)
		{
			coso1 = 16;
		}
	}
	//Nhap so thứ nhất 
	string so1;
	cout << "\nNhap thu nhat: ";
	cin >> so1;
	QInt x1;
	//Chọn phép tính
	int choose = 0;
	string dau = "+";
	c = '0';
	while (c != 13)
	{
		system("cls");
		cout << "TINH TOAN & SO SANH" << endl << endl;
		cout << "Chon he co so goc (mui ten trai, phai): " << coso1;
		cout << "\nNhap thu nhat: " << so1;
		cout << "\nChon phep tinh (mui ten trai, phai): " << dau;
		c = _getch();
		if (c == 75)
		{
			choose--;
		}
		if (c == 77)
		{
			choose++;
		}
		if (choose == -1)
		{
			choose = 12;
		}
		if (choose == 13)
		{
			choose = 0;
		}
		if (choose == 0)
		{
			dau = "+";
		}
		if (choose == 1)
		{
			dau = "-";
		}
		if (choose == 2)
		{
			dau = "*";
		}
		if (choose == 3)
		{
			dau = "/";
		}
		if (choose == 4)
		{
			dau = "<";
		}
		if (choose == 5)
		{
			dau = ">";
		}
		if (choose == 6)
		{
			dau = "==";
		}
		if (choose == 7)
		{
			dau = "<=";
		}
		if (choose == 8)
		{
			dau = ">=";
		}
		if (choose == 9)
		{
			dau = "AND";
		}
		if (choose == 10)
		{
			dau = "OR";
		}
		if (choose == 11)
		{
			dau = "XOR";
		}
		if (choose == 12)
		{
			dau = "NOT";
		}
	}
	//Trường hợp NOT không cần nhập số thứ 2
	if (choose == 12)
	{
		QInt x2;
		x2 = ~x1;
		if (coso1 == 2)
		{
			bool* he2;
			he2 = x2.DecToBin(x2);
			string a;
			a = x2.PrintBin(x2);
			cout << "\nDAP AN: " << a;
		}
		if (coso1 == 10)
		{
			cout << "\nDAP AN: " << x2.PrintQInt();
		}
		if (coso1 == 16)
		{
			string a;
			a = x2.DecToHex(x1);
			cout << "\nDAP AN: " << a;
		}
		return;
	}
	//Nhập số thứ 2
	string so2;
	cout << "\nNhap so thu hai: ";
	cin >> so2;
	QInt x2;
	if (coso1 == 2)
	{
		bool* a = new bool;
		a = x1.StringToBool(so1);
		x1 = x1.BinToDeC(a);
		bool* b = new bool;
		b = x2.StringToBool(so2);
		x2 = x2.BinToDeC(b);
	}
	cout << "\nDAP AN: ";
	if (coso1 == 10)
	{
		x1 = so1;
		x2 = so2;
	}
	if (coso1 == 16)
	{
		x1 = x1.HexToDec(so1);
		x2 = x2.HexToDec(so2);
	}
	QInt x3;
	if (choose == 0)
	{
		x3 = x1 + x2;
	}
	if (choose == 1)
	{
		x3 = x1 - x2;
	}
	if (choose == 2)
	{
		x3 = x1 * x2;
	}
	if (choose == 3)
	{
		QInt tam(0);
		if (x2 == tam)
		{
			cout << "Math Error";
			return;
		}
		x3 = x1 / x2;
	}
	if (choose == 4)
	{
		if (x1 < x2)
		{
			cout << "True";
		}
		else
		{
			cout << "False";
		}
		return;
	}
	if (choose == 5)
	{
		if (x1 > x2)
		{
			cout << "True";
		}
		else
		{
			cout << "False";
		}
		return;
	}
	if (choose == 6)
	{
		if (x1 == x2)
		{
			cout << "True";
		}
		else
		{
			cout << "False";
		}
		return;
	}
	if (choose == 7)
	{
		if (x1 <= x2)
		{
			cout << "True";
		}
		else
		{
			cout << "False";
		}
		return;
	}
	if (choose == 8)
	{
		if (x1 >= x2)
		{
			cout << "True";
		}
		else
		{
			cout << "False";
		}
		return;
	}
	if (choose == 9)
	{
		x3 = x1 & x2;
	}
	if (choose == 10)
	{
		x3 = x1 | x2;
	}
	if (choose == 11)
	{
		x3 = x1 ^ x2;
	}
	if (coso1 == 2)
	{
		bool* he2;
		he2 = x3.DecToBin(x3);
		string kq;
		kq = x3.PrintBin(x3);
		cout << kq;
	}
	if (coso1 == 10)
	{
		cout << x3.PrintQInt();
	}
	if (coso1 == 16)
	{
		string a;
		a = x3.DecToHex(x3);
		cout << a;
	}
}

//phép dịch và dời
void Menu::DichDoiQInt()
{
	//chon he co so goc
	int chon = 0;
	int coso1 = 2;
	char c = '0';
	while (c != 13)
	{
		system("cls");
		cout << "PHEP DICH & XOAY" << endl << endl;
		cout << "Chon he co so goc (mui ten trai, phai): " << coso1;
		c = _getch();
		if (c == 75)
		{
			chon--;
		}
		if (c == 77)
		{
			chon++;
		}
		if (chon == -1)
		{
			chon = 2;
		}
		if (chon == 3)
		{
			chon = 0;
		}
		if (chon == 0)
		{
			coso1 = 2;
		}
		if (chon == 1)
		{
			coso1 = 10;
		}
		if (chon == 2)
		{
			coso1 = 16;
		}
	}
	string so1;
	cout << "\nNhap so can dich, xoay: ";
	cin >> so1;
	QInt x1;
	if (coso1 == 2)
	{
		bool* a = new bool;
		a = x1.StringToBool(so1);
		x1 = x1.BinToDeC(a);
	}
	if (coso1 == 10)
	{
		x1 = so1;
	}
	if (coso1 == 16)
	{
		x1 = x1.HexToDec(so1);
	}
	//Chọn phép tính
	c = 0;
	chon = 0;
	string phep = "<<";
	while (c != 13)
	{
		system("cls");
		cout << "PHEP DICH & XOAY" << endl << endl;
		cout << "Chon he co so goc (mui ten trai, phai): " << coso1;
		cout << "\nNhap so can dich, xoay: " << so1;
		cout << "\nLua chon phep dich, xoay: " << phep;
		c = _getch();
		if (c == 75)
		{
			chon--;
		}
		if (c == 77)
		{
			chon++;
		}
		if (chon == -1)
		{
			chon = 2;
		}
		if (chon == 4)
		{
			chon = 0;
		}
		if (chon == 0)
		{
			phep = "<<";
		}
		if (chon == 1)
		{
			phep = ">>";
		}
		if (chon == 2)
		{
			phep = "Rotate Left";
		}
		if (chon == 3)
		{
			phep = "Rotate Right";
		}
	}
	int luong;
	cout << "\nNhap luong dich, xoay: ";
	cin >> luong;
	cout << "DAP AN: ";
	if (chon < 0)
	{
		cout << "Math Error";
	}
	if (chon == 0)
	{
		x1 = x1 << luong;
	}
	if (chon == 1)
	{
		x1 = x1 >> luong;
	}
	if (chon == 2)
	{
		x1 = x1.rol(luong);
	}
	if (chon == 3)
	{
		x1 = x1.ror(luong);
	}

	//CHuyển đổi rồi xuất ra màn hình
	if (coso1 == 2)
	{
		bool* he2;
		he2 = x1.DecToBin(x1);
		string kq;
		kq = x1.PrintBin(x1);
		cout << kq;
	}
	if (coso1 == 10)
	{
		cout << x1.PrintQInt();
	}
	if (coso1 == 16)
	{
		string a;
		a = x1.DecToHex(x1);
		cout << a;
	}
}

//Menu QFloat
int Menu::QFloatMenu()
{
	int chon = 0;
	while (true)
	{
		if (chon == 0)
		{
			system("cls");
			cout << "LUA CHON CHUC NANG" << endl << endl;
			setColor(31);
			cout << "Chuyen doi." << endl << endl;
			setColor(15);
			cout << "File" << endl << endl;
			cout << "Thoat.";
		}
		else if (chon == 1)
		{
			system("cls");
			cout << "LUA CHON CHUC NANG" << endl << endl;
			cout << "Chuyen doi." << endl << endl;
			setColor(31);
			cout << "File" << endl << endl;
			setColor(15);
			cout << "Thoat.";
		}
		else if (chon == 2)
		{
			system("cls");
			cout << "LUA CHON CHUC NANG" << endl << endl;
			cout << "Chuyen doi." << endl << endl;
			cout << "File" << endl << endl;
			setColor(31);
			cout << "Thoat.";
			setColor(15);
		}
		char c = _getch();
		if (c == 13)
		{
			break;
		}
		else if (c == 72)
		{
			chon--;
		}
		else if (c == 80)
		{
			chon++;
		}
		if (chon == 3)
		{
			chon = 0;
		}
		else if (chon == -1)
		{
			chon = 2;
		}
	}
	return chon;
}
//Hàm chuyển đổi QFloat
void Menu::ChuyenDoiQFloat()
{
	//chon he co so goc
	int chon = 0;
	int coso1 = 2;
	char c = '0';
	while (c != 13)
	{
		system("cls");
		cout << "CHUYEN DOI HE CO SO" << endl << endl;
		cout << "Chon he co so goc (mui ten trai, phai): " << coso1;
		c = _getch();
		if (c == 75)
		{
			chon--;
		}
		if (c == 77)
		{
			chon++;
		}
		if (chon == -1)
		{
			chon = 1;
		}
		if (chon == 2)
		{
			chon = 0;
		}
		if (chon == 0)
		{
			coso1 = 2;
		}
		if (chon == 1)
		{
			coso1 = 10;
		}
	}
	//Nhap so thứ nhất 
	string so1;
	cout << "\nNhap so can chuyen doi: ";
	cin >> so1;
	QFloat x1;
	QInt tam;
	if (coso1 == 2)
	{
		bool* he2;
		he2 = tam.StringToBool(so1);
		x1 = x1.BinToDec(he2);
	}
	if (coso1 == 10)
	{
		QFloat tam(so1);
		x1 = tam;
	}
	c = 0;
	chon = 0;
	int coso2 = 2;
	while (c != 13)
	{
		system("cls");
		cout << "CHUYEN DOI HE CO SO" << endl << endl;
		cout << "Chon he co so goc (mui ten trai, phai): " << coso1;
		cout << "\nNhap so can chuyen doi: " << so1;
		cout << "\nChon he co so chuyen doi (mui ten trai, phai): " << coso2;
		c = _getch();
		if (c == 75)
		{
			chon--;
		}
		if (c == 77)
		{
			chon++;
		}
		if (chon == -1)
		{
			chon = 1;
		}
		if (chon == 2)
		{
			chon = 0;
		}
		if (chon == 0)
		{
			coso2 = 2;
		}
		if (chon == 1)
		{
			coso2 = 10;
		}
	}
	cout << "\nSau khi chuyen doi: ";
	if (coso2 == 2)
	{
		bool* he2;
		he2 = x1.DecToBin(x1);
		string kq;
		kq = x1.PrintBin(x1);
		cout << kq;
	}
	if (coso2 == 10)
	{
		x1.PrintQFloat();
	}
}

//Hàm xuất màn hình chính
void Menu::HomeScreen()
{
mainmenu:
	int a = MainMenu();
	if (a == 0)
	{
		while (true)
		{
			int b = QIntMenu();
			if (b == 0)
			{
				ChuyenDoiQInt();
				_getch();
			}
			else if (b == 1)
			{
				TinhToanQInt();
				_getch();
			}
			else if (b == 2)
			{
				DichDoiQInt();
				_getch();
			}
			else if (b == 3)
			{
				//Nhập xuất file ở đây
			}
			else if (b == 4)
			{
				break;
			}
		}
		goto mainmenu;
	}
	if (a == 1)
	{
		while (true)
		{
			int b = QFloatMenu();
			if (b == 0)
			{
				ChuyenDoiQFloat();
				_getch();
			}
			else if (b == 1)
			{
				//Hàm nhập xuất file QFloat
			}
			else if (b == 2)
			{
				break;
			}
		}
	}
	if (a == 2)
	{
		return;
	}
}


//Hàm xử lý
void Menu::gotoXY(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

void Menu::setColor(int x)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}