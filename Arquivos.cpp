#include <iostream>
#include "Arquivos.h"
#include "list"

using  namespace  std;

Arquivos::Arquivos()
{

    //abrindo e inserindo na lista do tracks

    fstream arquivo;
    string linha;
    list<string> listaArtists;

    arquivo.open("artists.csv", ios::in);

    if (arquivo.is_open())
    {
        while (getline(arquivo, linha))
        {
            cout << linha << endl;
            listaArtists.push_back(linha);
        }
        arquivo.close();
    }
    else
    {
        cout << "Nao foi possivel abrir o arquivo (Arquivo nao esta aberto)" << endl;
    }


//abrindo e inserindo na lista do tracks

    fstream arquivo2;
    string linha2;
    list<string> listaTracks;

    arquivo.open("tracks.csv", ios::in);

    if (arquivo.is_open())
    {
        while (getline(arquivo2, linha2))
        {
            cout << linha2 << endl;
            listaTracks.push_back(linha2);
        }
        arquivo2.close();
    }
    else
    {
        cout << "Nao foi possivel abrir o arquivo (Arquivo nao esta aberto)" << endl;
    }
}

Arquivos::~Arquivos()
{

}
