#include <iostream>
#include <fstream>
#include "../parte1/headers/Tracks.h"
#include "headers/Ordenacao.h"
#include <vector>
#include <time.h>
#include <utility>

using namespace std;

static int comparacao = 0;
static int trocas = 0;
static int compQ = 0, trocaQ = 0, compM = 0, trocaM = 0, compH = 0, trocaH = 0, n = 0;
static clock_t timeQ, timeM, timeH;

void Ordenacao::chamaFuncaoOrdenacao(int n)
{
    clock_t beginTime, endTime;

    vector<pair<int, float>> aux;

    int tam = Artists::getTAM();
    int M = 3;

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

        //MergeSort
        comparacao = 0;
        trocas = 0;
        vet = aux;

        beginTime = clock();
        MergeSort(vet, 0, vet.size() - 1);
        endTime = clock();

        timeM = endTime - beginTime;
        compM = comparacao;
        trocaM = trocas;
    }
    //Pegando as médias
    timeQ /= M;
    timeM /= M;
    timeH /= M;

    compQ /= M;
    trocaQ /= M;

    compM /= M;
    trocaM /= M;

    compH /= M;
    trocaH /= M;

    PrintResult(n);
}

void Ordenacao::MergeSort(vector<pair<int, float>> &vet, int inicio, int fim)
{
    int i, j, k, metade;        //variaveis para contadores e para pegar a metade do vector
    vector<pair<int, float>> v; //vector auxiliar
    pair<int, float> par;
    for (int cont = 0; cont < (fim + 1 - inicio); cont++)
        v.push_back(par);

    if (inicio == fim)
    {
        return;
    }

    metade = (inicio + fim) / 2;

    MergeSort(vet, inicio, metade);  //usa-se o metodo recursivo para a primeira metada
    MergeSort(vet, metade + 1, fim); //usa-se o metodo recursivo para a sugunda metada

    i = inicio;     //recebe primeiro indice do vetor
    j = metade + 1; //recebe o indice do metade+1 do vetor
    k = 0;

    while (i < metade + 1 || j < fim + 1)
    {
        if (i == metade + 1)
        {
            trocas++;
            v[k] = vet[j];
            j++;
            k++;
        }
        else
        {
            if (j == fim + 1)
            {
                comparacao++;
                v[k] = vet[i];
                i++;
                k++;
            }
            else
            {
                if (vet[i].second < vet[j].second)
                {
                    comparacao++;
                    v[k] = vet[i];
                    i++;
                    k++;
                }
                else
                {
                    trocas++;
                    v[k] = vet[j];
                    j++;
                    k++;
                }
            }
        }
    }
    for (i = inicio; i <= fim; i++)
    {
        vet[i] = v[i - inicio];
    }
}

int Ordenacao::particionamento(vector<pair<int, float>> &vet, int b, int f)
{
    pair<int, float> pivo = vet[b]; //pivo escolhido, primeira posiçao do vetor
    pair<int, float> aux;           //vector auxiliar
    int i = b;
    int j = f + 1;

    do
    {
        do
        {
            i++;
            comparacao++;
        } while (vet[i].second < pivo.second && i <= f); //Comparando vet na posiçao i com o pivo
        do
        {
            j--;
            comparacao++;
        } while (pivo.second < vet[j].second); //Comparando vet na posiçao j com o pivo
        if (i < j)                             //Se i for menor que j, trocamos os valores de i e j do vector cada posiçao recebendo o valor da outra
        {
            trocas++;
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
        }
    } while (i < j);

    vet[b] = vet[j];
    vet[j] = pivo; //posiçao j recebe pivo para retorna-lo pra funçao que a chamou esta

    return j;
}

void Ordenacao::Quicksort(vector<pair<int, float>> &vet, int b, int f) //Ordenaçao dos artists
{
    int pivo;
    if (b < f)
    {
        pivo = particionamento(vet, b, f); //Recebe um pivo,indice onde o valor ja está na posiçao correta
        Quicksort(vet, b, pivo - 1);       //Chamada recursiva do método
        Quicksort(vet, pivo + 1, f);
    }
}

int Ordenacao::particionamentoTracks(vector<vector<tracks>> &vet, int b, int f)
{
    vector<tracks> pivo = vet[b];
    vector<tracks> aux;
    int i = b;
    int j = f + 1;

    do
    {
        do
        {
            i++;
            comparacao++;
        } while (vet[i].size() > pivo.size());
        do
        {
            j--;
            comparacao++;
        } while (pivo.size() > vet[j].size());
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

void Ordenacao ::ordenaQuickTraks(vector<vector<tracks>> &vet, int b, int f) //Ordenaçao das tracks
{
    int pivo;
    if (b < f)
    {
        pivo = particionamentoTracks(vet, b, f); //Recebe um pivo,indice onde o valor ja está na posiçao correta
        ordenaQuickTraks(vet, b, pivo - 1);      //Chamada recursiva do método
        ordenaQuickTraks(vet, pivo + 1, f);
    }
}

void Ordenacao::maxHeapify(vector<pair<int, float>> &vet, int n, int i) //funcao para verificar e transformar a heap em uma heap de maximo
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
        swap(vet[i].second, vet[maior].second); // troca o nó filho com o nó pai/raiz

        maxHeapify(vet, n, maior); //chamada recursiva para apilcar a propriedade de heap de máximo na sub-árvore afetada
    }
}

void Ordenacao ::heapSort(vector<pair<int, float>> &vet, int n) // Funcao de ordenacao do heapsort
{
    // Construindo a heap
    for (int i = n / 2 - 1; i >= 0; i--) // construcao de uma heap de maximo ao utilizar a funcao maxHeapify
    {
        maxHeapify(vet, n, i);
        comparacao++;
    }

    for (int i = n - 1; i > 0; i--) // Extraindo um a um os elementos da heap
    {

        swap(vet[0].second, vet[i].second); //move o nó atual para o fim
        trocas++;
        // Chama maxHeapify na heap reduzida
        maxHeapify(vet, i, 0);
    }
}

void Ordenacao::PrintResult(int n)
{

    ofstream saida("../print/saida.txt", ios::out | ios::app);

    saida << "\n-------------------------------------------------------------------------------------------------------\n"
          << "Quick Sort" << endl
          << "Para " << n << " registros: "
          << "\nNumero medio de comparacoes:\t" << compQ
          << "\nNumero  medio de trocas:\t" << trocaQ
          << "\nTempo medio de Processamento:\t" << timeQ / ((float)CLOCKS_PER_SEC)
          << " segundos" << endl;

    saida << "\n-------------------------------------------------------------------------------------------------------\n"
          << "Heap Sort" << endl
          << "Para " << n << " registros: "
          << "\nNumero medio de comparacoes:\t" << compH
          << "\nNumero  medio de trocas:\t" << trocaH
          << "\nTempo medio de Processamento:\t" << timeH / ((float)CLOCKS_PER_SEC)
          << " segundos" << endl;

    saida << "\n-------------------------------------------------------------------------------------------------------\n"
          << "Merge Sort" << endl
          << "Para " << n << " registros: "
          << "\nNumero medio de comparacoes:\t" << compM
          << "\nNumero  medio de trocas:\t" << trocaM
          << "\nTempo medio de Processamento:\t" << timeM / ((float)CLOCKS_PER_SEC)
          << " segundos" << endl;
    saida.close();
}

void Ordenacao::chamaFuncaoOrdenacaoTeste()
{
    ofstream saida("../print/teste.txt", ios::out | ios::trunc);

    clock_t beginTime, endTime;

    vector<pair<int, float>> aux;

    int tam = Artists::getTAM();

    aux = Artists::registrosArtFollowers(100, tam);
    vet = aux;

    saida << "\n-------------------------------------------------------------------------------------------------------\n"
          << "vetor desordenado:\n";
    for (int i = 0; i < aux.size(); i++)
    {
        saida << "Artista:\t" << Artists::reg(vet[i].first).name << "\t\tSeguidores:\t" << vet[i].second << endl;
    }
    saida << "\n";

    //QuickSort
    comparacao = 0;
    trocas = 0;

    beginTime = clock();
    Quicksort(vet, 0, vet.size() - 1);
    endTime = clock();

    timeQ = endTime - beginTime;
    compQ = comparacao;
    trocaQ = trocas;

    saida << "\n-------------------------------------------------------------------------------------------------------\n"
          << "Quick Sort" << endl
          << "\nNumero de comparacoes:\t" << compQ
          << "\nNumero de trocas:\t" << trocaQ
          << "\nTempo de Processamento:\t" << timeQ / ((float)CLOCKS_PER_SEC)
          << " segundos" << endl;
    saida << "\n-------------------------------------------------------------------------------------------------------\n"
          << "vetor ordenado:\n";
    for (int i = aux.size() - 1; i >= 0; i--)
    {
        saida << "Artista:\t" << Artists::reg(vet[i].first).name << "\t\tSeguidores:\t" << vet[i].second << endl;
    }
    saida << "\n";

    //HeapSort
    comparacao = 0;
    trocas = 0;
    vet = aux;

    beginTime = clock();
    heapSort(vet, vet.size());
    endTime = clock();

    timeH = endTime - beginTime;
    compH = comparacao;
    trocaH = trocas;

    saida << "\n-------------------------------------------------------------------------------------------------------\n"
          << "Heap Sort" << endl
          << "\nNumero de comparacoes:\t" << compH
          << "\nNumero de trocas:\t" << trocaH
          << "\nTempo de Processamento:\t" << timeH / ((float)CLOCKS_PER_SEC)
          << " segundos" << endl;
    saida << "\n-------------------------------------------------------------------------------------------------------\n";
    for (int i = aux.size() - 1; i >= 0; i--)
    {
        saida << "Artista:\t" << Artists::reg(vet[i].first).name << "\t\tSeguidores:\t" << vet[i].second << endl;
    }
    saida << "\n";

    //Merge sort
    comparacao = 0;
    trocas = 0;
    vet = aux;

    beginTime = clock();
    MergeSort(vet, 0, vet.size() - 1);
    endTime = clock();

    timeM = endTime - beginTime;
    compM = comparacao;
    trocaM = trocas;

    saida << "\n-------------------------------------------------------------------------------------------------------\n"
          << "Merge Sort" << endl
          << "\nNumero de comparacoes:\t" << compM
          << "\nNumero de trocas:\t" << trocaM
          << "\nTempo de Processamento:\t" << timeM / ((float)CLOCKS_PER_SEC)
          << " segundos" << endl;
    saida << "\n-------------------------------------------------------------------------------------------------------\n"
          << "vetor ordenado:\n";
    for (int i = aux.size() - 1; i >= 0; i--)
    {
        saida << "Artista:\t" << Artists::reg(vet[i].first).name << "\tSeguidores:\t" << vet[i].second << endl;
    }
    saida << "\n";
    saida.close();
}
