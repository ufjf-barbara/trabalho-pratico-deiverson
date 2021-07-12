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
    int mod,contador;
    int conta_colisao_de_artistas;

public:

    int getcont();

    tabelaHash();
    int gerarCodigoHash(string id);
    void inserir(vector<tracks> &vet);
    int detMod();
    
    tracks  musicaPopular(vector<tracks> &vet);
    void artistasFrequentes();
};

#endif // TABELAHASH_H_INCLUDED
