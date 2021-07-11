#include <iostream>
#include "tabelaHash.h"
#include <vector>


using namespace std;



tabelaHash::tabelaHash(int nn)
{
    primo=0;
    tracks track;
    track.id="-1";
    for(int i=0; i<n i++)
    {
        tabela[i].push_back(track);
    }
}


int  tabelaHash::gerarCodigoHash(string id)
{
    int num;
    for(int i=0; i<id.size(); i++)
    {
        num=num+char(id[i]);
    }
    return num%primo;
}


int tabelaHash::detMod()
{
    int mPrimo=0,result;
    for(int j=n; j>0; j--)
    {
        result=0;
        for (int i=1; i <= n ; i++)
        {
            if (n % i == 0)
            {
                result++;
            }
        }
        if(result==2)
        {
            primo=j;
            break;
        }
    }
}




void  tabelaHash::inserir (vector<tracks> &vet,vector<vector<tracks>>&tabela)
{
    int indice=0;
    bool verifica=false;
    for(int i=0; i<19; i++)
    {
        indice=gerarCodigoHash(vet[i].id_artists);
        do
        {
            verifica=false;
            if(tabela[i].[0].id=="-1")
            {
                tabela.insert(indice,vet[i]);
                verifica=true;
            }
            if(tabela[i].[0].id==vet[i].id_artists &&tabela[i].ar)
            {
                tabela[indice].push_back(vet[i]);
                verifica=true;
            }
            if()
            else
            {
                indice=gerarCodigoHash(vet[i].id);
                verifica=true;
            }
        }
        while(verifica!=false);
    }
}









