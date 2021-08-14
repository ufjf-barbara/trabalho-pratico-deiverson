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
#include <utility>

using namespace std;

ArvoreVp::ArvoreVp()
{
    raiz = NULL;
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

    for (int i = 0; i < n; i++)
    {
        Node *aux = new Node();
        artists art = Artists::reg(vet[i]);
        aux->nome = art.name;
        aux->posicao = vet[n];
        aux->id = art.id;
        aux->color = 0;
        aux->esq = NULL;
        aux->dir = NULL;
        aux->pai = NULL;

        insercao(aux);
    }
    cout << qtdd(raiz) << endl;
    cout << n << endl;
}

//algoritmo de inserção
void ArvoreVp::insercao(Node *aux)
{

    aux->color = 1;

    Node *y = NULL;
    Node *x = this->raiz;

    while (x != NULL)
    {
        y = x;
        int a = Compara(aux->nome, x->nome);
        if (a >= 0)
        {
            x = x->dir;
        }
        else
        {
            x = x->esq;
        }
    }

    aux->pai = y;
    if (y == NULL)
    {
        raiz = aux;
        raiz->color = 0;
    }
    else if (Compara(aux->nome, y->nome) < 0)
    {
        y->esq = aux;
    }
    else
    {
        y->dir = aux;
    }
    insercaoBalanceado(aux);

    //    if (aux->pai == NULL)
    //    {
    //        return;
    //    }

    //    if (aux->pai->pai == NULL)
    //    {
    //        return;
    //    }
}

//algoritmo de inserção
void ArvoreVp::insercaoBalanceado(Node *p)
{
    Node *u; //uncle
    Node *pai_p = NULL;
    Node *vo_p = NULL;
    while ((p != raiz) && (p->pai->color == 1) && (p->color == 0))
    {
        pai_p = p->pai;
        vo_p = p->pai->pai;
        if (pai_p == vo_p->esq)
        {
            u = vo_p->dir;
            if (u->color == 1 && u != NULL)
            {
                vo_p->color = 1;
                pai_p->color = 0;
                u->color = 0;
                p = vo_p;
            }
            else
            {
                if (p == pai_p->dir)
                {
                    leftRotate(pai_p);
                    p = pai_p;
                    pai_p = p->pai;
                } ////////////////////////////////
                leftRotate(vo_p);
                pai_p->color = 0;
                vo_p->color = 1;
                p = pai_p;
            }
        }
        else
        {
            u = vo_p->dir;

            if (u->color == 1 && u != NULL)
            {
                u->color = 0;
                pai_p->color = 0;
                vo_p->color = 1;
                p = vo_p;
            }
            else
            {
                if (p == pai_p->esq)
                {
                    rightRotate(pai_p);
                    p = pai_p;
                    pai_p = p->pai;
                }
                rightRotate(vo_p);
                pai_p->color = 0;
                vo_p->color = 1;
                p = pai_p;
            }
        }
    }
    raiz->color = 0;
}

//rotação para direita

void ArvoreVp::leftRotate(Node *no)
{
    Node *y = no->esq;

    no->esq = y->dir;

    if (y->dir != NULL)
    {
        y->dir->pai = no;
    }
    y->pai = no->pai;
    if (no->pai == NULL)
    {
        this->raiz = y;
    }
    else if (no == no->pai->dir)
    {
        no->pai->dir = y;
    }
    else
    {
        no->pai->esq = y;
    }
    y->dir = no;
    no->pai = y;
}

//rotação para esquerda

void ArvoreVp::rightRotate(Node *no)
{
    Node *y = no->dir;

    no->dir = y->esq;

    if (y->esq != NULL)
        y->esq->pai = no;

    y->pai = no->pai;

    if (no->pai == NULL)
        raiz = y;

    else if (no == no->pai->esq)
        no->pai->esq = y;

    else
        no->pai->dir = y;

    y->esq = no;
    no->pai = y;
}

//busca

bool ArvoreVp::busca(string val)
{
    return auxBusca(this->raiz, val);
}

bool ArvoreVp::auxBusca(Node *p, string val)
{
    if (p == NULL)
        return false;
    else if (p->nome == val)
        return true;
    else if (Compara(p->nome, val))
        return auxBusca(p->esq, val);
    else
        return auxBusca(p->dir, val);
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
        if (r->color == 1)
            Color = "Rubro";
        else
            Color = "Negro";

        cout << r->nome << "(" << Color << ")" << endl;
        auxImprime(r->esq, str, false);
        auxImprime(r->dir, str, true);
    }
}

int ArvoreVp::Compara(string str1, string str2)
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
