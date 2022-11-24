//
// Created by Théophile Dutrey on 03/11/2022.
//

#include "bibliotheque.h"
void route (CASE** tabCase, int x, int y, int* compteur, int detruire,ECECITY *JEU){
    if(detruire==0) {
        tabCase[x][y].type = 1;
        (*compteur)++;

        tabCase[x][y].identite = *compteur;

    }
    else{
        (*compteur)--;
        tabCase[x][y].type = 0;
        tabCase[x][y].identite = 0;
    }
}


void habitation(CASE **tabCase, int x, int y, int *compteur, int detruire,ECECITY *JEU) {
    if (detruire == 0) {
        if (x + LONGUEURE_TERRAIN_VAGUE <= COLONNES && y + LARGEUR_TERRAIN_VAGUE <= LIGNES &&
            possibiliteDeConstruire(tabCase, x, y, LONGUEURE_TERRAIN_VAGUE, LARGEUR_TERRAIN_VAGUE) == 0) {
            if (presenceRoute(tabCase, x, y, LONGUEURE_TERRAIN_VAGUE, LARGEUR_TERRAIN_VAGUE) != 0) {

                (*compteur)++;
                JEU->tabHab[*compteur].type = 5;
                tabCase[x][y].affichage = 1;
                JEU->tabHab[*compteur].origineX = x;
                JEU->tabHab[*compteur].origineY = y;
                for (int a = 0; a < LONGUEURE_TERRAIN_VAGUE; a++) {
                    for (int b = 0; b < LARGEUR_TERRAIN_VAGUE; b++) {
                        tabCase[x + a][y + b].type = 5;
                        tabCase[x + a][y + b].identite = *compteur;
                    }
                }
            }
        }
    } else {
        int caseIdentite = tabCase[x][y].identite;
        //(*compteur)--;
        for (int b = 0; b < LIGNES; b++) {
            for (int a = 0; a < COLONNES; a++) {

                if (tabCase[a][b].identite == caseIdentite && tabCase[a][b].type == 5) {
                    tabCase[a][b].type = 0;
                    tabCase[a][b].identite = 0;
                }
            }
        }
    }
}


void batiment (CASE** tabCase, int x, int y, int* compteur, int typeBatiment, int rotation, int detruire,ECECITY *JEU){
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
                        tabCase[x + a][y + b].type = typeBatiment;

                        tabCase[x + a][y + b].identite = *compteur;

                    }
                }
            }
        }
    }
    else {
        int caseIdentite;

        caseIdentite = tabCase[x][y].identite;;


        //(*compteur)--;
        for (int b = 0; b < LIGNES; b++) {
            for (int a = 0; a < COLONNES; a++) {
                if (tabCase[a][b].identite == caseIdentite && tabCase[a][b].type == typeBatiment) {
                    tabCase[a][b].type = 0;
                    tabCase[a][b].identite = 0;
                }
            }
        }
    }
}

int possibiliteDeConstruire(CASE** tabCase, int x, int y, int dimensionX, int dimensionY){
    int compteur = 0;
    for(int a = 0; a<dimensionX; a++){
        for(int b = 0; b<dimensionY; b++){
            if(tabCase[x+a][y+b].type != 0) {
                compteur++;
            }
        }
    }
    return compteur;
}

int presenceRoute(CASE** tabCase, int x, int y, int dimensionX, int dimensionY){
    int compteur = 0;
        for (int a = 0; a < dimensionX; a++) {
            if (tabCase[x + a][y - 1].type == 1) {
                compteur++;
            }
        }
        for (int a = 0; a < dimensionX; a++) {
            if (tabCase[x + a][y + (dimensionY)].type == 1) {
                compteur++;
            }
        }
        for (int a = 0; a < dimensionY; a++) {

                if (x - 1 >= 0 && tabCase[x - 1][y + a].type == 1) {
                    compteur++;
                }

        }
        for (int a = 0; a < dimensionY; a++) {

                if (x + dimensionX < COLONNES && tabCase[x + dimensionX][y + a].type == 1) {
                    compteur++;
                }

        }

    return compteur;
}


void constructionSouris(VECTEUR* mouseIso, int categorieConstruction, int* niveau, CASE** tabCase, int* CompteEnBanque, COMPTEUR* compteur, int rotationBattiment, int detruire,ECECITY *JEU) {
    if(mouseIso->x>=0 && mouseIso->y>=0 && mouseIso->x<COLONNES && mouseIso->y<LIGNES && tabCase[mouseIso->x][mouseIso->y].type == 0 && detruire == 0) {

        *niveau = 0;
        if (categorieConstruction == 0) {
            if (*CompteEnBanque >= COUT_ROUTE) {
                route(tabCase, mouseIso->x, mouseIso->y, &(compteur->nbRues), detruire,JEU);
                *CompteEnBanque = *CompteEnBanque - COUT_ROUTE;
            } else {
                printf("Vous n'avez pas assez d'argent\n");
            }
        }


        if (categorieConstruction == 1) {
            if (*CompteEnBanque >= COUT_TERRAIN_VAGUE) {
                habitation(tabCase, mouseIso->x, mouseIso->y, &(compteur->nbHab),detruire,JEU);
                *CompteEnBanque = *CompteEnBanque - COUT_TERRAIN_VAGUE;
            } else {
                printf("Vous n'avez pas assez d'argent\n");
            }
        }

        if (categorieConstruction == 2) {
            if (*CompteEnBanque >= COUT_CHATEAU_DEAU) {
                batiment(tabCase, mouseIso->x, mouseIso->y, &(compteur->nbUsines), 2, rotationBattiment,detruire,JEU);
                *CompteEnBanque = *CompteEnBanque - COUT_CHATEAU_DEAU;
            } else {
                printf("Vous n'avez pas assez d'argent\n");
            }
        }

        if (categorieConstruction == 3) {
            if (*CompteEnBanque >= COUT_CENTRAL) {
                batiment(tabCase, mouseIso->x, mouseIso->y, &(compteur->nbChateauO), 3, rotationBattiment,detruire,JEU);
                *CompteEnBanque = *CompteEnBanque - COUT_CENTRAL;
            } else {
                printf("Vous n'avez pas assez d'argent\n");
            }
        }
    }
    //modifGraphe();
    //modidConnexe();
}

void detruireConstruction(VECTEUR *mouseIso, CASE **tabCase, COMPTEUR *compteur, int rotationBattiment, int detruire,ECECITY *JEU) {
    if (mouseIso->x >= 0 && mouseIso->y >= 0 && mouseIso->x < COLONNES && mouseIso->y < LIGNES && tabCase[mouseIso->x][mouseIso->y].type != 0 && detruire != 0) {

        if (tabCase[mouseIso->x][mouseIso->y].type == 1) {

            route(tabCase, mouseIso->x, mouseIso->y, &(compteur->nbRues), detruire,JEU);

        }


        if (tabCase[mouseIso->x][mouseIso->y].type >= 5) {

            habitation(tabCase, mouseIso->x, mouseIso->y, &(compteur->nbHab),detruire,JEU);

        }

        if (tabCase[mouseIso->x][mouseIso->y].type == 2) {

            batiment(tabCase, mouseIso->x, mouseIso->y, &(compteur->nbUsines), 2, rotationBattiment,detruire,JEU);

        }

        if (tabCase[mouseIso->x][mouseIso->y].type == 3) {
            batiment(tabCase, mouseIso->x, mouseIso->y, &(compteur->nbChateauO), 3, rotationBattiment,detruire,JEU);
        }
    }
    //modifGraphe(mouseIso, tabCase);
    //modidConnexe();
}
void routeApercu (CASE** tabCase, int x, int y){

}

void habitationApercu (CASE** tabCase, int x, int y){

}
void batimentApercu(CASE** tabCase, int x, int y, int typeBatiment){

}



void evolutionBat (CASE** tabCase, float* tempsEcoule, ECECITY* JEU) {
    compteurTempsDuBat(JEU, tempsEcoule);

    for (int x = 1; x < 175; x++){
        if (JEU->tabHab[x].type >= 5 && JEU->tabHab[x].type <= 9){
            if (JEU->tabHab[x].tic == 15){
                JEU->tabHab[x].type ++;
                JEU->tabHab[x].tic = 0;
                if (JEU->tabHab[x].type == 6){
                    JEU->tabHab[x].nbHabitant = 10;
                } else if (JEU->tabHab[x].type == 7) {
                    JEU->tabHab[x].nbHabitant = 50;
                } else if (JEU->tabHab[x].type == 8) {
                    JEU->tabHab[x].nbHabitant = 100;
                } else if (JEU->tabHab[x].type == 9) {
                    JEU->tabHab[x].nbHabitant = 1000;
                }
            }
        }
    }
/*
    for (int y = 0; y < LIGNES; y++) {
        for (int x = 0; x < COLONNES; x++){
                if (tabCase[x][y].type >= 5 && tabCase[x][y].type <= 9){
                    if (tabCase[x][y].tic == 15){
                        tabCase[x][y].type ++;
                        tabCase[x][y].tic = 0;
                    }
                }
        }
    }*/
}

void demolitionBatCapitaliste (CASE** tabCase, float* tempsEcoule, ECECITY* JEU, int compteEnBanque){
    for (int x = 1; x < 175; x++){
            if (JEU->tabHab[x].type >= 5 && JEU->tabHab[x].type <= 9){
                if (JEU->tabHab[x].tic == 15){
                    if (JEU->tabHab[x].QO < 10 && JEU->tabHab[x].QE < 10) {
                        JEU->tabHab[x].type --;
                        if (JEU->tabHab[x].type == 5) {
                            JEU->tabHab[x].nbHabitant = 0;
                        }
                    }
                    else if (JEU->tabHab[x].QO < 50 && JEU->tabHab[x].QO > 10 &&  JEU->tabHab[x].QE < 50 && JEU->tabHab[x].QE >10) {
                        JEU->tabHab[x].type --;
                        if (JEU->tabHab[x].type == 6) {
                            JEU->tabHab[x].nbHabitant = 10;
                        }
                    }
                    else if (JEU->tabHab[x].QO < 100 && JEU->tabHab[x].QO > 50 && JEU->tabHab[x].QE < 100 && JEU->tabHab[x].QE > 50) {
                        JEU->tabHab[x].type --;
                        if (JEU->tabHab[x].type == 7) {
                            JEU->tabHab[x].nbHabitant = 500;
                        }
                    }
                    else if (JEU->tabHab[x].QO < 1000 && JEU->tabHab[x].QO > 100 && JEU->tabHab[x].QE < 1000 && JEU->tabHab[x].QE > 100) {
                        JEU->tabHab[x].type --;
                        if (JEU->tabHab[x].type == 8) {
                            JEU->tabHab[x].nbHabitant = 100;
                        }
                    }
                    JEU->tabHab[x].tic = 0;
                }
        }
    }
}

void compteurTempsDuBat (CASE** tabCase, int x, int y, float* tempsEcoule) {
    float tempsActuel = GetTime();
    float deltaTemps = tempsActuel - *tempsEcoule;

    if (deltaTemps >= 1.0){
        //incremente les tics de chaque batiment
        for (int x = 0; x < COLONNES; x++){
            JEU->tabHab[x].tic++;
        }
        printf("SS\n");
        *tempsEcoule = tempsActuel;
    }
    DrawRectangle(200, 30, 180, 60, (Color){100, 190, 50, 200});
    DrawText(TextFormat( "Temps : %.2f",tempsActuel) ,210, 40, 25, BLACK);
}