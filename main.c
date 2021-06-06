#include <stdlib.h>
#include <stdio.h>
#include "liste.c"


int main()
{
    struct liste l1,l2;
    creer_liste(&l1);creer_liste(&l2);
    remplir(&l1);
    printf("\n******************L1*************\n");
    affiche(l1);
    struct noeud* pmin = min_piste(l1);
    printf("\nmin l1 = %s avec %d minute\n",pmin->info.titre,pmin->info.duree);
    /*ajouter_av_premier(pmin,&l1); //having a prob here
    affiche(l1);
   */
    /*tri(&l1,&l2);

    printf("\n******************L2*************\n");

    affiche(l2);
*/






return 0;}
