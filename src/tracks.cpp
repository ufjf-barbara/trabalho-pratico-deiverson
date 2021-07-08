#include "Tracks.h"
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <sstream>
#include <string.h>
#include <algorithm>

using namespace std;

Tracks ::Tracks(string path)
{
    id = 0;
    name = 0;
    artists = 0;
    id_artists = 0;
    release_date = 0;
    leArquivo(path + "./tracks.csv");
}
Tracks ::Tracks()
{
}
Tracks::~Tracks()
{
}

//GETTERS E SETTERS

list<tracks> Tracks::getList()
{
    return lista;
}

//METODOS

void Tracks::leArquivo(string path)
{

    tracks tr;

    fstream arquivo;
    string linha;
    arquivo.open(path, ios::in);

    //variaveis utilizadas para conversão de string para valor numerico

    string auxPopularity;
    string auxDuration_ms;
    string auxexplicit_;
    string auxdanceability;
    string auxenergy;
    string auxkey;
    string auxloudness;
    string auxmode;
    string auxspeechiness;
    string auxacousticness;
    string auxinstrumentalness;
    string auxliveness;
    string auxvalence;
    string auxtempo;
    string auxtime_signature;

    int cont = 0;
    bool verifica;
    if (arquivo.is_open())
    {
        getline(arquivo, linha);
        while (getline(arquivo, linha))
        {
            int contid = 0;
            int contname = 0;
            int contartists = 0;
            int contid_artists = 0;
            int contrelease_date = 0;

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
                    cont++; //verifica posiçao do atributo na struct
                    i++;
                }
                if (cont == 0)
                {
                    contid++;
                    tr.id += linha[i];
                }
                if (cont == 1)
                {
                    contname++;
                    tr.name += linha[i];
                }
                if (cont == 2)
                {
                    auxPopularity += linha[i];
                    istringstream(auxPopularity) >> tr.popularity; //converte string para valor numerico
                }
                if (cont == 3)
                {
                    auxDuration_ms += linha[i];
                    istringstream(auxDuration_ms) >> tr.duration_ms;
                }
                if (cont == 4)
                {
                    auxexplicit_ += linha[i];
                    istringstream(auxexplicit_) >> tr.explicit_;
                }
                if (cont == 5)
                {
                    contartists++;
                    tr.artists += linha[i];
                }
                if (cont == 6)
                {
                    contid_artists++;
                    tr.id_artists += linha[i];
                }
                if (cont == 7)
                {
                    contrelease_date++;
                    tr.release_date += linha[i];
                }
                if (cont == 8)
                {
                    auxdanceability += linha[i];
                    istringstream(auxdanceability) >> tr.danceability;
                }
                if (cont == 9)
                {
                    auxenergy += linha[i];
                    istringstream(auxenergy) >> tr.energy;
                }
                if (cont == 10)
                {
                    auxkey += linha[i];
                    istringstream(auxkey) >> tr.key;
                }
                if (cont == 11)
                {
                    auxloudness += linha[i];
                    istringstream(auxloudness) >> tr.loudness;
                }
                if (cont == 12)
                {
                    auxmode += linha[i];
                    istringstream(auxmode) >> tr.mode;
                }
                if (cont == 13)
                {
                    auxspeechiness += linha[i];
                    istringstream(auxspeechiness) >> tr.speechiness;
                }
                if (cont == 14)
                {
                    auxacousticness += linha[i];
                    istringstream(auxacousticness) >> tr.acousticness;
                }
                if (cont == 15)
                {
                    auxinstrumentalness += linha[i];
                    istringstream(auxinstrumentalness) >> tr.instrumentalness;
                }
                if (cont == 16)
                {
                    auxliveness += linha[i];
                    istringstream(auxliveness) >> tr.liveness;
                }
                if (cont == 17)
                {
                    auxvalence += linha[i];
                    istringstream(auxvalence) >> tr.valence;
                }
                if (cont == 18)
                {
                    auxtempo += linha[i];
                    istringstream(auxtempo) >> tr.tempo;
                }
                if (cont == 19)
                {
                    auxtime_signature += linha[i];
                    istringstream(auxtime_signature) >> tr.time_signature;
                }
            }
            cont = 0;

            lista.push_back(tr); //adiciona na lista

            //zerando variaveis para reutilizalas

            if (this->id < contid)
                this->id = contid;
            if (this->name < contname)
                this->name = contname;
            if (this->artists < contartists)
                this->artists = contartists;
            if (this->id_artists < contid_artists)
                this->id_artists = contid_artists;
            if (this->release_date < contrelease_date)
                this->release_date = contrelease_date;

            tr.id = "";
            tr.name = "";
            tr.popularity = 0;
            tr.duration_ms = 0;
            tr.explicit_ = 0;
            tr.artists = "";
            tr.id_artists = "";
            tr.release_date = "";
            tr.danceability = 0;
            tr.energy = 0;
            tr.key = 0;
            tr.loudness = 0;
            tr.mode = 0;
            tr.speechiness = 0;
            tr.acousticness = 0;
            tr.instrumentalness = 0;
            tr.liveness = 0;
            tr.valence = 0;
            tr.tempo = 0;
            tr.time_signature = 0;

            //zerando variaveis auxiliares

            auxPopularity = "";
            auxDuration_ms = "";
            auxexplicit_ = "";
            auxdanceability = "";
            auxenergy = "";
            auxkey = "";
            auxloudness = "";
            auxmode = "";
            auxspeechiness = "";
            auxacousticness = "";
            auxinstrumentalness = "";
            auxliveness = "";
            auxvalence = "";
            auxtempo = "";
            auxtime_signature = "";
        }
        cout << "\n\nid = " << this->id
             << "\nname = " << this->name
             << "\nartists = " << this->artists
             << "\nid_artists = " << this->id_artists
             << "\n release_date = " << this->release_date << endl;

        arquivo.close();
        TransformaTrackBin();
    }
    else
    {
        cout << "Nao foi possivel abrir o arquivo (Arquivo nao esta aberto)tracks" << endl;
    }
}
void Tracks ::TransformaTrackBin() // Função que transforma o arquivo artists.csv em binário
{
    ofstream arquivoTrackBin;
    arquivoTrackBin.open("../print/tracks.bin", ios::binary);
    tracksAux tra;
    if (arquivoTrackBin.is_open())
    {
        for (tracks tr : lista)
        {
            tra = converteToAux(tr);
            arquivoTrackBin.write((char *)&tra, sizeof(tracksAux));
        }
    }
    else
    {
        cout << "N foi possível abrir o arquivo track \n"
             << endl;
    }
    arquivoTrackBin.close();
}

//converte os campos de string para vetores de caracteres

tracksAux Tracks::converteToAux(tracks tr)
{
    tracksAux tra;

    strcpy(tra.id, tr.id.c_str());
    strcpy(tra.name, tr.name.c_str());
    tra.popularity = tr.popularity;
    tra.duration_ms = tr.duration_ms;
    tra.explicit_ = tr.explicit_;
    strcpy(tra.artists, tr.artists.c_str());
    strcpy(tra.id_artists, tr.id_artists.c_str());
    strcpy(tra.artists, tr.artists.c_str());
    strcpy(tra.release_date, tr.release_date.c_str());
    tra.danceability = tr.danceability;
    tra.energy = tr.energy;
    tra.key = tr.key;
    tra.loudness = tr.loudness;
    tra.mode = tr.mode;
    tra.speechiness = tr.speechiness;
    tra.acousticness = tr.acousticness;
    tra.instrumentalness = tr.instrumentalness;
    tra.liveness = tr.liveness;
    tra.valence = tr.valence;
    tra.tempo = tr.tempo;
    tra.time_signature = tr.time_signature;

    return tra;
}

//converte vetores de caracteres para strings

tracks Tracks::converteTracksToString(tracksAux tr)
{
    tracks tra;

    tra.id = concatenaTracks(tr.id);
    tra.name = concatenaTracks(tr.name);
    tra.popularity = tr.popularity;
    tra.duration_ms = tr.duration_ms;
    tra.explicit_ = tr.explicit_;
    tra.artists = concatenaTracks(tr.artists);
    tra.id_artists = concatenaTracks(tr.id_artists);
    tra.artists = concatenaTracks(tr.artists);
    tra.release_date = tr.release_date;
    tra.danceability = tr.danceability;
    tra.energy = tr.energy;
    tra.key = tr.key;
    tra.loudness = tr.loudness;
    tra.mode = tr.mode;
    tra.speechiness = tr.speechiness;
    tra.acousticness = tr.acousticness;
    tra.instrumentalness = tr.instrumentalness;
    tra.liveness = tr.liveness;
    tra.valence = tr.valence;
    tra.tempo = tr.tempo;
    tra.time_signature = tr.time_signature;

    return tra;
}

//função para transformar vetores de caracteres em string

string Tracks::concatenaTracks(char linha[])
{
    string concatena = "";
    for (int i = 0; linha[i] != '\0'; i++)
    {
        concatena += linha[i];
    }
    return concatena;
}
vector<tracks> Tracks::registrosTr(int n, int tam)
{
    vector<tracks> vect;
    vector<int> vet;
    for (int i = 0; i < tam; i++)
    {
        vet.push_back(i);
    }
    random_shuffle(vet.begin(), vet.end());

    for (int i = 0; i < n; i++)
    {
        tracks tr;
        tracksAux tra;
        //abertura do arquivo binario
        ifstream fin;
        fin.open("../print/tracks.bin", ios::in);

        //estrutura auxiliar

        // pegando a posiçao em bytes
        int posicao = vet[i] * sizeof(tracksAux);
        // posicionando o ponteiro na posiçao a ser lida
        fin.seekg(posicao, ios::beg);
        //lendo o registro em uma estrurura aux com vetores de caracteres

        fin.read((char *)&tra, sizeof(tracksAux));
        // convertendo os vetores
        //de caracteres da estrutura auxiliar e atribuindo ela à estrutura padrao
        tr = Tracks ::converteTracksToString(tra);
        vect.push_back(tr);
        fin.close(); // fechando o arquivo binario
    }

    return vect;
}
