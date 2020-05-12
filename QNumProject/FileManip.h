#pragma once
#include <string>
#include <vector>
class FileManip {
public:
  FileManip();
  std::string Calc(std::string type, int base_1, int base_2, std::string operand_1, std::string op, std::string operand_2);
  //Xu li file
  void Manip(std::string source, std::string des, std::string type);
  //Tinh toan
  std::string Process();
private:
  void Reset();
  //Lay du lieu tu file
  void Parsing(std::ifstream& in_f);
private:
  std::string type_;
  int base_1_;
  int base_2_;
  std::string operand_1_;
  std::string op_;
  std::string operand_2_;
};
//Chuyen string thanh int
int StrToInt(std::string);
//Kiem tra toan tu (ko tinh NOT)
bool IsOperator(std::string);
//Chuyen chuoi bit thanh mang bit
bool* StrBinToArr(std::string);
//Chuyen mang bit thanh chuoi bit
std::string ArrBinToStr(bool*, bool keep_zero = 0);
//Xu li tham so dong lenh
void XuLiCMD(int argc, char* argv[]);