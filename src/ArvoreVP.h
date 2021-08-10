#include "Artists.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <ctime>
#include <algorithm>

#include <utility>

#ifndef ARVOREVP_H_INCLUDED
#define ARVOREVP_H_INCLUDED

using namespace std;

struct Node
{
    string id;
    string nome;
    int posicao;
    Node *pai;
    Node *esq;
    Node *dir;
    int color;
}

class ArvoreVp
{

private:
    Node *raiz;
    Node *aux;

public:
    ArvoreVp();
    ArvoreVp(int n);
    void insercao(Node* aux);
    void insercaoBalanceado();
    void busca(int val);
}

#endif // ARVOREVP_H_INCLUDED