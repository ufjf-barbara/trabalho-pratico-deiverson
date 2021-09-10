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
    int cont = 1;
    clock_t begin;
    clock_t end;

    string T;
    string P;
    string str;
    stringstream ss;

    dna.open("./dna1.txt");
    getline(dna, str);
    getline(dna, str);
    while (getline(dna, str))
    {
        T += str;
    }
    Padrao.open("./padrao" + to_string(cont) + ".txt");
    getline(Padrao, str);
    getline(Padrao, str);

    while (getline(Padrao, str))
    {
        P += str;
    }
    cout << P.length() << " Padroes" << endl;

    begin = clock();
    CasamentoPadrao::forcaBruta(T, P);
    end = clock();

    cout << "Custo computational de " << (end - begin) / ((float)CLOCKS_PER_SEC) << " segundos" << endl;
    cont++;
    P = "";
    return 0;
}