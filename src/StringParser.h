#pragma once
#include <vector>
#include <string>

class StringParser{
public:
  static std::vector<std::string> Tokenize(std::string const& text, std::string const& separator);
  static std::vector<std::string> SeekAndTokenize(std::string line, char a, char b);
  static void EliminateLabels(std::vector<std::string>& List, char a, char b);
};