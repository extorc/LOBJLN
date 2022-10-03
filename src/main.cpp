#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "StringParser.h"
#include<cstring>

int main () {
  std::string line;
  std::ifstream myfile ("../test.obj");
  if (myfile.is_open())
  {
    while ( std::getline (myfile,line) )
    {
      char *cline = &line[0];


      std::vector<std::string> posList = StringParser::SeekAndTokenize(line, 'v', ' ');
      StringParser::EliminateLabels(posList, 'v', ' ');

      for(int i = 0; i < posList.size(); i++){
        std::cout<<posList.at(i)<<std::endl;
      }

      std::vector<std::string> normList = StringParser::SeekAndTokenize(line, 'v', 'n');
      StringParser::EliminateLabels(normList, 'v', 'n');

      for(int i = 0; i < normList.size(); i++){
        std::cout<<normList.at(i)<<std::endl;
      }

      std::vector<std::string> texList = StringParser::SeekAndTokenize(line, 'v', 't');
      StringParser::EliminateLabels(texList, 'v', 't');

      for(int i = 0; i < texList.size(); i++){
        std::cout<<texList.at(i)<<std::endl;
      }

      std::vector<std::string> funcList = StringParser::SeekAndTokenize(line, 'f', ' ');
      StringParser::EliminateLabels(funcList, 'f', ' ');

      for(int i = 0; i < funcList.size(); i++){
        std::cout<<funcList.at(i)<<std::endl;
      }
    }
    myfile.close();
  }

  else std::cout << "Unable to open file"; 

  return 0;
}