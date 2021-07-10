#include <iostream>
#include <fstream>
#include "Artists.h"
#include <vector>
#include <time.h>
#include <utility>

using namespace std;

static int trocas = 0;
static int comparacao = 0;

void maxHeapify(vector<pair<int, float>> &vet, int n, int i)
{
    int maior = i;     // incializando o maior como raiz(pai)
    int l = 2 * i + 1; // Right(i) -- Filho a esquerda do indice i
    int r = 2 * i + 2; // Right(i) -- Filho a direita do indice i

    // Se o filho da esquerda é maior que o pai
    if ((l < n) && (vet[l].second > vet[maior].second))
        maior = l;

    // Se o filho da direita é maior que o pai
    if ((r < n) && (vet[r].second > vet[maior].second))
        maior = r;

    // Se o maior não é raiz
    if (maior != i)
    {
        swap(vet[i].second, vet[maior].second);

        maxHeapify(vet, n, maior);
    }
}

void heapSort(vector<pair<int, float>> &vet, int n) // Funcao de ordenacao do heapsort
{
    // Construindo a heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(vet, n, i);
        comparacao++;
    }

    for (int i = n - 1; i > 0; i--)
    {

        swap(vet[0].second, vet[i].second);
        trocas++;
        // Chama maxHeapify no heap reduzido
        maxHeapify(vet, i, 0);
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
    vector<pair<int, float>> vet = Artists::registrosArtFollowers(n, tam);

    cout << "Artists Desordenado:" << endl;

    for (int i = 0; i < n; i++)
        cout << "->" << vet[i].second;

    cout << "\n";

    beginTime = clock();
    heapSort(vet, n);
    endTime = clock();

    cout << "\nComparacoes:\t" << comparacao;
    cout << "\nTrocas:\t " << trocas;
    cout << "\nTempo de Processamento : " << (endTime - beginTime) / ((float)CLOCKS_PER_SEC) << " segundos" << endl;
    cout << "\n";

    cout << "Artists Ordenado:\t" << endl;

    for (int i = 0; i < n; i++)
        cout << "->" << vet[i].second;
    cout << "\n";

    return 0;
}