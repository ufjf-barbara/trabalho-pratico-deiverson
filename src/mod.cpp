#include "tracks.h"
#include <iostream>
#include <vector>
#include <fstream>

int main()
{
    ifstream finT;
    finT.open("../print/tracks.bin", ios::in | ios::binary);
    finT.seekg(0, finT.end);
    if (finT.is_open())
    {
        cout << "ta aberto" << endl;
    }

    int tam = finT.tellg() / sizeof(tracksAux);
    cout << finT.tellg() << endl;

    vector<tracks> vet = Tracks::registrosTr(tam, tam);

    int mod = 0;
    int aux = 0;
    for (int i = 0; i < tam; i++)
    {
        aux = vet[i].id_artists[3] * vet[i].id_artists[9] * vet[i].id_artists[6];
        if (aux > mod)
            mod = aux;
    }
        cout << mod << endl;
    return 1;
}
