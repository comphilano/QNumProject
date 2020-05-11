#pragma once
#include <string>
#include <vector>
class FileManip {
public:
  FileManip();
  void Manip(std::string, std::string, std::string);
  void Process();
private:
  bool IsOperator(std::string);
  void Reset();
private:
  int type;
  int base_1;
  int base_2;
  std::string operand_1;
  std::string op;
  std::string operand_2;
};

