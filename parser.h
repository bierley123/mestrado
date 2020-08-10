#include <iostream>
#include <map>
#include <stack>
#include <fstream>
#include <list>
class parser
{
private:
    /* data */
    std::list<std::string> optionsList;
public:
    parser(/* args */);
    ~parser();
    void errorPointer(std::map<std::string, std::string> tokens, int linha, std::string argumento, std::string generalForm, std::string currentToken, std::string msgErro);
    void floatValidator_wSymbol(std::string value,std::map<std::string,std::string> tokens, int linha, std::string argumento, std::string generalForm, std::string currentToken);
    void intValidator(std::string value,std::map<std::string,std::string> tokens, int linha, std::string argumento, std::string generalForm, std::string currentToken);
    

    std::string resistor(std::map<std::string,std::string> tokens, int linha, std::string argumento, int qtd_TOKEN);
    std::string capacitor(std::map<std::string,std::string> tokens, int linha, std::string argumento, int qtd_TOKEN);
    std::string inductor(std::map<std::string,std::string> tokens, int linha, std::string argumento, int qtd_TOKEN);
    std::string sourceVI(std::map<std::string,std::string> tokens, int linha, std::string argumento, int qtd_TOKEN);
    std::string sourceFH(std::map<std::string,std::string> tokens, int linha, std::string argumento, int qtd_TOKEN);
    std::string sourceGE(std::map<std::string,std::string> tokens, int linha, std::string argumento, int qtd_TOKEN);
    std::string junctionDiode(std::map<std::string,std::string> tokens, int linha, std::string argumento, int qtd_TOKEN);
    std::string bjt(std::map<std::string,std::string> tokens, int linha, std::string argumento, int qtd_TOKEN);
    std::string jfet(std::map<std::string,std::string> tokens, int linha, std::string argumento, int qtd_TOKEN);
    std::string mosfet(std::map<std::string,std::string> tokens, int linha, std::string argumento, int qtd_TOKEN);
    
    std::string options(std::map<std::string,std::string> tokens, int linha, std::string argumento, int qtd_TOKEN);
    std::string nodeset(std::map<std::string,std::string> tokens, int linha, std::string argumento, int qtd_TOKEN);
    std::string ic(std::map<std::string,std::string> tokens, int linha, std::string argumento, int qtd_TOKEN);
    std::string ac(std::map<std::string,std::string> tokens, int linha, std::string argumento, int qtd_TOKEN);
    std::string dc(std::map<std::string,std::string> tokens, int linha, std::string argumento, int qtd_TOKEN);
    std::string pz(std::map<std::string,std::string> tokens, int linha, std::string argumento, int qtd_TOKEN);
    std::string sens(std::map<std::string,std::string> tokens, int linha, std::string argumento, int qtd_TOKEN);
    std::string tf(std::map<std::string,std::string> tokens, int linha, std::string argumento, int qtd_TOKEN);
    std::string tran(std::map<std::string,std::string> tokens, int linha, std::string argumento, int qtd_TOKEN);
    //save
    std::string print(std::map<std::string,std::string> tokens, int linha, std::string argumento, int qtd_TOKEN);

    //subckt
    std::string subckt(std::map<std::string,std::string> tokens, int linha, std::string argumento, int qtd_TOKEN,  int *stackSUBCKT);
    std::string ends(std::map<std::string, std::string> tokens, int linha, std::string argumento, int qtd_TOKEN,  int *stackSUBCKT);
    std::string subcktCALL(std::map<std::string,std::string> tokens, int linha, std::string argumento, int qtd_TOKEN);
    std::string end(std::map<std::string, std::string> tokens, int linha, std::string argumento, int qtd_TOKEN,  bool *cktChaveFecha);
};

