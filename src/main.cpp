#include "Artists.h"
#include "Tracks.h"
#include "functeste.h"
#include <fstream>  //leitura e escrita de arquivos
#include <iostream> //entrada pelo teclado e saida pela prompt
#include <time.h>   // trabalhar com o relogio do sistema
#include <string.h>

using namespace std;

int main(int argc, char **argv)
{

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
    if (!trbin.is_open()) // Verificaçao pra saber se o arquivo Tracks.bin ja foi criado, caso nao, ler o Tracks.csv e cria-lo
    {
        trbin.close();
        Tracks *tr = new Tracks(path);
        delete tr;
    }

    artbin.close();
    trbin.close();

    int aux = 1;
    while (aux != 0)
    {
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "O que deseja executar? (Digite o numero conrespondente a opcao desejada)\n";
        cout << "[1] Ordenacao\n[2] Hash\n[3] Modulo teste\n[0] Finalizar\n";
        cout << "--------------------------------------------------------------------------" << endl;
        cin >> aux;

        cin.ignore();
        switch (aux)
        {
        case 0:
            break;
        case 1:
            //Chamar  Ordenacao;
            break;
        case 2:
            //Chamar  Hash;
            break;
        case 3:
            //Chamar  Modulo Teste;
            break;
        default:
            cout<<"\nOpcao invalida\n";
        }
    }
    func_teste::func_test(path); // chamada para executar a funçao teste

    return 0;
}
