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

/*void casamento(string path)
{
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
                    Padrao.open(path + "./padrao" + to_string(cont) + ".txt");
                    getline(Padrao, str);
                    getline(Padrao, str);

                    while (getline(Padrao, str))
                    {
                        P += str;
                    }

                    begin = clock();
                  CasamentoPadrao::  forcaBruta(T, P);
                    end = clock();

                    cout << "Custo computational de " << (end - begin) / ((float)CLOCKS_PER_SEC) << " segundos" << endl;
                    cont++;
                    P = "";
                    Padrao.close();
                }
                cont = 1;
                break;
            case 2:
                while (cont <= 5)
                {
                    Padrao.open(path + "./padrao" + to_string(cont) + ".txt");
                    getline(Padrao, str);
                    getline(Padrao, str);

                    while (getline(Padrao, str))
                    {
                        P += str;
                    }
                    cout << P.length() << " Padroes" << endl;
                    begin = clock();
                 CasamentoPadrao::   kmpMatch(T, P);
                    end = clock();
                    cout << "Custo computational de " << (end - begin) / ((float)CLOCKS_PER_SEC) << " segundos" << endl;
                    cont++;
                    P = "";
                    Padrao.close();
                }
                cont = 1;
                break;
            case 3:
                cout << "Executando BMH Para : " << endl;
                while (cont <= 5)
                {
                    Padrao.open(path + "./padrao" + to_string(cont) + ".txt");
                    getline(Padrao, str);
                    getline(Padrao, str);

                    while (getline(Padrao, str))
                    {
                        P += str;
                    }
                    cout << P.length() << " Padroes" << endl;
                    begin = clock();
               CasamentoPadrao::     BMH(T, P);
                    end = clock();
                    cout << "Custo computational de " << (end - begin) / ((float)CLOCKS_PER_SEC) << " segundos" << endl;
                    cont++;
                    P = "";
                    Padrao.close();
                }
                cont = 1;
                break;
            default:
                cout << "\nOpcao invalida\n";
            }
        }
    }
    dna.close();
}
*/

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
                CasamentoPadrao::casamento(path);
                break;
            case 2:
                dna.open("dna" + to_string(x) + ".txt");

                cout << "Qualquer coisa " << x << endl;
                while (!dna.eof())
                {

                    getline(dna, str);
                    getline(dna, str);

                    while (getline(dna, str))
                    {
                        for (char c : str)
                        {
                            if (c == 'a' || c == 'c' || c == 't' || c == 'g')
                                T += c;
                        }
                    }
                    T.shrink_to_fit();
                    huffman::HuffmanCode(T);
                    x++;
                    dna.close();
                    dna.open("dna" + to_string(x) + ".txt");
                    T = "";
                }
                x = 1;
                dna.close();
                break;
            default:
                cout << "\nOpcao invalida\n";
            }
        }
    }
}