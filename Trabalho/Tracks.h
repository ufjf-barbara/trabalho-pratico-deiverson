#include <iostream>
#include <fstream>
#include <list>

#ifndef TRACKS_H_INCLUDED
#define TRACKS_H_INCLUDED

using namespace std;

struct tracks
{
    string id;
    string name;
    int popularity;
    float duration_ms;
    int explicit_;
    string artists;
    string id_artists;
    string release_date;
    float danceability;
    float energy;
    int key;
    float loudness;
    int mode;
    float speechiness;
    float acousticness;
    float instrumentalness;
    float liveness;
    float valence;
    float tempo;
    int time_signature;
};
struct tracksAux
{
    char id[23];
    char name[1000];
    int popularity;
    float duration_ms;
    int explicit_;
    char artists[1000];
    char id_artists[1000];
    char release_date[1000];
    float danceability;
    float energy;
    int key;
    float loudness;
    int mode;
    float speechiness;
    float acousticness;
    float instrumentalness;
    float liveness;
    float valence;
    float tempo;
    int time_signature;
};

class Tracks
{

private:
    list<tracks> lista;

public:
    Tracks(string path);
    Tracks();
    ~Tracks();

    list<tracks> getList();

    //METODOS
    void leArquivo(string path);
    void TransformaTrackBin();
    tracksAux converteToAux(tracks tr);
    static tracks converteTracksToString(tracksAux tr);
    static string concatenaTracks(char linha[]);
};

#endif // TRACKS_H_INCLUDED
