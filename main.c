#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "liste.c"


int main()
{
    struct liste l1;
    creer_liste(&l1);
    remplir(&l1);
    affiche(l1);



return 0;}
