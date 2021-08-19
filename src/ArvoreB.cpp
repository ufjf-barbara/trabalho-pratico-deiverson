#include "Artists.h"
#include "ArvoreB.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <ctime>



using namespace std;

static int Comparacoes = 0;
static int trocas=0;

int Compara(string str1, string str2); //
key *divide(Node *um, Node *dois, int t);

//construtor

ArvoreB::ArvoreB()
{
    raiz = NULL;
    this->t = 200;

    int tam = Artists::getTAM();
    vector<int> vet;

    for (int i = 0; i < tam; i++)//add tam valores
    {
        vet.push_back(i);
    }
    random_shuffle(vet.begin(), vet.end());

    clock_t begin = clock();
    for (int i = 0; i < 10400; i++)
    {
        key *aux = new key();
        artists art = Artists::reg(vet[i]);
        aux->name = art.name;
        aux->posicao = vet[i];
        aux->id = art.id;
        insercao(aux);//insere
    }
    clock_t end = clock();
    cout << "\ntempo insercao:\t" << (end - begin) / ((float)CLOCKS_PER_SEC) << endl;//impressao tempo de inserção
}

//função para inserir NÓ na arvore

void ArvoreB::insercao(key *p)
{
    if (raiz == NULL)
    {
        raiz = new Node();
        raiz->pai = NULL;
        raiz->folha = true;
        raiz->m = 1;
        raiz->folhas.resize(2*t+1,NULL);
        raiz->chaves.push_back(p);
        raiz->chaves.resize(2*t-1, NULL);
    }
    else
    {
        auxInsert(raiz, p);
    }
}

//função auxiliar para inserir NÓ na arvore

void ArvoreB::auxInsert(Node *no, key *k)
{
    //caso base , de ser uma folha
    if (no->folha)
    {
        int aqui=0;
        for (int i = 0; no->chaves[i] != NULL ; i++)
        {

            if (Compara(k->name, no->chaves[i]->name) < 0)
            {
                no->chaves.insert(no->chaves.begin() + i, k);
                no->chaves.resize(2*t,NULL);
                no->m++;
                if (no->chaves.size() == 2 * t)
                    cisao(no);
                return;
            }
            aqui=i+1;
        }
        no->chaves.insert(no->chaves.begin()+aqui, k);
        no->chaves.resize(2*t,NULL);
        no->m++;
        if (no->chaves.size() == 2 * t)
            cisao(no);
    }
    else //caso de ser um no
    {
        int aqui=0;
        for (int i = 0; no->chaves[i] !=NULL ; i++)
        {
            if (Compara(k->name, no->chaves[i]->name) < 0)
            {
                auxInsert(no->folhas[i], k);
                return;
            }
            aqui=i+1;
        }
        auxInsert(no->folhas[aqui], k);
    }
}

//função de busca 
void ArvoreB::busca()
{

    int tam = Artists::getTAM();
    vector<int> vet;

    for (int i = 0; i < tam; i++)
    {
        vet.push_back(i);
    }
    random_shuffle(vet.begin(), vet.end());

    ofstream saida("saida.txt", ios::out | ios::trunc);//resultados inseridos em um documento saida.txt
    saida.close();

    for (int i = 0; i < 100; i++)
    {
        Node *aux = new Node();
        artists art = Artists::reg(vet[i]);
        // begin = clock();
        auxBusca(this->raiz, art.name);//chamada da função auxiliar
        imprime(i, true);//chamada da impressão
    }
}
//função auxiliar de busca
int ArvoreB::auxBusca(Node *no, string val)
{
    for (int i = 0; no->chaves[i] != NULL ; i++)
    {
        if (no->chaves[i]->name == val)
            return no->chaves[i]->posicao;
        else if (no->chaves[i - 1] && Compara(val, no->chaves[i - 1]->name) > 0 && Compara(val, no->chaves[i]->name) < 0)
            return auxBusca(no->folhas[i], val);
    }
    return -1;
}

//função de impressao na saida.txt

void ArvoreB::imprime(int pos, bool b)
{
    ofstream saida("saida.txt", ios::out | ios::app);
    if (b)
    {
        saida << "\n-------------------------------------------------------------------------------------------------------\n";
        saida << "Tempo medio:\t" << tempoGlob / 100 << " segundos" << endl;
        saida << "Media de comparaçoes:\t" << compGlob / 100 << endl;
        saida << "\n-------------------------------------------------------------------------------------------------------\n";

        saida.close();
        return;
    }
    compGlob += compI;
    clock_t end = clock();
    tempoGlob += ((end - begin) / ((float)CLOCKS_PER_SEC));
    artists art = Artists::reg(pos);
    saida << "\n-------------------------------------------------------------------------------------------------------\n"
          << "Artista:\t" << art.name << endl
          << "Followers:\t" << art.followers << endl
          << "Genres:\t" << art.genres << endl
          << "Id:\t" << art.id << endl
          << "Popularity:\t" << art.popularity << endl
          << "\nTempo da busca:\t" << (end - begin) / ((float)CLOCKS_PER_SEC) << " segundos" << endl
          << "Numero de comparacoes:\t" << compI << endl;
    compI = 0;
}

//função de cisão

void ArvoreB::cisao(Node *no) //overvlow apenas
{
    if (no->pai == NULL)//caso seja a raiz
    {
        Comparacoes++;

        Node *dad=new Node();
        Node *bro=new Node();

        key *k = divide(no, bro, t);

        dad->chaves.push_back(k);

        no->pai = dad;
        bro->pai = dad;
        bro->chaves.resize(2*t,NULL);

        dad->folhas.push_back(no);
        dad->folhas.push_back(bro);

        dad->folhas.resize(2*t+1,NULL);
        dad->chaves.resize(2*t,NULL);

        dad->folha = false;
        raiz = dad;

        trocas++;
    }
    else
    {
        Node *bro=new Node();

        key *k = divide(no, bro, t);//chama da função de divisão da key
        bro->chaves.resize(2*t,NULL);
        int tam = no->pai->m;

        bro->pai = no->pai;

        for (int i = 0; no->pai->chaves[i]!=NULL ; i++)
        {

            Comparacoes++;
            if (Compara(k->name, no->pai->chaves[i]->name) < 0)
            {
                no->pai->chaves.insert(no->pai->chaves.begin() + i, k);
                no->pai->folhas[i]= bro;
                no->pai->chaves.resize(2*t,NULL);
                break;
            }
        }
        Comparacoes++;
        if(no->pai->chaves[tam] && Compara(k->name, no->pai->chaves[tam]->name) > 0)
        {
            no->pai->chaves.insert(no->pai->chaves.end(), k);
            no->pai->folhas[no->pai->folhas.size()]= bro;

            no->pai->chaves.erase(no->pai->chaves.end());
        }
        if (no->pai->chaves.size() == 2 * t)
        {
            trocas++;
            cisao(no->pai);
        }
    }
}

key *divide(Node *um, Node *dois, int t)
{
    key *k;
    k = um->chaves[t];
    int aqui;

    for (int i = t+1; i < 2 * t; i++)
    {
        dois->chaves.push_back(um->chaves[i]);
        aqui=i+1;
    }
    dois->folhas.push_back(um->folhas[aqui]);
    if(!um->folha)
    {

        for (int i = t+1; i < 2 * t; i++)
        {
            dois->folhas.push_back(um->folhas[2*t]);
        }
        for (int i = 0; i <=t; i++)
        {

            um->folhas.pop_back();
        }

        um->folhas.resize(2*t+1,NULL);
    }

    for (int i = 0; i <t; i++)
    {
        um->chaves[i+t]=NULL;
    }
    um->m=t;
    dois->m=t;

    return k;
}

int Compara(string str1, string str2)
{
    int aux;
    if (str1.length() <= str2.length())
        aux = str1.length();
    else
        aux = str2.length();

    int resultado = strncmp(str1.c_str(), str2.c_str(), aux);
    if (resultado > 0)
        return 1;
    else if (resultado == 0)
        return 0;
    else
        return -1;
}

/*
void ArvoreB::imprime()
{

}
*/
