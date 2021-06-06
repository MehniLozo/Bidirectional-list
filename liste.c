#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "liste.h"

void creer_liste(struct liste *l)
{
    l->tete = NULL;
    l->queu = NULL;
}
unsigned liste_vide(struct liste l)
{
    return l.tete == NULL && l.queu == NULL;
}
void initialiser(piste x,struct liste *l)
{
    struct noeud *q = (struct noeud*)malloc(sizeof(struct noeud));
    q->info = x;
    q->suiv = NULL;
    q->prec = NULL;

    l->tete = l->queu = q;
}
piste saisie()
{
    piste x;
    printf("\nDonner le code \t");
    scanf("%d",&(x.code));
    printf("\nDonner le titre \t");
    scanf("%s",x.titre);
    printf("\nDonner l'artiste \t");
    scanf("%s",x.artiste);

    printf("\nDonner la duree \t");
    scanf("%d",&(x.duree));
    
    return x;

}
void ajouter_ap_dernier(struct liste* l){

    struct noeud *q = (struct noeud*)malloc(sizeof(struct noeud)); 
    q->info = saisie();
    q->suiv = NULL;
    q->prec = l->queu;
    

    if(l->tete == NULL)
        l->tete = q;
    else //liste pas vide
        l->queu->suiv = q;
    l->queu = q;

}
void ajouter_av_premier(struct noeud* p,struct liste *l)
{
   /*We will already have the node filled and ready to go*/ 
    
    printf("\nreached up here4\n");
    p->prec= NULL;
    if(liste_vide(*l))
    { //comme initialiser
        p->suiv = NULL;
        l->queu = p;

    }
     else
    {
        p->suiv = l->tete;
        l->tete->prec = p;
    }
    l->tete = p;
      
}
void remplir(struct liste *l)
{
    int res;
    do{
        ajouter_ap_dernier(l);
        do{
                printf("\nVoulez vous ajouter une autre piste(1:OUI,0:NON)\t");
                scanf("%d",&res);
        }while(!(res == 1 || res == 0));
    
    }while(res);

}
void affiche(struct liste l)
{
    struct noeud*p = l.tete;

    printf("\ncode\ttitre\tartiste\tduree\n");
    while(p)
    {
       printf("\n%d\t%s\t%s\t%d\n",p->info.code,p->info.titre,p->info.artiste,p->info.duree); 
        p = p->suiv;
    }

}
struct noeud* min_piste(struct liste l)
{
 /*chercher et retourner @ de la piste ayant une duree minmale de 
  * la liste l1*/

    printf("\nreached up here3\n");
    assert(!liste_vide(l));
    struct noeud * pmin = l.tete,*p= l.tete->suiv;

    while(p)
    {
        if(pmin->info.duree > p->info.duree)
            pmin = p;
        p = p->suiv;
    }

    return pmin;


}
void supp_chanson(struct noeud* pmin,struct liste *l)
{

    assert(!liste_vide(*l));
    /*4 cas pmin peut etre:
     *  -tete
     *  -queu
     *  -middle
     *  -
     * */

    if(pmin == l->tete && pmin == l->queu)
         l->tete=l->queu = NULL;
    
    else if(pmin == l->tete)
    {
        l->tete = l->tete->suiv;
        l->tete->prec = NULL;    
    }else if (pmin == l->queu)
    {
        l->queu = l->queu->prec;
        l->queu->suiv = NULL;
    }else{
        pmin->suiv->prec = pmin->prec;
        pmin->prec->suiv = pmin->suiv;
    }

    free(pmin);
}
void tri(struct liste *l1,struct liste *l2)
{
    /*TRI permet de trie la liste l1 dans une nouvelle liste l2
     * une liste triee par ordre decroissant selon la duree
     *principe:
        inserer la piste cherché entete dans la liste l2
     * */
    struct noeud* pmin;
    printf("\nreached up here\n");
    while(!liste_vide(*l1))
    {
    printf("\nreached up her2\n");
       pmin = min_piste(*l1); 
       ajouter_av_premier(pmin,l2);
       supp_chanson(pmin,l1);
       
    }

    printf("\nla liste est trié avec success\n");
}
