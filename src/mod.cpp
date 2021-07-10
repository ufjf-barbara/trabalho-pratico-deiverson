#include "tracks.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;
    fin.open("../print/tracks.bin", ios::in | ios::binary);

    fin.seekg(0, fin.end);

    int tam = fin.tellg() / sizeof(tracksAux);
    cout << tam << endl;

    tracks tr;
    tracksAux tra;
    int mod = 0;
    int aux = 0;
    int j = 0;
    for (j = 1; j < 20; j++)
    {
        for (int i = 0; i < tam; i++)
        {
            int posicao = i * sizeof(tracksAux);
            fin.seekg(posicao, ios::beg);
            fin.read((char *)&tra, sizeof(tracksAux));
            tr = Tracks ::converteTracksToString(tra);

            aux = (tr.id_artists[9] * tr.id_artists[3] * tr.id_artists[19]) / 3 + 1;
            if (aux > mod)
            {
                mod = aux;
            }
        }
    cout << mod << endl;
    cout << j << endl;
    }
    return 0;
}
