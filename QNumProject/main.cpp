#include "QInt.h"
#include "QFloat.h"
#include "Menu.h"
#include <Windows.h>
#include<conio.h>
#include "FileManip.h"

void main(int argc, char* argv[])
{
	//Hàm CMD-------------------------------------------------------------------------------------------
  XuLiCMD(argc, argv);
  FileManip x;
  x.Manip("d:\\floatin.txt", "d:\\floatout.txt", "float");
  QFloat z("0.1");
  cout << z.PrintQFloat();
	//--------------------------------------------------------------------------------------------------

	//Test làm tròn----------------------------------------------------------------------------------------

	//cout << "Ham chua set dieu kien so nao can lam tron. Nhap so khong can lam tron la sai.";
	//QFloat a;
	//a.ScanQFloat();
	//string x;
	//x = a.LamTron();
	//cout << "So duoc lam tron : " << x;
	//_getch();

	//--------------------------------------------------------------------------------------------------------
	//Giao diện Menu

	//Menu m;
	//m.HomeScreen();
	//_getch();

	//-----------------------------------------------------------------------------------------------------

	//QFloat a;
	//a.ScanQFloat();
	//a.PrintQFloat();
	//_getch();
}
