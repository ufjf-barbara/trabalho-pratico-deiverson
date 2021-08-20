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
static int trocas = 0;

int Compara(string str1, string str2);
key *divide(NodeB *um, NodeB *dois, int t);

ArvoreB::ArvoreB()
{
    raiz = NULL;
    this->t = 50;

    int tam = Artists::getTAM();
    vector<int> vet;

    for (int i = 0; i < tam; i++)
    {
        vet.push_back(i);
    }
    random_shuffle(vet.begin(), vet.end());

    clock_t begin = clock();
    for (int i = 0; i < tam; i++)
    {
        key *aux = new key();
        artists art = Artists::reg(vet[i]);
        aux->name = art.name;
        aux->posicao = vet[i];
        aux->id = art.id;
        insercao(aux);
    }
    clock_t end = clock();
    cout << "\nINSERCAO CONCLUIDA COM SUCESSO" << endl;
    cout << "\ntempo insercao:\t" << (end - begin) / ((float)CLOCKS_PER_SEC) << endl;
}

ArvoreB::ArvoreB(int t)
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

    clock_t begin = clock();
    for (int i = 0; i < tam; i++)
    {
        key *aux = new key();
        artists art = Artists::reg(vet[i]);
        aux->name = art.name;
        aux->posicao = vet[i];
        aux->id = art.id;
        insercao(aux);
    }
    clock_t end = clock();
    cout << "\nINSERCAO CONCLUIDA COM SUCESSO" << endl;
    cout << "\ntempo insercao:\t" << (end - begin) / ((float)CLOCKS_PER_SEC) << endl;
    busca();
}

//função para inserir NÓ na arvore

void ArvoreB::insercao(key *p)
{
    if (raiz == NULL)
    {
        raiz = new NodeB();
        raiz->pai = NULL;
        raiz->folha = true;
        raiz->m = 1;
        raiz->folhas.resize(2 * t + 1, NULL);
        raiz->chaves.push_back(p);
        raiz->chaves.resize(2 * t - 1, NULL);
    }
    else
    {
        auxInsert(raiz, p);
    }
}

//função auxiliar para inserir NÓ na arvore

void ArvoreB::auxInsert(NodeB *no, key *k)
{
    //caso base , de ser uma folha
    if (no->folha)
    {
        int aqui = 0;
        for (int i = 0; no->chaves[i] != NULL; i++)
        {

            if (Compara(k->name, no->chaves[i]->name) < 0)
            {
                no->chaves.insert(no->chaves.begin() + i, k);
                no->chaves.resize(2 * t, NULL);
                no->m++;
                if (no->m == 2 * t)
                    cisao(no);
                return;
            }
            aqui = i + 1;
        }
        no->chaves.insert(no->chaves.begin() + aqui, k);
        no->chaves.resize(2 * t, NULL);
        no->m++;
        if (no->m == 2 * t)
            cisao(no);
    }
    else //caso de ser um no
    {
        int aqui = 0;
        for (int i = 0; i < no->m; i++)
        {
            if (Compara(k->name, no->chaves[i]->name) < 0)
            {
                auxInsert(no->folhas[i], k);
                return;
            }
            aqui = i + 1;
        }
        auxInsert(no->folhas[aqui], k);
    }
}

void ArvoreB::busca(string val)
{
    int i = BuscaIN(this->raiz, val);
    if (i == -1)
    {
        cout << "Artista nao encontrado" << endl;
        return;
    }
    NodeB *aux = new NodeB();
    artists art = Artists::reg(i);
    cout << "\nArtista:\t" << art.name << endl
         << "Followers:\t" << art.followers << endl
         << "Genres:\t" << art.genres << endl
         << "Id:\t" << art.id << endl
         << "Popularity:\t" << art.popularity << endl;
}

int ArvoreB::BuscaIN(NodeB *no, string val)
{
    int aux = 0;

    if (no->folha)
    {
        int aqui = 0;
        for (int i = 0; no->chaves[i] != NULL; i++)
        {
            aux = Compara(val, no->chaves[i]->name);
            if (aux == 0)
            {
                return no->chaves[i]->posicao;
            }
        }
        return -1;
    }
    else //caso de ser um no
    {
        int aqui = 0;
        for (int i = 0; i < no->m; i++)
        {
            aux = Compara(val, no->chaves[i]->name);
            if (aux <= 0)
            {
                if (aux == 0)
                {
                    return no->chaves[i]->posicao;
                }
                auxBusca(no->folhas[i], val);
            }
            aqui = i + 1;
        }
        auxBusca(no->folhas[aqui], val);
    }
    return -1;
}

void ArvoreB::busca()
{

    int tam = Artists::getTAM();
    vector<int> vet;

    for (int i = 0; i < tam; i++)
    {
        vet.push_back(i);
    }
    random_shuffle(vet.begin(), vet.end());

    ofstream saida("saida.txt", ios::out | ios::app);

    saida << "\n-------------------------------------------------------------------------------------------------------\n";
    saida << "ARVORE B " << endl;
    saida << "MINIMO DE CHAVES POR NO:\t" << t << endl;
    saida << "\n-------------------------------------------------------------------------------------------------------\n";

    saida.close();

    for (int i = 0; i < 100; i++)
    {
        NodeB *aux = new NodeB();
        artists art = Artists::reg(vet[i]);
        begin = clock();
        compI = 0;
        auxBusca(this->raiz, art.name);
        imprime(i, true);
    }
}

int ArvoreB::auxBusca(NodeB *no, string val)
{
    int aux = 0;

    if (no->folha)
    {
        int aqui = 0;
        for (int i = 0; no->chaves[i] != NULL; i++)
        {
            aux = Compara(val, no->chaves[i]->name);
            compI++;
            if (aux == 0)
            {
                return no->chaves[i]->posicao;
                imprime(no->chaves[i]->posicao, false);
            }
        }
        return -1;
    }
    else //caso de ser um no
    {
        int aqui = 0;
        for (int i = 0; i < no->m; i++)
        {
            aux = Compara(val, no->chaves[i]->name);
            compI++;
            if (aux <= 0)
            {
                compI++;
                if (aux == 0)
                {
                    return no->chaves[i]->posicao;
                    imprime(no->chaves[i]->posicao, false);
                }
                auxBusca(no->folhas[i], val);
            }
        }
        auxBusca(no->folhas[aqui], val);
    }
    return -1;
}

void ArvoreB::imprime(int pos, bool b)
{
    ofstream saida("saida.txt", ios::out | ios::app);
    if (b)
    {
        saida << "\n-------------------------------------------------------------------------------------------------------\n";
        saida << "Tempo medio:\t" << tempoGlob / 100 << " segundos" << endl;
        saida << "Media de comparaçoes:\t" << compGlob / 100 << endl;
        saida << "\n-------------------------------------------------------------------------------------------------------\n";

        saida.close();
        return;
    }
    compGlob += compI;
    clock_t end = clock();
    tempoGlob += ((end - begin) / ((float)CLOCKS_PER_SEC));
    artists art = Artists::reg(pos);
    saida << "\n-------------------------------------------------------------------------------------------------------\n"
          << "Artista:\t" << art.name << endl
          << "Followers:\t" << art.followers << endl
          << "Genres:\t" << art.genres << endl
          << "Id:\t" << art.id << endl
          << "Popularity:\t" << art.popularity << endl
          << "\nTempo da busca:\t" << (end - begin) / ((float)CLOCKS_PER_SEC) << " segundos" << endl
          << "Numero de comparacoes:\t" << compI << endl;
    compI = 0;
}

void ArvoreB::cisao(NodeB *no) //overvlow apenas
{
    if (no->pai == NULL)
    {
        Comparacoes++;

        NodeB *dad = new NodeB();
        NodeB *bro = new NodeB();

        key *k = divide(no, bro, t);

        dad->chaves.push_back(k);

        no->pai = dad;
        bro->pai = dad;
        bro->chaves.resize(2 * t, NULL);

        if (no->folha)
            bro->folha = true;

        dad->folhas.push_back(no);
        dad->folhas.push_back(bro);

        dad->folhas.resize(2 * t + 1, NULL);
        dad->chaves.resize(2 * t, NULL);
        dad->chaves.shrink_to_fit();

        dad->folha = false;
        raiz = dad;

        trocas++;
    }
    else
    {
        NodeB *bro = new NodeB();

        key *k = divide(no, bro, t);
        NodeB *pai = no->pai;
        bro->chaves.resize(2 * t, NULL);
        int tam = pai->m;

        if (no->folha)
            bro->folha = true;

        bro->pai = no->pai;
        //        no->pai->chaves.capacity();
        for (int i = 0; i <= pai->m; i++)
        {

            Comparacoes++;

            // cout<< k->name << "---" << pai->chaves[i]->name <<endl;

            if (Compara(k->name, pai->chaves[i]->name) < 0)
            {
                pai->chaves.insert(pai->chaves.begin() + i, k);
                pai->folhas[i] = bro;
                pai->chaves.resize(2 * t, NULL);
                pai->chaves.shrink_to_fit();
                break;
            }
        }
        Comparacoes++;
        if (pai->chaves[tam] && Compara(k->name, pai->chaves[tam]->name) > 0)
        {
            pai->chaves.insert(pai->chaves.end(), k);
            pai->folhas[pai->folhas.size()] = bro;

            pai->chaves.resize(2 * t, NULL);
        }
        if (pai->m == 2 * t)
        {
            trocas++;
            cisao(pai);
        }
    }
}

key *divide(NodeB *um, NodeB *dois, int t)
{
    key *k = new key();
    k = um->chaves[t];
    int aqui;

    for (int i = t + 1; i < 2 * t; i++)
    {
        dois->chaves.push_back(um->chaves[i]);
        aqui = i + 1;
    }
    dois->folhas.push_back(um->folhas[aqui]);
    if (!um->folha)
    {

        for (int i = 0; i < t; i++)
        {
            dois->folhas.push_back(um->folhas[i + t]);
        }
        for (int i = 0; i <= t; i++)
        {

            um->folhas.pop_back();
        }

        um->folhas.resize(2 * t + 1, NULL);
    }

    for (int i = 0; i < t; i++)
    {
        um->chaves[i + t] = NULL;
    }
    um->m = t;
    dois->m = t;

    return k;
}

/*
void ArvoreB::imprime()
{

}
*/
