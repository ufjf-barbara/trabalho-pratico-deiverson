#include <iostream>
#include <fstream>
#include "Tracks.h"
#include <vector>
#include <time.h>
#include "Ordenacao.h"

using namespace std;

static comparacao=0;
static trocas=0;


void  Ordenacao::chamaFuncaoOrdenacao()
{
    srand(time(NULL));

    int compQ=0,trocaQ=0,compS=0,trocaS=0,compH=0,trocaH=0;
    clock_t beginTime, endTime,timeQ,timeS,timeH;
    ifstream finA;
    finA.open("../print/artists.bin", ios::in);
    finA.seekg(0, finA.end);

    int tam = finA.tellg() / sizeof(artistsAux);

    int n = 800000;

    vet = Artists::registrosArt(n, tam);

    ofstream fout;


    fout.close();


    for(int i=0; i<M; i++)
    {

        comparacao=0;
        trocas=0;
        //quickSort
        beginTime = clock();

        Quicksort(vet, 0, n - 1);

        endTime = clock();
        compQ=comparacao;
        trocaQ=trocas;

        //Selection
        comparacao=0;
        trocas=0;

        beginTime = clock();

        selectionSort(vet,n);

        endTime = clock();

        compS=comparacao;
        trocaS=trocas;
    }

    compQ/=M;
    trocaQ/=M;
    compS/=M;
    trocaS/=M;
    compH/=M;
    trocaH/=M;


}



void Ordenacao::OrdenaselectionSort(vector<artists> &vet,int n)
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
        trocas++;
    }
}

int Ordenacao::particionamento(vector<artists> &vet, int b, int f)
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
        }
        while (pivo < vet[j].followers);
        if (i < j)
        {
            trocas++;
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
        }
    }
    while (i < j);

    return j;
}

void Ordenacao::Quicksort(vector<artists> &vet, int b, int f)
{
    int pivo;
    if (b < f)
    {
        pivo = particionamento(vet, b, f);
        Quicksort(vet, b, pivo);
        Quicksort(vet, pivo + 1, f);
    }
}

