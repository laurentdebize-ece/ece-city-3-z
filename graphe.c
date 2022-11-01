
#include "graphe.h"



Graphe* CreerGraphe(int ordre)
{

    Graphe* Newgraphe=malloc(sizeof(Graphe));
    Newgraphe->tabSommet = malloc(ordre*sizeof(Sommet));

    for(int i=0; i<ordre; i++){
        Newgraphe->tabSommet[i]=malloc(sizeof(Sommet));
        //Newgraphe->tabSommet[i]->valeur=i;
    }
    for (int i=0; i<38; i++){
        for (int j=0; j<38; j++){
            //fscanf(ifs, "%d", &Newgraphe->tabSommet[i][j].valeur);
            Newgraphe->tabSommet[i][j].valeur = i*j;
            Newgraphe->tabSommet[i][j].etat = 0;   //il n'y a aucune construction au debut
        }

    }
    return Newgraphe;
}

Graphe * lire_graphe(char * nomFichier)
{
    Graphe* graphe;
    FILE * ifs = fopen(nomFichier,"r+");   //r+ pour lecture ET ecriture dans un fichier texte déjà crée
    int taille, ordre;
    if (!ifs){
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }

    fscanf(ifs,"%d",&ordre);
    graphe=CreerGraphe(ordre); // pn creer un graphe de 1444 sommets (38*38)
    graphe->ordre=ordre;
    return graphe;
}
