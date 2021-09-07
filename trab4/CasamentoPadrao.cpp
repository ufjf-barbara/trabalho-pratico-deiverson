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
        while (k > 0 && P[k] != P[i]) // k recebe o prefixo da pod
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

    for (int i = 0; i < n; i++) //varriçao do texto
    {
        if (P[k] == T[i]) //verifica correspondencia de caracter
            k++;
        if (k == m) //se ja fora verificado todo o Padrao
        {
            cout << "Padrao encontrado na posicao: " << (i + 1 - k) << endl;
            cont++;
            k = pi[k - 1];
        }
        if (i < m && P[k] != T[i]) // se verdadeiro, reinicia a busca por correspondencia
        {
            if (k > 0)
                k = pi[k - 1];
        }
    }
    cout << cont << " ocorrencias" << endl;
}

//algoritmo de força bruta

int forcaBruta(string T, string P)
{

    int n = T.length(); //n recebe o tamanho do texto
    int m = P.length(); //m recebe o tamanho do padrão
    int j = 1;
    for (int i = 0; i < n - m; i++) //for de i a i<n-m
    {
        if (j < m && P[j] == T[i + j])
        {
            j++;
            return i++;
        }
        j++;
    }
    return -1;
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

    //cout << P << endl;

    clock_t begin = clock();

    cout<<"Algoritmo de Knuth-Morris-Pratt (KMP)"<<endl;
    kmpMatch(T, P);

    clock_t end = clock();

    cout << "Custo computational de " << (end - begin) / ((float)CLOCKS_PER_SEC) << " segundos" << endl;

    begin = clock();

    int ocorrecias = forcaBruta(T, P);

    end = clock();
    cout<<"Algoritmo de Forca Bruta "<<endl;
    cout << ocorrecias <<" ocorrencias " << endl;
    cout << "Custo computational de " << (end - begin) / ((float)CLOCKS_PER_SEC) << " segundos" << endl;

    padrao.close();
    dna.close();

    return 0;
}