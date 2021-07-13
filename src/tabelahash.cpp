#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "tabelaHash.h"
#include "Tracks.h"
#include "Ordenacao.h"
using namespace std;

tabelaHash::tabelaHash(int n)
{
    mod = Tracks::getTAM();//tamanho da tebela

    this->conta_colisao_de_artistas = 0;

    tracks track;//criado track para inserir na tabela que as posições estão vagas
    track.id = "-1";

    vector<tracks> tr;
    tr.push_back(track);

    for (int i = 0; i < mod; i++)//inserção na tabela
    {
        this->tabela.push_back(tr);
    }

    vector<tracks> tra = Tracks::registrosTr(n, mod);//importando N registros tracks
    inserir(tra);//inserindo na tabela

    artistasFrequentesTeste();
}

tabelaHash::tabelaHash()
{
    mod = Tracks::getTAM();

    this->conta_colisao_de_artistas = 0;

    tracks track;
    track.id = "-1";

    vector<tracks> tr;
    tr.push_back(track);

    for (int i = 0; i < (this->mod); i++)
    {
        this->tabela.push_back(tr);
    }

    vector<tracks> tra = Tracks::registrosTr(mod, mod);//importando o mesmo tamanho da tabela 
    inserir(tra);
    artistasFrequentes();
}

int tabelaHash::gerarCodigoHash(string id)
{
    return abs((id[9] * id[3] * id[17]) % mod);
}

void tabelaHash::inserir(vector<tracks> &vet)
{

    int indice = 0;
    bool verifica = false;

    for (int i = 0; i < vet.size(); i++)
    {
        indice = gerarCodigoHash(vet[i].id_artists);//recebe indice para inserçao na tabela
        do
        {
            verifica = false;//variavel para verificar se o elemento foi inserido na tabela

            if (tabela[indice][0].id == "-1")//inserçao na primeira coluna da tabela
            {
                tabela[indice].erase(tabela[indice].begin());
                tabela[indice].push_back(vet[i]);
                verifica = true;
            }
            else if (tabela[indice][0].id_artists == vet[i].id_artists) //tratamento de colisao encadeado para adicionar as musicas do mesmo artista em um unica linha da tabela
            {
                tabela[indice].push_back(vet[i]);
                verifica = true;
            }
            else
            {
                this->conta_colisao_de_artistas++;
                if ((indice + 1) < mod)//verificaçao para ver se o indice nao e maior que a tabela
                    indice++;
                else
                    indice = 0;
            }
        } while (!verifica);
    }
}

tracks tabelaHash::musicaPopular(vector<tracks> &vet)
{
    int aux = 0;

    for (int i = 0; i < vet.size(); i++)//percorre a tabela para pegar o elemento com a musica mais popular
    {
        if (vet[aux].popularity < vet[i].popularity)
        {
            aux = i;
        }
    }
    return vet[aux];//retorna a musica mais popular
}

void tabelaHash::artistasFrequentes()
{
    tracks tr;
    Ordenacao::ordenaQuickTraks(tabela, 0, tabela.size());//o QuickSort e usado para ordenar a tabela pois mostrou-se ser o algoritmo mais eficiente
    int M = 0;
    cout << "\nDeseja obter quantos artistas mais frequentes?" << endl;
    cin >> M;//numero de artistas
    cin.ignore();
    for (int i = 0; i < M; i++)//pega as musicas populares e e apresentam os artistas mais frequentes
    {
        tr = musicaPopular(tabela[i]);
        cout << "\nArtista:\t" << tabela[i][0].artists
             << "\tocorrencias:\t" << tabela[i].size()
             << "\tMusica mais popular:\t" << tr.name
             << endl;
    }
    cout << "\nColisoes:\t" << this->conta_colisao_de_artistas << endl;//numero de colisoes
}

int tabelaHash::getcont()
{
    return this->conta_colisao_de_artistas;//retorna numero de colisoes
}

void tabelaHash::artistasFrequentesTeste()
{
    tracks tr;
    ofstream saida("../print/teste.txt", ios::out | ios::app);//escreve teste.txt os resultados
    Ordenacao::ordenaQuickTraks(tabela, 0, tabela.size());
    int M = 1;
    cout << "\nDeseja obter quantos artistas mais frequentes?" << endl;
    cin >> M;
    cin.ignore();
    for (int i = 0; i < M; i++)
    {
        tr = musicaPopular(tabela[i]);
        saida << "\nArtista:\t" << tabela[i][0].artists
             << "\tocorrencias:\t" << tabela[i].size()
             << "\tMusica mais popular:\t" << tr.name
             << endl;
    }
    saida << "\nColisoes:\t" << this->conta_colisao_de_artistas << endl;
}