#include "Artists.h"
#include "Tracks.h"
#include "functeste.h"
#include "Ordenacao.h"
#include "tabelaHash.h"
#include "ArvoreVP.h"
#include "ArvoreB.h"

#include <fstream>  //leitura e escrita de arquivos
#include <iostream> //entrada pelo teclado e saida pela prompt
#include <time.h>   // trabalhar com o relogio do sistema
#include <string.h>

using namespace std;

int display();
void call(string path);
void parteTres();
void parteDois();
void parteUm(string path);

int main(int argc, char **argv)
{
    srand(time(NULL));
    string path = argv[1];

    ifstream artbin, trbin;

    artbin.open("../print/artists.bin", ios::in | ios::binary);
    trbin.open("../print/tracks.bin", ios::in | ios::binary);

    if (!artbin.is_open()) // Verificaçao pra saber se o arquivo Artists.bin ja foi criado, caso nao, ler o Artist.csv e cria-lo
    {
        artbin.close();
        Artists *arti = new Artists(path);
        delete arti;
    }
    artbin.close();
    if (!trbin.is_open()) // Verificaçao pra saber se o arquivo Tracks.bin ja foi criado, caso nao, ler o Tracks.csv e cria-lo
    {
        trbin.close();
        Tracks *tr = new Tracks(path);
        delete tr;
    }
    trbin.close();

    ofstream saida("saida.txt", ios::out | ios::trunc);
    saida.close();

    call(path);

    return 0;
}

void call(string path) // funçao para chamar as execuçoes do trabalho
{
    int aux = 1;
    while (aux != 0)
    {
        cout << "\n-----------------------------------------------------------------------------------------------------\n"
             << endl;
        cout << "Qual parte do trabalho deseja executar? (Digite o numero conrespondente a opcao desejada)\n";
        cout << "[1] Primeira parte\n[2] Segunda parte\n[3] Terceira parte\n[0] Finalizar\n";
        cout << "\n-----------------------------------------------------------------------------------------------------\n";
        cin >> aux;
        cin.ignore();
        if (aux >= 0 && aux <= 3)
        {
            switch (aux)
            {
            case 0:
                break;
            case 1:
                parteUm(path); //chama a primeira parte do trabalho
                break;
            case 2:
                parteDois(); //chama a segunda parte do trabalho
                break;
            case 3:
                parteTres();
                break;
            default:
                cout << "\nOpcao invalida\n";
            }
        }
    }
}

void VP()
{
    string str;
    ArvoreVp *vp;
    switch (display())
    {
    case 1:
        vp = new ArvoreVp();
        vp->busca();
        break;
    case 2:
        vp = new ArvoreVp();
        cout << "\n-----------------------------------------------------------------------------------------------------\n"
             << endl;
        cout << "Qual artista pretende encontrar?\n";
        cout << "\n-----------------------------------------------------------------------------------------------------\n";
        getline(cin, str);
        vp->busca(str);
        break;
    case 3:
        break;
    default:;
    }
    delete vp;
}

void B()
{
    string str;
    ArvoreB *b;
    ArvoreB *b1;
    ArvoreB *b2;
    int t = -1;

    switch (display())
    {
    case 1:
        cout << "\nArvore B executando t=20";
        b = new ArvoreB(20);
        b->busca();
        cout << "\nArvore B executando t=200";
        b1 = new ArvoreB(200);
        b1->busca();
        break;
    case 2:
        while (t < 0)
        {
            cout << "\n-----------------------------------------------------------------------------------------------------\n"
                 << endl
                 << "Digite a ordem minima desejada para teste da ArvoreB\n ";
            cout << "\n-----------------------------------------------------------------------------------------------------\n";
            cin >> t;
            cin.ignore();
        }
        b = new ArvoreB(t);
        cout << "\n-----------------------------------------------------------------------------------------------------\n"
             << endl;
        cout << "Qual artista pretende encontrar?\n";
        cout << "\n-----------------------------------------------------------------------------------------------------\n";
        getline(cin, str);
        b->busca(str);
        break;
    case 3:
        break;
    default:;
    }
    delete b;
    delete b1;
}

int display()
{
    int aux;
    bool a = true;
    while (a)
    {
        cout << "\n-----------------------------------------------------------------------------------------------------\n"
             << endl;
        cout << "Qual modo deseja acessar? (Digite o numero conrespondente a opcao desejada)\n";
        cout << "[1]Analise\n[2]Teste\n[3]Sair\n";
        cout << "\n-----------------------------------------------------------------------------------------------------\n";
        cin >> aux;
        cin.ignore();
        if (aux == 1 || aux == 2 || aux == 3)
            a = false;
    }
    return aux;
}

void parteTres()
{
    int aux;
    while (aux != 3)
    {
        cout << "\n-----------------------------------------------------------------------------------------------------\n"
             << endl;
        cout << "qual estrutura dedados balanceada deseja executar? (Digite o numero conrespondente a opcao desejada)\n";
        cout << "[1]Arvore Rubro/Negro\n[2]ArvoreB\n[3]Sair\n";
        cout << "\n-----------------------------------------------------------------------------------------------------\n";
        cin >> aux;
        cin.ignore();
        switch (aux)
        {
        case 1:
            VP();
            break;
        case 2:
            B();
            break;
        case 3:
            break;
        default:
            cout << "\nOpçao invalida" << endl;
        }
    }
}

void parteDois()
{

    int aux = 1;
    while (aux != 0)
    {
        cout << "\n-----------------------------------------------------------------------------------------------------\n"
             << endl;
        cout << "O que deseja executar? (Digite o numero conrespondente a opcao desejada)\n";
        cout << "[1] Ordenacao\n[2] Hash\n[3] Modulo teste\n[0] Finalizar\n";
        cout << "\n-----------------------------------------------------------------------------------------------------\n";
        cin >> aux;

        cin.ignore();

        Ordenacao ord;
        int r;
        ofstream saida;

        ifstream ns("input.dat", ios::in);
        string straux;

        tabelaHash *table;

        switch (aux)
        {
        case 0:
            break;
        case 1:
            //Chamar  Ordenacao;
            saida.open("../print/saida.txt", ios::out | ios::trunc); //abre o arquivo o limpando
            saida.close();
            while (getline(ns, straux)) //Para cada linha o input.dat sao chamadas as funçoes de ordenaçao
            {
                cout << "Aguarde . . ." << endl;
                istringstream(straux) >> r;
                ord.chamaFuncaoOrdenacao(r);
                cout << "Ordenacao para " << r << " registros concluida " << endl; //mensagens de loading pra tela
            }
            break;

        case 2:
            //Chamar  Hash;
            table = new tabelaHash(); // Chama a funçao da tabela hash
            break;

        case 3:
            //Chamar  Modulo Teste;
            func_teste::moduloTesteDois(); // Chama uma funçao para realizar , testes das chamadas acima, porem com quantidades reduzidas
            break;

        default:
            cout << "\nOpcao invalida\n";
        }
    }
}

void parteUm(string path) // Parte 1 do trabalho
{
    func_teste::moduloTesteUm(path); // chamada para executar a funçao teste da primeira parte do trabalho
}