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

struct Node
{
    int m;                     //quantidade de chaves armazenadas no nó
    Node *pai;             //ptpara o nó pai
    vector<key *> chaves;      //array de chaves //TAM 2T
    vector<Node *> folhas; //ponteiro para array de ponteiros p/ os filhos //TAM 2T+1
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
    Node *raiz;
    int t;
    void auxImprime(Node *r, string str, bool verifica);
    //bool auxBusca(Node *p, string val);
    int Compara(string str1, string str2);
    void auxInsert(Node *no, key *val);
    void auxImprime(Node *r, string str, bool verifica);
    void cisao(Node *r);
    int auxBusca(Node *no, string val);

public:
    ArvoreB();
    ArvoreB(int n);

    void insercao(key *aux);
    void busca();
    void imprime();
};

#endif // ARVOREB_H_INCLUDED