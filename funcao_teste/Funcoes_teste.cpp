#include <fstream>
#include <iostream>
using namespace std;

/*struct dat
{
    string name;
    int idade;
};*/
class dat
{
private:
    /* data */
    string name;
    int idade;

public:
    dat();
    ~dat();
    int getIdade();
    string getName();
    void setName(string name);
    void setIdade(int idade);
};

dat::dat()
{
    this->name = "";
    this->idade = 0;
}

dat::~dat()
{
}

int dat ::getIdade() { return this->idade; }

string dat::getName() { return this->name; }

void dat::setName(string name)
{
    //  cout << name << endl;
    this->name = name;
}

void dat::setIdade(int idade)
{
    //   cout << idade << endl;
    this->idade = idade;
}
int main()
{
    ofstream fout;
    string information = "cabecalho pra leitura do .bin";
    fout.open("class.bin", ios::out | ios::binary);
    // dat d = {"Derivers Pedroso", 23};
    dat *d = new dat();
    d->setIdade(23);
    d->setName("Ta dando ruim muito ruim");
    int tamanho= d->getName().size()*sizeof(char)+sizeof(int);
    if (fout.is_open())
    {
        fout.write((char *)&information, sizeof(information));
        fout.write((char *)&d, sizeof(d));
    }
    fout.close();
    d->~dat();
    ifstream fin;
    string aux;
    dat *data = new dat();
    fin.open("class.bin",  ios::binary);
    if (fin.is_open())
    {
        fin.read((char *)&aux, sizeof(aux));
        fin.read((char *)&data, sizeof(data));
        cout << aux << "\n"
             << data->getName() << "\n"
             << data->getIdade()  <<endl;
    }
    fin.close();
}