
#ifndef ECE_CITY_3_Z_GRAPHE_H
#define ECE_CITY_3_Z_GRAPHE_H
//Le .h ou on mettra toutes les fonctions en lien avec le graphe et le déroulement du jeu
enum construction{terrainVague, cabane, maison, immeuble, gratteCiel};
//                   0             1       2      3          4


typedef struct {
    int niveau; // 0 = sur terre   -1 = canalisation       -2 = réseau d'electricité
    int carence;  // 0 si le batiment est bien alimenté en eau/electricité      1 si il y a une carrence d'eau ou d'electricté
}Niveau;


typedef struct {
    int etat; //etat des construction -> on utilisera l'enum "construction" pour que ce soit plus facile
    Niveau mapAffiche;   // par exemple si on a case[0][5].mapAfficher.niveau == 1  ->  on affichera la canalisation

}Case;  //chaque case correspond a un sommet de notre graphe





#endif //ECE_CITY_3_Z_GRAPHE_H
