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
#include <ArvoreVP.h>
#include <utility>

#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED

#define TAMMIN = 200;
using namespace std;



// typedef struct arvb
// {
//     int ordem;
//     int elems;
//     vector<int> info;
//     struct arvb *filhos[TAMMIN];

//     string id;
//     string nome;
//     int posicao;

// } Arvb;
typedef struct NodeArvB
{
    int m;                     //quantidade de chaves armazenadas no nó
    struct No *pai;            //pt para o nó pai
    list<key> chaves;        //array de chaves
    list<NodeArvB *> folhas; //ponteiro para array de ponteiros p/ os filhos

    int getSizeKeys() return chaves.size();

} TNo;

struct key
{
    string id;
    string nome;
    int posicao;
};

class ArvoreB
{

private:
    Arvb *raiz;

    void auxImprime(Arvb *r, string str, bool verifica);
    bool auxBusca(Arvb *p, string val);
    int N; //quantidade máxima por nó
    int t; //quantidade mínima de por nó

public:
    ArvoreB();
    ArvoreB(int n, int t);
    ~ArvoreB();

    void insercao(Arvb *aux);
    int Busca(Arvb *arvore, int val);
    void imprime();
};

#endif // ARVOREB_H_INCLUDED
