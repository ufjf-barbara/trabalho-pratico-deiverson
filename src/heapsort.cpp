#include <iostream>
#include <fstream>
#include "Artists.h"
#include <vector>
#include <time.h>

using namespace std;

static int trocas = 0;
static int comparacao = 0;

void MaxHeapify(vector<artists> &vet, int i, int n) //Funcao que verifica a propriedade de heap de maximo
{
    int m = i;           //incializando o maior como raiz(pai)
    int l = 2 * i;       //Left(i) -- Filho a esquerda do indice i
    int r = (2 * i) + 1; //Right(i) -- Filho a direita do indice i

    if ((l <= n) && (vet[l].followers > vet[i].followers)) //Se o filho da esquerda e maior do que a raiz(pai)
    {
        vet[m].followers = vet[l].followers;
    }
    else
        vet[m].followers = vet[i].followers;

    if ((r <= n) && (vet[r].followers > vet[m].followers)) //Se o filho da esquerda e maior do que a raiz(pai)
    {
        vet[m].followers = vet[r].followers;
    }
    if (m != i) // Se o maior não é raiz
    {
        swap(vet[i].followers, vet[m].followers);
        MaxHeapify(vet, m, n);
    }
}

void CriaMaxHeap(vector<artists> &vet, int n) //Funcao que cria heap de maximo
{

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        MaxHeapify(vet, i, n);
    }
}

void HeapSort(vector<artists> &vet, int n) //Funcao de sorteamento HeapSort
{

    CriaMaxHeap(vet, n);
    for (int i = n - 1; i > 0; i--)
    {
        swap(vet[1].followers, vet[i].followers);
        MaxHeapify(vet, 1, n - 1);
    }
}

int main(int argc, char **argv)
{

    srand(time(NULL));

    clock_t beginTime, endTime;
    ifstream finA;
    finA.open("../print/artists.bin", ios::in);
    finA.seekg(0, finA.end);

    int tam = finA.tellg() / sizeof(artistsAux);

    int n = 100;
    vector<artists> vet = Artists::registrosArt(n, tam);

    cout << "Artists Desordenado:" << endl;

    for (int i = 0; i < n; i++)
        cout << "->" << vet[i].followers;

    cout << "\n";

    beginTime = clock();
    HeapSort(vet, n);
    endTime = clock();

    cout << "\nComparacoes:\t" << comparacao;
    cout << "\nTrocas:\t " << trocas;
    cout << "\nTempo de Processamento : " << (endTime - beginTime) / ((float)CLOCKS_PER_SEC) << " segundos" << endl;
    cout << "\n";

    cout << "Artists Ordenado:\t" << endl;

    for (int i = 0; i < n; i++)
        cout << "->" << vet[i].followers;
    cout << "\n";

    return 0;
}