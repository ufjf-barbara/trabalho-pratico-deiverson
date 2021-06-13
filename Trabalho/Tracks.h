#include <iostream>
#include <fstream>
#include<list>

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
    string  artists;
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
    float  liveness;
    float  valence;
    float tempo;
    int time_signature;

};

class Tracks
{


private:

    list<tracks>lista;

public:

    Tracks(string path);
    ~Tracks();

    list<tracks> getList();


    //METODOS
    void leArquivo(string path);
    void TransformaTrackBin();

};






#endif // TRACKS_H_INCLUDED
