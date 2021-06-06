
/****************************Bi-directional list*****************************/

/*
 * Bidirectional list that mimics the beahviour of CD-ROM audio(TD5)
 *
 *
 * */

typedef struct {
    int code;
    char titre[50];
    char artiste[20];
    int duree;

}piste;

struct noeud{
    struct noeud* prec;
    piste info;
    struct noeud* suiv;
};


struct liste{
    struct noeud* tete;
    struct noeud* queu;
};


void creer_liste(struct liste *l);
unsigned liste_vide(struct liste l);
void initialiser(piste x,struct liste *l);
piste saisie();
void ajouter_ap_dernier(struct liste* l);
void ajouter_av_premier(piste  x,struct liste *l);
void remplir(struct liste *l);
void affiche(struct liste l);
struct noeud* min_piste(struct liste l);
void supp_chanson(struct noeud* pmin,struct liste *l);
void tri(struct liste *l1,struct liste *l2);
