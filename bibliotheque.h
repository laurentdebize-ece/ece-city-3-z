//
// Created by Théophile Dutrey on 01/11/2022.
//
#define LARGEUR 1600
#define HAUTEUR 800
#define LARGEUR_GRILLE 45*20
#define HAUTEUR_GRILLE 35*20
#define COLONNES 45
#define LIGNES 35
#define TUILE 20
#define TEMPS_CYCLE 5
#define LARGEUR_TUILE_ISO 34
#define HAUTEUR_TUILE_ISO 18
#define ISO_DECALAGE_X 2
#define ISO_DECALAGE_Y 20
#define COUT_CENTRAL 100000
#define COUT_CHATEAU_DEAU 100000
#define COUT_ROUTE 50
#define COUT_TERRAIN_VAGUE 1000
#define COUT_CASERNE 10000


#define TAXE 50
#define NBRHABITANT_CABANE 10
#define NBRHABITANT_MAISON 50
#define NBRHABITANT_IMMEUBLE 100
#define NBRHABITANT_GRATTECIEL 1000
#define LONGUEURE_TERRAIN_VAGUE 3
#define LARGEUR_TERRAIN_VAGUE 3
#define LONGUEURE_BATTIMENT 6
#define LARGEUR_BATTIMENT 4

#ifndef ECE_CITY_3_Z_BIBLIOTHEQUE_H
#define ECE_CITY_3_Z_BIBLIOTHEQUE_H
#include <stdlib.h>
#include <stdio.h>

typedef struct{

    int nbRues, nbHab, nbChateauO, nbUsines;

}COMPTEUR;

typedef struct{
    struct Arc* arc;
    int EnCoursDeConstruction;  //1 si nla construction a debuté mais que les 15 sec ne sont pas encore terminé  // 2 si les 15 sec on ecoulé et que c'est construit
    int etat; //etat des constructions -> on utilisera l'enum "construction" pour que ce soit plus facile
    int valeur; //valeur de la case : ex tabSommet[21][12]
    float x, y;
    int type;
    int identite;
    int couleur;
    int affichage;
    int connexe;
    int distance;
    int predX;
    int predY;
}CASE;

////////////////Les structures du graphe///////

typedef struct {
    int niveau; // 0 = sur terre   -1 = canalisation       -2 = réseau d'electricité
    int carence;  // 0 si le batiment est bien alimenté en eau/electricité   //   1 si il y a une carrence d'eau ou d'electricté
}Niveau;

//informations relatives aux sommets (chauque case du graphe)

struct _cellule{
    int element;
    struct _cellule *suivant;
};
typedef struct _cellule* Cellule;

struct _file{
    int longueur;
    Cellule tete;
    Cellule queue;
};
typedef struct _file* File;

/* Structure d'un arc*/
struct Arc {
    int sommetX;// numero de sommet d'un arc adjacent au sommet initial
    int sommetY;
    int valeur;
    struct Arc* arc_suivant;
};

/* Alias de pointeur sur un Arc */
typedef struct Arc* pArc;




typedef struct {
    Niveau mapAffiche;   // par exemple si on a case[0][5].mapAfficher.niveau == 1  ->  on affichera la canalisation
    int nbConnexe;
    int orientation;
    CASE** tabCase;  //matrice du graphe (tab de 38x38 cases)
}Graphe;  //chaque case correspond a un sommet de notre graphe


typedef struct{
    int tic;
    int type;
    int connexe;
    int nbHabitant;
    int QE;
    int QO;
    int origineX;
    int origineY;
}Habitations;

typedef struct{
    int connexe;
    int QEmax;
    int QErestant;
}Usines;

typedef struct{
    int connexe;
    int QOmax;
    int QOrestant;
}ChateauO;

typedef struct{
    Graphe *G; //Graphe du jeu
    COMPTEUR compteur;
    Habitations* tabHab; //tableau repertoriant chaque habitation
    Usines* tabE;//tableau repertoriant chaque Usine
    ChateauO* tabO;//tableau repertoriant chaque Chateau d'eau
}ECECITY;


typedef struct{
   int x,y;
}VECTEUR;

#include <raylib.h>
#include "graphe.h"
#include "construction.h"
#include "banque.h"
#include "affichage.h"
#include "isoConfig.h"
#include "barreOutil.h"

#endif //ECE_CITY_3_Z_BIBLIOTHEQUE_H
