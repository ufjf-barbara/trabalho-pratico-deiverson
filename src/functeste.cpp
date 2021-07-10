#include "Artists.h"
#include "Tracks.h"
#include "functeste.h"
#include <iostream> //entrada pelo teclado e saida pela prompt
#include <fstream>
#include <vector>

using namespace std;

void func_teste::func_test(string path) // funçao estatica
{
    ifstream finT, finA;
    artistsAux art;
    tracksAux tr;

    finT.open("../print/tracks.bin", ios::in);
    finA.open("../print/artists.bin", ios::in);

    //posicionando o ponteiro no final do arquivo
    finT.seekg(0, finT.end);
    finA.seekg(0, finA.end);

    // usando o tellg pra saber o tamanho do arquivo com o ponteiro no final delete
    // e dividindo pelo tamnha da estrutura utiliza pra fazer a escrita em binarios
    //consigo obter o numero de registros que há em cada arquivo binario
    int tamT = finT.tellg() / sizeof(tracksAux);
    int tamA = finA.tellg() / sizeof(artistsAux);
    cout<<"\ntellgT "<< finT.tellg() <<"\ntamT "<< tamT<<"\nsizeT "<< sizeof(tracksAux)<<endl;

    //verifico se os arquivos resalmente estao abertos e chamo finalmente a funçao teste
    if (finT.is_open() && finA.is_open())
    {
        testReadBin(tamT, tamA);
    }
    else
        cout << "arquivos nao abriram" << endl;
    finA.close();
    finT.close();
}

// funçao para saber quantos registros ler dos binarios,
// manipular os ponteiros nos arquivos e fazer a impreçao no console output
// em um arquivo de texto em uma pasta chamada " print " do diretorio principal
// do trabalho
void func_teste::testReadBin(int tamT, int tamA)

{
    int n = 0;
    while (!(n == 10 || n == 100)) // loop para chamar o teste adequadamente;
    {
        // pedindo informaçao ao usuario para saber quantos registros ler
        cout << "----------------Quantos registros deseja obter aleatoriamente, 10 ou 100?----------------" << endl;
        cin >> n;
        cin.ignore();

        // verifica se o usuario  digitou uma das opçoes validas
        if (!(n == 10 || n == 100))
        {
            cout << "Resposta invalida" << endl;
        }
        // se verdadeiro pega 10 registros aleatorios  e os imprime  na tela
        else if (n == 10)
        {
            cout << "\n\nRegistros Artists\n\n"
                 << endl;
            for (artists art : Artists::registrosArt(n, tamA))
            {
                cout << art.id
                     << "," << art.followers
                     << "," << art.genres
                     << "," << art.name
                     << "," << art.popularity
                     << endl;
            }

            cout << "\n\nRegistros Tracks\n\n"
                 << endl;

            for (tracks tr : Tracks::registrosTr(n, tamT))
            {
                cout << tr.id
                     << " , " << tr.name
                     << " , " << tr.popularity
                     << " , " << tr.duration_ms
                     << " , " << tr.explicit_
                     << " , " << tr.artists
                     << " , " << tr.id_artists
                     << " , " << tr.release_date
                     << " , " << tr.danceability
                     << " , " << tr.energy
                     << " , " << tr.key
                     << " , " << tr.loudness
                     << " , " << tr.mode
                     << " , " << tr.speechiness
                     << " , " << tr.acousticness
                     << " , " << tr.instrumentalness
                     << " , " << tr.liveness
                     << " , " << tr.valence
                     << " , " << tr.tempo
                     << " , " << tr.time_signature
                     <<"\n\n-----------------------------------\n\n";
            }
        }
        else //n= 100 ----- pega 100 registros e cria arquivo de texto armazenando-os na pasta print
        {

            //Criando os arquivos onde serao impressos os dados dos registros
            ofstream foutT, foutA;
            foutT.open("../print/printTRACK.txt");
            foutA.open("../print/printARTISTS.txt");

            //Registros Artists

            for (artists art : Artists::registrosArt(n, tamA))
            {
                foutA << art.id
                      << "," << art.followers
                      << "," << art.genres
                      << "," << art.name
                      << "," << art.popularity
                      << endl;
            }
            foutA.close();
            //Registros Tracks

            for (tracks tr : Tracks::registrosTr(n, tamT))
            {
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
                      << endl;
            }
            foutT.close();
        }
    }
}
