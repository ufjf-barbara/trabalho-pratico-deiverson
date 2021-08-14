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

using namespace std;

typedef struct NodeArvB
{
    
   int m; //quantidade de chaves armazenadas no nó
    struct No *pai; //pt para o nó pai
    int *chaves; //array de chaves
    struct No **p; //ponteiro para array de ponteiros p/ os filhos


    string id;
    string nome;
    int posicao;
    NodeArvB *pai;
    NodeArvB *esq;
    NodeArvB *dir;
}TNo;

class ArvoreB
{

private:
    NodeArvB *raiz;

    void auxImprime(NodeArvB *r, string str, bool verifica);
    bool auxBusca(NodeArvB *p, string val);
    int Compara(string str1, string str2);

public:
    ArvoreB();
    ArvoreB(int n);

    void insercao(NodeArvB *aux);
    bool busca(string val);
    void imprime();
};

#endif // ARVOREB_H_INCLUDED
