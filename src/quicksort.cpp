#include <iostream>
#include <fstream>
#include "Artists.h"
#include <vector>
#include <ctime>

using namespace std;

static int trocas = 0;
static int comparacao = 0;

int particionamento(vector<artists> &vet, int b, int f)
{
    float pivo = vet[b + (f - b) / 2].followers;
    int i = b;
    int j = f + 1;
    artists aux;

    do
    {
        while (vet[i].followers < pivo)
        {
            i++;
            comparacao++;
        }

        do
        {
            j--;
            comparacao++;
        } while (pivo < vet[j].followers);
        if (i < j)
        {
            trocas++;
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
        }
    } while (i < j);

    return j;
}

void Quicksort(vector<artists> &vet, int b, int f)
{
    int pivo;
    if (b < f)
    {
        pivo = particionamento(vet, b, f);
        Quicksort(vet, b, pivo);
        Quicksort(vet, pivo + 1, f);
    }
}
int main(int argc, char **argv)
{
    srand(time(NULL));

    cout << "1\n";
    clock_t beginTime, endTime;
    ifstream finA;
    finA.open("../print/artists.bin", ios::in);
    cout << "2\n";
    finA.seekg(0, finA.end);

    int tam = finA.tellg() / sizeof(artistsAux);

    int n = 800000;

    vector<artists> vet = Artists::registrosArt(n, tam);
   
    ofstream fout;

    fout.open("ArtistsDesordenado.txt", ios::out);

    for (int i = 0; i < n; i++)
        fout << "->" << vet[i].followers;
        
    fout.close();

    cout << "\n";

    beginTime = clock();

    Quicksort(vet, 0, n - 1);

    endTime = clock();

    cout << "\nComparacoes:\t" << comparacao;
    cout << "\nTrocas:\t " << trocas;
    cout << "\nTempo de Processamento : " << (endTime - beginTime) / ((float)CLOCKS_PER_SEC) << " segundos" << endl;
    cout << "\n";

    fout.open("ArtistsOrdenado.txt", ios::out);
    for (int i = 0; i < n; i++)
        fout << "->" << vet[i].followers;
    cout << "\n";
    fout.close();
    return 0;
}