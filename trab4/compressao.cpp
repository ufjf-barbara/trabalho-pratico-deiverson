#include <iostream>
#include <map>
#include <stdio.h>
#include <queue>
#include <vector>
#include <fstream>
#include <sstream>

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

int binary_to_decimal(string &in)
{
    int result = 0;
    for (int i = 0; i < in.size(); i++)
        result = result * 2 + in[i] - '0';
    return result;
}

string Compressao(string &code)
{
    stringstream ss;
    string str, aux;
    int bit;

    for (int i = 0; i < code.length(); i++)
    {
        str += code[i];

        if ((i + 1) % 8 == 0 || ((code.length() - i) < 8 && i + 1 == code.length()))
        {
            // ss<<str;ss>>bit;
            ss << binary_to_decimal(str);
            // cout << " " << ss.str() << endl;
            cout << "codificacao: \t" << str << endl;
            cout << "compressao: \t" << binary_to_decimal(str) << endl;
            str = "";
        }
    }
    return ss.str();
}

string decimal_to_binary(string str)
{
    stringstream ss;
    string temp = "";
    string result = "";
    int in;
    ss << str;
    ss >> in;
    // cout << "in :" << in << endl;
    while (in > 0)
    {
        temp += ('0' + in % 2);
        in /= 2;
    }
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        result += temp[i];
    }
    cout << "here \t" << result << endl;
    return result;
}

string Decompressao(string &code)
{
    string aux = "";
    string str;
    string decode = "";
    int i = 0;
    while (i < code.length())
    {
        str += code[i];
        i++;
        aux = decimal_to_binary(str);
        if (aux.length() == 8 || i + 1 == code.length())
        {
            decode += aux;
            cout << "decode:" << decode << endl;
            str = "";
        }
    }
    return decode;
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
    string result = Compressao(code);
    cout << "\nresult :" << result << endl
         << endl;
    //  cout // << "Frase normal:\t" << T
    //     // << "\nCODIFICADA:\t" << result << endl
    //     << "\nT\t" << T.length() << endl
    //     << "\nR\t" << result.length() << endl
    //     << (float)(T.length() - result.length()) / T.length() << endl; //tentativa de medir a compressao

    //  << "DECODIFICADA:\t" << decodificacao(raiz, code) << endl; //decodificação
    string aux = Decompressao(result);
    cout << "\n\naux\t" << aux << endl;
    cout << "code\t" << code << endl;
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

    HuffmanCode("ABACATEABAFABAFO");

    cout << "\n";
    return 0;
}
