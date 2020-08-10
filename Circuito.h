//=============================================Circuito.h
#include <iostream>
#include <fstream>
#include <map>
#include <stack>
#include <fstream>
#include "parser.h"

class Circuito
{
private:
  std::string filename;
  std::string oDisplay_aux;
  std::string oDisplay = "";
  std::string oDisplayRegistry = "";
  std::map<std::string, std::string> tokens;
  std::string token_NUM = "token"; //nome de um token : token_NUM+token_NUM_var : token0,token1,token2...
  int token_NUM_var = 0;           //-------------^
  std::stack<int> parentheses;
  
  int linha = 1;
  int stackSUBCKT=0;
  bool blockToken = true;
  std::string statusLine; //status retornado pelo parsing

  //ifstream openedFile()

public:
  Circuito();
  ~Circuito();
  bool cktChaveFecha = true;
  void runFile(std::string filename);
  void setLine_from_ckt(std::string lineInput);
  std::string parseCircuit(std::map<std::string, std::string> argumento, int linha, std::string argC, int qtd_TOKEN);
};
