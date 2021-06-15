
#include <iostream>
#include <fstream>
#include "Artists.h"
#include <list>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

Artists::Artists(string path)
{

    leArquivo(path + "./artists.csv");
}
Artists::Artists()
{
}
Artists::~Artists()
{
}

//GETTERS E SETTERS

list<artists> Artists::getList()
{
    return lista;
}

//METODOS

void Artists::leArquivo(string path)
{

    fstream arquivo;
    string linha;
    arquivo.open(path, ios::in);

    artists art;
    string auxFollowers = "";
    string auxPopularity = "";

    int cont = 0;
    bool verifica;
    if (arquivo.is_open())
    {
        getline(arquivo, linha);
        while (getline(arquivo, linha))
        {

            for (int i = 0; i < linha.size(); i++)
            {
                if (linha[i] == '[')
                {
                    verifica = 1;
                }
                if (linha[i] == ']')
                {
                    verifica = 0;
                }
                if (linha[i] == ',' && verifica == 0)
                {
                    cont++;
                    i++;
                }
                if (cont == 0)
                {
                    art.id += linha[i];
                }
                if (cont == 1)
                {
                    auxFollowers += linha[i];
                    istringstream(auxFollowers) >> art.followers;
                    //art.followers=atof(auxFollowers.c_str());
                    //atof()
                }
                if (cont == 2)
                {
                    art.genres += linha[i];
                }
                if (cont == 3)
                {
                    art.name += linha[i];
                }
                if (cont == 4)
                {
                    auxPopularity += linha[i];
                    istringstream(auxPopularity) >> art.popularity;
                }
            }

            cont = 0;
            lista.push_back(art);
 
            art.id = "";
            art.followers = 0;
            art.genres = "";
            art.name = "";
            art.popularity = 0;
            auxFollowers = "";
            auxPopularity = "";
        }

        arquivo.close();
        TransformaArtistBin();
    }

    else
    {
        cout << "Nao foi possivel abrir o arquivo (Arquivo nao esta aberto)" << endl;
    }
}

void Artists ::TransformaArtistBin() // Fun��o que transforma o arquivo artists.csv em bin�rio
{
    ofstream arquivoArtistBin;

    arquivoArtistBin.open("../print/artists.bin", ios::binary);
    if (arquivoArtistBin.is_open())
    {
        artistsAux arti;
        for (artists art : lista)
        {
            arti=converteToAux(art);
            arquivoArtistBin.write((char *)&arti, sizeof(artistsAux));
              /*    cout << arti.id
                      << "," << arti.followers
                      << "," << arti.genres
                      << "," << arti.name
                      << "," << arti.popularity
                      << endl; */
        }
    }
    else
    {
        cout << "N foi possivel abrir o arquivo" << endl;
    }
    arquivoArtistBin.close();
}
artistsAux Artists::converteToAux(artists art)
{
    artistsAux arti;

    strcpy(arti.id, art.id.c_str());
    arti.followers = art.followers;
    arti.followers = art.followers;
    strcpy(arti.genres, art.genres.c_str());
    strcpy(arti.name, art.name.c_str());
    arti.popularity = art.popularity;

    return arti;
}
artists Artists:: converteArtToString(artistsAux art)
{
    artists arti;

    arti.id = concatenaArtists(art.id);
    arti.followers = art.followers;
    arti.followers = art.followers;
    arti.genres = concatenaArtists(art.genres);
    arti.name = concatenaArtists(art.name);
    arti.popularity = art.popularity;

    return arti;
}
string Artists::concatenaArtists(char linha[])
{
    string concatena = "";
    for (int i = 0; linha[i] != '\0'; i++)
    {
        concatena += linha[i];
    }
    return concatena;
}
