#include "list"
#include "iostream"

#ifndef UNTITLED_ARQUIVOS_H
#define UNTITLED_ARQUIVOS_H


class Arquivos
{
private:
    //atributos do artists
    String id;
    float followers;
    String genres;
    String name;
    int popularity;

    //atributos do tracks

    String id2;
    String name2;
    int popularity2;
    float duration_ms;
    int explicit;
    String  artists;
    String id_artists;
    DATE release_date;
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

public:
    list <string> listaArtists;
    list <string> listaTracks;

    //metodos


};





#endif //UNTITLED_ARQUIVOS_H
