#include "FileManip.h"
#include <fstream>
#include "QFloat.h"
FileManip::FileManip() : type_ { 0 }, base_1_ { 0 }, base_2_ { 0 }, op_ { 0 } {
}
std::string FileManip::Calc(std::string type, int base_1, int base_2, std::string operand_1, std::string op, std::string operand_2) {
  type_ = type;
  base_1_ = base_1;
  base_2_ = base_2;
  operand_1_ = operand_1;
  op_ = op;
  operand_2_ = operand_2;
  return Process();
}
void FileManip::Manip(std::string source, std::string result, std::string type) {
  std::ifstream in_f;
  in_f.open(source);
  std::ofstream out_f;
  out_f.open(result);
  type_ = type;
  while (in_f.peek() != EOF) {
    Parsing(in_f);
    out_f << Process() << std::endl;
  }
  in_f.close();
}

std::string FileManip::Process() {
  if (type_ == "int") {
    QInt x;
    QInt y;
    bool* arr_1;
    bool* arr_2;
    if (base_1_ == 2) {
      arr_1 = StrBinToArr(operand_1_);
      x.BinToDeC(arr_1);
      if (operand_2_ != "") {
        arr_2 = StrBinToArr(operand_2_);
        y.BinToDeC(arr_2);
      }
    } else
      if (base_1_ == 10) {
        QInt t1(operand_1_);
        x = t1;
        if (operand_2_ != "") {
          QInt t2(operand_2_);
          y = t2;
        }
      } else {
        x.HexToDec(operand_1_);
        if (operand_2_ != "") {
          y.HexToDec(operand_2_);
        }
      }
    if (op_ == "") { //Chuyen co so
       if (base_2_ == 10)
         return x.PrintQInt();
       if (base_2_ == 16)
         return x.DecToHex(x);
       else
         return ArrBinToStr(x.DecToBin(x));
    }
    else { //Tinh toan
      QInt temp;
      if (op_ == "+" || op_ == "-" || op_ == "*" || op_ == "/" || op_ == ">>" || op_ == "<<"
          || op_ == "rol" || op_ == "ror" || op_ == "&" || op_ == "|" || op_ == "^" || op_ == "~") {
        if (op_ == "+")
          temp = (x + y);
        if (op_ == "-")
          temp = (x - y);
        if (op_ == "*")
          temp = (x * y);
        if (op_ == "/")
          temp = (x / y);
        if (op_ == "&")
          temp = (x & y);
        if (op_ == "|")
          temp = (x | y);
        if (op_ == "^")
          temp = (x ^ y);
        if (op_ == "~")
          temp = (~x);
        int z = StrToInt(operand_2_);
        if (op_ == ">>")
          temp = (x >> z);
        if (op_ == "<<")
          temp = (x << z);
        if (op_ == "ror")
          temp = (x.ror(z));
        if (op_ == "rol")
          temp = (x.rol(z));
        if (base_1_ == 2)
          return ArrBinToStr(temp.DecToBin(temp));
        else if (base_1_ == 10)
          return temp.PrintQInt();
        else
          return temp.DecToHex(temp);
      } else {
        std::string s;
        if (op_ == "<")
          return s + (static_cast<char>(x < y) ? "true" : "false");
        if (op_ == ">")
          return s + (static_cast<char>(x > y) ? "true" : "false");
        if (op_ == "==")
          return s + (static_cast<char>(x == y) ? "true" : "false");
        if (op_ == ">=")
          return s + (static_cast<char>(x >= y) ? "true" : "false");
        if (op_ == "<=")
          return s + (static_cast<char>(x <= y) ? "true" : "false");
      }
    }
  } else {
    QFloat x;
    QFloat y;
    bool* arr_1;
    bool* arr_2;
    if (base_1_ == 2) {
      arr_1 = StrBinToArr(operand_1_);
      if (operand_2_ != "");
      arr_2 = StrBinToArr(operand_2_);
    } else
      if (base_1_ == 10) {
        //QFloat t1(operand_1_);
        //x = t1;
        //if (operand_2_ != "") {
        //  QFloat t2(operand_2_);
        //  y = t2;
        //}
      }
    if (op_ == "") { //Chuyen co so
      if (base_2_ == 10);
       // return x.PrintQFloat(x);
      else
        return ArrBinToStr(x.DecToBin(x));
    }
  }
  return "";
}

bool IsOperator(std::string o) {
  return o == "+" || o == "-" || o == "*" || o == "/" || o == ">>" || o == "<<"
    || o == "rol" || o == "ror" || o == "&" || o == "|" || o == "^" || o == "<"
    || o == ">" || o == ">=" || o == "<=" || o == "==";
}

void FileManip::Reset() {
  base_1_ = 0;
  base_2_ = 0;
  operand_1_ = "";
  op_ = "";
  operand_2_ = "";
}

void FileManip::Parsing(std::ifstream& in_f) {
  Reset();
  in_f >> base_1_;
  std::streampos pos = in_f.tellg();
  in_f >> operand_1_;
  if (operand_1_ == "~") {
    op_ = "~";
    in_f >> operand_1_;
  } else {
    in_f >> op_;
    if (IsOperator(op_))
      in_f >> operand_2_;
    else {
      op_ = "";
      in_f.seekg(pos);
      in_f >> base_2_;
      in_f >> operand_1_;
    }
  }
}

bool* StrBinToArr(std::string s) {
  bool* x;
  x = new bool[s.length()];
  for (int i = 0; i < s.length(); i++)
    x[i] = (s[i] - '0');
  return x;
}

std::string ArrBinToStr(bool* b) {
  std::string s;
  bool flag = false;
  for (int i = 0; i < 128; i++) {
    if (b[i] == 1)
      flag = true;
    if (flag)
      s = s + static_cast<char>(b[i] + '0');
  }
  return s;
}

int StrToInt(std::string s) {
  int j = 1;
  int res = 0;
  for (int i = s.length() - 1; i >= 0; i--) {
    res += (s[i] - '0') * j;
    j *= 10;
  }
  return res;
}

void XuLiCMD(int argc, char* argv[]) {
  if (argc == 4) {
    std::string file_1(argv[1]);
    std::string file_2(argv[2]);
    std::string type(argv[3]);
    FileManip x;
    if (type == "1")
      type = "int";
    else
      type = "float";
    x.Manip(file_1, file_2, type);
    std::cout << "Done!";
  } else if (argc > 1 && argc < 4)
    cout << "Thieu tham so";
}