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
    char name[322];
    int popularity;
};

class Artists
{

private:
    list<artists> lista;

public:
    Artists(string path);
    Artists();

    ~Artists();

    //metodos
    list<artists> getList();
    artistsAux converteToAux(artists art);
    void leArquivo(string path);
    void TransformaArtistBin();
    static artists converteArtToString(artistsAux art);
    static string concatenaArtists(char linha[]);

    //METODOS estaticos
    static vector<pair<int, float>> registrosArtFollowers(int n, int tam);
    static vector<artists> registrosArt(int n, int tam);
    // static list<artists> registrosArt(int n, int tam);

    // contadores
    int id;
    int name;
    int genres;
};

#endif // ARTISTS_H_INCLUDED
