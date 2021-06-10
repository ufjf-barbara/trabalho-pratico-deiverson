#include <iostream>
#include <fstream>
#include <list>
#include <Artists.h>

using namespace std;

Artists :: Artists( string id,float followers,string genres,string name,int popularity)
{
    this->art.id=id;
    this->art.followers=followers;
    this->art.genres=genres;
    this->art.name=name;
    this->art.popularity=popularity;
}

Artists::~Artists()
{
    cout<<"deletando leitura do arquivo Artists"<<endl;
     this->art.id=NULL;
    this->art.followers=NULL;
    this->art.genres=NULL;
    this->art.name=NULL;
    this->art.popularity=NULL;
}

string Artists::getId()
{
    return  this->art.id;
}

void Artists::setId(string id)
{
    this->art.id+=id;
}

float Artists::getFollowers()
{
    return this->art.followers;
}

void Artists::setFollowers(float followers)
{
    this->art.followers+=followers;
}

string Artists::getGenres()
{
    return this->art.genres;
}

void Artists::SetGenres(string genres)
{
    this->art.genres+=genres;
}

string Artists:: getName()
{
    return this->art.name;
}

void Artists::setName(string name)
{
    this->art.name+=name;
}

int Artists::getPopularity()
{
    return this->art.popularity;
}

void Artists::setPopularity(int popularity)
{
    this->art.popularity+=popularity;
}

