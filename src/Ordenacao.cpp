#include <iostream>
#include <fstream>
#include "Tracks.h"
#include <vector>
#include <time.h>
#include "Ordenacao.h"
#include <utility>

using namespace std;

static int comparacao = 0;
static int trocas = 0;
static int compQ = 0, trocaQ = 0, compS = 0, trocaS = 0, compH = 0, trocaH = 0, n = 0;
static clock_t timeQ, timeS, timeH;

void Ordenacao::chamaFuncaoOrdenacao(int N)
{
    srand(time(NULL));

    clock_t beginTime, endTime;
    ifstream finA;
    finA.open("../print/artists.bin", ios::in);
    finA.seekg(0, finA.end);

    vector<pair<int, float>> aux;

    int tam = finA.tellg() / sizeof(artistsAux);
    int M = 3;
    n = N;

    ofstream fout;
    fout.close();

    for (int i = 0; i < M; i++)
    {
        aux = Artists::registrosArtFollowers(n, tam);
        vet = aux;

        //QuickSort
        comparacao = 0;
        trocas = 0;

        beginTime = clock();
        Quicksort(vet, 0, n - 1);
        endTime = clock();

        timeQ = endTime - beginTime;
        compQ = comparacao;
        trocaQ = trocas;

        //HeapSort
        comparacao = 0;
        trocas = 0;
        vet = aux;

        beginTime = clock();
        heapSort(vet, n);
        endTime = clock();

        timeH = endTime - beginTime;
        compH = comparacao;
        trocaH = trocas;

        //Selection
        comparacao = 0;
        trocas = 0;
        vet = aux;

        beginTime = clock();
        SelectionSort(vet, n);
        endTime = clock();

        timeS = endTime - beginTime;
        compS = comparacao;
        trocaS = trocas;
    }
    timeQ /= M;
    timeS /= M;
    timeH /= M;

    compQ /= M;
    trocaQ /= M;

    compS /= M;
    trocaS /= M;
    
    compH /= M;
    trocaH /= M;

    PrintResult();
}

void Ordenacao::SelectionSort(vector<pair<int, float>> &vet, int n)
{

    float menor = vet[0].second;
    int indice = 0;
    pair<int, float> aux;
    int i = 0, j = 0;

    for (i = 0; i < n; i++)
    {
        menor = vet[i].second;
        indice = i;
        for (j = i; j < n; j++)
        {
            if (menor > vet[j].second)
            {
                menor = vet[j].second;
                indice = j;
                comparacao++;
            }
        }
        aux = vet[i];
        vet[i] = vet[indice];
        vet[indice] = aux;
        trocas++;
    }
}

int Ordenacao::particionamento(vector<pair<int, float>> &vet, int b, int f)
{
    pair<int, float> pivo = vet[b];
    pair<int, float> aux;
    int i = b;
    int j = f + 1;

    do
    {
        do
        {
            i++;
            comparacao++;
        } while (vet[i].second < pivo.second && i <= f);
        do
        {
            j--;
            comparacao++;
        } while (pivo.second < vet[j].second);
        if (i < j)
        {
            trocas++;
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
        }
    } while (i < j);
    vet[b] = vet[j];
    vet[j] = pivo;
    return j;
}

void Ordenacao::Quicksort(vector<pair<int, float>> &vet, int b, int f)
{
    int pivo;
    if (b < f)
    {
        pivo = particionamento(vet, b, f);
        Quicksort(vet, b, pivo - 1);
        Quicksort(vet, pivo + 1, f);
    }
}
void Ordenacao::maxHeapify(vector<pair<int, float>> &vet, int n, int i)
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

void Ordenacao ::heapSort(vector<pair<int, float>> &vet, int n) // Funcao de ordenacao do heapsort
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

void Ordenacao::PrintResult()
{

    ofstream saida("../print/saida.txt", ios::out | ios::app);

    saida << "\n-----------------------------------------------\n"
          << "Quick Sort" << endl
          << "Para " << n << " registros: "
          << "\nNumero medio de comparacoes:\t" << compQ
          << "\nNumero  medio de trocas:\t" << trocaQ
          << "\nTempo medio de Processamento:\t" << timeQ / ((float)CLOCKS_PER_SEC)
          << " segundos" << endl;

    saida << "\n-----------------------------------------------\n"
          << "Heap Sort" << endl
          << "Para " << n << " registros: "
          << "\nNumero medio de comparacoes:\t" << compH
          << "\nNumero  medio de trocas:\t" << trocaH
          << "\nTempo medio de Processamento:\t" << timeH / ((float)CLOCKS_PER_SEC)
          << " segundos" << endl;

    saida << "\n-----------------------------------------------\n"
          << "Selection Sort" << endl
          << "Para " << n << " registros: "
          << "\nNumero medio de comparacoes:\t" << compS
          << "\nNumero  medio de trocas:\t" << trocaS
          << "\nTempo medio de Processamento:\t" << timeS / ((float)CLOCKS_PER_SEC)
          << " segundos" << endl;
    saida.close();
}