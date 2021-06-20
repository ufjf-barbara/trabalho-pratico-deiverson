#include <iostream>
#include <fstream>
#include "Artists.h"
#include <list>
#include <string>
#include <sstream>

using namespace std;

Artists::Artists(string path)
{
    leArquivo(path);
}

Artists::~Artists()
{
    cout << "deletando leitura do arquivo Artists" << endl;
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
            cout << art.id << " ---";
            cout << art.followers << "---";
            cout << art.genres << "---";
            cout << art.name << "--- ";
            cout << art.popularity << endl;
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
void Artists ::TransformaArtistBin() // Função que transforma o arquivo artists.csv em binário
{
    ofstream arquivoArtistBin;
    arquivoArtistBin.open("artists.bin", ios::binary);

    cout << " " << endl;
    cout << "Transformando Artists.csv em Binario" << endl;
    cout << " " << endl;
    if (arquivoArtistBin.is_open())
    {
        for (artists art : lista)
        {
            arquivoArtistBin.write((char *)&art, sizeof(art));
        }
    }
    else
    {
        cout << "N foi possível abrir o arquivo" << endl;
    }
    arquivoArtistBin.close();
}