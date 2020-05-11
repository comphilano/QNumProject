#include "QInt.h"
#include "QFloat.h"
#include "Menu.h"
#include <Windows.h>
#include<conio.h>
#include "FileManip.h"
void main()
{
  FileManip x;
  x.Manip("d:\\alo.txt", "d:\\nac.txt", "int");
  //cout << StrToInt("6969");
  //QInt y("-873129580771448538940058586182283");
  //cout << ArrBinToStr(y.DecToBin(y));
}