#include <iostream>
#include <vector>
#include <string>
#include"tracks.h"

#ifndef TABELAHASH_H_INCLUDED
#define TABELAHASH_H_INCLUDED

class tabelaHash
{

private:
    vector<vector<tracks>> tabela;
    int mod;
    int conta_colisao_de_artistas;

public:

    int getcont();

    tabelaHash(int n);
    tabelaHash();
    int gerarCodigoHash(string id);
    void inserir(vector<tracks> &vet);
    int detMod();
    
    tracks  musicaPopular(vector<tracks> &vet);
    void artistasFrequentes();
    void artistasFrequentesTeste();
};

#endif // TABELAHASH_H_INCLUDED
