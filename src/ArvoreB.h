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
//estrutura da chave


struct key
{
    string id;
    string name;
    int posicao;
};

struct NodeB
{
    int m;                 //quantidade de chaves armazenadas no nó
    NodeB *pai;             //ptpara o nó pai
    vector<key *> chaves;  //array de chaves //TAM 2T
    vector<NodeB *> folhas; //ponteiro para array de ponteiros p/ os filhos //TAM 2T+1
    bool folha;            //verifica se o no e folha
};



class ArvoreB
{

private:
    clock_t begin;
    clock_t end;
    clock_t tempoGlob;
    int compI;
    int compGlob;

    NodeB *raiz;
    int t;
    void auxImprime(NodeB *r, string str, bool verifica);
    void auxInsert(NodeB *no, key *val);

    void cisao(NodeB *r);
    int auxBusca(NodeB *no, string val);
    int BuscaIN(NodeB *no, string val);

public:
    ArvoreB(int t);
    ArvoreB();

    void insercao(key *aux);
    void busca(string val);
    void busca();
    void imprime(int pos, bool b);
    void imprime(Node *p);
};

#endif // ARVOREB_H_INCLUDED
