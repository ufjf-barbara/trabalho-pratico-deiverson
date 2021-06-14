
#include <iostream>
#include <fstream>
#include "Artists.h"
#include <list>

using namespace std;

Artists::Artists(string path)
{

    leArquivo(path+"/artiststeste.txt");
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
                    art.followers += linha[i];
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
                    art.popularity += int(linha[i]);
                }
            }

            cont = 0;
            lista.push_back(art);
           /* cout << art.id << " ---";
            cout << art.followers << "---";
            cout << art.genres << "---";
            cout << art.name << "--- ";
            cout << art.popularity << endl;*/
            art.id = "";
            art.followers = 0;
            art.genres = "";
            art.name = "";
            art.popularity = 0;
        }

        arquivo.close();
    }

    else
    {
        cout << "Nao foi possivel abrir o arquivo (Arquivo nao esta aberto)" << endl;
    }
}
void Artists ::TransformaArtistBin() // Fun��o que transforma o arquivo artists.csv em bin�rio
{
    ofstream arquivoArtistBin;
    arquivoArtistBin.open("../arquivo/artists.bin", ios::binary);
    if (arquivoArtistBin.is_open())
    {
        for (artists art : lista)
        {
            arquivoArtistBin.write((char *)&art, sizeof(artists));
        }
    }
    else
    {
        cout << "N foi possivel abrir o arquivo" << endl;
    }
    arquivoArtistBin.close();
}
