#include <iostream>
#include <fstream>
#include "Artists.h"
#include <vector>
#include <time.h>

using namespace std;

static int trocas = 0;
static int comparacao = 0;


void selectionSort(vector<artists> &vet,int n)
{

    int menor=vet[0].followers;
    int indice=0;
    artists aux;
    int i=0,j=0;

    for(i=0; i<n; i++)
    {
        menor=vet[i].followers;
        indice=i;
        for(j=i; j<n; j++)
        {
            if(menor>vet[j].followers)
            {
                menor=vet[j].followers;
                indice=j;
                comparacao++;
            }
        }
        aux=vet[i];
        vet[i]=vet[indice];
        vet[indice]=aux;
        troca++;
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

    cout << "Vetor inicial:" << endl;

    for (int i = 0; i < n; i++)
        cout << "->" << vet[i].followers;

    cout << "\n";

    beginTime = clock();
    selectionSort(vet,n);
    endTime = clock();


    cout << "\nComparacoes:\t" << comparacao;
    cout << "\nTrocas:\t " << trocas;
    cout << "\nTempo de Processamento : " << (endTime - beginTime)
         / ((float)CLOCKS_PER_SEC) << " segundos" << endl;
    cout << "\n";

    cout << "Vetor ordenado:\t" << endl;

    for (int i = 0; i < n; i++)
        cout << "->" << vet[i].followers;
    cout << "\n";

    return 0;
}
