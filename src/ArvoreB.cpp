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
        if (no->chaves.size() == 0)
        {
            no->chaves.insert(no->chaves.begin(), k);
            return;
        }
        else
        {
            int tam = no->chaves.size();
            for (int i = 0; i < tam; i++)
            {
                if (i == 0 && Compara(k->name, no->chaves[i]->name) < 0)
                {
                    no->chaves.insert(no->chaves.begin(), k);
                    no->folhas.insert(no->folhas.begin(), new NodeArvB());
                    no->folhas.insert(no->folhas.begin() + 1, new NodeArvB());
                    //if cisao
                    return;
                }
                else if (Compara(k->name, no->chaves[i - 1]->name) > 0 && Compara(k->name, no->chaves[i]->name) < 0)
                {
                    no->chaves.insert(no->chaves.begin() + i, k);
                    no->folhas.insert(no->folhas.begin() + i + 1, new NodeArvB());
                    //if cisao
                    return;
                }
                else
                {
                    no->chaves.insert(no->chaves.end(), k);
                    no->folhas.insert(no->folhas.end(), new NodeArvB());
                    //if cisao
                    return;
                }
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
            else if (Compara(k->name, no->chaves[i]->name) > 0 &&
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

NodeArvB *ArvoreB::busca(NodeArvB *p, NodeArvB *node)
{

    NodeArvB *aux;
    aux = busca(raiz, node);

    if (aux == NULL)
    {
        return NULL;
    }
    else
    {
        int i = 0;
        while ((i < (aux->m)) && (aux->chaves[i]->id < node->chaves[i]->id))
        {
            Comparacoes++;
            i++;
        }
        if (aux->m > i)
        {
            if (aux->chaves[i]->id == p->chaves[i]->id)
            {
                Comparacoes++;
                return aux;
            }
        }
        return NULL;
    }
}

//função para comparar os valores das strings

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

