#include "FileManip.h"
#include <fstream>
#include <iostream>
#include <chrono>
#include "QInt.h"
FileManip::FileManip() : type_ { 0 }, base_1_ { 0 }, base_2_ { 0 }, op_ { 0 } {
}
void FileManip::Set(std::string type, int base_1, int base_2, std::string operand_1, std::string op, std::string operand_2) {
  type_ = type;
  base_1_ = base_1;
  base_2_ = base_2;
  operand_1_ = operand_1;
  op_ = op;
  operand_2_ = operand_2;
}
void FileManip::Manip(std::string source, std::string result, std::string type) {
  std::ifstream in_f;
  in_f.open(source);
  std::ofstream out_f;
  out_f.open(result);
  type_ = type;
  while (in_f.peek() != EOF) {
    //auto start = chrono::high_resolution_clock::now();
    Parsing(in_f);
    //auto stop = chrono::high_resolution_clock::now();
    //auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    //cout << "Time taken by parsing: "
    //  << duration.count() << " microseconds" << endl;
    //start = chrono::high_resolution_clock::now();
    out_f << Process() << std::endl;
    //stop = chrono::high_resolution_clock::now();
    //duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    //cout << "Time taken by process: "
    //  << duration.count() << " microseconds" << endl;
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
      if (operand_2_ != "");
        arr_2 = StrBinToArr(operand_2_);
      //Chuyen 2 ve 10
    } else
      if (base_1_ == 10) {
        QInt t1(operand_1_);
        x = t1;
        if (operand_2_ != "") {
          QInt t2(operand_2_);
          y = t2;
        }
      } else {
        //Chuyen 16 ve 10
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
      if (op_ == "+")
        return (x + y).PrintQInt();
      if (op_ == "-")
        return (x - y).PrintQInt();
      if (op_ == "*")
        return (x * y).PrintQInt();
      if (op_ == "/")
        return (x / y).PrintQInt();
      if (op_ == "&") 
        return (x & y).PrintQInt();
      if (op_ == "|")
        return (x | y).PrintQInt();
      if (op_ == "^")
        return (x | y).PrintQInt();
      if (op_ == "~")
        return (~x).PrintQInt();
      int z = StrToInt(operand_2_);
      if (op_ == ">>")
        return (x >> z).PrintQInt();
      if (op_ == "<<")
        return (x << z).PrintQInt();
      if (op_ == "ror")
        return (x.ror(z)).PrintQInt();
      if (op_ == "rol")
        return (x.rol(z)).PrintQInt();
      std::string s;
      if (op_ == "<")
        return s + static_cast<char>((x < y) + '0');
      if (op_ == ">")
        return s + static_cast<char>((x > y) + '0');
      if (op_ == "==")
        return s + static_cast<char>((x == y) + '0');
      if (op_ == ">=")
        return s + static_cast<char>((x >= y) + '0');
      if (op_ == "<=")
        return s + static_cast<char>((x <= y) + '0');
    }
  }
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
  x = new bool[128];
  for (int i = 0; i < s.length(); i++)
    x[i] = s[i];
  return x;
}

std::string ArrBinToStr(bool* b) {
  std::string s;
  for (int i = 0; i < 128; i++)
    s = s + static_cast<char>(b[i] + '0');
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