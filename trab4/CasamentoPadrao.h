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
    static void prefix(string P, vector<int> &pi);
    static void prefixBMH(string P, int *pi);

public:
    static void kmpMatch(string T, string P);
    static void forcaBruta(string T, string P);
    static void BMH(string T, string P);
};

#endif // CASAMENTOPADRAO_H_INCLUDED