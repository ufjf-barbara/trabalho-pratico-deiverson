#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Artists.h"
#include "ArvoreVp.h"

using namespace std;



int main()
{
    ArvoreVp* vp = new ArvoreVp(10);
    vp->imprime();
    return 0;
}
