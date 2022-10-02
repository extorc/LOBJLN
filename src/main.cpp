#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "StringParser.h"

int main () {
  std::string line;
  std::ifstream myfile ("../test.obj");
  if (myfile.is_open())
  {
    while ( std::getline (myfile,line) )
    {
      char *cline = &line[0];


      std::vector<std::string> posList = StringParser::SeekAndTokenize(line, cline, 'v', ' ');
      for(std::string s : posList){
        std::cout<<s;
      }

      std::vector<std::string> normList = StringParser::SeekAndTokenize(line, cline, 'v', 'n');
      for(std::string s : normList){
        std::cout<<s;
      }

      std::vector<std::string> texList = StringParser::SeekAndTokenize(line, cline, 'v', 't');
      for(std::string s : texList){
        std::cout<<s;
      }

      std::vector<std::string> funcList;

      if(cline[0]=='f'){
        funcList = StringParser::Tokenize(line, " ");
        for(std::string s : funcList){
          std::cout<<s;
        }
        std::cout<<'\n';
      }
    }
    myfile.close();
  }

  else std::cout << "Unable to open file"; 

  return 0;
}