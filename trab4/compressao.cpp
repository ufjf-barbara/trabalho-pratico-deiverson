#include <iostream>
#include <map>
#include <unordered_map>
#include <stdio.h>
#include <string_view>
#include <queue>

using namespace std;

struct Node
{
    char c;
    unsigned int count;
    Node *esq, *dir;
};

int main(int argc, char **argv)
{
    map<char, unsigned int> uai;
    char c = 'c';
    uai['d']++;
    uai[' '] = 123456789;
    uai[' ']++;
    uai['r'] = 100;
    uai['a'] = 100;
    uai['w'] = 100;

    priority_queue<Node*,vector<Node*>,greater<Node>> q;

    for (auto pair : uai) {
        q.push(pair);
        std::cout << pair.first << " " << pair.second <<endl;
    }

    std::cout << "\n";
    cout << uai[' '] << endl;
}