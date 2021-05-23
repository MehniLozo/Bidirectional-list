#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "liste.h"
void creer_liste(struct liste *l){
    l->tete = NULL;
    l->queue = NULL;

}

piste saisie(){
    
   piste x; 
   printf("\nDonner le code\t");
   scanf("%d",&x.code);

   printf("\nDonner le titre\t");
   scanf("%s",x.titre);
  printf("\nDonner le artiste\t");
   scanf("%s",x.artiste);
   printf("\nDonner la duree\t");
   scanf("%d",&x.duree);
    
   return x;


}
void ajout_apres_dernier(struct liste *l)
{


    struct noeud* p = (struct noeud*)malloc(sizeof(struct noeud));
         p->info=saisie();
         p->suivant = NULL;
         p->avant = l->queue;
        if(l->tete == NULL && l->queue == NULL)
        
            l->tete = p;
           
        else
        
            l->queue->suivant = p;
        
        l->queue = p;
}
void remplir(struct liste *l)
{int rep;
    do{
        ajout_apres_dernier(l);
        do{
            printf("Voulez vous ajouter une autre piste (1:OUI,0:NON)\t");
            scanf("%d",&rep);
        }while(!(rep == 1 || rep == 0));
    }while(rep);
}
void affiche(struct liste l){
    struct noeud* p = l.tete; // p = l.queue for inverse  display

        printf("\ncode\ttitre\tartiste\tduree\n");
    while(p)
    {
        printf("%d\t%s\t%s\t%d\n",p->info.code,p->info.titre,p->info.artiste,p->info.duree);
    
        p = p->suivant;//p = p->avant; for inverse display
    }


}
