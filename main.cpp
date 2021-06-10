#include <iostream>
#include <fstream>
#include <list>

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

    void SetGenres(string genres);

    string getName();

    void setName(string name);

    int getPopularity();

    void setPopularity(int popularity);

};

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
    cout<<"deletando leitura do arquivo artists"<<endl;
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




int main()
{

//Artists

    fstream arquivo;
    string linha;
    arquivo.open("artists.csv",ios::in);

    int tam;
    Artists vet[];

    string id;
    float followers;
    string genres;
    string name;
    int popularity;


    int cont=0;
    if(arquivo.is_open())
    {
        while(getline(arquivo,linha))
        {
            for(int i=0; i<linha.size(); i++)
            {
                if(linha[i]==',')
                {
                    cont++;
                    i++;
                }

                if(cont==0)
                {
                    id=id+linha[i];
                    vet[i]->setId(id);
                }
                if( cont==1)
                {
                    followers=followers+float(linha[i]);
                    vet[i].setFollowers(followers);
                }
                if(cont==2)
                {
                    genres=genres+linha[i];
                    vet[i].setGenres(genres);
                }
                if(cont==3)
                {
                    name=name+linha[i];
                    vet[i].setLinha(name);
                }
                if(cont==4)
                {
                    popularity=int(linha[i]);
                    vet[i].setPopularity(popularity);
                }
                if(cont==4)
                {
                    cont=0;
                }
            }
        }
    }
    arquivo.close();
}
else
{
    cout<<"Nao foi possivel abrir o arquivo (Arquivo nao esta aberto)"<<endl;
}

}


return 0;
}







