#ifndef ECE_CITY_3_Z_GRAPHE_H
#define ECE_CITY_3_Z_GRAPHE_H


/////////////Bibiliotheques/////////////////

#include <stdio.h>
#include <stdlib.h>

///////////////Les macros///////////////////



////////////// Les enums utilisés////////////

//Le .h ou on mettra toutes les fonctions en lien avec le graphe et le déroulement du jeu
enum construction{terrainVague, cabane, maison, immeuble, gratteCiel};
//                   0             1       2      3          4


////////////////Les structures du graphe///////

typedef struct {
    int niveau; // 0 = sur terre   -1 = canalisation       -2 = réseau d'electricité
    int carence;  // 0 si le batiment est bien alimenté en eau/electricité   //   1 si il y a une carrence d'eau ou d'electricté
}Niveau;

//informations relatives aux sommets (chauque case du graphe)
typedef struct {
    int EnCoursDeConstruction;  //1 si nla construction a debuté mais que les 15 sec ne sont pas encore terminé  // 2 si les 15 sec on ecoulé et que c'est construit
    int etat; //etat des constructions -> on utilisera l'enum "construction" pour que ce soit plus facile
    int valeur; //valeur de la case : ex tabSommet[21][12]
}Sommet;


typedef struct {
    Niveau mapAffiche;   // par exemple si on a case[0][5].mapAfficher.niveau == 1  ->  on affichera la canalisation
    int taille;
    int ordre;
    int orientation;
    Sommet** tabSommet;  //matrice du graphe (tab de 38x38 cases)
}Graphe;  //chaque case correspond a un sommet de notre graphe





////////////Fonction pour la creation et la lecturedu graphe////////////////

Graphe* CreerGraphe(int ordre);
Graphe * lire_graphe(char * nomFichier);



#endif //ECE_CITY_3_Z_GRAPHE_H
