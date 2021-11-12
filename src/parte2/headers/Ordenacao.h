#include "../../parte1/headers/Artists.h"
#include <iostream>
#include <vector>
#include <utility>

#ifndef ORDENACAO_H_INCLUDED
#define ORDENACAO_H_INCLUDED

class Ordenacao
{

private:
    vector<pair<int, float>> vet;

public:
    void chamaFuncaoOrdenacao(int N);
    void chamaFuncaoOrdenacaoTeste();
    void MergeSort(vector<pair<int, float>> &vet, int inicio,int fim);
    int particionamento(vector<pair<int, float>> &vet, int b, int f);
    void Quicksort(vector<pair<int, float>> &vet, int b, int f);
    void maxHeapify(vector<pair<int, float>> &vet, int n, int i);
    void heapSort(vector<pair<int, float>> &vet, int n);
    void PrintResult(int n);
    static void ordenaQuickTraks(vector<vector<tracks>> &vet, int b, int f);
    static int particionamentoTracks(vector<vector<tracks>> &vet, int b, int f);
    
};
#endif //ORDENACAO_H_INCLUDED