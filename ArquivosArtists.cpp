#include <iostream>
#include "list"
#include "ArquivosArtists.h"
#include "fstream"

using namespace std;


 ArquivosArtists::ArquivosArtists()
 {
    fstream arquivo;
    string linha;
    list<string> listaArtists;
    int cont=0;

    arquivo.open("artists.csv", ios::in);

    if (arquivo.is_open())
    {
        while (getline(arquivo, linha))
        {

            listaArtists.push_back(linha);
        }
        arquivo.close();
    }
    else
    {
        cout << "Nao foi possivel abrir o arquivo (Arquivo nao esta aberto)" << endl;
    }

    int tam= listaArtists.size();
    ArquivoArtists vet[tam];

    for(int i=0;i<tam;i++)
    {



    }



}
ArquivosArtists::~ArquivosArtists() {

}








