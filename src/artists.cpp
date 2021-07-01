#include <iostream>
#include <fstream>
#include "Artists.h"
#include <list>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <list>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;
uint64_t xzero;

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
            lista.push_back(art); //adiciona na lista

            art.id = "";
            art.followers = 0;
            art.genres = "";
            art.name = "";
            art.popularity = 0;
            auxFollowers = "";
            auxPopularity = "";
        }
        cout << "\n id = " << this->id
             << "\n name = " << this->name
             << "\n genres = " << this->genres;
        arquivo.close();
        TransformaArtistBin();
    }

    else
    {
        cout << "Nao foi possivel abrir o arquivo (Arquivo nao esta aberto)art\n"
             << endl;
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
            arti = converteToAux(art);
            arquivoArtistBin.write((char *)&arti, sizeof(artistsAux));
        }
    }
    else
    {
        cout << "N foi possivel abrir o arquivo" << endl;
    }
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

    arti.id = concatenaArtists(art.id);
    arti.followers = art.followers;
    arti.followers = art.followers;
    arti.genres = concatenaArtists(art.genres);
    arti.name = concatenaArtists(art.name);
    arti.popularity = art.popularity;

    return arti;
}

//função para transformar vetores de caracteres em string

string Artists::concatenaArtists(char linha[])
{
    string concatena = "";
    for (int i = 0; linha[i] != '\0'; i++)
    {
        concatena += linha[i];
    }
    return concatena;
}
/* bool Artists::verifica_numero(int vet[], int n, int aux)
{
    for (int i = 0; i < n; i++)
        if (i == aux)
            return true;
    return false;
}
 */

uint64_t myRand(int tam)
{
    int a = 6521;
    int b = 56152;
  //  cout << "a " << a << " b " << b << endl;
    xzero = (uint64_t)(a * xzero + b) % tam;
    return xzero;
}
// função que sorteia o numero da posiçao dos registros a serem coletados para impressao
void Artists::sorteia_numero(int vet[], int n, int qtddReg) //funçao para sortear a posiçao dos registros a serem impressos na tela ou arquivo
{
    xzero = 5009;
    int aux;
    int cont;

    for (int i = 0; i < n; i++)
    {
        cout << i << "\n ";
       /*  cont = 0;
        for (int j = 0; j < qtddReg; j++)
        {
            if (vet[j] != -1)
                cont++; 
        }*/
     //   cout << cont << "--------------\n";
        do
        {
            aux = myRand(qtddReg);

        //    cout << aux << "-->" << qtddReg << "\n ";
        } while (vet[aux] != -1); //verifica_numero(vet, n, aux)

        vet[aux] = 1;
    }
}
vector<artists> Artists::registrosArt(int n, int tam)
//list<artists> Artists::registrosArt(int n, int tam)
{
    // list<artists> list;
    vector<artists> vect;
    cout << "for\n";
    int *vet = (int *)malloc(tam * sizeof(int));

    for (int i = 0; i < tam; i++)
        vet[i] = -1;

    cout << "sort\n";
    sorteia_numero(vet, n, tam);
    cout << "sorted\n";
    for (int i = 0; i < tam; i++)
    {
        if (vet[i] == 1)
        {
            artists art;
            artistsAux arti;
            //abertura do arquivo binario
            ifstream fin;
            fin.open("../print/artists.bin", ios::in);

            //estrutura auxiliar
            // pegando a posiçao em bytes
            int posicao = i * sizeof(artistsAux);
            // posicionando o ponteiro na posiçao a ser lida
            fin.seekg(posicao, ios::beg);
            //lendo o registro em uma estrurura aux com vetores de caracteres

            fin.read((char *)&arti, sizeof(artistsAux));
            // convertendo os vetores
            //de caracteres da estrutura auxiliar e atribuindo ela à estrutura padrao
            art = Artists ::converteArtToString(arti);
            //  list.push_back(art);
            vect.push_back(art);
            fin.close(); // fechando o arquivo binarios
        }
    }

    // return list;
    free(vet);
    return vect;
}