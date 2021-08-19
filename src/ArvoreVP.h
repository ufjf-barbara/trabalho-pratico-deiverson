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

#define NEGRO 0
#define RUBRO 1
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
};

class ArvoreVp
{

private:
    clock_t begin;
    clock_t end;
    clock_t tempoGlob;
    int compI;
    int compGlob;

    Node *raiz;
    void auxImprime(Node *r, string str, bool verifica);
    int auxBusca(Node *p, string val);
    void insercao(Node *aux);
    void Balanceamento(Node *p);
    void rightRotate(Node *no);
    void leftRotate(Node *no);
    void imprime(int pos, bool b);
    // int Compara(string str1, string str2);
    int buscaIn(Node* p,string str);

public:
    ArvoreVp();
    ArvoreVp(int n);
    void busca();
    void busca(string str);
    void imprime();
    int qtdd(Node *no);
};

#endif // ARVOREVP_H_INCLUDED
