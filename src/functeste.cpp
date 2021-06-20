#include "Artists.h"
#include "Tracks.h"
#include "functeste.h"
#include <fstream>  //leitura e escrita de arquivos
#include <iostream> //entrada pelo teclado e saida pela prompt
#include <time.h>   // trabalhar com o relogio do sistema
#include <stdlib.h>

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

    //verifico se os arquivos resalmente estao abertos e chamo finalmente a funçao teste
    if (finT.is_open() && finA.is_open())
    {
        finA.close();
        finT.close();
        callTeste(tamT, tamA);
    }
    else
        cout << "arquivos nao abriram" << endl;
}

//funçao que verifica se o numero sorteado ja foi sorteado
bool func_teste::verifica_numero(int vet[], int n, int aux)
{
    for (int i = 0; i < n; i++)
        if (vet[i] == aux)
            return true;
    return false;
}

// função que sorteia o numero da posiçao dos registros a serem coletados para impressao
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

// funçao para saber quantos registros ler dos binarios,
// manipular os ponteiros nos arquivos e fazer a impreçao no console output
// em um arquivo de texto em uma pasta chamada " print " do diretorio principal
// do trabalho
void func_teste::callTeste(int tamT, int tamA)

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
            // vetores para armazenar os numeros das posiçoes aleatorias
            int vetA[n], vetT[n];

            //vetor de estruturas dos registros a serem impressos
            artists art[n];
            tracks tr[n];

            //chamada para sortear os numeros das posiçoes aleatorias
            sorteia_numero(vetA, n, tamA);
            sorteia_numero(vetT, n, tamT);
            
            cout << "\n\nRegistros Artists\n\n"
                 << endl;
            for (int i = 0; i < n; i++)
            {
                //abertura do arquivo binario
                ifstream finA;
                finA.open("../print/artists.bin", ios::in);

                //estrutura auxiliar
                artistsAux arti;
                // pegando a posiçao em bytes
                int posicao = vetA[i] * sizeof(artistsAux);
                // posicionando o ponteiro na posiçao a ser lida
                finA.seekg(posicao, ios::beg);
                //lendo o registro em uma estrurura aux com vetores de caracteres

                finA.read((char *)&arti, sizeof(artistsAux));
                // convertendo os vetores
                //de caracteres da estrutura auxiliar e atribuindo ela à estrutura padrao
                art[i] = Artists ::converteArtToString(arti);
                //imprimindo no console
                cout << arti.id
                     << "," << arti.followers
                     << "," << arti.genres
                     << "," << arti.name
                     << "," << arti.popularity
                     << endl;
                finA.close(); // fechando o arquivo binario
            }

            cout << "\n\nRegistros Tracks\n\n"
                 << endl;
            for (int i = 0; i < n; i++)
            {
                //abertura do arquivo binario
                ifstream finT;
                finT.open("../print/tracks.bin", ios::in);
                //estrutura auxiliar
                tracksAux tra;
                // posicionando o ponteiro na posiçao a ser lida
                finT.seekg(vetT[i] * sizeof(tracksAux), finT.beg);
                //lendo o registro em uma estrurura aux com vetores de caracteres
                finT.read((char *)&tra, sizeof(tracksAux));
                // convertendo os vetores
                //de caracteres da estrutura auxiliar e atribuindo ela à estrutura padrao
                tr[i] = Tracks::converteTracksToString(tra);
                //imprimindo no console
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
                finT.close(); // fechando o arquivo binario
            }
        }
        else //n= 100 ----- pega 100 registros e cria arquivo de texto armazenando-os na pasta print
        {
            // vetores para armazenar os numeros das posiçoes aleatorias
            int vetA[n], vetT[n];

            //vetor de estruturas dos registros a serem impressos
            artists art[n];
            tracks tr[n];

            //chamada para sortear os numeros das posiçoes aleatorias
            sorteia_numero(vetA, n, tamA);
            sorteia_numero(vetT, n, tamT);

            //Criando os arquivos onde serao impressos os dados dos registros
            ofstream foutT, foutA;
            foutT.open("../print/printTRACK.txt");
            foutA.open("../print/printARTISTS.txt");

            //Registros Artists
            for (int i = 0; i < n; i++)
            { //abertura do arquivo binario
                ifstream finA;
                finA.open("../print/artists.bin", ios::in);

                //estrutura auxiliar
                artistsAux arti;
                // pegando a posiçao em bytes
                int posicao = vetA[i] * sizeof(artistsAux);
                // posicionando o ponteiro na posiçao a ser lida
                finA.seekg(posicao, ios::beg);
                //lendo o registro em uma estrurura aux com vetores de caracteres

                finA.read((char *)&arti, sizeof(artistsAux));
                // convertendo os vetores
                //de caracteres da estrutura auxiliar e atribuindo ela à estrutura padrao
                art[i] = Artists ::converteArtToString(arti);

                //imprimindo no arquivo de texto
                foutA << art[i].id
                      << "," << art[i].followers
                      << "," << art[i].genres
                      << "," << art[i].name
                      << "," << art[i].popularity
                      << endl;
                finA.close(); //fechando o arquivo binario
            }

            //Registros Tracks

            for (int i = 0; i < n; i++)
            {
                //abertura do arquivo binario
                ifstream finT;
                finT.open("../print/tracks.bin", ios::in);
                //estrutura auxiliar
                tracksAux tra;
                // posicionando o ponteiro na posiçao a ser lida
                finT.seekg(vetT[i] * sizeof(tracksAux), finT.beg);
                //lendo o registro em uma estrurura aux com vetores de caracteres
                finT.read((char *)&tra, sizeof(tracksAux));
                // convertendo os vetores
                //de caracteres da estrutura auxiliar e atribuindo ela à estrutura padrao
                tr[i] = Tracks::converteTracksToString(tra);
                //imprimindo no arquivo de texto
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
                finT.close(); //fechando o arquivo binario
            }
            //Fechando os arquivos de impressao
            foutT.close();
            foutA.close();
        }
    }
}
