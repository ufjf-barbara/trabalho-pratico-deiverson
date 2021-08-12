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

  vector<int> vet;
  for (int i = 0; i < Artists::getTAM(); i++)
  {
    vet.push_back(i);
  }
  random_shuffle(vet.begin(), vet.end());

  for (int i = 0; i < n; i++)
  {
    Node *aux;
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
}

//algoritmo de inserção
void ArvoreVp::insercao(Node *aux)
{

  aux->color = 1;

  Node *y = nullptr;
  Node *x = this->raiz;

  while (x != NULL)
  {
    y = x;
    int a = Compara(aux->nome, raiz->nome);
    if (a == 0 || a > 0)
    {
      x = x->dir;
    }
    else
    {
      x = x->esq;
    }
  }

  aux->pai = y;
  if (y == nullptr)
  {
    raiz = aux;
  }
  else if (Compara(aux->nome, y->nome))
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
  insercaoBalanceada(aux);
}

//algoritmo de inserção
void ArvoreVp::insercaoBalanceada(Node *p)
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
          rotacaoDir(p);
        }
        p->pai->color = 0;
        p->pai->pai->color = 1;
        rotacaoEsq(p->pai->pai);
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
          rotacaoEsq(p);
        }
        p->pai->color = 0;
        p->pai->pai->color = 1;
        rotacaoDir(p->pai->pai);
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

void ArvoreVp::rotacaoDir(Node *x)
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

void ArvoreVp::rotacaoEsq(Node *x)
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

void ArvoreVp::auxImprime(Node *p, string str, bool verifica)
{
  if (p != NULL)
  {
    cout << str;
    if (verifica)
    {
      cout << "D----";
      str += "   ";
    }
    else
    {
      cout << "E----";
      str += "|  ";
    }

    string Color = p->color ? "Rubro" : "Negro";
    cout << p->nome << "(" << Color << ")" << endl;
    auxImprime(p->esq, str, false);
    auxImprime(p->dir, str, true);
  }
}

int ArvoreVp::Compara(string str1, string str2)
{
  char aux1[375];
  char aux2[375];

  strcpy(aux1, str1.c_str());
  strcpy(aux2, str2.c_str());

  int aux;
  if (str1.length() <= str2.length())
    aux = str1.length();
  else
    aux = str2.length();

  int resultado = strncmp(aux1, aux2, aux);
  if (resultado > 0)
    return 1;
  else if (resultado == 0)
    return 0;
  else
    return -1;
}