#pragma once
#include <vector>
#include <string>

class StringParser{
public:
  static std::vector<std::string> Tokenize(std::string const& text, std::string const& separator);
  static std::vector<std::string> SeekAndTokenize(std::string line, char* cline, char a, char b);
};