#include <iostream>
#include <vector>

#ifndef TABELAHASH_H_INCLUDED
#define TABELAHASH_H_INCLUDED

class tabelaHash
{

private:
    vector<vector<tracks>> tabela;
    int primo, n;

public:
    tabelaHash(int n);
    int gerarCodigoHash(string id);
    void inserir(vector<tracks> &vet, vector<vector<tracks>> &tabela);
    int detMod();
    
    tracks  musicaPopular(vector<tracks> &vet);
    void artistasFrequentes(vector<vector<tracks>> &tabela);
};

#endif // TABELAHASH_H_INCLUDED
