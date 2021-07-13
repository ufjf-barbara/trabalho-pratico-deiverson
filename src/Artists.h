#include <iostream>
#include <fstream>
#include <list>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <list>
#include <vector>
#include <math.h>
#include <ctime>
#include <algorithm>

#ifndef ARTISTS_H_INCLUDED
#define ARTISTS_H_INCLUDED

using namespace std;

struct artists
{
    string id;
    float followers;
    string genres;
    string name;
    int popularity;
};
struct artistsAux
{
    char id[32];
    float followers;
    char genres[375];
    char name[375];
    int popularity;
};

class Artists
{

private:

 // contadores
    int id;
    int name;
    int genres;

public:
    Artists(string path);
    Artists();

    ~Artists();

    //metodos
    artistsAux converteToAux(artists art);
    void leArquivo(string path);
   // void TransformaArtistBin();
    static artists converteArtToString(artistsAux art);

    //METODOS estaticos
    static vector<pair<int, float>> registrosArtFollowers(int n, int tam);
    static vector<artists> registrosArt(int n, int tam);
    static int getTAM();


};

#endif // ARTISTS_H_INCLUDED
