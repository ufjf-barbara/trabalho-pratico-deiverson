#include <iostream>
#include <fstream>
#include "Artists.h"
#include <list>

using namespace std;

Artists::Artists()
{
    leArquivo();
}

Artists::~Artists()
{
    cout<<"deletando leitura do arquivo Artists"<<endl;

}

//GETTERS E SETTERS

list<artists> Artists::getList()
{
    return lista;
}


//METODOS

void Artists::leArquivo()
{

    fstream arquivo;
    string linha;
    arquivo.open("artists.csv",ios::in);

    artists art;


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
                    art.id+=linha[i];

                }
                if( cont==1)
                {
                    art.followers+=linha[i];

                }
                if(cont==2)
                {
                    art.genres+=linha[i];

                }
                if(cont==3)
                {
                    art.name+=linha[i];

                }
                if(cont==4)
                {
                    art.popularity+=int(linha[i]);
                }
                if(cont==4)
                {
                    cont=0;
                    i=0;
                    lista.push_back(art);

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













