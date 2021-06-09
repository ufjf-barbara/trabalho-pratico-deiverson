#include "iostream"
#include "list"

#ifndef TRABALHO_ARQUIVOSTRACKS_H
#define TRABALHO_ARQUIVOSTRACKS_H

class ArquivosTracks{


private:

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
    list <string> listaTracks;
    ArquivosTracks();
    ~ArquivosTracks();

};


};



#endif //TRABALHO_ARQUIVOSTRACKS_H
