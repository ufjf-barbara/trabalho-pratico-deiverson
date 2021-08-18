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

#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED

#define TAMMIN = 200;
using namespace std;

struct NodeArvB
{
    int m;                     //quantidade de chaves armazenadas no nó
    NodeArvB *pai;             //ptpara o nó pai
    vector<key *> chaves;      //array de chaves //TAM 2T
    vector<NodeArvB *> folhas; //ponteiro para array de ponteiros p/ os filhos //TAM 2T+1
    bool folha;
};

struct key
{
    string id;
    string name;
    int posicao;
};

class ArvoreB
{

private:
    NodeArvB *raiz;
    int O;
    int t;
    void auxImprime(NodeArvB *r, string str, bool verifica);
    //bool auxBusca(NodeArvB *p, string val);
    int Compara(string str1, string str2);
    void auxInsert(NodeArvB *no, key *val);
    void auxImprime(NodeArvB *r, string str, bool verifica);

public:
    ArvoreB();
    ArvoreB(int n);

    void insercao(key *aux);
    NodeArvB *busca(NodeArvB *p, NodeArvB *node);
    void imprime();
};

#endif // ARVOREB_H_INCLUDED