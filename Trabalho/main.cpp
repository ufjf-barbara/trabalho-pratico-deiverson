#include <list>
#include "Artists.h"
#include "Tracks.h"
#include "functeste.h"
#include <fstream>  //leitura e escrita de arquivos
#include <iostream> //entrada pelo teclado e saida pela prompt
#include <time.h>   // trabalhar com o relogio do sistema
#include <stdlib.h>

using namespace std;

int main()
{

    Artists *arti = new Artists("artiststeste.txt");
    arti->TransformaArtistBin();

    Tracks *tr = new Tracks("tracksteste.txt");
    tr->TransformaTrackBin();
    func_teste *teste = new func_teste();

    return 0;
}
