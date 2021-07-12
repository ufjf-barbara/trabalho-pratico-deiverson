#include "tracks.h"
#include "tabelaHash.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    tabelaHash *hash = new tabelaHash();

    cout << "\n\ncolisisoes :\t"<<hash->getcont();

    return 0;
}
