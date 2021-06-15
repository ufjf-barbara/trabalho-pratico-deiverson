#include "Artists.h"
#include "Tracks.h"
#include "functeste.h"
#include <fstream>  //leitura e escrita de arquivos
#include <iostream> //entrada pelo teclado e saida pela prompt
#include <time.h>   // trabalhar com o relogio do sistema
#include <stdlib.h>

using namespace std;

void func_teste::func_test(string path) //construtor
{
    ifstream finT, finA;
    artistsAux art;
    tracksAux tr;

    finT.open("../print/tracks.bin", ios::in);
    finA.open("../print/artists.bin", ios::in);

    finT.seekg(0, finT.end);
    finA.seekg(0, finA.end);

    int tamT = finT.tellg() / sizeof(tracksAux);
    int tamA = finA.tellg() / sizeof(artistsAux);

    finT.seekg(0, finT.beg);
    finA.seekg(0, finA.beg);

    if (finT.is_open() && finA.is_open())
    {
        finA.close();
        finT.close();
        callTeste(tamT, tamA);
    }
    else
        cout << "arquivos nao abriram" << endl;
}

bool func_teste::verifica_numero(int vet[], int n, int aux)
{
    for (int i = 0; i < n; i++)
        if (vet[i] == aux)
            return true;
    return false;
}

void func_teste::sorteia_numero(int vet[], int n, int qtddReg) //funçao para sortear a posiçao dos registros a serem impressos na tela ou arquivo
{

    int aux;
    for (int i = 0; i < n; i++)
    {
        do
        {
            aux = rand() % qtddReg;
        } while (verifica_numero(vet, n, aux));

        vet[i] = aux;
    }
}
void func_teste::callTeste(int tamT, int tamA)

{
    int n = 0;
    while (!(n == 10 || n == 100)) // loop para chamar o teste adequadamente;
    {
        cout << "----------------Quantos registros deseja obter aleatoriamente, 10 ou 100?----------------" << endl;
        cin >> n;
        cin.ignore();

        if (!(n == 10 || n == 100))
        {
            cout << "Resposta invalida" << endl;
        }
        else if (n == 10) // chamar funçao pra pegar 10 registros e imprimilos na tela
        {

            int vetA[n], vetT[n];
            artists art[n];

            tracks tr[n];

            sorteia_numero(vetA, n, tamA);
            sorteia_numero(vetT, n, tamT);

            for (int i = 0; i < n; i++)
            {
                ifstream finA;
                finA.open("../print/artists.bin", ios::in);
                artistsAux arti;
                int posicao = vetA[i] * sizeof(artistsAux);
                finA.seekg(posicao, ios::beg);
                finA.read((char *)&arti, sizeof(artistsAux));

                art[i] = Artists ::converteArtToString(arti);

                cout << arti.id
                     << "," << arti.followers
                     << "," << arti.genres
                     << "," << arti.name
                     << "," << arti.popularity
                     << endl;
                finA.close();
            }
           
            cout << "\n\nRegistros Tracks\n\n"
                 << endl;
            for (int i = 0; i < n; i++)
            {
                ifstream finT;
                finT.open("../print/tracks.bin", ios::in);
                tracksAux tra;
                finT.seekg(vetT[i] * sizeof(tracksAux), finT.beg);
                finT.read((char *)&tra, sizeof(tracksAux));
                tr[i] = Tracks::converteTracksToString(tra);

                cout << tr[i].id
                     << "," << tr[i].name
                     << "," << tr[i].popularity
                     << "," << tr[i].duration_ms
                     << "," << tr[i].explicit_
                     << "," << tr[i].artists
                     << "," << tr[i].id_artists
                     << "," << tr[i].release_date
                     << "," << tr[i].danceability
                     << "," << tr[i].energy
                     << "," << tr[i].key
                     << "," << tr[i].loudness
                     << "," << tr[i].mode
                     << "," << tr[i].speechiness
                     << "," << tr[i].acousticness
                     << "," << tr[i].instrumentalness
                     << "," << tr[i].liveness
                     << "," << tr[i].valence
                     << "," << tr[i].tempo
                     << "," << tr[i].time_signature
                     << endl;
                finT.close();
            }
        }
        else //n= 100 ----- chamar funçao pra pegar 100 registros e criar arquivo de texto
        {
            int vetA[n], vetT[n];
            artists art[n];

            tracks tr[n];

            sorteia_numero(vetA, n, tamA);
            sorteia_numero(vetT, n, tamT);

            ofstream foutT, foutA;

            foutT.open("../print/printTRACK.txt");
            foutA.open("../print/printARTISTS.txt");
            //Registros Artists
            for (int i = 0; i < n; i++)
            {
                ifstream finA;
                finA.open("../print/artists.bin", ios::in);
                artistsAux arti;
                int posicao = vetA[i] * sizeof(artistsAux);
                finA.seekg(posicao, ios::beg);
                finA.read((char *)&arti, sizeof(artistsAux));
                art[i] = Artists ::converteArtToString(arti);

                foutA << art[i].id
                      << "," << art[i].followers
                      << "," << art[i].genres
                      << "," << art[i].name
                      << "," << art[i].popularity
                      << endl;
                finA.close();
            }

            //Registros Tracks

            for (int i = 0; i < n; i++)
            {
                ifstream finT;
                finT.open("../print/tracks.bin", ios::in);
                tracksAux tra;
                finT.seekg(vetT[i] * sizeof(tracksAux), finT.beg);
                finT.read((char *)&tra, sizeof(tracksAux));
                tr[i] = Tracks::converteTracksToString(tra);

                foutT << tr[i].id
                     << "," << tr[i].name
                     << "," << tr[i].popularity
                     << "," << tr[i].duration_ms
                     << "," << tr[i].explicit_
                     << "," << tr[i].artists
                     << "," << tr[i].id_artists
                     << "," << tr[i].release_date
                     << "," << tr[i].danceability
                     << "," << tr[i].energy
                     << "," << tr[i].key
                     << "," << tr[i].loudness
                     << "," << tr[i].mode
                     << "," << tr[i].speechiness
                     << "," << tr[i].acousticness
                     << "," << tr[i].instrumentalness
                     << "," << tr[i].liveness
                     << "," << tr[i].valence
                     << "," << tr[i].tempo
                     << "," << tr[i].time_signature
                     << endl;
                finT.close();
            }
            foutT.close();
            foutA.close();
        }
    }
}
