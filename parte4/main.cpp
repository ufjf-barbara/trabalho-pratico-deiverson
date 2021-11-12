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