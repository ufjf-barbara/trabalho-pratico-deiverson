#include <iostream>
#include <fstream>
#include <list>
#include "Tracks.h"


using namespace std;



Tracks ::Tracks( string id,string name,int popularity,float duration_ms,int explicit_,string  artists,string id_artists,string release_date, float danceability,float energy,
                 int key,float loudness,int mode,float speechiness,float acousticness,float instrumentalness,float  liveness, float  valence,float tempo,int time_signature)
{

cout<<"Criando objeto tracks"<<endl;
/*
    this->tra.id=id;
    this->tra.name=name;
    this->tra.popularity=popularity;
    this->tra.duration_ms=duration_ms;
    this->tra.explicit_=explicit_;
    this->tra.artists=artists;
    this->tra.id_artists=id_artists;
    this->tra.release_dat=release_dat;
    this->tra.danceability=danceability;
    this->tra.energy=energy;
    this->tra.key=key;
    this->tra.loudness=loudness;
    this->tra.mode=mode;
    this->tra.speechiness=speedchiness;
    this->tra.acousticness=acusticness;
    this->tra.instrumentalness=instrumentalness;
    this->tra.liveness=liveness;
    this->tra.valence=valence;
    this->tra.tempo=tempo;
    this->tra.time_signature=time_signature;
*/
}


Tracks::~Tracks()
{
    cout<<"deletando objeto tracks "<<endl;

    /*
    this->tra.id=NULL;
    this->tra.name==NULL;
    this->tra.popularity=NULL;
    this->tra.duration_ms=NULL;
    this->tra.explicit_=NULL;
    this->tra.artists=NULL;
    this->tra.id_artists=NULL;
    this->tra.release_dat=NULL;
    this->tra.danceability==NULL;
    this->tra.energy==NULL;
    this->tra.key=NULL;
    this->tra.loudness=NULL;
    this->tra.mode=NULL;
    this->tra.speechiness=NULL;
    this->tra.acousticness=NULL;
    this->tra.instrumentalness=NULL;
    this->tra.liveness=NULL;
    this->tra.valence=NULL;
    this->tra.tempo=NULL;
    this->tra.time_signature=NULL;
*/
}

//GETTERS E SETTERS

string getId()
{
    return this->tra.id;
}

void setId(string id)
{

    this->tra.id+=id;
}

string getName()
{
    return this->tra.name;
}

void setName(string name)
{
    this->tra.name+=namee;
}

int getPopularity()
{
    return this->tra.popularity;
}

void setPopularity(int popularity)
{
    this->tra.popularity+=popularity;
}

float getDuration_ms()
{
    return this->tra.duration;
}

void setDuration_ms(float duration_ms)
{
    this->tra.duration+=duration;
}

int getExplicit_()
{
    return this->tra.explicit_;
}


void setExplicit_(int explicit_)
{
    this->tra.explicit_+=explicit_;
}

string  getArtists()
{
    return this->tra.artists;
}

void setArtists(string artists)
{
    this->tra.artists=artists;
}

string getId_artists()
{
    return this->tra.id_artists;
}

void setId_artists(string id_artists)
{
    this->tra.id_artists+=id_artists;
}


string  getRelease_date()
{
    return this->tra.release_date;

}


void  setRelease_date(string release_date)
{
    this->tra.release_date+=release_date;

}

float getDanceability()
{

    return this->tra.danceability;
}
void setDanceability(float danceability)
{
    this->tra.danceability+=danceability;

}

float getEnergy()
{
    return this->energy;

}

void setEnergy(float energy)
{
    return this->tra.energy+=energy;

}

int getKey()
{

    return this->tra.getKey;

}

void setKey(int key
{
    this->tra.key+=key;
}

float getLoudness()
{
    this->tra.loudness;

}
void setLoudness(float loudness)
{
    this->tra.loudness+=loudness;
}

int getMode()
{
    return this->tra.mode;

}

void setMode(int mode)
{

    this->tra.mode+=mode;
}

float getSpeechiness()
{
    return this->tra.speechiness;

}

void setSpeechiness(float speechiness)
{

    this->tra.speechiness+=speechiness;
}

float getAcousticness()
{
    return this->tra.acousticness;

}

void SetAcousticness(float acousticness)
{
    this->tra.acousticness+=acousticness;

}

float getInstrumentalness()
{

    return  this->tra.instrumentalness;
}

void setInstrumentalness(float instrumentalness)
{

    this->tra.instrumentalness=instrumentalness;
}

float  getLiveness()
{
    return this->tra.liveness;
}

void setLiveness(float liveness)
{
    this->tra.liveness+=liveness;
}

float  getValence()
{
    return this->tra.valence;

}
void setValence(float valence)
{
    this->tra.valence+=valence;

}

float getTempo()
{
    return this->tra.tempo;

}

void setTempo(float tempo)
{

    this->tra.tempo+=tempo;
}

int getTime_signature()
{
    return this->tra.time;
}

void setTime_signature(int time_signature)
{
    this->tra.time_signature+=time_signature;

}

//METODOS

void Tracks::leArquivo()
{
    /*
        string id;
        string name;
        int popularity;
        float duration_ms;
        int explicit_;
        string  artists;
        string id_artists;
        // date string release_date;
        float danceability;
        float energy;
        int key;
        float loudness;
        int mode;
        float speechiness;
        float acousticness;
        float instrumentalness;
        float  liveness;
        float  valence;
        float tempo;
        int time_signature;
    */

    Tracks vet[TAM];//vetor de tracks

    fstream arquivo;
    string linha;
    arquivo.open("tracks.csv",ios::in);

    int cont=0;

    if(arquivo.is_open())
    {
        while(getline(arquivo,linha))
        {
            for(int i=0; i<linha.size(); i++)
            {
                if(linha[i]==',')
                {
                    cont++;
                    i++;
                }
                if(cont==0)
                {
                    id=id+linha[i];
                    vet[i].setId(linha[i]);
                }
                if(cont==1)
                {
                    name=name+linha[i];
                    vet[i].setName(linha[i]);
                }
                if(cont==2)
                {
                    popularity=popularity+linha[i];
                    vet[i].setPopularity(linha[i]);
                }
                if(cont==3)
                {
                    duration_ms+=linha[i];
                    vet[i].setDuration_ms(linha[i]);

                }
                if(cont==4)
                {
                    explicit_+=linha[i];
                    vet[i].setExplicit_(linha[i]);

                }
                if(cont==5)
                {
                    artists+=linha[i];
                    vet[i].setArtists(linha[i]);
                }
                if(cont==6)
                {
                    id_artists+=linha[i];
                    vet[i].setId_artists(linha[i]);
                }
                if(cont==7)
                {
                    release_date+=linha[i];
                    vet[i].setRelease_date(linha[i]);
                }
                if(cont==8)
                {
                    danceability+=linha[i];
                    vet[i].setDanceability(linha[i]);

                }
                if(cont==9)
                {
                    energy+=linha[i];
                    vet[i].setEnergy(linha[i]);
                }
                if(cont==10)
                {
                    key+=linha[i];
                    vet[i].setKey(linha[i]);

                }
                if(cont==11)
                {
                    loudness+=linha[i];
                    vet[i].setLoudness(linha[i]);

                }
                if(cont==12)
                {
                    mode+=linha[i];
                    vet[i].setMode(linha[i]);

                }
                if(cont==13)
                {
                    speechiness+=linha[i];
                    vet[i].setSpeechiness(linha[i]);

                }
                if(cont==14)
                {

                    acousticness+=linha[i];
                    vet[i].setAcousticness(linha[i]);

                }
                if(cont==15)
                {
                    instrumentalness+=linha[i];
                    vet[i].setInstrumentalness(linha[i]);

                }
                if(cont==16)
                {
                    liveness+=linha[i];
                    vet[i].setLiveness(linha[i]);

                }
                if(cont==17)
                {
                    valence+=linha[i];
                    vet[i].setValence(linha[i]);


                }
                if(cont==18)
                {
                    tempo+=linha[i];
                    vet[i].setTempo(linha[i]);


                }
                if(cont==19)
                {
                    time_signature+=linha[i];
                    vet[i].setTime_signature(linha[i]);

                }

                if(cont==20)
                {
                    speechiness+=linha[i];
                    vet[i].setSpeechiness(linha[i]);
                }
                if(cont==20)
                {
                    cont==0
                    i=0;
                    this->tra.id=NULL;
                    this->tra.name==NULL;
                    this->tra.popularity=NULL;
                    this->tra.duration_ms=NULL;
                    this->tra.explicit_=NULL;
                    this->tra.artists=NULL;
                    this->tra.id_artists=NULL;
                    this->tra.release_dat=NULL;
                    this->tra.danceability==NULL;
                    this->tra.energy==NULL;
                    this->tra.key=NULL;
                    this->tra.loudness=NULL;
                    this->tra.mode=NULL;
                    this->tra.speechiness=NULL;
                    this->tra.acousticness=NULL;
                    this->tra.instrumentalness=NULL;
                    this->tra.liveness=NULL;
                    this->tra.valence=NULL;
                    this->tra.tempo=NULL;
                    this->tra.time_signature=NULL;
                }
                arquivo.close();
            }
            else
            {
                cout<<"Nao foi possivel abrir o arquivo (Arquivo nao esta aberto)"<<endl;
            }

        }

    }


