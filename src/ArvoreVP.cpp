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
#include "ArvoreVP.h"

#include <utility>

using namespace std;

ArvoreVp::ArvoreVp()
{
  raiz = NULL;
  aux = NULL;
}
ArvoreVp::ArvoreVp(int n)
{
  raiz = NULL;
  aux = NULL;

  vector<int> vet;
  for (int i = 0; i < Artists::getTAM(); i++)
  {
    vet.push_back(i);
  }
  random_shuffle(vet.begin(), vet.end());

  for (int i = 0; i < n; i++)
  {

    artists art = Artists::reg(vet[n]);
    aux->nome = art.name;
    aux->posicao = vet[n];
    aux->id = art.id;
    aux->color = 0;
    aux->esq = NULL;
    aux->dir = NULL;
    aux->pai = NULL;

    insercao();
  }
}

//algoritmo de inserção
void ArvoreVp::insercao()
{

  aux->color = 1;

  Node *y = nullptr;
  Node *x = this->raiz;

  while (x != NULL)
  {
    y = x;
    if (aux->data < x->data)
    {
      x = x->esq;
    }
    else
    {
      x = x->dir;
    }
  }

  aux->pai = y;
  if (y == nullptr)
  {
    raiz = aux;
  }
  else if (aux->data < y->data)
  {
    y->esq = aux;
  }
  else
  {
    y->dir = aux;
  }

  if (aux->pai == nullptr)
  {
    aux->color = 0;
    return;
  }

  if (aux->pai->pai == nullptr)
  {
    return;
  }
}

//algoritmo de inserção
void ArvoreVp::insercaoBalanceado(Node *p)
{
  Node *u;
  while (p->pai->color == 1)
  {
    if (p->pai == p->pai->pai->dir)
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
          rightRotate(p);
        }
        p->pai->color = 0;
        p->pai->pai->color = 1;
        leftRotate(p->pai->pai);
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
        rightRotate(p->pai->pai);
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

void ArvoreVp::rightRotate(Node *x)
{
  Node *y = x->esq;
  x->esq = y->dir;
  if (y->dir != NULL)
  {
    y->dir->pai = x;
  }
  y->pai = x->pai;
  if (x->pai == nullptr)
  {
    this->raiz = y;
  }
  else if (x == x->pai->dir)
  {
    x->pai->dir = y;
  }
  else
  {
    x->pai->esq = y;
  }
  y->dir = x;
  x->pai = y;
}

//rotação para esquerda

void ArvoreVp::leftRotate(Node *x)
{
  Node *y = x->dir;
  x->dir = y->esq;
  if (y->esq != NULL)
  {
    y->esq->pai = x;
  }
  y->pai = x->pai;
  if (x->pai == nullptr)
  {
    this->raiz = y;
  }
  else if (x == x->pai->esq)
  {
    x->pai->esq = y;
  }
  else
  {
    x->pai->dir = y;
  }
  y->esq = x;
  x->pai = y;
}



