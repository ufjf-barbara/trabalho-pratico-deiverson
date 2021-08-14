#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Artists.h"
#include "ArvoreVp.h"

using namespace std;



int main()
{
    // srand(time(NULL));
    ArvoreVp* vp = new ArvoreVp(9);
    vp->imprime();
    return 0;
}
