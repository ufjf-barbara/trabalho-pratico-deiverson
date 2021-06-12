#include <iostream>
#include <fstream>
#include <list>
#include "Artists.h"
#include "Tracks.h"

using namespace std;




int main()
{

    Artists *arti=new Artists("teste.txt");
    arti->TransformaArtistBin();
    return 0;
}







