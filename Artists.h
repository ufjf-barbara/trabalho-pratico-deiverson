#include <iostream>
#include <fstream>
#include <list>

#ifndef ARTISTS_H_INCLUDED
#define ARTISTS_H_INCLUDED



using namespace std;

struct artists
{
    string id;
    float followers;
    string genres;
    string name;
    int popularity;
};


class Artists
{

private:
    artists art;


public:
    Artists( string id,float followers,string genres,string name,int popularity);

    ~Artists();

    string getId();

    void setId(string id);

    float getFollowers();

    void setFollowers(float followers);

    string getGenres();

    void setGenres(string genres);

    string getName();

    void setName(string name);

    int getPopularity();

    void setPopularity(int popularity);

    void leArquivo();

};




#endif // ARTISTS_H_INCLUDED
