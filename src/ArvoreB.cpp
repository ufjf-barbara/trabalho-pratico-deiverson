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

ArvoreB::ArvoreB(int n)
{
    raiz = NULL;

    int tam = Artists::getTAM();
    vector<int> vet;
    for (int i = 0; i < tam; i++)
    {
        vet.push_back(i);
    }
    random_shuffle(vet.begin(), vet.end());

    for (int i = 0; i < n; i++)
    {
        NodeArvB *aux = new NodeArvB();
        artists art = Artists::reg(vet[i]);
        aux->m = 0;
        aux->nome = art.name;
        aux->posicao = vet[n];
        aux->id = art.id;
        aux->aux->folha = NULL;
        aux->esq = NULL;
        aux->dir = NULL;
        aux->pai = NULL;
    }

    bool ArvoreB::busca(string val)
    {
        return auxBusca(this->raiz, val);
    }

    TNo *auxBusca(TNo * no, int ch)
    {
        if (no != NULL)
        {
            int i = 0;
            while (i < no->m && ch > no->s[i])
            {
                i++;
            }
            if (i < no->m && ch == no->s[i])
            {
                return no; // encontrou chave
            }
            else if (no->p[i] != NULL)
            {
                return busca(no->p[i], ch);
            }
            else
                return no; //nó era folha -- não existem mais
            nós a buscar, então retorna o nó onde a chave deveria estar
        }
        else
            return NULL; //nó é NULL, não há como buscar
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

    int ArvoreB::Compara(string str1, string str2)
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
