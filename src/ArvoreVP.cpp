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
Node *BSTInsert(Node *raiz, Node *p);
int Compara(string str1, string str2);

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

// //algoritmo de inserção
// void ArvoreVp::insercao(Node *no)
// {

//     no->color = 1;

//     Node *y = NULL;
//     Node *x = this->raiz;

//     while (x != NULL)
//     {
//         y = x;
//         int a = Compara(no->nome, x->nome);
//         if (a >= 0)
//         {
//             x = x->dir;
//         }
//         else
//         {
//             x = x->esq;
//         }
//     }

//     no->pai = y;
//     if (y == NULL)
//     {
//         raiz = no;
//     }
//     else if (Compara(no->nome, y->nome) < 0)
//     {
//         y->esq = no;
//     }
//     else
//     {
//         y->dir = no;
//     }

//     if (no->pai == NULL)
//     {
//         raiz->color = 0;
//         return;
//     }

//     if (no->pai->pai == NULL)
//     {
//         return;
//     }
//     insercaoBalanceado(no);
// }

void ArvoreVp::insercao(Node *no)
{
    // Do a normal BST insert
    raiz = BSTInsert(raiz, no);

    // fix Red Black Tree violations
    insercaoBalanceado(no);
}
Node *BSTInsert(Node *raiz, Node *p)
{
    /* If the tree is empy, return a new node */
    if (raiz == NULL)
        return p;

    /* Otherwise, recur down the tree */
    if (Compara(p->nome , raiz->nome)<0)
    {
        raiz->esq = BSTInsert(raiz->esq, p);
        raiz->esq->pai = raiz;
    }
    else if (Compara(p->nome , raiz->nome)>=0)
    {
        raiz->dir = BSTInsert(raiz->dir, p);
        raiz->dir->pai = raiz;
    }

    /* return the (unchanged) node pointer */
    return raiz;
}
//algoritmo de inserção
void ArvoreVp::insercaoBalanceado(Node *p)
{
    Node *u; //uncle
    while (p->pai->color == 0)
    {
        if (p->pai == p->pai->pai->dir)
        {
            u = p->pai->pai->esq;
            if (u->color == 1)
            {
                u->color = 0;
                p->pai->color = 0;
                p->pai->pai->color = 1;
                p = p->pai->pai;
            }
            else
            {
                if (p == p->pai->esq)
                {
                    p = p->pai;
                    rightRotate(p);
                }
                p->pai->color = 0;
                p->pai->pai->color = 1;
                leftRotate(p);
            }
        }
        else
        {
            u = p->pai->pai->dir;

            if (u->color == 1)
            {

                u->color = 0;
                p->pai->color = 0;
                p->pai->pai->color = 1;
                p = p->pai->pai;
            }
            else
            {
                if (p == p->pai->dir)
                {
                    p = p->pai;
                    leftRotate(p);
                }
                p->pai->color = 0;
                p->pai->pai->color = 1;
                rightRotate(p);
            }
        }
        if (p == raiz)
        {
            break;
        }
    }
    raiz->color = 0;
}

//rotação para direita

void ArvoreVp::rightRotate(Node *no)
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

void ArvoreVp::leftRotate(Node *no)
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
    else if (Compara(p->nome, val)<0)
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
