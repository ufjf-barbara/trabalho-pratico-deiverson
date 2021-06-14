#include <list>
#include "Artists.h"
#include "Tracks.h"
#include "functeste.h"
#include <fstream>  //leitura e escrita de arquivos
#include <iostream> //entrada pelo teclado e saida pela prompt
#include <time.h>   // trabalhar com o relogio do sistema
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv)
{
    //colocar verificaçao pra caso os arquivos bin ja existam!!!!11

    string path = argv[1];

    ifstream artbin, trbin;

    artbin.open("../arquivo/artists.bin", ios::in);
    trbin.open("../arquivo/tracks.bin", ios::in);

    if (!(artbin.is_open() && trbin.is_open()))

    {
        artbin.close();
        trbin.close();

        cout << "vai criar arquivo" << endl;

        Artists *arti = new Artists(path);
        delete arti;

        //  arti->TransformaArtistBin() ; //colocar o endereço certo e criar string path como atributo pra classe

        Tracks *tr = new Tracks(path);
        delete tr;

        // tr->TransformaTrackBin(); //colocar o endereço certo e criar string path como atributo pra classe
    }
    Artists *ar = new Artists();
    Tracks *tra = new Tracks();

    func_teste *teste = new func_teste(path);

    return 0;
}
