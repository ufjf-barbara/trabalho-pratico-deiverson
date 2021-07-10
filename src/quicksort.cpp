#include <iostream>
#include <fstream>
#include "Artists.h"
#include <vector>
#include <ctime>

#include <utility>

using namespace std;

static int trocas = 0;
static int comparacao = 0;

int particionamento(vector<pair<int, float>> &vet, int b, int f)
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


void Quicksort(vector<pair<int, float>> &vet, int b, int f)
{
    int pivo;
    if (b < f)
    {
        pivo = particionamento(vet, b, f);
        Quicksort(vet, b, pivo-1);
        Quicksort(vet, pivo + 1, f);
    }
}
int main(int argc, char **argv)
{
    srand(unsigned(time(NULL)));

    clock_t beginTime, endTime;
    ifstream finA;
    finA.open("../print/artists.bin", ios::in);
    finA.seekg(0, finA.end);

    int tam = finA.tellg() / sizeof(artistsAux);

    int n = 800000;

    vector<pair<int, float>> vet;
    ofstream fout;
    int j = 0;
    for (j = 0; j < 1; j++)
    {
        comparacao = 0;
        trocas = 0;
        cout << "\n-----------------------------------------------------------";
        vet = Artists::registrosArtFollowers(n, tam);

        fout.open("ArtistsDesordenado.txt", ios::out);
        for (int i = 0; i < n; i++)
            fout << "->" << vet[i].second;

        fout.close();

        beginTime = clock();

        Quicksort(vet, 0, n - 1);

        endTime = clock();

        cout << "\nComparacoes:\t" << comparacao;
        cout << "\nTrocas:\t " << trocas;
        cout << "\nTempo de Processamento : " << (endTime - beginTime) / ((float)CLOCKS_PER_SEC) << " segundos" << endl;
        cout << "\n";

        fout.open("ArtistsOrdenado.txt", ios::out);

        for (int i = 0; i < n; i++)
            fout <<i<< "->" << vet[i].second<<endl;
        fout.close();


    }

    return 0;
}