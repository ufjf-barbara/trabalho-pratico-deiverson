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

    clock_t begin = clock();
    for (int i = 0; i < tam; i++)
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
    cout << "\ntempo insecao" << (end - begin) / ((float)CLOCKS_PER_SEC) << endl;
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
    insercaoBalanceado(no);
}

Node *BSTInsert(Node *raiz, Node *p)
{
    if (raiz == NULL)
        return p;

    if (Compara(p->nome, raiz->nome) < 0)
    {
        raiz->esq = BSTInsert(raiz->esq, p);
        raiz->esq->pai = raiz;
    }
    else if (Compara(p->nome, raiz->nome) >= 0)
    {
        raiz->dir = BSTInsert(raiz->dir, p);
        raiz->dir->pai = raiz;
    }

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

    // aux=pai->dir;
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

    //    aux=pai->esq;
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

int ArvoreVp::busca(string val)
{
    cout << "\n"
         << val << endl;
    // cont=0;
    return auxBusca(this->raiz, val);
}

int ArvoreVp::auxBusca(Node *p, string val)
{
    if (p == NULL)
        return -1;
    // cout << "\n"
    //      << p->nome << "---" << val << endl;
    if (p->nome == val)
    { // cont++;
        // imprime(p->posicao); ;;tbm imprimir comp e tempo
        return p->posicao;
    }
    else if (Compara(val, p->nome) < 0)
    { // cont+=2;
        return auxBusca(p->esq, val);
    }
    else
    { // cont+=3;
        return auxBusca(p->dir, val);
    }
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
