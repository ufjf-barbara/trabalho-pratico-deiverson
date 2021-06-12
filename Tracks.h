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

    tracks tra;

public:

    Tracks(string id,string name,int popularity,float duration_ms,int explicit_,string  artists,string id_artists,string release_date, float danceability,float energy,
           int key,float loudness,int mode,float speechiness,float acousticness,float instrumentalness,float  liveness, float  valence,float tempo,int time_signature);
    ~Tracks();

    string getId();
    void setId(string id);

    string getName();
    void setName(string name);

    int getPopularity();
    void setPopularity(int popularity);

    float getDuration_ms();
    void setDuration_ms(float duration_ms);

    int getExplicit_();
    void setExplicit_(int explicit_);

    string  getArtists();
    void setArtists(string artists);

    string getId_artists();
    void setId_artists(string id_artists);

    string  getRelease_date();
    void  setRelease_date(string release_date);

    float getDanceability();
    void setDanceability(float danceability);

    float getEnergy();
    void setEnergy(float energy);

    int getKey();
    void setKey(int key);

    float getLoudness();
    void setLoudness(float loudness);

    int getMode();
    void setMode(int mode);

    float getSpeechiness();
    void setSpeechiness(float speechiness);

    float getAcousticness();
    void SetAcousticness(float acousticness);

    float getInstrumentalness();
    void setInstrumentalness(float instrumentalness);

    float  getLiveness();
    void setLiveness(float liveness);

    float  getValence();
    void setValence(float valence);

    float getTempo();
    void setTempo(float tempo);

    int getTime_signature();
    void setTime_signature(int time_signature);

    //METODOS
    void leArquivo();

};













#endif // TRACKS_H_INCLUDED
