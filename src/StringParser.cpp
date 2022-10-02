#include "StringParser.h"

std::vector<std::string> StringParser::Tokenize(std::string const& text, std::string const& separator)
{
    std::vector<std::string> result;
    std::string tmp = text;

    size_t first_pos = 0;
    size_t second_pos = tmp.find(separator);

    while (second_pos != std::string::npos)
    {
        if (first_pos != second_pos)
        {
            std::string word = tmp.substr(first_pos, second_pos - first_pos);
            result.push_back(word);
        }
        tmp = tmp.substr(second_pos + separator.length());
        second_pos = tmp.find(separator);
    }

    result.push_back(tmp);

    return result;
}

std::vector<std::string> StringParser::SeekAndTokenize(std::string line, char* cline, char a, char b){
  std::vector<std::string> List;

  if(cline[0]==a && cline[1]==b){
    List = StringParser::Tokenize(line, " ");
  }
  return List;
}