#include "Artists.h"
#include "ArvoreB.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <math.h>
#include <ctime>
#include <algorithm>
#include <utility>

using namespace std;

static int Comparacoes = 0;

//construtor padrao

ArvoreB::ArvoreB()
{
    raiz = NULL;
}

//Construtor de inserção

ArvoreB::ArvoreB(int n)
{
    raiz = NULL;
    this->O = 90;

    int tam = Artists::getTAM();
    vector<int> vet;

    for (int i = 0; i < tam; i++)
    {
        vet.push_back(i);
    }
    random_shuffle(vet.begin(), vet.end());

    for (int i = 0; i < n; i++)
    {
        key *aux = new key();
        artists art = Artists::reg(vet[i]);
        aux->name = art.name;
        aux->posicao = vet[n];
        aux->id = art.id;
        insercao(aux);
    }
}

//função para inserir NÓ na arvore

void ArvoreB::insercao(key *p)
{
    if (raiz == NULL)
    {
        raiz = new NodeArvB();
        raiz->pai = NULL;
        raiz->folha = true;
        raiz->m = 1;
        raiz->chaves.push_back(p);
    }
    else
    {
        auxInsert(raiz, p);
    }
}

//função auxiliar para inserir NÓ na arvore

void ArvoreB::auxInsert(NodeArvB *no, key *k)
{
    //caso base , de ser uma folha
    if (no->folha)
    {
        int tam = no->chaves.size();
        for (int i = 0; i < tam; i++)
        {
            if (i == 0 && Compara(k->name, no->chaves[i]->name) < 0)
            {
                no->chaves.insert(no->chaves.begin(), k);
                if (no->chaves.size() == 2 * t)
                    cisao(no);
                return;
            }
            else if (Compara(k->name, no->chaves[i - 1]->name) > 0 && Compara(k->name, no->chaves[i]->name) < 0)
            {
                no->chaves.insert(no->chaves.begin() + i, k);
                if (no->chaves.size() == 2 * t)
                    cisao(no);
                return;
            }
            else
            {
                no->chaves.insert(no->chaves.end(), k);
                if (no->chaves.size() == 2 * t)
                    cisao(no);
                return;
            }
        }

        return;
    }
    else //caso de ser um no
    {
        int tam = no->chaves.size();
        for (int i = 0; i < tam; i++)
        {
            if (i == 0 && Compara(k->name, no->chaves[i]->name) < 0)
            {
                auxInsert(no->folhas[i], k);
                return;
            }
            else if (i + 1 != NULL && Compara(k->name, no->chaves[i]->name) > 0 &&
                     Compara(k->name, no->chaves[i + 1]->name) < 0)
            {
                auxInsert(no->folhas[i], k);
                return;
            }
            else if (i == no->chaves.size() && Compara(k->name, no->chaves[i]->name) > 0)
            {
                auxInsert(no->folhas[i + 1], k);
                return;
            }
        }
    }
}

int ArvoreB::busca(NodeArvB *no, string val)
{
    int tam = no->chaves.size();
    for (int i = 0; i < tam; i++)
    {
        if (no->chaves[i]->name == val)
            return no->chaves[i]->posicao;
        else if (no->chaves[i - 1] && Compara(val, no->chaves[i - 1]->name) > 0 && Compara(val, no->chaves[i]->name) < 0)
            return busca(no->folhas[i], val);
    }
    return -1;
}

//função para comparar os valores das strings

/*
void ArvoreB::imprime()
{
    if (raiz)
    {
        auxImprime(this->raiz, "", true);
    }
}

void ArvoreB::auxImprime(NodeArvB *p, string str, bool verifica)
{
    if (p != NULL)
    {
        cout << str;
        if (verifica)
        {
            cout << "R----";
            str += "   ";
        }
        else
        {
            cout << "L----";
            str += "|  ";
        }

        for(int i=0;i<p->m;i++)
        {
          cout << " " <<p->chaves[i]->id;
        }
        
        auxImprime(p->, str, false);
        auxImprime(p->, str, true);
    }
}
*/

void ArvoreB::cisao(NodeArvB *no) //overvlow apenas
{
    if (no->pai == NULL)
    {
        NodeArvB *dad;
        NodeArvB *bro;

        key *k = divide(no, bro, t);

        dad->chaves.push_back(k);

        no->pai = dad;
        bro->pai = dad;

        dad->folhas.push_back(no);
        dad->folhas.push_back(bro);
        dad->folha = false;
        raiz = dad;
    }
    else
    {
        NodeArvB *bro;

        key *k = divide(no, bro, t);
        bro->pai = no->pai;

        int tam = no->pai->chaves.size();

        for (int i = 0; i < tam; i++)
        {

            if (no->chaves[i + 1] && Compara(k->name, no->pai->chaves[i]->name) > 0 && Compara(k->name, no->pai->chaves[i + 1]->name) < 0)
            {
                no->pai->chaves.insert(no->pai->chaves.begin() + i, k);
                no->pai->folhas.insert(no->pai->folhas.begin() + i, bro);
            }
        }
        if (no->pai->chaves.size() == 2 * t)
        {
            cisao(no->pai);
        }
    }
}

key *divide(NodeArvB *um, NodeArvB *dois, int t)
{
    key *k;
    for (int i = t; i <= 2 * t; i++)
    {
        if (i == t + 1)
            k = um->chaves[i];
        else
            dois->chaves.push_back(um->chaves[i]);
    }
    for (int i = 2 * t; i >= t; i--)
    {
        um->chaves.pop_back();
    }
    return k;
}

int Compara(string str1, string str2)
{
    int aux;
    if (str1.length() <= str2.length())
        aux = str1.length();
    else
        aux = str2.length();

    int resultado = strncmp(str1.c_str(), str2.c_str(), aux);
    if (resultado > 0)
        return 1;
    else if (resultado == 0)
        return 0;
    else
        return -1;
}