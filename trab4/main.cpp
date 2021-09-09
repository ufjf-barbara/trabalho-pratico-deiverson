#include <iostream>
#include <map>
#include <stdio.h>
#include <queue>
#include <vector>
#include <sstream>
#include <fstream>
#include <time.h>
#include <utility>

using namespace std;

void display(string path);
void parteTres();
void parteDois();
void parteUm(string path);
void parteQuatro();

int main(int argc, char **argv)
{
    display(argv[1]);

    return 0;
}

void display(string path) // funçao para chamar as execuçoes do trabalho
{
    int aux = 1;
    while (aux != 0)
    {
        cout << "\n-----------------------------------------------------------------------------------------------------\n"
             << endl;
        cout << "O que deseja executar? (Digite o numero conrespondente a opcao desejada)\n";
        cout << "[1]Casamento de padroes\n[2] Compressao \n[0] Finalizar\n";
        cout << "\n-----------------------------------------------------------------------------------------------------\n";
        cin >> aux;
        cin.ignore();
        if (aux >= 0 && aux <= 2)
        {
            switch (aux)
            {
            case 0:
                break;
            case 1:

                parteUm(path); //chama a primeira parte do trabalho
                break;
            case 2:
                
                break;
            default:
                cout << "\nOpcao invalida\n";
            }
        }
    }
}