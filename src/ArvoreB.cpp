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
static int trocas=0;

int Compara(string str1, string str2);
key *divide(Node *um, Node *dois, int t);

ArvoreB::ArvoreB()
{
    raiz = NULL;
    this->t = 4;

    int tam = Artists::getTAM();
    vector<int> vet;

    for (int i = 0; i < tam; i++)
    {
        vet.push_back(i);
    }
    random_shuffle(vet.begin(), vet.end());

    clock_t begin = clock();
    for (int i = 0; i < 20; i++)
    {
        key *aux = new key();
        artists art = Artists::reg(vet[i]);
        aux->name = art.name;
        aux->posicao = vet[i];
        aux->id = art.id;
        insercao(aux);
    }
    clock_t end = clock();
    cout << "\ntempo insercao:\t" << (end - begin) / ((float)CLOCKS_PER_SEC) << endl;
}

//função para inserir NÓ na arvore

void ArvoreB::insercao(key *p)
{
    if (raiz == NULL)
    {
        raiz = new Node();
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

void ArvoreB::auxInsert(Node *no, key *k)
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
                if (no->chaves.size() ==( 2 * this->t))
                    cisao(no);
                    imprime(no);
                return;
            }
            else if (Compara(k->name, no->chaves[i - 1]->name) > 0 && Compara(k->name, no->chaves[i]->name) < 0)
            {
                no->chaves.insert(no->chaves.begin() + i, k);
                if (no->chaves.size() == 2 * t)
                    cisao(no);
                    imprime(no);
                return;
            }
            else
            {
                no->chaves.insert(no->chaves.end(), k);
                if (no->chaves.size() == 2 * t)
                    cisao(no);
                    imprime(no);
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
            else if ( no->chaves[i + 1] != NULL && Compara(k->name, no->chaves[i]->name) > 0 &&
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
void ArvoreB::busca()
{

    int tam = Artists::getTAM();
    vector<int> vet;

    for (int i = 0; i < tam; i++)
    {
        vet.push_back(i);
    }
    random_shuffle(vet.begin(), vet.end());

    ofstream saida("../print/saida.txt", ios::out | ios::trunc);
    saida.close();

    for (int i = 0; i < 100; i++)
    {
        Node *aux = new Node();
        artists art = Artists::reg(vet[i]);
        // begin = clock();
        auxBusca(this->raiz, art.name);
    }
      imprime(0, true);
}
int ArvoreB::auxBusca(Node *no, string val)
{
    int tam = no->chaves.size();
    for (int i = 0; i < tam; i++)
    {
        if (no->chaves[i]->name == val)
            return no->chaves[i]->posicao;
        else if (no->chaves[i - 1] && Compara(val, no->chaves[i - 1]->name) > 0 && Compara(val, no->chaves[i]->name) < 0)
            return auxBusca(no->folhas[i], val);
    }
    return -1;
}



void ArvoreB::imprime(int pos, bool b)
{
    ofstream saida("../print/saida.txt", ios::out | ios::app);
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


void ArvoreB::cisao(Node *no) //overvlow apenas
{
    if (no->pai == NULL)
    {
        Comparacoes++;

        Node *dad;
        Node *bro;

        key *k = divide(no, bro, t);

        dad->chaves.push_back(k);

        no->pai = dad;
        bro->pai = dad;

        dad->folhas.push_back(no);
        dad->folhas.push_back(bro);
        dad->folha = false;
        raiz = dad;

        trocas++;
    }
    else
    {
        Node *bro;

        key *k = divide(no, bro, t);
        bro->pai = no->pai;

        int tam = no->pai->chaves.size();

        for (int i = 0; i < tam; i++)
        {

            if (no->chaves[i + 1] && Compara(k->name, no->pai->chaves[i]->name) > 0 && Compara(k->name, no->pai->chaves[i + 1]->name) < 0)
            {
                no->pai->chaves.insert(no->pai->chaves.begin() + i, k);
                no->pai->folhas.insert(no->pai->folhas.begin() + i, bro);
                Comparacoes++;
            }
        }
        if (no->pai->chaves.size() == 2 * t)
        {
            cisao(no->pai);
            trocas++;
        }
    }
}

key *divide(Node *um, Node *dois, int t)
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


void ArvoreB::imprime(Node *p)
{
    if(p==NULL)
    {
        cout<<"invalido"<<endl;
    }
    else
    {
        cout<<"chaves: ";
        for(int i=0;i<p->chaves.size();i++)
        {
            cout<<p->chaves[i]<<" ";
        }
        cout<<endl;
    }
}
