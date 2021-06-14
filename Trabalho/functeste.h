#include <iostream>
#include <fstream>
#include <list>

#ifndef FUNCTESTE_H_INCLUDED
#define FUNCTESTE_H_INCLUDED


using namespace std;

class func_teste
{
public:
    func_teste();

private:
    void sorteia_numero(int vet[], int n, int qtddReg);
    bool verifica_numero(int vet[], int n, int aux);
    void callTeste(int tamT, int tamA, ifstream *finT, ifstream *finA);
    //void callTeste(int tamA, ifstream *finA);
};

#endif // ARTISTS_H_INCLUDED