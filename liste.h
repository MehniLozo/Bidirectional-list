
/*Bidirectional list definition*/
typedef struct {
    int code;
    char titre[10];
    char artiste[10];
    int duree;
}piste;

struct noeud{
    struct noeud* avant;
    piste info;
    struct noeud* suivant;
};
struct liste{
    struct noeud* tete;
    struct noeud* queue;

};

void creer_liste(struct liste *);
piste saisie();
void ajout_apres_dernier(struct liste *);
void remplir(struct liste *);
void affiche(struct liste);
