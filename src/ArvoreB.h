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

typedef struct NodeArvB
{
    int m;                     //quantidade de chaves armazenadas no nó
    NodeArvB *pai;            //ptpara o nó pai
    vector<key> chaves;        //array de chaves
    vector<NodeArvB *> folhas; //ponteiro para array de ponteiros p/ os filhos

    int getSizeKeys() {return chaves.size();}

};

struct key
{
    string id;
    string nome;
    int posicao;
};

class ArvoreB
{

private:
    NodeArvB *raiz;
    int O;
    int t;
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
