#include <stdio.h>
#include <string>
#include <vector>
#include <time.h>
#include <iostream>
#include <time.h>
#include <utility>
#include <string>
#include <string.h>
#include <sstream>
#include "CasamentoPadrao.h"

using namespace std;

//algoritmo KMP

void CasamentoPadrao::prefix(string P, vector<int> &pi)
{
    int m = P.length(); // tamanho do padrao
    int k = 0;
    pi[1] = 0;

    for (int q = 2; q <= m; q++) //varrendo o padrao
    {
        while (k > 0 && P[k + 1] != P[q])
            k = pi[k];
        if (P[k] == P[q])
            k++;
        pi[q] = k;
    }
    // for (int i = 0; i < P.size(); i++)
    // {
    //     cout << pi[i] << " caracter " << P[i] << endl;
    // }
}

void CasamentoPadrao::kmpMatch(string T, string P)
{
    cout << "\nPadroes encontrados nas posicoes : " << endl;
    int n = T.size(), m = P.size(), q = 0;
    vector<int> pi(P.size() + 1); //vector de prefixos

    prefix(P, pi);
    T = " " + T;

    int cont = 0;

    for (int i = 1; i <= n; i++)
    {
        while (q > 0 && P[q + 1] != T[i])
            q = pi[q];
        if (P[q + 1] = T[i])
            q = q + 1; //
        if (q == m)
        {
            cout << i - m << " ";
            q = pi[q];
            cont++;
        }
    }
    cout << cont << " ocorrencias" << endl;
}
// {
//     cout << "Padroes encontrados nas posicoes : " << endl;
//     vector<int> pi(P.size()); //vector de prefixos

//     int n = T.size(), m = P.size();

//     int cont = 0; //contador de ocorrencias

//     prefix(P, pi); //chama funcao que computa os prefixos do padrao

//     int k = 0; //contador de caracteres correspondentes
//     int i = 0;

//     while (i < n) //varriçao do texto
//     {
//         // cout << " " << i << "    " << n << endl;
//         if (P[k] == T[i]) //verifica correspondencia de caracter
//         {
//             k++;
//             i++;
//         }
//         if (k == m) //se ja fora verificado todo o Padrao
//         {
//             cout << i - k << " ";
//             cont++;
//             k = pi[k - 1];
//         }
//         if (i < n && P[k] != T[i]) // se verdadeiro, reinicia a busca por correspondencia
//         {
//             // cout << "aqui" << endl;
//             if (k > 0)
//                 k = pi[k - 1];
//             else
//                 i++;
//         }
//     }

//     cout << "\n"
//          << cont << " ocorrencias" << endl;
// }

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

    int n = T.size(), m = P.size();

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

void CasamentoPadrao::casamento(string path)
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

    dna.open("dna1.txt");
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
                    Padrao.open("padrao" + to_string(cont) + ".txt");
                    getline(Padrao, str);
                    getline(Padrao, str);

                    while (getline(Padrao, str))
                    {
                        for (char c : str)
                        {
                            if (c == 'a' || c == 'c' || c == 't' || c == 'g')
                                P += c;
                        }
                    }
                    cout << P.length() << " Padroes" << endl;
                    begin = clock();
                    forcaBruta(T, P);
                    end = clock();

                    cout << "Custo computational de " << (end - begin) / ((float)CLOCKS_PER_SEC) << " segundos" << endl;
                    cont++;
                    P = "";
                    Padrao.close();
                }
                cont = 1;
                break;
            case 2:
                cout << "Executando forca Bruta Para : " << endl;
                while (cont <= 5)
                {
                    Padrao.open("padrao" + to_string(cont) + ".txt");
                    getline(Padrao, str);
                    getline(Padrao, str);

                    while (getline(Padrao, str))
                    {
                        for (char c : str)
                        {
                            if (c == 'a' || c == 'c' || c == 't' || c == 'g')
                                P += c;
                        }
                    }
                    cout << P.length() << " Padroes" << endl;

                    begin = clock();
                    kmpMatch(T, P);
                    end = clock();

                    cout << "Custo computational de " << (end - begin) / ((float)CLOCKS_PER_SEC) << " segundos" << endl;
                    P = "";
                    Padrao.close();

                    cont++;
                }
                cont = 1;
                break;
            case 3:
                cout << "Executando BMH Para : " << endl;
                while (cont <= 5)
                {
                    Padrao.open("padrao" + to_string(cont) + ".txt");
                    getline(Padrao, str);
                    getline(Padrao, str);

                    while (getline(Padrao, str))
                    {
                        for (char c : str)
                        {
                            if (c == 'a' || c == 'c' || c == 't' || c == 'g')
                                P += c;
                        }
                    }
                    cout << P.length() << " Padroes" << endl;
                    begin = clock();
                    BMH(T, P);
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