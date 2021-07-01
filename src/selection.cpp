#include <iostream>
#include <fstream>
#include "Artists.h"
#include <vector>
#include <time.h>

using namespace std;


void selectionSort(vector<artists> &vet)
{
    int tam=lista.size();

    for(artists art:lista)
    {
        vet.push_back(art);
    }

    int menor=vet[0].followers;
    int indice=0;
    artists aux;
    int i=0,j=0;

    for(i=0; i<tam; i++)
    {
        menor=vet[i].followers;
        indice=i;
        for(j=i; j<tam; j++)
        {
            if(menor>vet[j].followers)
            {
                menor=vet[j].followers;
                indice=j;
            }
        }
        aux=vet[i];
        vet[i]=vet[indice];
        vet[indice]=aux;
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
    selectionSort(vet);
    endTime = clock();



    cout << "\nTempo de Processamento : " << (endTime - beginTime)
         / ((float)CLOCKS_PER_SEC) << " segundos" << endl;
    cout << "\n";

    cout << "Vetor ordenado:\t" << endl;

    for (int i = 0; i < n; i++)
        cout << "->" << vet[i].followers;
    cout << "\n";

    return 0;
}
