#include "Artists.h"
#include "Tracks.h"
#include "functeste.h"
#include "Ordenacao.h"
#include "tabelaHash.h"

#include <fstream>  //leitura e escrita de arquivos
#include <iostream> //entrada pelo teclado e saida pela prompt
#include <time.h>   // trabalhar com o relogio do sistema
#include <string.h>

using namespace std;

void call(string path);
void parteDois(string path);
void parteUm(string path);

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
    artbin.close();
    if (!trbin.is_open()) // Verificaçao pra saber se o arquivo Tracks.bin ja foi criado, caso nao, ler o Tracks.csv e cria-lo
    {
        trbin.close();
        Tracks *tr = new Tracks(path);
        delete tr;
    }
    trbin.close();

    call(path);

    return 0;
}
void call(string path)
{
    int aux = 1;
    while (aux != 0)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------\n"<< endl;
        cout << "Qual parte do trabalho deseja executar? (Digite o numero conrespondente a opcao desejada)\n";
        cout << "[1] Primeira parte\n[2] Segunda parte\n[0] Finalizar\n";
        cout << "\n-------------------------------------------------------------------------------------------------------\n";
        cin >> aux;
        cin.ignore();
        if (aux >= 0 && aux <= 2)
        {
            switch (aux)
            {
            case 0:
                break;
            case 1:
                parteUm(path);
                break;
            case 2:
                parteDois(path);
                break;
            default:
                cout << "\nOpcao invalida\n";
            }
        }
    }
}

void parteDois(string path)
{

    int aux = 1;
    while (aux != 0)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------\n"<< endl;
        cout << "O que deseja executar? (Digite o numero conrespondente a opcao desejada)\n";
        cout << "[1] Ordenacao\n[2] Hash\n[3] Modulo teste\n[0] Finalizar\n";
        cout << "\n-------------------------------------------------------------------------------------------------------\n";
        cin >> aux;

        cin.ignore();

        Ordenacao ord;
        int r;
        ofstream saida;

        ifstream ns("input.dat", ios::in);
        string straux;

        tabelaHash *table;

        switch (aux)
        {
        case 0:
            break;
        case 1:
            //Chamar  Ordenacao;
            saida.open("../print/saida.txt", ios::out | ios::trunc);
            saida.close();
            while (getline(ns, straux))
            { cout << "Aguarde . . ."<<endl;
                istringstream(straux) >> r;
                ord.chamaFuncaoOrdenacao(r);
                cout << "Ordenacao para "<<r<<" registros concluida "<< endl;
            }
            break;

        case 2:
            //Chamar  Hash;
            table = new tabelaHash();
            break;

        case 3:
            //Chamar  Modulo Teste;
            func_teste::moduloTesteDois();
            break;

        default:
            cout << "\nOpcao invalida\n";
        }
    }
}

void parteUm(string path)
{
    func_teste::func_test(path); // chamada para executar a funçao teste
}