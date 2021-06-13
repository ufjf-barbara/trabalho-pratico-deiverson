#include <iostream>
#include <fstream>
#include "Tracks.h"
#include <list>

using namespace std;

Tracks ::Tracks(string path)
{

    cout << "Criando objeto tracks" << endl;
    leArquivo(path);
}

Tracks::~Tracks()
{
    cout << "deletando objeto tracks " << endl;
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
    arquivo.open(path,ios::in);

    int cont=0;
    bool verifica;
    if(arquivo.is_open())
    {
        getline(arquivo,linha);
        while(getline(arquivo,linha))
        {
            for(int i=0; i<linha.size(); i++)
            {
                if(linha[i]=='[')
                {
                    verifica=1;
                }
                if(linha[i]==']')
                {
                    verifica=0;
                }
                if(linha[i]==',' && verifica==0)
                {
                    cont++;
                    i++;
                }
                if(cont==0)
                {
                    tr.id+=linha[i];
                }
                if(cont==1)
                {
                    tr.name+=linha[i];
                }
                if(cont==2)
                {

                    tr.popularity+=linha[i];
                }
                if(cont==3)
                {

                    tr.duration_ms+=linha[i];
                }
                if(cont==4)
                {
                    tr. explicit_+=linha[i];


                }
                if(cont==5)
                {
                    tr.artists+=linha[i];

                }
                if(cont==6)
                {
                    tr.id_artists+=linha[i];

                }
                if(cont==7)
                {
                    tr.release_date+=linha[i];

                }
                if(cont==8)
                {
                    tr.danceability+=linha[i];


                }
                if(cont==9)
                {
                    tr.energy+=linha[i];

                }
                if(cont==10)
                {
                    tr.key+=linha[i];

                }
                if(cont==11)
                {
                    tr.loudness+=linha[i];


                }
                if(cont==12)
                {
                    tr.mode+=linha[i];


                }
                if(cont==13)
                {
                    tr.speechiness+=linha[i];


                }
                if(cont==14)
                {

                    tr.acousticness+=linha[i];

                }
                if(cont==15)
                {
                    tr.instrumentalness+=linha[i];


                }
                if(cont==16)
                {
                    tr.liveness+=linha[i];


                }
                if(cont==17)
                {
                    tr.valence+=linha[i];


                }
                if(cont==18)
                {
                    tr.tempo+=linha[i];

                }
                if(cont==19)
                {
                    tr.time_signature+=linha[i];

                }


            }
            cont=0;
            cout << tr.id << "---" << tr.name << "---" << tr.popularity << "---" << tr.duration_ms << "---" << tr.explicit_ << "---" << tr.artists << "---" << tr.id_artists << "---" << tr.release_date << "---" << tr.danceability << "---" << tr.energy << "---" << tr.key << "---" << tr.loudness << "---" << tr.mode << "---" << tr.speechiness << "---" << tr.acousticness << "---" << tr.instrumentalness
                 << "---" << tr.liveness << "---" << tr.valence << "---" << tr.tempo << "---" << tr.time_signature << endl;

            lista.push_back(tr);

            tr.id="";
            tr.name="";
            tr.popularity=NULL;
            tr.duration_ms=NULL;
            tr.explicit_=NULL;
            tr.artists="";
            tr.id_artists="";
            tr.release_date="";
            tr.danceability=NULL;
            tr.energy=NULL;
            tr.key=NULL;
            tr.loudness=NULL;
            tr.mode=NULL;
            tr.speechiness=NULL;
            tr.acousticness=NULL;
            tr.instrumentalness=NULL;
            tr.liveness=NULL;
            tr.valence=NULL;
            tr.tempo=NULL;
            tr.time_signature=NULL;

        }
        arquivo.close();
    }
    else
    {
        cout<<"Nao foi possivel abrir o arquivo (Arquivo nao esta aberto)"<<endl;
    }

}

void Tracks ::TransformaTrackBin() // Função que transforma o arquivo artists.csv em binário
{
    ofstream arquivoTrackBin;
    arquivoTrackBin.open("tracks.bin", ios::binary);

    if (arquivoTrackBin.is_open())
    {
        for (tracks tr : lista)
        {
            arquivoTrackBin.write((char *)&tr, sizeof(tr));
        }
    }
    else
    {
        cout << "N foi possível abrir o arquivo" << endl;
    }
    arquivoTrackBin.close();
}
