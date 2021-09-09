#include <map>
#include <stdio.h>
#include <queue>
#include <vector>
#include <fstream>
#include <time.h>

#ifndef HUFFMAN_H_INCLUDED
#define HUFFMAN_H_INCLUDED

using namespace std;

struct Node
{
    char c;
    unsigned int count;
    Node *esq, *dir;
};

struct ordem
{
    bool operator()(Node *esq, Node *dir)
    {
        // Menos frequente fica no final
        return esq->count > dir->count;
    }
};

class huffman
{

private:
    static void codificar(Node *raiz, string str, map<char, string> &dic);
    static Node *Arvore(priority_queue<Node *, vector<Node *>, ordem> q);
    static priority_queue<Node *, vector<Node *>, ordem> frequencia(string T);
    static string decodificacao(Node *p, string code);
    static unsigned int binario_decimal(string &in);

public:
    static void HuffmanCode(string T);
};

#endif // HUFFMAN_H_INCLUDED