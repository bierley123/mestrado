//============================================================================//

// The MIT License (MIT)

// Copyright (c) GABRIEL TEIXEIRA ANDRADE SOUSA

//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.
//============================================================================//
//g++ main.cpp parser.cpp parser.h Circuito.cpp Circuito.h -std=c++11
// The MIT

#include <iostream>
#include "Circuito.h"
#include <fstream>
#include "windows.h"
#include <chrono>
#include <locale.h>
int main(void)
{
    setlocale(LC_ALL, "Portuguese");
   // std::string filename = "C:\\Users\\Gabriel\\Documents\\Dev\\exemplo.ckt"; //Input is the adress of the ckt file
   // std::cout << filename << std::endl;
    std::string filename = "C:\\Users\\Gabriel\\Documents\\Dev\\IniciacaoCientifica\\Parser\\parsersourcecodeparaapresentao_\\TE_v0.3.ckt";
    
    float somador1=0;
    float somador2=0;
    float somador3=0;
    float somador4=0;
    float somador5=0;
    float somador6=0;
    float somador7=0;
    float somador8=0;
    float somador9=0;
    float somador10=0;
   // filename = "C:\\Users\\Gabriel\\Documents\\Dev\\exemplo.ckt";
    Circuito mainCKT;
    mainCKT.runFile(filename);
    /*for (int i = 0; i < 5; i++)//1
    {
        auto start = std::chrono::high_resolution_clock::now();
        Circuito mainCKT;
        mainCKT.runFile(filename);
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        somador1 = somador1 + elapsed.count();
    }
    somador1 = somador1/5;
    filename = "C:\\Users\\Gabriel\\Documents\\Dev\\exemplo2.ckt";
    for (int i = 0; i < 5; i++)//2
    {
        auto start = std::chrono::high_resolution_clock::now();
        Circuito mainCKT;
        mainCKT.runFile(filename);
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        somador2 = somador2 + elapsed.count();
    }
    somador2 = somador2/5;
    filename = "C:\\Users\\Gabriel\\Documents\\Dev\\exemplo3.ckt";
    for (int i = 0; i < 5; i++)//3
    {
        auto start = std::chrono::high_resolution_clock::now();
        Circuito mainCKT;
        mainCKT.runFile(filename);
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        somador3 = somador3 + elapsed.count();
    }
    somador3 = somador3/5;
    filename = "C:\\Users\\Gabriel\\Documents\\Dev\\exemplo4.ckt";
    for (int i = 0; i < 5; i++)//4
    {
        auto start = std::chrono::high_resolution_clock::now();
        Circuito mainCKT;
        mainCKT.runFile(filename);
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        somador4 = somador4 + elapsed.count();
    }
    somador4 = somador4/5;
    filename = "C:\\Users\\Gabriel\\Documents\\Dev\\exemplo5.ckt";
    for (int i = 0; i < 5; i++)//5
    {
        auto start = std::chrono::high_resolution_clock::now();
        Circuito mainCKT;
        mainCKT.runFile(filename);
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        somador5 = somador5 + elapsed.count();
    }
    somador5 = somador5/5;
    filename = "C:\\Users\\Gabriel\\Documents\\Dev\\exemplo6.ckt";
    for (int i = 0; i < 5; i++)//6
    {
        auto start = std::chrono::high_resolution_clock::now();
        Circuito mainCKT;
        mainCKT.runFile(filename);
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        somador6 = somador6 + elapsed.count();
    }
    somador6 = somador6/5;
    filename = "C:\\Users\\Gabriel\\Documents\\Dev\\exemplo7.ckt";
    for (int i = 0; i < 5; i++)//7
    {
        auto start = std::chrono::high_resolution_clock::now();
        Circuito mainCKT;
        mainCKT.runFile(filename);
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        somador7 = somador7 + elapsed.count();
    }
    somador7 = somador7/5;
    filename = "C:\\Users\\Gabriel\\Documents\\Dev\\exemplo8.ckt";
    for (int i = 0; i < 5; i++)//8
    {
        auto start = std::chrono::high_resolution_clock::now();
        Circuito mainCKT;
        mainCKT.runFile(filename);
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        somador8 = somador8 + elapsed.count();
    }
    somador8 = somador8/5;
    filename = "C:\\Users\\Gabriel\\Documents\\Dev\\exemplo9.ckt";
    for (int i = 0; i < 5; i++)//9
    {
        auto start = std::chrono::high_resolution_clock::now();
        Circuito mainCKT;
        mainCKT.runFile(filename);
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        somador9 = somador9 + elapsed.count();
    }
    somador9 = somador9/5;
    filename = "C:\\Users\\Gabriel\\Documents\\Dev\\exemplo10.ckt";
    for (int i = 0; i < 5; i++)//10
    {
        auto start = std::chrono::high_resolution_clock::now();
        Circuito mainCKT;
        mainCKT.runFile(filename);
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        somador10 = somador10 + elapsed.count();
    }
    somador10 = somador10/5;
    
    std::cout << "Elapsed time 010K: " << somador1 << " s\n";
    std::cout << "Elapsed time 020K: " << somador2 << " s\n";
    std::cout << "Elapsed time 030K: " << somador3 << " s\n";
    std::cout << "Elapsed time 040K: " << somador4 << " s\n";
    std::cout << "Elapsed time 050K: " << somador5 << " s\n";
    std::cout << "Elapsed time 060K: " << somador6 << " s\n";
    std::cout << "Elapsed time 070K: " << somador7 << " s\n";
    std::cout << "Elapsed time 080K: " << somador8 << " s\n";
    std::cout << "Elapsed time 090K: " << somador9 << " s\n";
    std::cout << "Elapsed time 100K: " << somador10 << " s\n";
    */

    return 0;
}
