#include <iostream>
#include <fstream>
#include <list>
#include <vector>

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
    static artists converteArtToString(artistsAux art);
    void leArquivo(string path);
    void TransformaArtistBin();
    static string concatenaArtists(char linha[]);

    //METODOS estaticos
    
    static bool verifica_numero(int vet[], int n, int aux);
    static void sorteia_numero(int vet[], int n, int qtddReg);
    static vector<artists> registrosArt(int n, int tam);
   //' static list<artists> registrosArt(int n, int tam);

    // contadores
    int id;
    int name;
    int genres;
};

#endif // ARTISTS_H_INCLUDED
