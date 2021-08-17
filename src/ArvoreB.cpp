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
#include <ArvoreB.h>
#include <utility>
#include <ArvoreVP.h>

using namespace std;

ArvoreB::ArvoreB()
{
    raiz = NULL;
}

ArvoreB::ArvoreB(int ordem, int t)
{
    raiz = NULL;
    this->t = t;
    int tam = Artists::getTAM();
    vector<int> vet;
    for (int i = 0; i < tam; i++)
    {
        vet.push_back(i);
    }
    random_shuffle(vet.begin(), vet.end());

    for (int i = 0; i < n; i++)
    {
        Arvb *aux= new Arvb();
        artists art = Artists::reg(vet[i]);

        
        aux->nome = art.name;
        aux->posicao = vet[n];
        aux->id = art.id;

        // aux->esq = NULL;
        // aux->dir = NULL;
        // aux->pai = NULL;
    }
}
// bool ArvoreB::Busca(string val)
// {
//     return auxBusca(this->raiz, val);
// }

// NodeArvB *auxBusca(NodeArvB *no, int ch)
// {
//     if (no != NULL)
//     {
//         int i = 0;
//         while (i < no->m && ch > no->s[i])
//         {
//             i++;
//         }
//         if (i < no->m && ch == no->s[i])
//         {
//             return no; // encontrou chave
//         }
//         else if (no->p[i] != NULL)
//         {
//             return Busca(no->p[i], ch);
//         }
//         else
//             return no; //nó era folha -- não existem mais
//         // nós a Buscar, então retorna o nó onde a chave deveria estar
//     }
//     else
//         return NULL; //nó é NULL, não há como Buscar
// }

// int Compara(string str1, string str2)
// {
//     int aux;
//     if (str1.length() <= str2.length())
//         aux = str1.length();
//     else
//         aux = str2.length();

//     int resultado = strncmp(str1.c_str(), str2.c_str(), aux);
//     if (resultado > 0)
//         return 1;
//     else if (resultado == 0)
//         return 0;
//     else
//         return -1;
// }

int ArvoreB::Busca(Arvb *arvore, int val)
{
    int nivel = 1, i = 0;
    int valor = val; //mudar para o artists
    Arvb *aux;
    if (aux == NULL)
    {
        return 0;
    }
    while (nivel)
    {
        while ((aux->info[i] < valor) && (i < aux->elems))
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
            no->chaves.insert(val);
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