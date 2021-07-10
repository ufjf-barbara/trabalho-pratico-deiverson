#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include "Tracks.h"
#include <time.h>


using namespace std;

void  Hashtable(vector<vector<tracks>>&tabela)
{
    for(int i=0; i<19; i++)
    {
        tracks track;
        track.id="-1";
        tabela[i].push_back(track);
    }
}



int  gerarCodigoHash(string id)
{
    int num;
    for(int i=0; i<id.size(); i++)
    {
        num=num+char(id[i]);
    }
    return num%19;
}


void  inserir (vector<tracks> &vet,vector<vector<tracks>>&tabela)
{
    int indice=0;
    bool verifica=false;
    for(int i=0; i<19; i++)
    {
        indice=gerarCodigoHash(vet[i].id);
        do
        {
            verifica=false;
            if(tabela[i].[0].id=="-1")
            {
                tabela.insert(indice,vet[i]);
                verifica=true;
            }
            else if(tabela[i].[0].id==vet[i].id)
            {
                tabela[indice].push_back(vet[i]);
                verifica=true;
            }
            else //chama o tratamento de colisao
            {
                indice=gerarCodigoHash(vet[i].id);
                verifica=true;
            }
        }
        while(verifica!=false);
    }
}







int main(int argc, char **argv)
{

    srand(time(NULL));

    clock_t beginTime, endTime;
    ifstream finA;
    finA.open("../print/tracks.bin", ios::in);

    finA.seekg(0, finA.end);

    int tam = finA.tellg() / sizeof(auxTracks);

    int n = 19;

    vector<tracks> vet = Tracks::registrosTr(n, tam);

    vector<vector<tracks>>tabela;

    Hashtable(tabela);
    inserir(vet,tabela);





    return 0;
}
