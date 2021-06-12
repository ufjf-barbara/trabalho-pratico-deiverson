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
   list<artists>lista;

public:

    Artists();

    ~Artists();

    //metodos
    list<artists>getList();

    void leArquivo();

};




#endif // ARTISTS_H_INCLUDED
