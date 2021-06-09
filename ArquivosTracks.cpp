#include <iostream>
#include "list"
#include "ArquivosTracks.h"
#include "fstream"


using namespace std;

ArquivosTracks::ArquivosTracks()
{

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

ArquivosTracks::~ArquivosTracks()
{

}