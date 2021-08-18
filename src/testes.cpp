#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Artists.h"
#include "ArvoreVp.h"

using namespace std;

int main()
{
    srand(time(NULL));
    ArvoreVp *vp = new ArvoreVp();
    vp->busca();
    // vp->imprime();
    // cout << "\nBuscar: " << endl;
    // string str="Vincent Poag";
    // // getline(cin, str);
    // cout << "\n"
    //      << str << endl;

    // bool a = vp->busca(str);
    // if (a)
    //     cout << "OK" << endl;


    return 0;
}
