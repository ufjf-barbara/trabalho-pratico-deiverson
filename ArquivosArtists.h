#include "iostream"

#ifndef TRABALHO_ARQUIVOSARTISTS_H
#define TRABALHO_ARQUIVOSARTISTS_H


class ArquivosArtists{

private:
    //atributos do artists
    String id;
    float followers;
    String genres;
    String name;
    int popularity;

    //atributos do tracks

public:
    list <string> listaArtists;
     ArquivosArtists();
     ~ArquivosArtists();

};






#endif //TRABALHO_ARQUIVOSARTISTS_H
