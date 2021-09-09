#include <stdio.h>
#include <string>
#include <vector>
#include <time.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <utility>

using namespace std;

//algoritmo KMP

void prefix(string P, vector<int> &pi)
{
    int m = P.length(); // tamanho do padrao
    pi[0] = 0;
    int k = 0;

    for (int i = 1; i < m; i++) //varrendo o padrao
    {
        while (k > 0 && P[k] != P[i])
            k = pi[k];
        if (P[k] == P[i])
            k++;
        pi[i] = k;
    }
}

void kmpMatch(string T, string P)
{
    vector<int> pi(P.length()); //vector de prefixos

    int n = T.size(), m = P.size();

    int cont = 0; //contador de ocorrencias

    prefix(P, pi); //chama funcao que computa os prefixos do padrao

    int k = 0; //contador de caracteres correspondentes
    int i = 0;
    while (i < n) //varriçao do texto
    {
        if (P[k] == T[i]) //verifica correspondencia de caracter
        {
            k++;
            i++;
        }
        if (k == m) //se ja fora verificado todo o Padrao
        {
            cout << "Padrao encontrado na posicao: " << (i - k) << endl;
            cont++;
            k = pi[k - 1];
        }
        if (i < n && P[k] != T[i]) // se verdadeiro, reinicia a busca por correspondencia
        {
            if (k > 0)
                k = pi[k - 1];
            else
                i++;
        }
    }
    cout << cont << " ocorrencias" << endl;
}

//algoritmo de força bruta

int forcaBruta(string T, string P)
{
    int n = T.size(); //n recebe o tamanho do texto
    int m = P.size(); //m recebe o tamanho do padrão
    int num = 0;
    bool eh = false;
    for (int i = 0; i < n - m + 1; i++) //for de i a i<n-m
    {
        eh = true;
        for (int k = 0; k < m; k++)
        {
            if (P[k] != T[i + k])
            {
                eh = false;
                break;
            }
        }
        if (eh)
        {
            for (int k = 0; k < m; k++)
            {
                cout << T[i + k];
            }
            cout << "Padrao encontrado na posicao: " << i << endl; //imprime a posição da ocorrencia
            num++;
        }
    }
    return num; //retorna o numero de ocorrencias
}

int main()
{
    string x = "1";
    ifstream padrao("padrao" + x + ".txt");
    ifstream dna("dna1.txt");

    string T;
    string P;

    string aux;

    getline(padrao, aux);
    getline(padrao, aux);

    while (getline(padrao, aux))
    {
        P += aux;
    }

    while (getline(dna, aux))
    {
        T += aux;
    }

    clock_t begin = clock();

    cout << "Algoritmo de Knuth-Morris-Pratt (KMP)" << endl;
    kmpMatch(T, "gatactgttc");

    clock_t end = clock();

    cout << "Custo computational de " << (end - begin) / ((float)CLOCKS_PER_SEC) << " segundos" << endl;

    vector<int> vet(P.size());

    cout << "Algoritmo de Forca Bruta " << endl;
    begin = clock();
    int ocorrencias = forcaBruta(T, "gatactgttc");
    end = clock();
    cout << ocorrencias << " ocorrencias" << endl;
    cout << "Custo computational de " << (end - begin) / ((float)CLOCKS_PER_SEC) << " segundos" << endl;

    padrao.close();
    dna.close();

    return 0;
}