#include "Artists.h"
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
    void SelectionSort(vector<pair<int, float>> &vet, int n);
    int particionamento(vector<pair<int, float>> &vet, int b, int f);
    void Quicksort(vector<pair<int, float>> &vet, int b, int f);
    void maxHeapify(vector<pair<int, float>> &vet, int n, int i);
    void heapSort(vector<pair<int, float>> &vet, int n);
    void PrintResult();
    static vector < vector<tracks> ordenaQuickTraks(vector<vector<tracks>> &vet, int b, int f);
    int Ordenacao::particionamentoTracks(vector<vector<tracks>> &vet, int b, int f);
    
};
#endif //ORDENACAO_H_INCLUDED