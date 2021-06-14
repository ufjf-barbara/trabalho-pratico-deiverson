#include <iostream>
#include <fstream>
#include <list>
#include "Artists.h"
#include "Tracks.h"

using namespace std;

int main()
{

     Artists *arti=new Artists("artiststeste.txt");
    // arti->TransformaArtistBin();
    Tracks *tr = new Tracks("tracksteste.txt");
    
    // tr->TransformaTrackBin();
   
    return 0;

}
