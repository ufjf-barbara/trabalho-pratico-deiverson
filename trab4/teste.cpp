#include <iostream>
#include <map>
#include <stdio.h>
#include <queue>
#include <vector>
#include <sstream>
#include <fstream>
#include <time.h>
#include <utility>
#include <string>
#include "huffman.h"
#include "CasamentoPadrao.h"

int main()
{
    int x = 1;

    ifstream dna;
    ifstream Padrao;
    clock_t begin;
    clock_t end;

    string T;
    string P;
    string str;
    stringstream ss;

    int cont = 2;
    dna.open("./dna1.txt");
    Padrao.open("./padrao" + to_string(cont) + ".txt");

    getline(dna, str);
    getline(dna, str);
    while (getline(dna, str))
    {

        for (char c : str)
        {
            if (c == 'a' || c == 'c' || c == 't' || c == 'g')
                T += c;
        }
    }
    getline(Padrao, str);
    getline(Padrao, str);
    str = "";

    while (getline(Padrao, str))
    {

        for (char c : str)
        {
            if (c == 'a' || c == 'c' || c == 't' || c == 'g')
                P += c;
        }
    }

    std::size_t found = T.find(P);

    if (found != std::string::npos)
        cout << "funcao : " << found << endl;

    cout << T.length() << " dna" << endl;
    cout << P.length() << " Padroes" << endl;

    // T = "ABACATEABAFABAFO";
    // P = "ABA";

    begin = clock();

    CasamentoPadrao::kmpMatch(T, P);

    end = clock();

    cout << "Custo computational de " << (end - begin) / ((float)CLOCKS_PER_SEC) << " segundos" << endl;
    cont++;

    begin = clock();
    CasamentoPadrao::forcaBruta(T, P);
    end = clock();
    cout << "Custo computational de " << (end - begin) / ((float)CLOCKS_PER_SEC) << " segundos" << endl;

    P = "";
    return 0;
}