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
int Compara(string strRUBRO, string str2);

ArvoreVp::ArvoreVp()
{
    raiz = NULL;
}
ArvoreVp::ArvoreVp(int n)
{
    raiz = NULL;

    int tam = Artists::getTAM();
    vector<int> vet;

    for (int i = NEGRO; i < tam; i++)
    {
        vet.push_back(i);
    }
    random_shuffle(vet.begin(), vet.end());

    for (int i = NEGRO; i < n; i++)
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
//    imprime();
//    cin.get();
    insercaoBalanceado(no);
//    imprime();
//    cin.get();
}

// void ArvoreVp::insercao(Node *no)
// {
//     // Do a normal BST insert
//     raiz = BSTInsert(raiz, no);

//     // fix Red Black Tree violations
//     insercaoBalanceado(no);
// }
Node *BSTInsert(Node *raiz, Node *p)
{
    /* If the tree is empy, return a new node */
    if (raiz == NULL)
        return p;

    /* Otherwise, recur down the tree */
    if (Compara(p->nome, raiz->nome) < NEGRO)
    {
        raiz->esq = BSTInsert(raiz->esq, p);
        raiz->esq->pai = raiz;
    }
    else if (Compara(p->nome, raiz->nome) >= NEGRO)
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
//
                    rightRotate(p);

                    leftRotate(p);
                    if(p->pai)
                    {
                        p=p->pai;
                        p->color = NEGRO;
                        if(p->dir)
                            p->dir->color = RUBRO;
                        if(p->esq)
                            p->esq->color = RUBRO;
                    }
                    else
                    {
                        raiz=p;
                        break;
                    }//
//
                }
                else
                {
                    leftRotate(p->pai);
                    p=p->pai;
                    p->color = NEGRO;
                    if(p->esq)
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

                    // cout<<"\n\n"<<p->nome<<"\n\n";

                    rightRotate(p);
                    if(p->pai)
                    {
                        p=p->pai;
                        p->color = NEGRO;
                        if(p->esq)
                            p->esq->color = RUBRO;
                        if(p->dir)
                            p->dir->color = RUBRO;
                    }
                    else
                    {
                        raiz=p;
                        break;
                    }//                    p=p->esq;
                }
//                if(p->pai->pai==NULL)
//                {
//                    auxImprime(p, "", true);
//                    p->pai->pai->color = RUBRO;
//                }
                else
                {
                    rightRotate(p->pai);
                    p=p->pai;
                    p->color = NEGRO;
                    p->esq->color = RUBRO;
                    if(p->dir)
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
    if(p->pai==NULL)
        raiz=p;
    raiz->color = NEGRO;
}

//rotação para direita

void ArvoreVp::rightRotate(Node *pai)
{
    Node *p = pai->esq;
    Node *avo = pai->pai;
    Node *aux = pai->dir;


    // aux=pai->dir;
    pai->dir=avo;
    if(avo)
    {
        avo->esq=aux;
        if(avo->pai)
        {
            if(avo->pai->dir==avo)
                avo->pai->dir=pai;
            else
                avo->pai->esq=pai;

        }
        pai->pai=avo->pai;
        avo->pai=pai;
    }
    if(aux)
        aux->pai=avo;
}

//rotação para esquerda

void ArvoreVp::leftRotate(Node *pai)
{
    Node *p = pai->dir;
    Node *avo = pai->pai;
    Node *aux = pai->esq;

//    aux=pai->esq;
    pai->esq=avo;
    if(avo)
    {

        avo->dir=aux;
        if(avo->pai)
        {
            if(avo->pai->dir==avo)
                avo->pai->dir=pai;
            else
                avo->pai->esq=pai;

        }
        pai->pai=avo->pai;
        avo->pai=pai;
    }
    if(aux)
        aux->pai=avo;


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
    else if (Compara(p->nome, val) < NEGRO)
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
        if (r->color == RUBRO)
            Color = "Rubro";
        else
            Color = "Negro";

        cout << r->nome << "(" << Color << ")" << endl;
        auxImprime(r->esq, str, false);
        auxImprime(r->dir, str, true);
    }
}

int Compara(string strRUBRO, string str2)
{
    int aux;
    if (strRUBRO.length() <= str2.length())
        aux = strRUBRO.length();
    else
        aux = str2.length();

    int resultado = strncmp(strRUBRO.c_str(), str2.c_str(), aux);
    if (resultado > NEGRO)
        return RUBRO;
    else if (resultado == NEGRO)
        return NEGRO;
    else
        return -1;
}
int ArvoreVp::qtdd(Node *no)
{
    if (no == NULL)
    {
        return NEGRO;
    }
    else
    {
        return RUBRO + qtdd(no->esq) + qtdd(no->dir);
    }
}
