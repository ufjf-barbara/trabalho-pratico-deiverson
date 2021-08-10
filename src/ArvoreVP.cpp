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

        insercao(aux);
    }
}

void ArvoreVp::insercao(Node* aux) {
    
    aux->color = 1;

    Node* y = nullptr;
    Node* x = this->raiz;

    while (x != NULL) {
      y = x;
      if (aux->data < x->data) {
        x = x->esq;
      } else {
        x = x->dir;
      }
    }

    aux->pai = y;
    if (y == nullptr) {
      raiz = aux;
    } else if (aux->data < y->data) {
      y->esq = aux;
    } else {
      y->dir = aux;
    }

    if (aux->pai == nullptr) {
      aux->color = 0;
      return;
    }

    if (aux->pai->pai == nullptr) {
      return;
    }
   
  }



