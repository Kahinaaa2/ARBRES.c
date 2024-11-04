/*Exercice 2 (Arbre binaire) Remarque : la plupart des fonctions démandées dans cet exercice sont disponibles en pseudo-code
dans le cours.
1. Construction de l’arbre :
(a) Déclarer une structure Arbre permettant de gérer un arbre binaire contenant des entiers.
(b) Redéfinir le type pointeur sur arbre en pArbre.
(c) Créer la fonction creerArbre permettant de creer un un arbre. Cette fonction prend en paramètre l’élément à
insérer dans le nœud de l’arbre, initialise ses fils et retoune son adresse.
(d) Écrire la fonction int estVide(pArbre a) qui retourne 1 si a est un arbre vide, 0 sinon.
(e) Écrire la fonction int estFeuille(pArbre a) qui retourne 1 si l’arbre est une feuille, 0 sinon.
(f) Écrire la fonction int element(pArbre a) qui retourne l’élément stocké dans le nœud de a.
(g) Écrire une fonction exitseFilsGauche(pArbre a) qui retourne 1 si l’arbre a un fils gauche, 0 sinon. Faire une
fonction similaire exitseFilsDroit(pArbre a).
(h) Écrire une fonction ajouterFilsGauche(pArbre a, int e) qui créé à l’arbre un fils gauche qui va contenir e.
Faire de même avec ajouterFilsDroit(pArbre a, int e).
2. Parcours de l’arbre :
(a) Écrire une fonction traiter qui affichera le contenu du nœud de l’arbre passé en paramètre.
(b) Écrire une procédure parcoursPrefixe permettant d’afficher tous les éléments d’un arbre par un parcours en
profondeur préfixe.
(c) Vérifier que l’arbre que vous avez construit est correct en affichant son parcours préfixe.
(d) Écrire une procédure parcoursPostfixe permettant d’afficher tous les éléments d’un arbre par un parcours en
profondeur postfixe. Tester la fonction sur l’arbre.
(e) Déclarer une structure permettant de gérér une FILE contenant des pArbre.
(f) Écrire une procédure parcoursLargeur permettant d’afficher tous les éléments d’un arbre par un parcours en
largeur.
3. Modification de l’arbre
(a) Écrire une fonction parbre modifierRacine(pArbre a, int e) qui modifie l’élément stocké dans a par l’élément
e et retourne a.
(b) Écrire une fonction pArbre supprimerFilsGauche(pArbre) qui supprime le fils gauche d’un arbre. Idem avec
supprimerFilsDroit(pArbre). Attention aux fuites mémoire !(voir cours).
(c) Supprimer les nœud 9, 15 et 3 de l’arbre. Quel devrait être son parcours en largeur ? Vérifier.
4. Annalyse de l’arbre
5. Écrire une fonction nmbFeuille qui retourne le nombre de feuilles d’un arbre.
6. Écrire une fonction tailleArbre qui retourne la taille (nombre de nœuds internes) de l’arbre.
7. pas facile ! Écrire une fonction hauteur qui retourne la hauteur d’un arbre. Elle renvera -1 si l’arbre est vide.
*/

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

int hauteur(pArbre racine){
  if(estVide(racine)){
    return -1;
  }
  if(estFeuille(racine)){
    return 0;
  }
  1+max(hauteur(racine->fg), hauteur(racine->fd));
}

int main() {
    pArbre arbre1 = creerArbre(1);

    // Construction de l'arbre avec plusieurs nœuds
    ajouterFilsGauche(arbre1, 2);
    ajouterFilsDroit(arbre1, 8);
    ajouterFilsGauche(arbre1->fg, 3);
    ajouterFilsDroit(arbre1->fg, 6);
    ajouterFilsGauche(arbre1->fd, 9);
    ajouterFilsDroit(arbre1->fd, 10);
    ajouterFilsGauche(arbre1->fg->fg, 4);
    ajouterFilsDroit(arbre1->fg->fg, 5);

    // Exécution des parcours et affichage des résultats pour test
    printf("Parcours en largeur :\n");
    parcoursLargeur(arbre1);
    return 0;
}
