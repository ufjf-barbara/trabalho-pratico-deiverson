#include <iostream>
#include <fstream>
#include "Tracks.h"
#include <list>
#include <sstream>


using namespace std;

Tracks ::Tracks(string path)
{

    cout << "Criando objeto tracks" << endl;
    leArquivo(path+"./tracksteste.txt");
}
Tracks ::Tracks(){
    
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
    string  auxliveness;
    string  auxvalence;
    string auxtempo;
    string auxtime_signature;


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
                    auxPopularity+=linha[i];
                    istringstream(auxPopularity)>>tr.popularity;
                }
                if(cont==3)
                {
                    auxDuration_ms+=linha[i];
                    istringstream(auxDuration_ms)>>tr.duration_ms;
                }
                if(cont==4)
                {
                    auxexplicit_+=linha[i];
                    istringstream(auxexplicit_)>>tr. explicit_;

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
                    auxdanceability+=linha[i];
                    istringstream(auxdanceability)>>tr.danceability;

                }
                if(cont==9)
                {
                    auxenergy+=linha[i];
                    istringstream(auxenergy)>>tr.energy;

                }
                if(cont==10)
                {
                    auxkey+=linha[i];
                    istringstream(auxkey)>>tr.key;

                }
                if(cont==11)
                {
                    auxloudness+=linha[i];
                    istringstream(auxloudness)>>tr.loudness;


                }
                if(cont==12)
                {
                    auxmode+=linha[i];
                    istringstream(auxmode)>>tr.mode;


                }
                if(cont==13)
                {
                    auxspeechiness+=linha[i];
                    istringstream(auxspeechiness)>>tr.speechiness;


                }
                if(cont==14)
                {
                    auxacousticness+=linha[i];
                    istringstream(auxacousticness)>>tr.acousticness;

                }
                if(cont==15)
                {
                    auxinstrumentalness+=linha[i];
                    istringstream(auxinstrumentalness)>>tr.instrumentalness;


                }
                if(cont==16)
                {
                    auxliveness+=linha[i];
                    istringstream(auxliveness)>>tr.liveness;


                }
                if(cont==17)
                {
                    auxvalence+=linha[i];
                    istringstream(auxvalence)>>tr.valence;


                }
                if(cont==18)
                {
                    auxtempo+=linha[i];
                    istringstream(auxtempo)>>tr.tempo;

                }
                if(cont==19)
                {
                    auxtime_signature+=linha[i];
                    istringstream(auxtime_signature)>>tr.time_signature;

                }


            }
            cont=0;
           // cout << tr.id << "---" << tr.name << "---" << tr.popularity << "---" << tr.duration_ms << "---" << tr.explicit_ << "---" << tr.artists << "---" << tr.id_artists << "---" << tr.release_date << "---" << tr.danceability << "---" << tr.energy << "---" << tr.key << "---" << tr.loudness << "---" << tr.mode << "---" << tr.speechiness << "---" << tr.acousticness << "---" << tr.instrumentalness
               //  << "---" << tr.liveness << "---" << tr.valence << "---" << tr.tempo << "---" << tr.time_signature << endl;

            lista.push_back(tr);

            tr.id="";
            tr.name="";
            tr.popularity=0;
            tr.duration_ms=0;
            tr.explicit_=0;
            tr.artists="";
            tr.id_artists="";
            tr.release_date="";
            tr.danceability=0;
            tr.energy=0;
            tr.key=0;
            tr.loudness=0;
            tr.mode=0;
            tr.speechiness=0;
            tr.acousticness=0;
            tr.instrumentalness=0;
            tr.liveness=0;
            tr.valence=0;
            tr.tempo=0;
            tr.time_signature=0;
            //zerando variaveis auxiliares

            auxPopularity="";
            auxDuration_ms="";
            auxexplicit_="";
            auxdanceability="";
            auxenergy="";
            auxkey="";
            auxloudness="";
            auxmode="";
            auxspeechiness="";
            auxacousticness="";
            auxinstrumentalness="";
            auxliveness="";
            auxvalence="";
            auxtempo="";
            auxtime_signature="";


        }
        arquivo.close();
        TransformaTrackBin();
    }
    else
    {
        cout<<"Nao foi possivel abrir o arquivo (Arquivo nao esta aberto)tracks"<<endl;
    }

}
void Tracks ::TransformaTrackBin() // Função que transforma o arquivo artists.csv em binário
{
    ofstream arquivoTrackBin;
    arquivoTrackBin.open("../arquivo/tracks.bin", ios::binary);

    if (arquivoTrackBin.is_open())
    {
        for (tracks tr : lista)
        {
            arquivoTrackBin.write((char *)&tr, sizeof(tracks));
        }
    }
    else
    {
        cout << "N foi possível abrir o arquivo" << endl;
    }
    arquivoTrackBin.close();
}
