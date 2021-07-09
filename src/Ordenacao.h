#include <iostream>
#include <vector>



#ifndef ORDENACAO_H_INCLUDED
#define ORDENACAO_H_INCLUDED


class Ordenacao
{
private :
    vector<artists> vet;
public:
    void chamaFuncaoOrdenacao();
    void OrdenaselectionSort(vector<artists> &vet,int n);
    int particionamento(vector<artists> &vet, int b, int f);
    void Ordenacao::Quicksort(vector<artists> &vet, int b, int f);



}




#endif // ORDENACAO_H_INCLUDED
