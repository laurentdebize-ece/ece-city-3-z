//
// Created by Théophile Dutrey on 03/11/2022.
//

#include "bibliotheque.h"
void route (CASE** tabCase, int x, int y, int* compteur, int detruire){
    if(detruire==0) {
        tabCase[x][y].construction.type = 1;
        (*compteur)++;

        tabCase[x][y].construction.compteur.nbRues = *compteur;
    }
    else{
        (*compteur)--;
        tabCase[x][y].construction.type = 0;
        tabCase[x][y].construction.compteur.nbRues = 0;
    }
}


void habitation(CASE **tabCase, int x, int y, int *compteur, int detruire) {
    if (detruire == 0) {
        if (x + LONGUEURE_TERRAIN_VAGUE <= COLONNES && y + LARGEUR_TERRAIN_VAGUE <= LIGNES &&
            possibiliteDeConstruire(tabCase, x, y, LONGUEURE_TERRAIN_VAGUE, LARGEUR_TERRAIN_VAGUE) == 0) {
            if (presenceRoute(tabCase, x, y, LONGUEURE_TERRAIN_VAGUE, LARGEUR_TERRAIN_VAGUE) != 0) {

                (*compteur)++;
                for (int a = 0; a < LONGUEURE_TERRAIN_VAGUE; a++) {
                    for (int b = 0; b < LARGEUR_TERRAIN_VAGUE; b++) {
                        tabCase[x + a][y + b].construction.type = 5;
                        tabCase[x + a][y + b].construction.compteur.nbHab = *compteur;
                    }
                }
            }
        }
    } else {
        int caseIdentite = tabCase[x][y].construction.compteur.nbHab;
        //(*compteur)--;
        for (int b = 0; b < LIGNES; b++) {
            for (int a = 0; a < COLONNES; a++) {

                if (tabCase[a][b].construction.compteur.nbHab == caseIdentite) {
                    tabCase[a][b].construction.type = 0;
                    tabCase[a][b].construction.compteur.nbHab = 0;
                }
            }
        }
    }
}


void batiment (CASE** tabCase, int x, int y, int* compteur, int typeBatiment, int rotation, int detruire){
    int longueureBatX;
    int longueureBatY;
    if(rotation==0){
        longueureBatX=LONGUEURE_BATTIMENT;
        longueureBatY=LARGEUR_BATTIMENT;
    }
    else{
        longueureBatX=LARGEUR_BATTIMENT;
        longueureBatY=LONGUEURE_BATTIMENT;
    }
    if (detruire == 0) {
        if (x + longueureBatX <= COLONNES && y + longueureBatY <= LIGNES &&
            possibiliteDeConstruire(tabCase, x, y, longueureBatX, longueureBatY) == 0) {
            if (presenceRoute(tabCase, x, y, longueureBatX, longueureBatY) != 0) {
                (*compteur)++;
                for (int a = 0; a < longueureBatX; a++) {
                    for (int b = 0; b < longueureBatY; b++) {
                        tabCase[x + a][y + b].construction.type = typeBatiment;
                        if(typeBatiment == 2) {
                            tabCase[x + a][y + b].construction.compteur.nbUsines = *compteur;
                        }
                        if(typeBatiment == 3) {
                            tabCase[x + a][y + b].construction.compteur.nbChateauO = *compteur;
                        }
                    }
                }
            }
        }
    }
    else {
        int caseIdentite;
        if(typeBatiment == 2) {
            caseIdentite = tabCase[x][y].construction.compteur.nbUsines;
        }
        if(typeBatiment == 3) {
            caseIdentite = tabCase[x][y].construction.compteur.nbChateauO;
        }
        //(*compteur)--;
        for (int b = 0; b < LIGNES; b++) {
            for (int a = 0; a < COLONNES; a++) {
                if(typeBatiment == 2) {
                    if (tabCase[a][b].construction.compteur.nbUsines == caseIdentite) {
                        tabCase[a][b].construction.type = 0;
                        tabCase[a][b].construction.compteur.nbUsines = 0;
                    }
                }
                if(typeBatiment == 3) {
                    if (tabCase[a][b].construction.compteur.nbChateauO == caseIdentite) {
                        tabCase[a][b].construction.type = 0;
                        tabCase[a][b].construction.compteur.nbChateauO = 0;
                    }
                }
            }
        }
    }
}

int possibiliteDeConstruire(CASE** tabCase, int x, int y, int dimensionX, int dimensionY){
    int compteur = 0;
    for(int a = 0; a<dimensionX; a++){
        for(int b = 0; b<dimensionY; b++){
            if(tabCase[x+a][y+b].construction.type != 0) {
                compteur++;
            }
        }
    }
    return compteur;
}

int presenceRoute(CASE** tabCase, int x, int y, int dimensionX, int dimensionY){
    int compteur = 0;
        for (int a = 0; a < dimensionX; a++) {
            if (tabCase[x + a][y - 1].construction.type == 1) {
                compteur++;
            }
        }
        for (int a = 0; a < dimensionX; a++) {
            if (tabCase[x + a][y + (dimensionY)].construction.type == 1) {
                compteur++;
            }
        }
        for (int a = 0; a < dimensionY; a++) {

                if (x - 1 >= 0 && tabCase[x - 1][y + a].construction.type == 1) {
                    compteur++;
                }

        }
        for (int a = 0; a < dimensionY; a++) {

                if (x + dimensionX < COLONNES && tabCase[x + dimensionX][y + a].construction.type == 1) {
                    compteur++;
                }

        }

    return compteur;
}


void constructionSouris(VECTEUR* mouseIso, int categorieConstruction, int* niveau, CASE** tabCase, int* CompteEnBanque, COMPTEUR* compteur, int rotationBattiment, int detruire) {
    if(mouseIso->x>=0 && mouseIso->y>=0 && mouseIso->x<COLONNES && mouseIso->y<LIGNES && tabCase[mouseIso->x][mouseIso->y].construction.type == 0 && detruire == 0) {

        *niveau = 0;
        if (categorieConstruction == 0) {
            if (*CompteEnBanque >= COUT_ROUTE) {
                route(tabCase, mouseIso->x, mouseIso->y, &(compteur->nbRues), detruire);
                *CompteEnBanque = *CompteEnBanque - COUT_ROUTE;
            } else {
                printf("Vous n'avez pas assez d'argent\n");
            }
        }


        if (categorieConstruction == 1) {
            if (*CompteEnBanque >= COUT_TERRAIN_VAGUE) {
                habitation(tabCase, mouseIso->x, mouseIso->y, &(compteur->nbHab),detruire);
                *CompteEnBanque = *CompteEnBanque - COUT_TERRAIN_VAGUE;
            } else {
                printf("Vous n'avez pas assez d'argent\n");
            }
        }

        if (categorieConstruction == 2) {
            if (*CompteEnBanque >= COUT_CHATEAU_DEAU) {
                batiment(tabCase, mouseIso->x, mouseIso->y, &(compteur->nbUsines), 2, rotationBattiment,detruire);
                *CompteEnBanque = *CompteEnBanque - COUT_CHATEAU_DEAU;
            } else {
                printf("Vous n'avez pas assez d'argent\n");
            }
        }

        if (categorieConstruction == 3) {
            if (*CompteEnBanque >= COUT_CENTRAL) {
                batiment(tabCase, mouseIso->x, mouseIso->y, &(compteur->nbChateauO), 3, rotationBattiment,detruire);
                *CompteEnBanque = *CompteEnBanque - COUT_CENTRAL;
            } else {
                printf("Vous n'avez pas assez d'argent\n");
            }
        }
    }
}

void detruireConstruction(VECTEUR *mouseIso, CASE **tabCase, COMPTEUR *compteur, int rotationBattiment, int detruire) {
    if (mouseIso->x >= 0 && mouseIso->y >= 0 && mouseIso->x < COLONNES && mouseIso->y < LIGNES && tabCase[mouseIso->x][mouseIso->y].construction.type != 0 && detruire != 0) {

        if (tabCase[mouseIso->x][mouseIso->y].construction.type == 1) {

            route(tabCase, mouseIso->x, mouseIso->y, &(compteur->nbRues), detruire);

        }


        if (tabCase[mouseIso->x][mouseIso->y].construction.type == 5) {

            habitation(tabCase, mouseIso->x, mouseIso->y, &(compteur->nbHab),detruire);

        }

        if (tabCase[mouseIso->x][mouseIso->y].construction.type == 2) {

            batiment(tabCase, mouseIso->x, mouseIso->y, &(compteur->nbUsines), 2, rotationBattiment,detruire);

        }

        if (tabCase[mouseIso->x][mouseIso->y].construction.type == 3) {
            batiment(tabCase, mouseIso->x, mouseIso->y, &(compteur->nbChateauO), 3, rotationBattiment,detruire);
        }
    }
}
void routeApercu (CASE** tabCase, int x, int y){
    tabCase[x][y].construction.apercu = 1;
}

void habitationApercu (CASE** tabCase, int x, int y){

}
void batimentApercu(CASE** tabCase, int x, int y, int typeBatiment){

}



void evolutionBat (CASE** tabCase, float* tempsEcoule) {
    compteurTempsDuBat(tabCase, 0, 0, tempsEcoule);
    for (int y = 0; y < LIGNES; y++) {
        for (int x = 0; x < COLONNES; x++){
                if (tabCase[x][y].construction.type >= 5 && tabCase[x][y].construction.type <= 9){
                    if (tabCase[x][y].construction.tic == 15){
                        tabCase[x][y].construction.type ++;
                        tabCase[x][y].construction.tic = 0;
                    }
                }
        }
    }
}

void compteurTempsDuBat (CASE** tabCase, int x, int y, float* tempsEcoule) {
    float tempsActuel = GetTime();
    float deltaTemps = tempsActuel - *tempsEcoule;

    if (deltaTemps >= 1.0) {
        //incremente les tics de chaque batiment
        for (int y = 0; y < LIGNES; y++) {
            for (int x = 0; x < COLONNES; x++) {
                tabCase[x][y].construction.tic++;
            }
        }
        printf("SS\n");
        *tempsEcoule = tempsActuel;
    }
    DrawRectangle(200, 30, 180, 60, (Color){100, 190, 50, 200});
    DrawText(TextFormat( "Temps : %.2f",tempsActuel) ,210, 40, 25, BLACK);
}