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
    void kmpMatch(string T, string P);
    int forcaBruta(string T, string P);
    void prefix(string P, vector<int> &pi);

   public:




};

#endif // CASAMENTOPADRAO_H_INCLUDED