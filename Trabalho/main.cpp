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
    cout << "\n\n\n\n\n\n\n"<< path <<"\n\n\n\n\n\n\n";
    Artists *arti = new Artists(path);
    arti->TransformaArtistBin();//colocar o endereço certo e criar string path como atributo pra classe

    Tracks *tr = new Tracks(path);
    tr->TransformaTrackBin();//colocar o endereço certo e criar string path como atributo pra classe
    func_teste *teste = new func_teste(path); 

    return 0;
}
