#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <sstream>
#include <string.h>
#include <algorithm>

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
    char name[386];
    int popularity;
    float duration_ms;
    int explicit_;
    char artists[939];
    char id_artists[1000];//1511
    char release_date[1000];//1433
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
    // contadores estaticos
    int id;
    int name;
    int artists;
    int id_artists;
    int release_date;

public:
    Tracks(string path);
    Tracks();
    ~Tracks();

    //METODOS
    void leArquivo(string path);
    tracksAux converteToAux(tracks tr);
    static tracks converteTracksToString(tracksAux tra);

    //METODOS estaticos
    static vector<tracks> registrosTr(int n, int tam);
    static int Tracks::getTAM();
};

#endif // TRACKS_H_INCLUDED
