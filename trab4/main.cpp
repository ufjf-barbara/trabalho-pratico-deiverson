#include <iostream>
#include <map>
#include <stdio.h>
#include <queue>
#include <vector>
#include <sstream>
#include <fstream>
#include <time.h>
#include <utility>
#include <string>
#include "huffman.h"
#include "CasamentoPadrao.h"

using namespace std;

void display(string path);
void casamento(string path);

int main(int argc, char **argv)
{
    display(argv[1]);

    return 0;
}

void casamento(string path)
{
    int x = 1;

    ifstream dna;
    ifstream Padrao;
    int cont = 1;
    clock_t begin;
    clock_t end;

    string T;
    string P;
    string str;
    stringstream ss;

    dna.open(path + "./dna1.txt");
    getline(dna, str);
    getline(dna, str);
    while (getline(dna, str))
    {
        T += str;
    }

    int aux = 1;
    while (aux != 0)
    {
        cout << "\n-----------------------------------------------------------------------------------------------------\n"
             << endl;
        cout << "Qual deseja executar? (Digite o numero conrespondente a opcao desejada)\n";
        cout << "[1]Forca bruta\n[2]Knuth-Morris-Pratt (KMP) \n[3]Boyer-Moore-Horspool (BMH)\n[0]Finalizar\n";
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
                cout << "Executando forca Bruta Para : " << endl;
                while (cont <= 5)
                {
                    Padrao.open(path + "./Padrao" + to_string(cont) + ".txt");
                    getline(Padrao, str);
                    getline(Padrao, str);

                    while (getline(Padrao, str))
                    {
                        P += aux;
                    }
                    cout << P.length() << " Padroes" << endl;
                    begin = clock();
                    CasamentoPadrao::forcaBruta(T, P);
                    end = clock();
                    cout << "Custo computational de " << (end - begin) / ((float)CLOCKS_PER_SEC) << " segundos" << endl;
                }
                break;
            case 2:

                cout << "Executando KMP Para : " << endl;
                while (cont <= 5)
                {
                    Padrao.open(path + "./Padrao" + to_string(cont) + ".txt");
                    getline(Padrao, str);
                    getline(Padrao, str);

                    while (getline(Padrao, str))
                    {
                        P += aux;
                    }
                    cout << P.length() << " Padroes" << endl;
                    begin = clock();
                    CasamentoPadrao::kmpMatch(T, P);
                    end = clock();
                    cout << "Custo computational de " << (end - begin) / ((float)CLOCKS_PER_SEC) << " segundos" << endl;
                }
                break;
            case 3:

                cout << "Executando BMH Para : " << endl;
                while (cont <= 5)
                {
                    Padrao.open(path + "./Padrao" + to_string(cont) + ".txt");
                    getline(Padrao, str);
                    getline(Padrao, str);

                    while (getline(Padrao, str))
                    {
                        P += aux;
                    }
                    cout << P.length() << " Padroes" << endl;
                    begin = clock();
                    CasamentoPadrao::BMH(T, P);
                    end = clock();
                    cout << "Custo computational de " << (end - begin) / ((float)CLOCKS_PER_SEC) << " segundos" << endl;
                }
                break;
            default:
                cout << "\nOpcao invalida\n";
            }
        }
    }
}

void display(string path) // funçao para chamar as execuçoes do trabalho
{
    ifstream dna;
    int x = 1;

    clock_t begin;
    clock_t end;

    string T;
    string S;
    string str;
    stringstream ss;

    int aux = 1;
    while (aux != 0)
    {
        cout << "\n-----------------------------------------------------------------------------------------------------\n"
             << endl;
        cout << "O que deseja executar? (Digite o numero conrespondente a opcao desejada)\n";
        cout << "[1]Casamento de padroes\n[2] Compressao \n[0] Finalizar\n";
        cout << "\n-----------------------------------------------------------------------------------------------------\n";
        cin >> aux;
        cin.ignore();
        if (aux >= 0 && aux <= 2)
        {
            switch (aux)
            {
            case 0:
                break;
            case 1:
                casamento(path);
                break;
            case 2:
                dna.open(path + "./dna" + to_string(x) + ".txt");

                while (dna)
                {

                    getline(dna, str);
                    getline(dna, str);

                    while (getline(dna, str))
                    {
                        T += str;
                    }

                    huffman::HuffmanCode(T);
                    x++;
                    dna.close();
                    dna.open(path + "./dna" + to_string(x) + ".txt");
                }

                break;
            default:
                cout << "\nOpcao invalida\n";
            }
        }
    }
}