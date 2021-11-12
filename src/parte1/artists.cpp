#include "headers/Artists.h"

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
#include <utility>

using namespace std;

Artists::Artists(string path)
{
    id = 0;
    name = 0;
    genres = 0;

    leArquivo(path + "./artists.csv");
}

Artists::Artists()
{
}

Artists::~Artists()
{
}

//METODOS

void Artists::leArquivo(string path)
{
    fstream arquivo;
    string linha;
    arquivo.open(path, ios::in);

    ofstream arquivoArtistBin;
    arquivoArtistBin.open("../print/artists.bin", ios::binary | ios::out);
    artistsAux arti;
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

            int contid = 0;
            int contname = 0;
            int contgenres = 0;

            for (int i = 0; i < linha.size(); i++)
            {
                if (linha[i] == '[') //verificaçao de virgulas no meio de colchetes
                {
                    verifica = 1;
                }
                if (linha[i] == ']')
                {
                    verifica = 0;
                }
                if (linha[i] == ',' && verifica == 0)
                {
                    cont++; //variavel para verificar qual atribut esta
                    i++;
                }
                if (cont == 0)
                {
                    contid++;
                    art.id += linha[i];
                }
                if (cont == 1)
                {
                    auxFollowers += linha[i];
                    istringstream(auxFollowers) >> art.followers; //usado para converter strings para valor numerico
                }
                if (cont == 2)
                {
                    contgenres++;
                    art.genres += linha[i];
                }
                if (cont == 3)
                {
                    contname++;
                    art.name += linha[i];
                }
                if (cont == 4)
                {
                    auxPopularity += linha[i];
                    istringstream(auxPopularity) >> art.popularity;
                }
                if (this->id < contid)
                    this->id = contid;
                if (this->name < contname)
                    this->name = contname;
                if (this->genres < contgenres)
                    this->genres = contgenres;
            }

            cont = 0;

            // Escrita---------------------------------------------------------------------------

            arti = converteToAux(art);
            arquivoArtistBin.write((char *)&arti, sizeof(artistsAux)); // chamada de funçao pra escrita em binario

            //-----------------------------------------------------------------------------------

            art.id = "";
            art.followers = 0;
            art.genres = "";
            art.name = "";
            art.popularity = 0;
            auxFollowers = "";
            auxPopularity = "";
        }
        // prints para saber os tamanhos dos vetores de caracteres
        // cout << "\n id = " << this->id
        //      << "\n name = " << this->name
        //      << "\n genres = " << this->genres;
    }

    else
    {
        cout << "\nNao foi possivel abrir o arquivo artists.csv\n"
             << endl;
    }
    arquivo.close();
    arquivoArtistBin.close();
}

//converte os campos de string para vetores de caracteres
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

//converte vetores de caracteres para strings
artists Artists::converteArtToString(artistsAux art)
{
    artists arti;

    arti.id.assign(art.id, strlen(art.id));
    arti.followers = art.followers;
    arti.genres.assign(art.genres, strlen(art.genres));
    arti.name.assign(art.name, strlen(art.name));
    arti.popularity = art.popularity;

    return arti;
}

//função para transformar vetores de caracteres em string
vector<artists> Artists::registrosArt(int n, int tam)
{
    vector<artists> vect;

    //Embaralhamento de um vector para obter registros aleatoriamente-----
    vector<int> vet;
    for (int i = 0; i < tam; i++)
    {
        vet.push_back(i);
    }
    random_shuffle(vet.begin(), vet.end());
    //--------------------------------------------------------------------

    // Leitura dos registros--------------------------------------
    for (int i = 0; i < n; i++)
    {
        vect.push_back(reg(vet[i]));
    }
    //-------------------------------------------------------------
    return vect;
}

vector<pair<int, float>> Artists::registrosArtFollowers(int n, int tam) //funçao para retornar vector<pair<int, float>> para as funçoes de ordenaçao de artists
{
    vector<pair<int, float>> vect;

    //Embaralhamento de um vector para obter registros aleatoriamente-----
    vector<int> vet;
    for (int i = 0; i < tam; i++)
    {
        vet.push_back(i);
    }
    random_shuffle(vet.begin(), vet.end());
    //--------------------------------------------------------------------

    // Leitura dos registros--------------------------------------
    for (int i = 0; i < n; i++)
    {
        pair<int, float> paer(vet[i], reg(vet[i]).followers);

        vect.push_back(paer);
    }
    //-------------------------------------------------------------
    return vect;
}

int Artists::getTAM()
{
    ifstream fin;
    fin.open("../print/artists.bin", ios::in);
    fin.seekg(0, fin.end);// posicionamento do ponteiro no final do arquivo
    int tam = fin.tellg() / sizeof(artistsAux);//tamamnho do arquivo dividido pelo tamnho da estrutura para saber a quantidade de registrosArtFollowers
    fin.close();
    return tam;
}

artists Artists::reg(int i)
{
    artistsAux arti;
    //abertura do arquivo binario
    ifstream fin;
    fin.open("../print/artists.bin", ios::in | ios::binary);
    //estrutura auxiliar
    // pegando a posiçao em bytes
    int posicao = i * sizeof(artistsAux);
    // posicionando o ponteiro na posiçao a ser lida
    fin.seekg(posicao, ios::beg);
    //lendo o registro em uma estrurura aux com vetores de caracteres
    fin.read((char *)&arti, sizeof(artistsAux));

    fin.close(); // fechando o arquivo binarios

    // convertendo os vetores
    //de caracteres da estrutura auxiliar e atribuindo ela à estrutura padrao
    return Artists ::converteArtToString(arti);
}