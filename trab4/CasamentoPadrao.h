#include <map>
#include <stdio.h>
#include <queue>
#include <vector>
#include <fstream>
#include <time.h>

#ifndef CASAMENTOPADRAO_H_INCLUDED
#define CASAMENTOPADRAO_H_INCLUDED

using namespace std;

class CasamentoPadrao
{
private:
    void prefix(string P, vector<int> &pi);
    void prefixBMH(string P, int *pi);

public:
    void kmpMatch(string T, string P);
    int forcaBruta(string T, string P);
    void BMH(string T, string P);
};

#endif // CASAMENTOPADRAO_H_INCLUDED