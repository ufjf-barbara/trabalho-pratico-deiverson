#include "Artists.h"
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
#include "ArvoreB.h"
#include <utility>

using namespace std;

ArvoreB::ArvoreB()
{
    raiz = NULL;
}

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
        aux->nome = art.name;
        aux->posicao = vet[n];
        aux->id = art.id;
        Insert(aux);
    }
}

void Insert(key *val)
{
    // int aux = raiz.getSizeKeys();
    // if (aux = 0)
    // {
    //     raiz->chaves.push_back(val);
    //     return;
    // }
    auxinsert(raiz, val);
}

void auxInsert(NodeArvB *no, key *val)
{
    int aux = no.getSizeKeys();
    if (aux < O)
    {
        if (aux == 0)
            no->chaves.push_back(val);
        else
        {
            
            for (int i = 0; i < no->chaves.size(); i++)
            {
                if (i == 0 && Compara(val->name, no->chaves[i]->name) < 0)
                {
                    no->chaves.insert(i, val);
                    break;
                }
                else if (i != 0 && Compara(val->name, no->chaves[i - 1]->name) > 0 &&
                         Compara(val->name, no->chaves[i]->name) < 0)
                {
                    no->chaves.insert(i, val);
                    break;
                }
            }
        }
        return;
    }
    int i = 0;
    while (no->chaves[i] != NULL)
    {
        if (i = 0)
        {
            auxinsert(no->folhas[i], val);
            break;
        }
        else if (Compara(val->name, no->chaves[i]->name) > 0 &&
                 Compara(val->name, no->chaves[i + 1]->name) < 0)
        {
            auxinsert(no->folhas[i], val);
            break;
        }
        else if (i == no.getSizeKeys() && Compara(val->name, no->chaves[i]->name) > 0)
        {
            auxinsert(no->folhas[i], val);
            break;
        }
        else
            i++;
    }
}

bool ArvoreB::busca(string val)
{
    return auxBusca(this->raiz, val);
}

bool ArvoreB::auxBusca(NodeArvB *p, string val)
{
    int nivel = 1, i = 0;
    string valor = val; //mudar para o artists
    NodeArvB *aux;
    if (aux == NULL)
    {
        return 0;
    }
    while (nivel)
    {
        while ((aux-> < valor) && (i < aux->elems))
        {
            i++;
            if ((aux->info[i] == valor) && (i < aux->elems))
                return (nivel);
            else
            {
                if (aux->filhos[i] != NULL)
                {

                    aux = aux->filhos[i];
                    i = 0;
                    nivel++;
                    else
                    {
                        return 0;
                    }
                }
            }
        }
        return 0;
    }

    // bool ArvoreB::auxBusca(NodeArvB *p, string val)
    // {
    //     if (p == NULL)
    //         return false;
    //     else if (p->nome == val)
    //         return true;
    //     else if (Compara(p->nome, val))
    //         return auxBusca(p->esq, val);
    //     else
    //         return auxBusca(p->dir, val);
    // }

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