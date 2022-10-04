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

      std::vector<std::string> posList = StringParser::SeekAndTokenize(line, 'v', ' '); //Isolating Portion of OBJ file which starts with 'v ' 
      std::vector<float> posListFloat;
      StringParser::EliminateLabels(posList, 'v', ' ');                                 //removing the 'v ' labels before data conversion

      for(int i = 0; i < posList.size(); i++){                                          //data conversion
        posListFloat.push_back(std::stof(posList.at(i)));
      }
      for(int i = 0; i < posList.size(); i++){
        std::cout<<posListFloat.at(i)<<std::endl;                                       //debugging output
      }

      std::vector<std::string> normList = StringParser::SeekAndTokenize(line, 'v', 'n');
      std::vector<float> normListFloat;
      StringParser::EliminateLabels(normList, 'v', 'n');

      for(int i = 0; i < normList.size(); i++){
        normListFloat.push_back(std::stof(normList.at(i)));
      }
      for(int i = 0; i < normList.size(); i++){
        std::cout<<normListFloat.at(i)<<std::endl;
      }

      std::vector<std::string> texList = StringParser::SeekAndTokenize(line, 'v', 't');
      std::vector<float> texListFloat;
      StringParser::EliminateLabels(texList, 'v', 't');

      for(int i = 0; i < texList.size(); i++){
        texListFloat.push_back(std::stof(texList.at(i)));
      }
      for(int i = 0; i < texList.size(); i++){
        std::cout<<texListFloat.at(i)<<std::endl;
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