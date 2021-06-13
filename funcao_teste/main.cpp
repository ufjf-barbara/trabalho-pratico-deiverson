#include <list>
#include "Artists.h"
#include "Tracks.h"
#include <fstream>  //leitura e escrita de arquivos
#include <iostream> //entrada pelo teclado e saida pela prompt
#include <time.h>   // trabalhar com o relogio do sistema
#include <stdlib.h>

using namespace std;
struct artist
{
    string id;
    float followers;
    string genres;
    string name;
    int popularity;
};
bool verifica_numero(int vet[], int n, int aux)
{
    for (int i = 0; i < n; i++)
        if (vet[i] == aux)
            return true;
    return false;
}

void sorteia_numero(int vet[], int n, int qtddReg) //funçao para sortear a posiçao dos registros a serem impressos na tela ou arquivo
{
    srand(time(NULL));

    int aux;
    for (int i = 0; i < n; i++)
    {
        do
        {
            aux = rand() % qtddReg;
        }
        while (verifica_numero(vet, n, aux));

        vet[i] = aux;
    }
}

//void func_teste(int tamT, int tamA, ifstream *finT, ifstream *finA)
void func_teste(int tamA, ifstream *finA)
{
    int n = 0;
    artists art;
    tracks tr;
    while (!(n == 10 || n == 100)) // loop para chamar o teste adequadamente;
    {
        cout << "Quantos registros deseja obter aleatoriamente, 10 ou 100?" << endl;
        cin >> n;
        cin.ignore();

        if (!(n == 10 || n == 100))
        {
            system("cls");
            cout << "Resposta invalida" << endl;
        }
        else if (n == 10)
        {
            // chamar funçao pra pegar 10 registros e imprimilos na tela
            //  int vetA[n], vetT[n];
            int vetA[n];
            artist art[n];
            sorteia_numero(vetA, n, tamA);
            // sorteia_numero(vetT, n, tamT);

            cout << "Registros Artists" << endl;
            for (int i=0; i<n; i++)
            {
                //artist art;
                finA->seekg(vetA[i] * sizeof(artist), finA->beg);
                finA->read((char *)&art[i], sizeof(artist));
                cout << art[i].id
                     << "," << art[i].followers
                     << "," << art[i].genres
                     << "," << art[i].name
                     << "," << art[i].popularity
                     << endl;
                //cout<< finA->tellg()<<endl;

            }
            //finA->seekg(0, finA->beg);
            /* cout << "Registros Tracks" << endl;
            for (int i = 0; i < n; i++)
            {
                finT->seekg(vetT[i] * tamT, finT->beg);
                finT->read((char *)&tr, tamT);
                cout << tr.id
                     << "," << tr.name
                     << "," << tr.popularity
                     << "," << tr.duration_ms
                     << "," << tr.explicit_
                     << "," << tr.artists
                     << "," << tr.id_artists
                     << "," << tr.release_date
                     << "," << tr.danceability
                     << "," << tr.energy
                     << "," << tr.key
                     << "," << tr.loudness
                     << "," << tr.mode
                     << "," << tr.speechiness
                     << "," << tr.acousticness
                     << "," << tr.instrumentalness
                     << "," << tr.liveness
                     << "," << tr.valence
                     << "," << tr.tempo
                     << "," << tr.time_signature
                     << endl; // colocar os parametros a serem impressos
            }
            finT->seekg(0, finT->beg);*/
        }
        else //n= 100 ----- chamar funçao pra pegar 100 registros e criar arquivo de texto
        {
            // int vetA[n], vetT[n];
            int vetA[n];
            artist art[n];
            sorteia_numero(vetA, n, tamA);
            //sorteia_numero(vetT, n, tamT);
            //  ofstream foutT, foutA;
            ofstream  foutA;
            //foutT.open("");
            foutA.open("print.txt");
            //Registros Artists
            for (int i = 0; i < n; i++)
            {

                finA->seekg(vetA[i] * sizeof(artist), finA->beg);
                finA->read((char *)&art[i], sizeof(artist));
                foutA << art[i].id
                      << "," << art[i].followers
                      << "," << art[i].genres
                      << "," << art[i].name
                      << "," << art[i].popularity
                      << endl; // colocar os parametros a serem impressos
            }
            finA->seekg(0, finA->beg);
            foutA.close();
            /* //Registros Tracks
            for (int i = 0; i < n; i++)
            {
                finT->seekg(vetT[i] * tamT, finT->beg);
                finT->read((char *)&tr, tamT);
                foutT << tr.id
                      << "," << tr.name
                      << "," << tr.popularity
                      << "," << tr.duration_ms
                      << "," << tr.explicit_
                      << "," << tr.artists
                      << "," << tr.id_artists
                      << "," << tr.release_date
                      << "," << tr.danceability
                      << "," << tr.energy
                      << "," << tr.key
                      << "," << tr.loudness
                      << "," << tr.mode
                      << "," << tr.speechiness
                      << "," << tr.acousticness
                      << "," << tr.instrumentalness
                      << "," << tr.liveness
                      << "," << tr.valence
                      << "," << tr.tempo
                      << "," << tr.time_signature
                      << endl; // colocar os parametros a serem impressos
            }
            finT->seekg(0, finT->beg);
            foutT.close();*/
        }
    }
}
int main()
{

    Artists *arti = new Artists("artiststeste.txt");
    arti->TransformaArtistBin();
    //  Tracks *tr = new Tracks("tracksteste.txt");
    //  tr->TransformaTrackBin();

    //fonte pra mecher com seekg e tellg
    //https://www.cplusplus.com/reference/istream/istream/seekg/
    ifstream //finT,
    finA;
    artists art;
    tracks tr;
    //finT.open("tracks.bin", ios::binary);
    finA.open("artists.bin", ios::binary);
    // finT.seekg(0, finT.end);
    finA.seekg(0, finA.end);

    //   int tamT = finT.tellg() / sizeof(tr);
    int tamA = finA.tellg() / sizeof(art);
    cout <<finA.tellg()<< "--"<<sizeof(art)<<"--"<< tamA<<endl;


    //  finT.seekg(0, finT.beg);
    finA.seekg(0, finA.beg);

    // func_teste(tamT, tamA, &finT, &finA);
    func_teste(tamA, &finA);
    //  finT.close();
    finA.close();
    return 0;
}
