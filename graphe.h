#ifndef ECE_CITY_3_Z_GRAPHE_H
#define ECE_CITY_3_Z_GRAPHE_H


/////////////////////Bibiliotheques////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

///////////////////////////Les macros/////////////////////////////

#define QUADRICOLONNE 45
#define QUADRILIGNE 35

////////////////////// Les enums utilisés///////////////////

//Le .h ou on mettra toutes les fonctions en lien avec le graphe et le déroulement du jeu
enum construction{terrainVague, cabane, maison, immeuble, gratteCiel};
//                   0             1       2      3          4




////////////Fonction pour la creation et la lecturedu graphe////////////////

//Graphe* CreerGraphe(int ordre);
//Graphe * lire_graphe(char * nomFichier);

CASE **CreerArete(CASE **sommet, int s1X, int s1Y, int s2X, int s2Y, int valeurs);
void CalculeConnexe(CASE **tabSommet, int i, int j, int *nbConnexe);
void iniTabHab(CASE **tabCase, int i, int j, ECECITY *JEU);
void iniTabE(CASE **tabCase, int i, int j, ECECITY *JEU);
void iniTabO(CASE **tabCase, int i, int j, ECECITY *JEU);
void CalculeCompteurEtTab(CASE **tabCase, int i, int j, ECECITY *JEU);
Graphe *CreerGraphe(FILE *ifs, FILE *ifsID, ECECITY *JEU);
Graphe *lire_graphe(char *nomFichier, char *nomFichierid, ECECITY *JEU);
ECECITY *iniJeu();
void afficher_successeurs(CASE **sommet, int i, int j);
void graphe_afficher(Graphe *graphe);
int defilement(File F);
File CreerFile();
void enfiler(File F, int sommet);
void ecrireFile(File F);
int checkBlanc(Graphe *G, int num);
void BFS(Graphe *G, int SommetX, int SommetY, int *compte);
void afficheBFS(int tab[], int compte, int *c);
void CalculDistance(Graphe *G, int SommetX, int SommetY, int con);
void triDistance(int *ordre, ECECITY *JEU, int nbHabitationCon);
void repartitionO(ECECITY *JEU, int* ordre, int nbHabitationCon, int id);
void ECEBFS(int con, int id, ECECITY *JEU, int nbHabitationCon);
bool checkApproO(int i, ECECITY *JEU);
void CalculeO(ECECITY *JEU);
void CalculeElec(ECECITY *JEU);
int minimain();


#endif //ECE_CITY_3_Z_GRAPHE_H
