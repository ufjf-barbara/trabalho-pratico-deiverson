#include <iostream>
#include <fstream>
#include <list>

#ifndef FUNCTESTE_H_INCLUDED
#define FUNCTESTE_H_INCLUDED

using namespace std;

class func_teste
{
public:
  static void func_test(string path);

private:
  static void sorteia_numero(int vet[], int n, int qtddReg);
  static bool verifica_numero(int vet[], int n, int aux);
  static void callTeste(int tamT, int tamA);
};

#endif // ARTISTS_H_INCLUDED