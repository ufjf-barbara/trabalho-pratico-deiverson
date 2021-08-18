#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Artists.h"
#include "ArvoreVp.h"

using namespace std;

int main()
{
    srand(time(NULL));
    ArvoreVp *vp = new ArvoreVp(1000);
    // vp->imprime();
    cout << "\nBuscar: " << endl;
    string str="Vincent Poag";
    // getline(cin, str);
    cout << "\n"
         << str << endl;

    clock_t begin = clock();
    bool a = vp->busca(str);
    clock_t end = clock();
    if (a)
        cout << "OK" << endl;

    cout << " tempo " << (end - begin) / ((float)CLOCKS_PER_SEC) << endl;

    return 0;
}
