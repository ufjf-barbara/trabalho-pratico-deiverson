#include <iostream>
#include <map>
#include <stdio.h>
#include <queue>
#include <vector>
#include <fstream>
#include <time.h>

using namespace std;

struct Node
{
    char c;
    unsigned int count;
    Node *esq, *dir;
};

Node *setNode(char c, int freq, Node *esq, Node *dir)
{
    Node *no = new Node();
    no->c = c;
    no->count = freq;
    no->esq = esq;
    no->dir = dir;
    return no;
}

struct ordem
{
    bool operator()(Node *esq, Node *dir)
    {
        // Menos frequente fica no final
        return esq->count > dir->count;
    }
};

//Codifica i texto pra string de bits
void codificar(Node *raiz, string str, map<char, string> &dic)
{
    if (raiz == nullptr)
        return;

    // Encontra folha
    if (!raiz->esq && !raiz->dir)
    {
        dic[raiz->c] = str; //atribui o camimha ao caractere
    }

    codificar(raiz->esq, str + "0", dic);
    codificar(raiz->dir, str + "1", dic);
}

//criacao recursiva da arvore de huffman
Node *Arvore(priority_queue<Node *, vector<Node *>, ordem> q)
{
    //caso base
    if (q.size() == 1)
    {
        Node *no = new Node();
        no = q.top();
        q.pop();
        return no;
    }

    Node *esq = q.top();
    q.pop();
    Node *dir = q.top();
    q.pop();

    q.push(setNode(' ', esq->count + dir->count, esq, dir)); //cria um novo e no com esq e dir

    return Arvore(q);
}

//função pra computar a frequencia
priority_queue<Node *, vector<Node *>, ordem> frequencia(string T)
{
    //map para contar frequencia
    map<char, unsigned int> freq;

    for (char ch : T)
    {
        //se o caractere ainda nao estiver no map e o adiciona
        if (!freq[ch])
            freq[ch] = 1;
        else
            freq[ch]++; //incremento do contador
    }

    //fila de prioridade para ordenaçao dos caracteres de acordo com a frenquencia
    priority_queue<Node *, vector<Node *>, ordem> q;

    for (auto pair : freq)
    {
        q.push(setNode(pair.first, pair.second, NULL, NULL));
    }

    return q;
}

//algoritmo de decodificação
string decodificacao(Node *p, string code)
{
    string str = "";                         //string auxiliar
    Node *l = p;                             //no auxiliar recebe a raiz
    for (int i = 0; i <= code.length(); i++) //percorre ate
    {
        if (l->dir == NULL && l->esq == NULL) //ve se e no folha
        {
            str += l->c;
            l = p; //volta para a raiz
        }
        if (code[i] == '0') //se for 0 vai para o no a esquerda
        {
            l = l->esq;
        }
        else //se for 0 vai para o no a direita
        {
            l = l->dir;
        }
    }
    return str;
}

unsigned int binario_decimal(string &in)
{
    int result = 0;
    for (int i = 0; i < in.size(); i++)
        result = result * 2 + in[i] - '0';
    return result;
}

void HuffmanCode(string T)
{

    Node *raiz = new Node();

    map<char, string> dic;

    //chamando codificacao

    clock_t begin = clock();

    //retorna a fila dos caracteres ordenados do mais frequente pro menos no final da fila
    //e cria a arvore de huffman
    raiz = Arvore(frequencia(T));

    codificar(raiz, "", dic);
    clock_t end = clock();

    cout << "-----------------------------------------------------" << endl;
    cout << "DNA com " << T.length() << " padroes" << endl;
    cout << "Custo computational da compressao de "
         << (end - begin) / ((float)CLOCKS_PER_SEC)
         << " segundos" << endl;

    string code;
    for (char c : T) //criando a string codificada
    {
        code += dic[c];
    }

    int code_len = code.length();
    int compri = code_len / 8; //recebe numero de inteiros em de code

    if (code_len % 8 > 0) //verifica resto
    {
        compri++;
    }

    float compri_gain = (float)(T.length() - compri) / T.length();
    printf("Taxa de %.2f %% de compressao\n", compri_gain * 100);

    begin = clock();
    decodificacao(raiz, code);
    end = clock();
    cout << "Custo computational da decompressao de "
         << (end - begin) / ((float)CLOCKS_PER_SEC)
         << " segundos" << endl;
    cout << "-----------------------------------------------------" << endl;
}