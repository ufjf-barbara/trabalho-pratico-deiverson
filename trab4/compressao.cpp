#include <iostream>
#include <map>
#include <stdio.h>
#include <queue>
#include <vector>
#include <fstream>

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

void codificar(Node *raiz, string str, map<char, string> &dic)
{
    if (raiz == nullptr)
        return;

    // Encontra folha
    if (!raiz->esq && !raiz->dir)
    {
        dic[raiz->c] = str;
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

    q.push(setNode(' ', esq->count + dir->count, esq, dir));

    return Arvore(q);
}

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
    // //----------------------------------------------------------------
    // while (q.size() > 0)
    // {
    //     cout << q.top()->count << "->'" << q.top()->c << "'" << endl;
    //     q.pop();
    // }
    // //----------------------------------------------------------------
    return q;
}

//algoritmo de decodificação
string decodificacao(Node *p, string code)
{
    string str="";//string auxiliar
    Node *l=p;//no auxiliar recebe a raiz
    for (int i = 0; i <= code.length(); i++)//percorre ate 
    {
        if (l->dir == NULL && l->esq == NULL)//ve se e no folha
        {
             str+=l->c;
             l=p;//volta para a raiz
        }
        if(code[i]=='0')//se for 0 vai para o no a esquerda
        {
           l=l->esq;
        }
        else//se for 0 vai para o no a direita
        {
            l=l->dir;
        }
    }
    return str;
}

void HuffmanCode(string T)
{
    Node *raiz = new Node();

    //retorna a fila dos caracteres ordenados do mais frequente pro menos no final da fila
    //e cria a arvore de huffman
    raiz = Arvore(frequencia(T));

    map<char, string> dic;

    //chamando codificacao
    codificar(raiz, "", dic);

    // //----------------------------------------------------------------
    // for (auto pair : dic)
    // {
    //     cout << pair.first << " " << pair.second << endl;
    // }
    // //----------------------------------------------------------------

    string code;
    for (char c : T)
    {
        code += dic[c];
    }
    cout << "Frase normal:\t" << T
         << "\nCODIFICADA:\t" << code << endl
         << (float)sizeof(code) / sizeof(T) << endl //tentativa de medir a compressao
         << "DECODIFICADA:\t"<<decodificacao(raiz, code)<<endl;//decodificação 
    
}

int main(int argc, char **argv)
{
    //Testes
    // map<char, unsigned int> uai;
    // char c = 'c';
    // uai['d']++;
    // uai[' '] = 123456789;
    // uai[' ']++;
    // uai['r'] = 100;
    // uai['a'] = 100;
    // uai['w'] = 100;

    // // priority_queue<Node *, vector<Node *>, greater<Node>> q;

    // for (auto pair : uai)
    // {
    //     // q.push(pair);
    //     // std::cout << pair.first << " " << pair.second <<endl;
    // }

    string x = "1";
    ifstream padrao("padrao" + x + ".txt");

    string P, aux;

    while (getline(padrao, aux))
    {
        P += aux;
    }

    HuffmanCode("ABACDAMDMSJFAJSFKASFKAFSFA");

    std::cout << "\n";
    return 0;
}