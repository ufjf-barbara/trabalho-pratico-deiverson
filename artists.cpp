#include <iostream>
#include <fstream>
#include "Artists.h"
#include <list>

using namespace std;

Artists::Artists(string path)
{
    leArquivo(path);
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

void Artists::leArquivo(string path)
{

    fstream arquivo;
    string linha;
    arquivo.open(path,ios::in);

    artists art;


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


            }

            cont=0;
            lista.push_back(art);
            cout<<art.id<<" ---";
            cout<<art.followers<<"---";
            cout<<art.genres<<"---";
            cout<<art.name<<"--- ";
            cout<<art.popularity<<endl;
            art.id="";
            art.followers=NULL;
            art.genres="";
            art.name="";
            art.popularity=NULL;
        }


        arquivo.close();
    }

    else
    {
        cout<<"Nao foi possivel abrir o arquivo (Arquivo nao esta aberto)"<<endl;
    }



}













