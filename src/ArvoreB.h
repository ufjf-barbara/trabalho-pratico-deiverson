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
#define TAMMIN= 200;
using namespace std;

// struct Arvb
// {
//    Arvb *pai; //pt para o nó pai
//     int m;          //quantidade de chaves armazenadas no nó
//     vector<Arvb> chaves;    //array de chaves
//     vector<Arvb> filhos;  //ponteiro para array de ponteiros p/ os filhos

//     string id;
//     string nome;
//     int posicao;
//     Arvb *pai;
//     Arvb *esq;
//     Arvb *dir;
// };
typedef struct arvb {
int ordem;
int elems;
 vector<int> info;
 struct arvb *filhos[TAMMIN];

} Arvb;



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
    ArvoreB(int n,int t);
    ~ArvoreB();
     
    void insercao(Arvb *aux);
    int Busca(Arvb *arvore, int val);
    void imprime();
};

#endif // ARVOREB_H_INCLUDED
