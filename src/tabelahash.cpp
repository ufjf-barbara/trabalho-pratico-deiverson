#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "tabelaHash.h"
#include "Tracks.h"
#include "Ordenacao.h"
using namespace std;

tabelaHash::tabelaHash()
{
    ifstream ifs("../print/tracks.bin");
    ifs.seekg(0, ifs.end);
    mod = ifs.tellg() / sizeof(tracksAux);
    ifs.close();

    this->conta_colisao_de_artistas = 0;

    tracks track;
    track.id = "-1";

    vector<tracks> tr;
    tr.push_back(track);

    cout << "\nconstrutor " << mod << endl;
    for (int i = 0; i < this->mod; i++)
    {
        if (i == 0)
        {
            cout << "\nprimeiro for";
        }
        this->tabela.push_back(tr);

        //  vector<vector<tracks>>
    }
    cout << "\nconstrutor " << endl;

    vector<tracks> tra = Tracks::registrosTr(mod, mod);
    inserir(tra);
    artistasFrequentes();
}

int tabelaHash::gerarCodigoHash(string id)
{

    return (id[9] * id[3] * id[19] % mod);
}

// int tabelaHash::detMod()
// {
//     int j = 0;
//     int mmod = 0, result;
//     for (j = n; j > 0; j--)
//     {
//         result = 0;
//         for (int i = 1; i <= n / 2; i++)
//         {
//             if (n % i == 0)
//             {
//                 result++;
//             }
//         }
//         if (result == 2)
//         {
//             mod = j;
//             break;
//         }
//     }
//     return j;
// }

void tabelaHash::inserir(vector<tracks> &vet)
{

    int indice = 0;
    bool verifica = false;

    for (int i = 0; i < mod; i++)
    {
        cout << "\ninsercao" << endl;
        indice = gerarCodigoHash(vet[i].id_artists);
        do
        {
            verifica = false;
            if (tabela[indice][0].id == "-1")
            {
                tabela[indice].insert(tabela[indice].begin(), vet[i]);
                verifica = true;
            }
            else if (tabela[i][0].id_artists == vet[i].id_artists)
            {
                tabela[indice].push_back(vet[i]);
                verifica = true;
            }
            else
            {
                conta_colisao_de_artistas++;
                if (indice + 1 < mod)
                    indice++;
                 else
                 indice=0;   
            }
        } while (verifica != false);
    }
}

tracks tabelaHash::musicaPopular(vector<tracks> &vet)
{
    int aux = 0;

    for (int i = 0; i < vet.size(); i++)
    {
        if (vet[aux].popularity < vet[i].popularity)
        {
            aux = i;
        }
    }
    return vet[aux];
}

void tabelaHash::artistasFrequentes()
{
    Ordenacao::ordenaQuickTraks(tabela, 0, tabela.size());
    int M = 0;
    cout << "\nDeseja obter quantos artistas mais frequentes?" << endl;
    cin >> M;
    cin.ignore();
    for (int i = 0; i < M; i++)
    {
        cout << "\nArtista:\t" << tabela[i][0].artists
             << "\tMusica mais popular:\t" << musicaPopular(tabela[i]).name << endl;
    }
}
int tabelaHash::getcont()
{
    return conta_colisao_de_artistas;
}