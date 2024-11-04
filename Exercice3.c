/*Exercice 3 (Arbre binaire filiforme)
Un arbre binaire est dit filiforme si chaque nœud a au plus un seul fils (qu’il soit gauche ou droit).
— A quoi va ressembler un tel arbre ?
— Écrire une fonction permettant de determiner si un arbre est filiforme (plusieurs méthodes sont possibles !).
— Un arbre est dit peigne gauche si les nœuds n’ont qu’un fils gauche et pas de fils droit.
— Écrire une fonction permettant de determiner si un arbre est peigne gauche.
— Écrire une fonction parbre constrPeigneGauche(int h) qui va créer un arbre peigne gauche de hauteur h en le
remplissant avec des valeurs aléatoires entre 0 et 10. L’afficher.*/




#include<stdio.h>
#include<stdlib.h>

typedef struct arbre {
  int valeur;
  struct arbre *fg;
  struct arbre *fd;
}Arbre;

typedef arbres *Parbre; //avec ca on peut ne pas mettre dans la fonction creeArbre le pointeur Parbre *creeAbre
//en gros c'est soit Arbre *creeArbre soit Parbre creeArbre

//on cree la fonction pour cree un noeud d'arbre avec une valeur

Parbre creeArbre(int a){
  Parbre new = malloc(sizeof(Arbre));
  if(new == NULL){
    exit(1);
  }
  new->fd =NULL;
  new->fg=NULL;
  new->valeur=a;
  return new;
}

//on cree la fonction qui verifie si l'arbre est vide

int estVide(Parbre arbre){
  if(arbre == NULL){
    return 1;
  }
  else{
    return 0;
  }
}

//on cree la fonction qui verifie si l'arbre est une feuille(sans fils)

int estFeuille(Parbre arbre){
  if(estVide(arbre)){
    exit(3);
  }
  if(arbre->fg ==NULL && arbre->fd ==NULL){
    return 1;
  }
  else{
    return 0;
  }
}

//on cree la fonction qui recupere la valeur du noeud avec verification d'existance

int element(Parbre arbre){
  if(estVide(arbre)){
    exit(7);
  }
  else{
    return arbre(->valeur;
  }
}

//on cree la fonction qui verifie si un noeud a un fils gauche

int ExistefilsGauche(Parbre arbre){
  if(estVide(arbre)){
    exit(13);
  }
  if(arbre->fg != NULL){
    return 1;
  }
  else{
    return 0;
  }
}

int Existefilsdroit(Parbre arbre){
  if(estVide(arbre)){
    exit(18);
  }
  if(arbre->fd != NULL){
    return 1;
  }
  else{
    return 0;
  }
}

//on cree la fonction qui ajoute un fils gauche a un noeud spécifié

int ajouterFilsGauche(Parbre arbre, int a){
  if(estVide(arbre)){
    exit(19);
  }
  if(arbre->fg == NULL){
  arbre->fg =creeArbre(a);
  return 1;
  }
  else{
    return 0;
  }
}

int ajouterFilsDroit(Parbre arbre, int a){
  if(estVide(arbre)){
    exit(20);
  }
  if(arbre->fd==NULL){
    arbre->fd =creeArbre(a);
    return 1;
  }
  else{
    return 0;
  }
}

//partie 1 : parcourir l'arbre

//on cree la fonction qui affiche un noeud

void afficherNoeud(Parbre arbre){
  if(estVide(arbre)){
    printf("l'arbre est vide");
  }
  else{
    printf("%d\n", arbre->valeur);
  }
}

//on implemente le parcour prefixe (noeud, gauche, droite)

void parcoursPrefixe(Parbre arbre){
  afficherNoeud(arbre); //afficher la valeur du noeud actuel
  if(!estVide(arbre)){
    if(ExisteFilsGauche(arbre)){
      parcoursPrefixe(arbre->fg); //parcours du fils gauche
    }
    if(ExisteFilsDroit(arbre)){
      parcoursPrefixe(arbre->fd); //parcours du fils droit
    }
  }
}

//on implemente le parcours postfixe(gauche droite noeud)
void parcoursPostfixe(Parbre arbre){//parcours profondeur
  if(!estVide(arbre)){
    if(ExisteFilsGauche(arbre)){
      parcoursPostfixe(arbre->fg); //parcours du fils gauche
    }
    if(ExisteFilsDroit(arbre)){
      parcoursPostfixe(arbre->fd); //parcours du fils droit
    }
  }
  afficherNoeud(arbre); //afficher la valeur du noeud actuel
}

typedef struct chainon{
  Parbre valeur;
  struct chainon *suivant
}Chainon;

typedef struct file{
  Chainon *tete;
  Chainon *fin;
}File;

Chainon* create Chainon(Parbre a){
  Chainon *nouveau = malloc(sizeof(Chainon));
  if(nouveau == NULL){
    exit(22);
  }
  nouveau->valeur = a;
  nouveau->suivant = NULL;
  return nouveau;
}

File *creationFile(){
  File *new =malloc(sizeof(File));
  if(new == NULL){
    exit(25);
  }
  new->tete=NULL;
  new->fin=NULL;
  return new;
}

void enfiler(File *file, Parbre a){
  if(file == NULL){
    exit(29);
  }
  if(file->fin == NULL){
    file->fin = createChainon(a);
    file->tete =file->fin;
  }else{
    file->fin->suivant = createChainon(a);
    file->fin =file->fin->suivant;
  }
}

int defiler(File *file, Parbre *val){
  if(file==NULL || file->tete == NULL){
    return -1;
  }
  Chainon *tmp = file->tete->suivant;
  *val = file->tete->valeur;
  free(file->tete);
  file->tete =tmp;
  if(file->tete ==NULL){
    file->fin = NULL;
  }
  return 0;
}

//on implemente le parcours en largeur de l'arbre

void parcourLargeur(Parbre a){
  File *file =createFile(); //creation de la file
  Parbre valeur;
  enfiler(file,a); //enfiler la racine
  while(file->tete!=NULL){
    defiler(file,&valeur); //defiler la racine
    afficherNoeud(valeur); //afficher la valeur du noeud actuel
    if(estVide(valeur)){
      if(ExisteFilsGauche(valeur)){
        enfiler(file, valeur->fg);
      }
      if(ExisteFilsDroit(valeur)){
        enfiler(file, valeur->fd);
      }
    }
  }
}
//Le parcours en largeur utilise une file pour stocker temporairement les nœuds à visiter.
//modification de l'arbre Partie 3

//on cree une fonction qui modifie la valeur de la racine de l'arbre

pArbre modifierRacine(pArbre racine, int val){
  if(estVide(racine)){
    exit(34);
  }
  racine->valeur = val;
  return racine;
}

//on cree une fonction de suppression des sous  arbre gauche et droit

void SupprimerFilsGauche(pArbre racine){
  if(!estVide(racine) && existeFilsGauche(racine)){
    SupprimerFilsGauche(racine->fg);
    SupprimerFilsDroit(racine->fg);
    free(racine->fg);
    racine->fg = NULL; //on supprime le fils gauche
  }
}

void SupprimerFilsDroit(pArbre racine){
  if(!estVide(racine) && existeFilsDroit(racine)){
    SupprimerFilsGauche(racine->fd);
    SupprimerFilsDroit(racine->fd);
    free(racine->fd);
    racine->fd = NULL;
  }
}

//on cree une fonction recursive qui compte le nombre de feuilles

int nmbFeuille(pArbre racine){
  if(estVide(racine)){
    return 0;
  }
  if(estFeuille(racine)){
    return 1;
  }
  return nmbFeuille(racine->fg) + nmbFeuille(racine->fd);
}

//on calcule la taille de l'arbre ( nombre total de noeuds

int tailleArbre(pArbre racine){
  if(estVide(racine)){
    return 0;
  }
  return 1+tailleArbre(racine->fg)+tailleArbre(racine->fd);
}

//on calcule la hauteur de l'arbre
int max(int a, int b){
  //fonction maximum
  if(a>b){
    return a;
  }
  if(b>a){
    return b;
  }
}

int hauteurArbre(pArbre racine){
  if(estVide(racine)){
    return -1;
  }
  if(estFeuille(racine)){
    return 0;
  }
  1+max(hauteurArbre(racine->fg),hauteurArbre(racine->fd));
}
//on cree une fonction qui affiche l'arbre en largeur
void afficherArbre(pArbre racine){
  if(estVide(racine)){
    printf("l'arbre est vide");
  }
  else{
    printf("%d\n", racine->valeur);
    if(ExisteFilsGauche(racine)){
      afficherArbre(racine->fg);
    }
    if(ExisteFilsDroit(racine)){
      afficherArbre(racine->fd);
    }
    
  }
  printf("\n");
}

int filiforme(pArbre racine){
  if(estVide(racine) || estFeuille(racine)){
    return 1;
  }// un arbre vide ou un arbre feuille est filiforme
  if(ExisteFilsGauche(racine) && ExisteFilsDroit(racine)){
    return 0;// pa filiforme
  }
  return filiforme(racine->fg) && filiforme(racine->fd);
}
//methode recurssive


int filiforme2(pArbre racine) { // Autre méthode (itérative)
    pArbre tmp = racine;
    while (!estVide(tmp) && !estFeuille(tmp)) { // Parcourt jusqu'à atteindre une feuille
        if (existeFilsDroit(tmp) && existeFilsGauche(tmp)) { // Si un nœud a deux fils, il n'est pas filiforme
            return 0;
        } else if (existeFilsDroit(tmp)) { // Avance dans le fils droit
            tmp = tmp->fd;
        } else if (existeFilsGauche(tmp)) { // Avance dans le fils gauche
            tmp = tmp->fg;
        }
    }
    return 1; // Tous les nœuds n'avaient qu'un seul fils ou moins
}

//methode itérative

int peigne_gauche(pArbre racine) {
    if (estVide(racine) || estFeuille(racine)) { // Un arbre vide ou une feuille est un peigne gauche
        return 1;
    }
    if (existeFilsDroit(a)) { // Si un nœud a un fils droit, il n'est pas un peigne gauche
        return 0;
    }
    return peigne_gauche(a->fg); // Appel récursif sur le fils gauche, peut etre fait aussi de manière itérative
}

pArbre constrPeigneGauche(int h) {
    pArbre racine = creerArbre(rand() % 11); // Crée la racine avec une valeur aléatoire
    pArbre tmp = racine;
    while (h > 1) { // Ajoute des fils gauches jusqu'à atteindre la hauteur
        ajouterFilsGauche(tmp, rand() % 11); // Valeur aléatoire pour chaque nouveau nœud
        tmp = tmp->fg;
        h--;
    }
    return racine;
}

int main() {
    srand(time(NULL)); // Initialise le générateur de nombres aléatoires

    // Création d'un arbre pour tester les fonctions
    pArbre arbre1 = creerArbre(1);
    ajouterFilsGauche(arbre1, 2);
    ajouterFilsDroit(arbre1, 8);
    ajouterFilsGauche(arbre1->fg, 3);
    ajouterFilsDroit(arbre1->fg, 6);
    ajouterFilsGauche(arbre1->fd, 9);
    ajouterFilsDroit(arbre1->fd, 10);
    ajouterFilsGauche(arbre1->fg->fg, 4);
    ajouterFilsDroit(arbre1->fg->fg, 5);
    ajouterFilsDroit(arbre1->fg->fd, 7);

    // Test des fonctions sur arbre1
    printf("Arbre 1 est filiforme (méthode récursive) : %d\n", filiforme1(arbre1));
    printf("Arbre 1 est filiforme (méthode itérative) : %d\n", filiforme2(arbre1));
    printf("Arbre 1 est peigne gauche : %d\n", peigne_gauche(arbre1));

    // Création d'un second arbre pour tester
    pArbre arbre2 = creerArbre(1);
    ajouterFilsGauche(arbre2, 3);
    ajouterFilsDroit(arbre2->fg, 6);
    ajouterFilsDroit(arbre2->fg->fd, 6);
    ajouterFilsGauche(arbre2->fg->fd->fd, 3);

    // Test des fonctions sur arbre2
    printf("Arbre 2 est filiforme (méthode récursive) : %d\n", filiforme1(arbre2));
    printf("Arbre 2 est filiforme (méthode itérative) : %d\n", filiforme2(arbre2));
    printf("Arbre 2 est peigne gauche : %d\n", peigne_gauche(arbre2));

    // Création d'un peigne gauche de hauteur 5
    pArbre arbre3 = constrPeigneGauche(5);
    printf("Parcours préfixe de l'arbre 3 (peigne gauche) :\n");
    parcoursPrefixe(arbre3);

    // Test des fonctions sur arbre3
    printf("Arbre 3 est filiforme (méthode récursive) : %d\n", filiforme1(arbre3));
    printf("Arbre 3 est filiforme (méthode itérative) : %d\n", filiforme2(arbre3));
    printf("Arbre 3 est peigne gauche : %d\n", peigne_gauche(arbre3));

    return 0;
}
