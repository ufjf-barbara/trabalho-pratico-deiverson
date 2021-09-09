#include <iostream>
#include <map>
#include <stdio.h>
#include <queue>
#include <vector>
#include <sstream>
#include <fstream>
#include <time.h>
#include <utility>
#include "Tracks.h"
#include "Artists.h"

using namespace std;


int display();
void call(string path);
void parteTres();
void parteDois();
void parteUm(string path);
void parteQuatro();



int main(int argc, char **argv)
{
    srand(time(NULL));
    string path = argv[1];

    srand(time(NULL));
    string path = argv[1];

    ifstream artbin, trbin;

    artbin.open("../print/artists.bin", ios::in | ios::binary);
    trbin.open("../print/tracks.bin", ios::in | ios::binary);

    if (!artbin.is_open()) // Verificaçao pra saber se o arquivo Artists.bin ja foi criado, caso nao, ler o Artist.csv e cria-lo
    {
        artbin.close();
        Artists *arti = new Artists(path);
        delete arti;
    }
    artbin.close();
    if (!trbin.is_open()) // Verificaçao pra saber se o arquivo Tracks.bin ja foi criado, caso nao, ler o Tracks.csv e cria-lo
    {
        trbin.close();
        Tracks *tr = new Tracks(path);
        delete tr;
    }
    trbin.close();

    ofstream saida("../print/saida.txt", ios::out | ios::trunc);
    saida.close();

    call(path);

    return 0;
}

void call(string path) // funçao para chamar as execuçoes do trabalho
{
    int aux = 1;
    while (aux != 0)
    {
        cout << "\n-----------------------------------------------------------------------------------------------------\n"
             << endl;
        cout << "Qual parte do trabalho deseja executar? (Digite o numero conrespondente a opcao desejada)\n";
        cout << "[1] Primeira parte\n[2] Segunda parte\n[3] Terceira parte\n[4] Quarta Parte \n[0] Finalizar\n";
        cout << "\n-----------------------------------------------------------------------------------------------------\n";
        cin >> aux;
        cin.ignore();
        if (aux >= 0 && aux <= 4)
        {
            switch (aux)
            {
            case 0:
                break;
            case 1:
                parteUm(path); //chama a primeira parte do trabalho
                break;
            case 2:
                parteDois(); //chama a segunda parte do trabalho
                break;
            case 3:
                parteTres();
                break;
            case 4:
                parteQuatro();
                break;
            default:
                cout << "\nOpcao invalida\n";
            }
        }
    }
}