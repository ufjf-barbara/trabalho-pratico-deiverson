#include <iostream>
#include <fstream>
#include "Artists.h"
#define TAM 10

using namespace std;

Artists::Artists()
{
    leArquivo();
}

Artists::~Artists()
{
    cout<<"deletando leitura do arquivo Artists"<<endl;
    /*
    this->art.id=NULL;
    this->art.followers=NULL;
    this->art.genres=NULL;
    this->art.name=NULL;
    this->art.popularity=NULL;
    */
}

//GETTERS E SETTERS

string Artists::getId()
{
    return  this->art.id;
}

//GETTERS E SETTERS

void Artists::setId(string id)
{
    this->art.id+=id;
}

float Artists::getFollowers()
{
    return this->art.followers;
}

void Artists::setFollowers(float followers)
{
    this->art.followers+=followers;
}

string Artists::getGenres()
{
    return this->art.genres;
}

void Artists::setGenres(string genres)
{
    this->art.genres+=genres;
}

string Artists:: getName()
{
    return this->art.name;
}

void Artists::setName(string name)
{
    this->art.name+=name;
}

int Artists::getPopularity()
{
    return this->art.popularity;
}

void Artists::setPopularity(int popularity)
{
    this->art.popularity+=popularity;
}


//METODOS

void Artists::leArquivo()
{


    fstream arquivo;
    string linha;
    arquivo.open("artists.csv",ios::in);


    Artists *vet[TAM];

    string id;
    float followers;
    string genres;
    string name;
    int popularity;


    int cont=0;
    bool verifica;
    if(arquivo.is_open())
    {
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
                    id=id+linha[i];
                    vet[i]->setId(id);
                }
                if( cont==1)
                {
                    followers=followers+float(linha[i]);
                    vet[i]->setFollowers(followers);
                }
                if(cont==2)
                {
                    genres=genres+linha[i];
                    vet[i]->setGenres(genres);
                }
                if(cont==3)
                {
                    name=name+linha[i];
                    vet[i]->setName(name);
                }
                if(cont==4)
                {
                    popularity=int(linha[i]);
                    vet[i]->setPopularity(popularity);
                }
                if(cont==4)
                {
                    cont=0;
                    i=0;
                }
            }
        }

        arquivo.close();
    }
    else
    {
        cout<<"Nao foi possivel abrir o arquivo (Arquivo nao esta aberto)"<<endl;
    }



}













