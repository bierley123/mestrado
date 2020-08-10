#include "Circuito.h"
#include "windows.h"
Circuito::~Circuito()
{
}

Circuito::Circuito()
{
}

std::string Circuito::parseCircuit(std::map<std::string, std::string> argumento, int linha, std::string argC, int qtd_TOKEN)
{
    parser parserOBJ;
    std::string status = "ok";
    std::string token0 = argumento["token0"];
    if (token0[0] == 'R')
        status = parserOBJ.resistor(argumento, linha, argC, qtd_TOKEN);
    else if (token0[0] == 'C')
        status = parserOBJ.capacitor(argumento, linha, argC, qtd_TOKEN);
    else if (token0[0] == 'L')
        status = parserOBJ.inductor(argumento, linha, argC, qtd_TOKEN);
    else if (token0[0] == 'V' || token0[0] == 'I')
        status = parserOBJ.sourceVI(argumento, linha, argC, qtd_TOKEN); //Independent Sources(Voltage - V) (Current - I)
    else if (token0[0] == 'G' || token0[0] == 'E')
        status = parserOBJ.sourceGE(argumento, linha, argC, qtd_TOKEN); //Linear Voltage-Controlled Current Sources(G)
                                                                        //Linear Voltage-Controlled Voltage Sources(E)
    else if (token0[0] == 'F' || token0[0] == 'H')
        status = parserOBJ.sourceFH(argumento, linha, argC, qtd_TOKEN); //Linear Current-Controlled Current Sources(F)
                                                                        //Linear Current-Controlled Voltage Sources(H)
    else if (token0[0] == 'D')
        status = parserOBJ.junctionDiode(argumento, linha, argC, qtd_TOKEN);
    else if (token0[0] == 'Q')
        status = parserOBJ.bjt(argumento, linha, argC, qtd_TOKEN);
    else if (token0[0] == 'J')
        status = parserOBJ.jfet(argumento, linha, argC, qtd_TOKEN);
    else if (token0[0] == 'M')
        status = parserOBJ.mosfet(argumento, linha, argC, qtd_TOKEN);
    else if (token0 == ".SUBCKT")
        status = parserOBJ.subckt(argumento, linha, argC, qtd_TOKEN, &stackSUBCKT);
    else if (token0 == ".ENDS")
        status = parserOBJ.ends(argumento, linha, argC, qtd_TOKEN, &stackSUBCKT);
    else if (token0[0] == 'X')
        status = parserOBJ.subcktCALL(argumento, linha, argC, qtd_TOKEN);
    else if (token0 == ".END")
        status = parserOBJ.end(argumento, linha, argC, qtd_TOKEN, &cktChaveFecha);
    else if (token0 == ".OPTIONS")
        status = parserOBJ.options(argumento, linha, argC, qtd_TOKEN);
    else if (token0 == ".NODESET")
        status = parserOBJ.nodeset(argumento, linha, argC, qtd_TOKEN);
    else if (token0 == ".IC")
        status = parserOBJ.ic(argumento, linha, argC, qtd_TOKEN);
    else if (token0 == ".AC")
        status = parserOBJ.ac(argumento, linha, argC, qtd_TOKEN);
    else if (token0 == ".DC")
        status = parserOBJ.dc(argumento, linha, argC, qtd_TOKEN);
    else if (token0 == ".PZ")
        status = parserOBJ.pz(argumento, linha, argC, qtd_TOKEN);
    else if (token0 == ".SENS")
        status = parserOBJ.sens(argumento, linha, argC, qtd_TOKEN);
    else if (token0 == ".TF")
        status = parserOBJ.tf(argumento, linha, argC, qtd_TOKEN);
    else if (token0 == ".TRAN")
        status = parserOBJ.tran(argumento, linha, argC, qtd_TOKEN);
    else if (token0 == ".PRINT")
        status = parserOBJ.print(argumento, linha, argC, qtd_TOKEN);
    else if (token0[0] == '*' || qtd_TOKEN == 0 || token0 == ".SAVE")
    { /* DO NOTHING */
    }
    else
    {
        status = "(path_UNDEFINED) line " + std::to_string(linha + 1) + ":\n" + argC + "\n^\n";
    }
    return status;
}

void Circuito::setLine_from_ckt(std::string argumento)
{
    oDisplay_aux = argumento;
    //esse for separa a sentença em tokens e verifica se os parenteses estao corretos
    for (int lcount = 0; lcount < oDisplay_aux.length(); lcount++)
    {
        if (oDisplay_aux[lcount] == '=' || oDisplay_aux[lcount] == ',')
        {
            tokens[token_NUM + std::to_string(token_NUM_var)] = oDisplay_aux[lcount];
            token_NUM_var++;
            oDisplayRegistry = "";
            lcount++;
        }

    AQUI:
        if (oDisplay_aux[lcount] != ' ' && oDisplay_aux[lcount] != '\t')
        {
            while (((oDisplay_aux[lcount] != ' ' && oDisplay_aux[lcount] != '\t') && (lcount) < oDisplay_aux.length()))
            {
                if (oDisplay_aux[lcount] == '(' && token_NUM_var > 0)
                {
                    parentheses.push(lcount);
                    lcount++;
                    if (oDisplayRegistry == "")
                    {
                        //std::cout<<"\nentrou 1"<<std::endl;
                        //std::cout<<oDisplayRegistry<<std::endl;
                        //oDisplayRegistry = "";
                        goto AQUI;
                    }
                    else
                    {
                        goto fimWhile;
                    }
                }
                else if (oDisplay_aux[lcount] == ')' && token_NUM_var > 0)
                {
                    if (parentheses.empty())
                    {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, 12); //to Red
                        std::string parserError = "parserError:";
                        std::cout << parserError;
                        SetConsoleTextAttribute(hConsole, 7); //back to white
                        throw std::string("line " + std::to_string(linha + 1) +
                                          " column " + std::to_string(oDisplay_aux.find(')') + 1) +
                                          ". Invalid argument:\n" + oDisplay_aux + "\n\nerror on parentheses syntax.");
                    }
                    parentheses.pop();
                    lcount++;
                    if (oDisplayRegistry == "")
                    {
                        //std::cout<<"\nentrou 1"<<std::endl;
                        //std::cout<<oDisplayRegistry<<std::endl;
                        //oDisplayRegistry = "";
                        goto AQUI;
                    }
                    else
                    {
                        goto fimWhile;
                    }
                }
                else if (oDisplay_aux[lcount] == '=' || oDisplay_aux[lcount] == ',')
                {
                    if (oDisplayRegistry != "")
                    {
                        tokens[token_NUM + std::to_string(token_NUM_var)] = oDisplayRegistry;
                        token_NUM_var++;
                        oDisplayRegistry = "";
                        //lcount++;
                    }
                    else
                    {

                        tokens[token_NUM + std::to_string(token_NUM_var)] = oDisplay_aux[lcount];
                        token_NUM_var++;
                        oDisplayRegistry = "";
                        lcount++;
                        goto AQUI;
                    }
                }
                else
                {
                    oDisplayRegistry += oDisplay_aux[lcount];
                    lcount++;
                }
            }
        fimWhile:
            tokens[token_NUM + std::to_string(token_NUM_var)] = oDisplayRegistry;
            token_NUM_var++;
            oDisplayRegistry = "";
            blockToken = true;
        }
    }
    /*for(std::map<std::string,std::string>::const_iterator it = tokens.begin();it != tokens.end(); ++it)
    {
        std::cout << it->first << " " << it->second<< "\n";
    }*/
    if (!parentheses.empty()) // Verifica se a pilha dos parenteses está vazia.
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "parserError: ";
        SetConsoleTextAttribute(hConsole, 7);
        throw std::string("line " + std::to_string(linha + 1) +
                          " column " + std::to_string(oDisplay_aux.find('(') + 1) +
                          ". Invalid argument:\n" + oDisplay_aux + "\n\nerror on parentheses syntax.");
    }
    if (parseCircuit(tokens, linha, oDisplay_aux, token_NUM_var) != "ok")
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "parserError:";
        SetConsoleTextAttribute(hConsole, 7);
        std::cout << parseCircuit(tokens, linha, oDisplay_aux, token_NUM_var);
    }
    token_NUM_var = 0;
    linha++;
    tokens.clear();
}

void Circuito::runFile(std::string filename)
{
    this->filename = filename;
    std::string oDisplay_input = "";
    std::ifstream openedFile(this->filename);

    getline(openedFile, oDisplay_input); //TITLE
    system("cls");
    std::cout<<filename<<std::endl;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 6);//amarelo
    std::cout << oDisplay_input << std::endl;
    SetConsoleTextAttribute(hConsole, 7);//branco
    getline(openedFile, oDisplay_input);
    try
    {
        while (!openedFile.fail())
        {
            this->setLine_from_ckt(oDisplay_input);
            getline(openedFile, oDisplay_input);
        }
        if(cktChaveFecha)
        {
            SetConsoleTextAttribute(hConsole, 12);//vermelho
            std::cout<<"parseError:";
            SetConsoleTextAttribute(hConsole, 7);//branco
            std::cout<<"Missing argument '.END'."<<std::endl;
            SetConsoleTextAttribute(hConsole, 9);//azul
            std::cout<<"\nYou must end the circuit.";
            SetConsoleTextAttribute(hConsole, 7);//branco
        }
    }
    catch (std::string msg)
    {
        std::cout << msg << std::endl;
    }
    openedFile.close();
}