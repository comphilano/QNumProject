#include "FileManip.h"
#include <fstream>
#include <iostream>
FileManip::FileManip() : type { 0 }, base_1 { 0 }, base_2 { 0 }, op { 0 } {
}
void FileManip::Manip(std::string source, std::string result, std::string type) {
  std::ifstream in_f;
  in_f.open(source);
  while (in_f.peek() != EOF) {
    Reset();
    in_f >> base_1;
    std::streampos pos = in_f.tellg();
    in_f >> operand_1;
    if (operand_1 == "~") {
      op = "~";
      in_f >> operand_1;
    } else {
      in_f >> op;
      if (IsOperator(op))
        in_f >> operand_2;
      else {
        op = "";
        in_f.seekg(pos);
        in_f >> base_2;
        in_f >> operand_1;
      }
    }
  }
  in_f.close();
}

void FileManip::Process() {
}

bool FileManip::IsOperator(std::string o) {
  return o == "+" || o == "-" || o == "*" || o == "/" || o == ">>" || o == "<<"
    || o == "rol" || o == "ror" || o == "&" || o == "|" || o == "^" || o == "<"
    || o == ">" || o == ">=" || o == "<=" || o == "==";
}

void FileManip::Reset() {
  type = 0;
  base_1 = 0;
  base_2 = 0;
  operand_1 = "";
  op = "";
  operand_2 = "";
}
