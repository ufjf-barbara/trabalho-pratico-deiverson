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
    srand(time(NULL));

    string path = argv[1];

    ifstream artbin, trbin;

    artbin.open("../print/artists.bin", ios::in | ios::binary);
    trbin.open("../print/tracks.bin", ios::in | ios::binary);

    if (!artbin.is_open())
    {
        artbin.close();
        Artists *arti = new Artists(path);
        delete arti;
    }
    if (!trbin.is_open())
    {
        trbin.close();
        Tracks *tr = new Tracks(path);
        delete tr;
    }

    artbin.close();
    trbin.close();

    func_teste::func_test(path);

    return 0;
}
