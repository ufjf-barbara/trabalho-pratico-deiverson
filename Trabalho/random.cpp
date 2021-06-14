#include <fstream>  //leitura e escrita de arquivos
#include <iostream> //entrada pelo teclado e saida pela prompt
#include <time.h>   // trabalhar com o relogio do sistema
#include <stdlib.h>
using namespace std;

bool verifica_numero(int vet[], int n, int aux)
{
    for (int i = 0; i < n; i++)
        if (vet[i] == aux)
            return true;
    return false;
}

void sorteia_numero(int vet[], int n, int qtddReg) //funçao para sortear a posiçao dos registros a serem impressos na tela ou arquivo
{
    srand(time(NULL));
    int aux;
    for (int i = 0; i < n; i++)
    {
        do
        {
            aux = rand() % qtddReg;
        } while (verifica_numero(vet, n, aux));

        vet[i] = aux;
    }
}

int main(int argc, char **argv)
{
    int vet[10], qtddReg = 500;
    sorteia_numero(vet, 10, qtddReg);
    for (int i = 0; i < 10; i++)
        cout << vet[i] << "--";

    return 0;
}