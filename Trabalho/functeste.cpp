#include "Artists.h"
#include "Tracks.h"
#include "functeste.h"
#include <fstream>  //leitura e escrita de arquivos
#include <iostream> //entrada pelo teclado e saida pela prompt
#include <time.h>   // trabalhar com o relogio do sistema
#include <stdlib.h>

using namespace std;

func_teste::func_teste(string path) //construtor
{
    ifstream finT, finA;
    artists art;
    tracks tr;

    finT.open("../arquivo/tracks.bin", ios::in);
    finA.open("../arquivo/artists.bin", ios::in);

    finT.seekg(0, finT.end);
    finA.seekg(0, finA.end);

    int tamT = finT.tellg() / sizeof(tracks);
    int tamA = finA.tellg() / sizeof(artists);

    finT.seekg(0, finT.beg);
    finA.seekg(0, finA.beg);

    if (finT.is_open() && finA.is_open())
        callTeste(tamT, tamA, &finT, &finA);
    else
        cout << "arquivos nao abriram" << endl;

    finA.close();
    finT.close();
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
    
    cout << "------------------\n"<<qtddReg << "\n";
    int aux;
    for (int i = 0; i < n; i++)
    {
        do
        {
            aux = rand() % qtddReg + 1;
        } while (verifica_numero(vet, n, aux));

        vet[i] = aux;
        cout <<aux<<endl;
    }
}

void func_teste::callTeste(int tamT, int tamA, ifstream *finT, ifstream *finA)

{
    int n = 0;
    while (!(n == 10 || n == 100)) // loop para chamar o teste adequadamente;
    {
        cout << "----------------Quantos registros deseja obter aleatoriamente, 10 ou 100?----------------" << endl;
        cin >> n;
        cin.ignore();

        if (!(n == 10 || n == 100))
        {
            system("cls");
            cout << "Resposta invalida" << endl;
        }
        else if (n == 10) // chamar funçao pra pegar 10 registros e imprimilos na tela
        {

            int vetA[n], vetT[n];
            artists art[n];
            tracks tr[n];
            artists test;
            sorteia_numero(vetA, n, tamA);
            sorteia_numero(vetT, n, tamT);

            cout << "Registros Artists" << endl;
            for (int i = 0; i < n; i++)
            {

                finA->seekg(vetA[i] * sizeof(artists), finA->beg);

                finA->read((char *)&test, sizeof(artists));
                cout << "uai";
                art[i]=test;
                cout << art[i].id
                     << "," << art[i].followers
                     << "," << art[i].genres
                     << "," << art[i].name
                     << "," << art[i].popularity
                     << endl;
            }
            finA->seekg(0, finA->beg);
            cout << "Registros Tracks" << endl;
            for (int i = 0; i < n; i++)
            {
                finT->seekg(vetT[i] * sizeof(tracks), finT->beg);
                finT->read((char *)&tr[i], sizeof(tracks));

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
            }
            finT->seekg(0, finT->beg);
        }
        else //n= 100 ----- chamar funçao pra pegar 100 registros e criar arquivo de texto
        {
            int vetA[n], vetT[n];

            artists art[n];
            tracks tr[n];

            sorteia_numero(vetA, n, tamA);
            sorteia_numero(vetT, n, tamT);

            ofstream foutT, foutA;

            foutT.open("../arquivo/printTRACK.txt");
            foutA.open("../arquivo/printARTISTS.txt");
            //Registros Artists
            for (int i = 0; i < n; i++)
            {

                finA->seekg(vetA[i] * sizeof(artists), finA->beg);
                finA->read((char *)&art[i], sizeof(artists));
                foutA << art[i].id
                      << "," << art[i].followers
                      << "," << art[i].genres
                      << "," << art[i].name
                      << "," << art[i].popularity
                      << endl;
            }
            finA->seekg(0, finA->beg);
            //Registros Tracks

            for (int i = 0; i < n; i++)
            {
                finT->seekg(vetT[i] * sizeof(tracks), finT->beg);
                finT->read((char *)&tr[i], sizeof(tracks));
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
            }
            finT->seekg(0, finT->beg);
            foutT.close();
            foutA.close();
        }
    }
}
