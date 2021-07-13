#include "Artists.h"
#include "Tracks.h"
#include "functeste.h"
#include "Ordenacao.h"
#include "tabelaHash.h"

#include <iostream> //entrada pelo teclado e saida pela prompt
#include <fstream>
#include <vector>

using namespace std;

// funçao estatica
void func_teste::moduloTesteUm(string path) //funçao pra teste da primeira parte de trabalhho
{
    ifstream finT, finA;
    artistsAux art;
    tracksAux tr;

    //abertura do arquivo binario para verificaçao se estao abertos

    finT.open("../print/tracks.bin", ios::in);
    finA.open("../print/artists.bin", ios::in);

    if (finT.is_open() && finA.is_open())
    {
        testReadBin(Tracks::getTAM(), Artists::getTAM()); //chama a funçao
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
            for (artists art : Artists::registrosArt(n, tamA)) //recebe um vector de estruturas artists para imprimir
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

            for (tracks tr : Tracks::registrosTr(n, tamT)) //recebe um vector de estruturas tracks para imprimir
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
                     << " , " << tr.time_signature;
            }
        }
        else //n= 100 ----- pega 100 registros e cria arquivo de texto armazenando-os na pasta print
        {

            //Criando os arquivos onde serao impressos os dados dos registros
            ofstream foutT, foutA;
            foutT.open("../print/printTRACK.txt");
            foutA.open("../print/printARTISTS.txt");

            //Registros Artists

            for (artists art : Artists::registrosArt(n, tamA)) //recebe um vector de estruturas artists para imprimir em arquivo de texto
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

            for (tracks tr : Tracks::registrosTr(n, tamT)) //recebe um vector de estruturas tracks para imprimir em arquivo de texto
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

void func_teste::moduloTesteDois() //funçao pra teste da segunda parte de trabalhho
{
    Ordenacao ord;

    ord.chamaFuncaoOrdenacaoTeste(); //chama a funçao de teste da ordenaçao

    tabelaHash *table = new tabelaHash(1000); //chama o construtor de teste da tabela hash
}