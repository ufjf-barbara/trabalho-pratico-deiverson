#include <iostream>
#include <fstream>
#include <list>


using namespace std;



Tracks ::Tracks( string id,string name,int popularity,float duration_ms,int explicit,string  artists,,string id_artists,string release_date; float danceability,float energy,
                 int key,float loudness,int mode,float speechiness,float acousticness,float instrumentalness,float  liveness; float  valence,float tempo,int time_signature))
{

    this->tra.id=id;
    this->tra.name=name;
    this->tra.popularity=popularity;
    this->tra.duration_ms=duration_ms;
    this->tra.explicit_=explicit_;
    this->tra.artists=artists;
    this->tra.id_artists=id_artists;
    this->tra.release_dat=release_dat;
    this->tra.danceability=danceability;
    this->tra.energy=energy;
    this->tra.key=key;
    this->tra.loudness=loudness;
    this->tra.mode=mode;
    this->tra.speechiness=speedchiness;
    this->tra.acousticness=acusticness;
    this->tra.instrumentalness=instrumentalness;
    this->tra.liveness=liveness;
    this->tra.valence=valence;
    this->tra.tempo=tempo;
    this->tra.time_signature=time_signature;

}


Tracks::~Tracks()
{
    cout<<"deletando objeto tracks "<<endl;

    this->tra.id=NULL;
    this->tra.name==NULL;
    this->tra.popularity=NULL;
    this->tra.duration_ms=NULL;
    this->tra.explicit_=NULL;
    this->tra.artists=NULL;
    this->tra.id_artists=NULL;
    this->tra.release_dat=NULL;
    this->tra.danceability==NULL;
    this->tra.energy==NULL;
    this->tra.key=NULL;
    this->tra.loudness=NULL;
    this->tra.mode=NULL;
    this->tra.speechiness=NULL;
    this->tra.acousticness=NULL;
    this->tra.instrumentalness=NULL;
    this->tra.liveness=NULL;
    this->tra.valence=NULL;
    this->tra.tempo=NULL;
    this->tra.time_signature=NULL;

}


string getId()
{
    return this->tra.id;
}

void setId(string id)
{

    this->tra.id+=id;
}

string getName()
{
    return this->tra.name;
}

void setName(string name)
{
    this->tra.name+=namee;
}

int getPopularity()
{
    return this->tra.popularity;
}

void setPopularity(int popularity)
{
    this->tra.popularity+=popularity;
}

float getDuration_ms()
{
    return this->tra.duration;
}

void setDuration_ms(float duration_ms)
{
    this->tra.duration+=duration;
}

int getExplicit_()
{
    return this->tra.explicit_;
}


void setExplicit_(int explicit_)
{
    this->tra.explicit_+=explicit_;
}

string  getArtists()
{
    return this->tra.artists;
}

void setArtists(string artists)
{
    this->tra.artists=artists;
}

string getId_artists()
{
    return this->tra.id_artists;
}

void setId_artists(string id_artists)
{
    this->tra.id_artists+=id_artists;
}


string  getRelease_date()
{
    return this->tra.release_date;

}


void  setRelease_date(string release_date)
{
    this->tra.release_date+=release_date;

}

float getDanceability()
{

    return this->tra.danceability;
}
void setDanceability(float danceability)
{
    this->tra.danceability+=danceability;

}

float getEnergy()
{
    return this->energy;

}

void setEnergy(float energy)
{
    return this->tra.energy+=energy;

}

int getKey()
{

    return this->tra.getKey;

}

void setKey(int key
{
    this->tra.key+=key;
}

float getLoudness()
{
    this->tra.loudness;

}
void setLoudness(float loudness)
{
    this->tra.loudness+=loudness;
}

int getMode()
{
    return this->tra.mode;

}

void setMode(int mode)
{

    this->tra.mode+=mode;
}

float getSpeechiness()
{
    return this->tra.speechiness;

}

void setSpeechiness(float speechiness)
{

    this->tra.speechiness+=speechiness;
}

float getAcousticness()
{
    return this->tra.acousticness;

}

void SetAcousticness(float acousticness)
{
    this->tra.acousticness+=acousticness;

}

float getInstrumentalness()
{

    return  this->tra.instrumentalness;
}

void setInstrumentalness(float instrumentalness)
{

    this->tra.instrumentalness=instrumentalness;
}

float  getLiveness()
{
    return this->tra.liveness;
}

void setLiveness(float liveness)
{
    this->tra.liveness+=liveness;
}

float  getValence()
{
    return this->tra.valence;

}
void setValence(float valence)
{
    this->tra.valence+=valence;

}

float getTempo()
{
    return this->tra.tempo;

}

void setTempo(float tempo)
{

    this->tra.tempo+=tempo;
}

int getTime_signature()
{
    return this->tra.time;
}

void setTime_signature(int time_signature)
{
     this->tra.time_signature+=time_signature;

}












