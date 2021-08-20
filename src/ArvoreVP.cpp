#include "ArvoreVP.h"
#include "Artists.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int Compara(string str1, string str2);

ArvoreVp::ArvoreVp()
{
    raiz = NULL;

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
        Node *aux = new Node();
        artists art = Artists::reg(vet[i]);
        aux->nome = art.name;
        aux->posicao = vet[i];
        aux->id = art.id;
        aux->color = NEGRO;
        aux->esq = NULL;
        aux->dir = NULL;
        aux->pai = NULL;

        insercao(aux);
    }
    clock_t end = clock();
    cout << "\ntempo insercao:\t" << (end - begin) / ((float)CLOCKS_PER_SEC) << endl;
}

ArvoreVp::ArvoreVp(int n)
{
    raiz = NULL;

    int tam = Artists::getTAM();
    vector<int> vet;

    for (int i = 0; i < tam; i++)
    {
        vet.push_back(i);
    }
    random_shuffle(vet.begin(), vet.end());

    clock_t begin = clock();
    for (int i = 0; i < n; i++)
    {
        Node *aux = new Node();
        artists art = Artists::reg(vet[i]);
        aux->nome = art.name;
        aux->posicao = vet[n];
        aux->id = art.id;
        aux->color = NEGRO;
        aux->esq = NULL;
        aux->dir = NULL;
        aux->pai = NULL;

        insercao(aux);
    }
    clock_t end = clock();
    cout << "\ntempo insercao:\t" << (end - begin) / ((float)CLOCKS_PER_SEC) << endl;
    cout << qtdd(raiz) << endl;
    cout << n << endl;
}

//algoritmo de inserção
void ArvoreVp::insercao(Node *no)
{

    no->color = RUBRO;

    Node *y = NULL;
    Node *x = this->raiz;

    while (x != NULL)
    {
        y = x;
        int a = Compara(no->nome, x->nome);
        if (a >= NEGRO)
        {
            x = x->dir;
        }
        else
        {
            x = x->esq;
        }
    }

    no->pai = y;
    if (y == NULL)
    {
        raiz = no;
    }
    else if (Compara(no->nome, y->nome) < NEGRO)
    {
        y->esq = no;
    }
    else
    {
        y->dir = no;
    }

    if (no->pai == NULL)
    {
        raiz->color = NEGRO;
        return;
    }

    if (no->pai->pai == NULL)
    {
        return;
    }
    Balanceamento(no);
}

void ArvoreVp::Balanceamento(Node *p)
{
    Node *u; //uncle
    while (p->pai && p->pai->color == RUBRO && p->color == RUBRO)
    {
        if (p->pai->pai && p->pai == p->pai->pai->dir)
        {
            u = p->pai->pai->esq;
            if (u && u->color == RUBRO)
            {
                u->color = NEGRO;
                p->pai->color = NEGRO;
                p->pai->pai->color = RUBRO;
                p = p->pai->pai;
            }
            else
            {
                if (p == p->pai->esq)
                {
                    rightRotate(p);

                    leftRotate(p);
                    if (p->pai)
                    {
                        p = p->pai;
                        p->color = NEGRO;
                        if (p->dir)
                            p->dir->color = RUBRO;
                        if (p->esq)
                            p->esq->color = RUBRO;
                    }
                    else
                    {
                        raiz = p;
                        break;
                    }
                }
                else
                {
                    leftRotate(p->pai);
                    p = p->pai;
                    p->color = NEGRO;
                    if (p->esq)
                        p->esq->color = RUBRO;
                    p->dir->color = RUBRO;
                }
            }
        }
        else if (p->pai->pai && p->pai == p->pai->pai->esq)
        {
            u = p->pai->pai->dir;

            if (u && u->color == RUBRO)
            {
                u->color = NEGRO;
                p->pai->color = NEGRO;
                p->pai->pai->color = RUBRO;
                p = p->pai->pai;
            }
            else
            {
                if (p == p->pai->dir)
                {
                    leftRotate(p);

                    rightRotate(p);
                    if (p->pai)
                    {
                        p = p->pai;
                        p->color = NEGRO;
                        if (p->esq)
                            p->esq->color = RUBRO;
                        if (p->dir)
                            p->dir->color = RUBRO;
                    }
                    else
                    {
                        raiz = p;
                        break;
                    }
                }
                else
                {
                    rightRotate(p->pai);
                    p = p->pai;
                    p->color = NEGRO;
                    p->esq->color = RUBRO;
                    if (p->dir)
                        p->dir->color = RUBRO;
                }
            }
        }
        else
        {
        }
        if (p == raiz)
        {
            break;
        }
    }
    if (p->pai == NULL)
        raiz = p;
    raiz->color = NEGRO;
}

//rotação para direita

void ArvoreVp::rightRotate(Node *pai)
{
    Node *p = pai->esq;
    Node *avo = pai->pai;
    Node *aux = pai->dir;

    pai->dir = avo;
    if (avo)
    {
        avo->esq = aux;
        if (avo->pai)
        {
            if (avo->pai->dir == avo)
                avo->pai->dir = pai;
            else
                avo->pai->esq = pai;
        }
        pai->pai = avo->pai;
        avo->pai = pai;
    }
    if (aux)
        aux->pai = avo;
}

//rotação para esquerda

void ArvoreVp::leftRotate(Node *pai)
{
    Node *p = pai->dir;
    Node *avo = pai->pai;
    Node *aux = pai->esq;

    pai->esq = avo;
    if (avo)
    {

        avo->dir = aux;
        if (avo->pai)
        {
            if (avo->pai->dir == avo)
                avo->pai->dir = pai;
            else
                avo->pai->esq = pai;
        }
        pai->pai = avo->pai;
        avo->pai = pai;
    }
    if (aux)
        aux->pai = avo;
}

//busca

void ArvoreVp::busca(string str)
{
    int i = buscaIn(this->raiz, str);
    if (i == -1)
    {
        cout << "Artista nao encontrado" << endl;
        return;
    }
    Node *aux = new Node();
    artists art = Artists::reg(i);
    cout << "\nArtista:\t" << art.name << endl
         << "Followers:\t" << art.followers << endl
         << "Genres:\t" << art.genres << endl
         << "Id:\t" << art.id << endl
         << "Popularity:\t" << art.popularity << endl;
}

int ArvoreVp::buscaIn(Node *p, string str)
{
    if (p == NULL)
        return -1;

    if (p->nome == str)
    {
        compI++;
        return p->posicao;
    }
    else if (Compara(str, p->nome) < 0)
    {
        compI += 2;
        return buscaIn(p->esq, str);
    }
    else
    {
        compI += 3;
        return buscaIn(p->dir, str);
    }
}

void ArvoreVp::busca()
{

    int tam = Artists::getTAM();
    vector<int> vet;

    for (int i = 0; i < tam; i++)
    {
        vet.push_back(i);
    }
    random_shuffle(vet.begin(), vet.end());

    ofstream saida("../print/saida.txt", ios::out | ios::app);
    saida << "\n-------------------------------------------------------------------------------------------------------\n";
    saida << "ARVORE RUBRO/NEGRO" << endl;
    saida << "\n-------------------------------------------------------------------------------------------------------\n";

    saida.close();

    for (int i = 0; i < 100; i++)
    {
        Node *aux = new Node();
        artists art = Artists::reg(vet[i]);
        begin = clock();
        compI;
        auxBusca(this->raiz, art.name);
    }
    imprime(0, true);
}

int ArvoreVp::auxBusca(Node *p, string val)
{
    if (p == NULL)
        return -1;

    if (p->nome == val)
    {
        compI++;
        imprime(p->posicao, false);
        return p->posicao;
    }
    else if (Compara(val, p->nome) < 0)
    {
        compI += 2;
        return auxBusca(p->esq, val);
    }
    else
    {
        compI += 3;
        return auxBusca(p->dir, val);
    }
}

void ArvoreVp::imprime(int pos, bool b)
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

void ArvoreVp::imprime()
{
    if (raiz)
    {
        auxImprime(this->raiz, "", true);
    }
}

void ArvoreVp::auxImprime(Node *r, string str, bool verifica)
{
    if (r != NULL)
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
        string Color;
        if (r->color == RUBRO)
            Color = "Rubro";
        else
            Color = "Negro";

        cout << r->nome << "(" << Color << ")" << endl;
        auxImprime(r->esq, str, false);
        auxImprime(r->dir, str, true);
    }
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

int ArvoreVp::qtdd(Node *no)
{
    if (no == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + qtdd(no->esq) + qtdd(no->dir);
    }
}