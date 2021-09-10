#include <stdio.h>
#include <string>
#include <vector>
#include <time.h>
#include <iostream>
#include <time.h>
#include <utility>
#include <string>
#include <string.h>
#include "CasamentoPadrao.h"

using namespace std;

//algoritmo KMP

void CasamentoPadrao::prefix(string P, vector<int> &pi)
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

void CasamentoPadrao::kmpMatch(string T, string P)
{
    cout << "Padroes encontrados nas posicoes : ";
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
            cout << (i - k) << " ";
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
    cout << "\n"
         << cont << " ocorrencias" << endl;
}

//algoritmo de força bruta

void CasamentoPadrao::forcaBruta(string T, string P)
{
    cout << "Padroes encontrados nas posicoes : ";
    int n = T.size(); //n recebe o tamanho do texto
    int m = P.size(); //m recebe o tamanho do padrão
    bool eh = false;
    int num = 0;
    for (int i = 0; i < n - m + 1; i++) //for de i a i<n-m
    {
        eh = true;
        for (int k = 0; k < m; k++)
        {
            if (P[k] != T[i + k]) //compara as posições do padrao e do texto
            {
                eh = false;
                break;
            }
        }
        if (eh)
        {
            for (int k = 0; k < m; k++) //percorre todo o padrao
            {
                cout << T[i + k];
            }
            cout << i << " "; //imprime a posição da ocorrencia
            num++;
        }
    }
    cout << "\n"
         << num << " ocorrencias" << endl;
}

//algoritmo BMH

void CasamentoPadrao::prefixBMH(string P, int *pi)
{
    int m = P.size();
    for (int i = 0; i < m; i++)
    {

        pi[P[i]] = m - i - 1;
        if (i + 1 == m) //criar tabela de prefixBMHos tamanho 128
            pi[P[i]] = m;
    }
}

void CasamentoPadrao::BMH(string T, string P)
{
    cout << "Padroes encontrados nas posicoes : ";
    int pi[128]; //vetor de prefixBMHos
    memset(pi, 0, sizeof(int) * 128);

    int n = T.length(), m = P.size();

    int cont = 0; //contador de ocorrencias

    prefixBMH(P, pi); //chama funcao que computa os prefixos do padrao

    for (int i = m - 1; i < n; i++) //varredura do texto
    {

        for (int j = 0; j < m; j++) // j= m-1 , j>=0
        {

            if (P[m - 1 - j] != T[i - j]) //verifica se o caractere do texto esta no padrao
            {

                if (pi[T[i - j]]) // se tiver, o pulo e feito com o valor do calculo do prefixo
                {
                    //cout << P[m - 1 - j] << " " << T[i - j] << endl;

                    i += pi[T[i - j]] - 1;
                    break;
                }
                else // senao pula o padrao inteiro
                {

                    i += m - 1;
                    break;
                }
            }
            else if (j + 1 == m)
            {
                cout << (i + 1 - m) << " ";
                cont++;
            }
        }
    }
    cout << "\n"
         << cont << " ocorrencias" << endl;
}
