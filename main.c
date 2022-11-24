
#include <math.h>
#include "bibliotheque.h"

int main() {
    int niveau = 0;
    int construction;
    int NbrHabitant = 0;
    COMPTEUR compteur;
    int compteEnBanque = 999999999;
    int minute = 0;
    int seconde = 0;
    int heure = 0;
    int mois = 11;
    int annee = 2022;
    int tempsVirtuelle = 0;
    float lastT = 0.0f;
    float accelerateurTemps = 1.00f;
    int compteurAccele = 1;
    int batimentSurvole;


    FILE *ifs = fopen("../map.txt", "r");
    VECTEUR mouseIso;
    VECTEUR mouseIsoClic;

    int categorieConstruction = 0; // 0:route 1:habitation 2:usine 3:chateauEau 4:caserne
    animationBarre barre;
    barre.etat = FERME;
    barre.temps = 0;

    CASE **tabCase = malloc((COLONNES) * sizeof(CASE *));
    for (int i = 0; i < COLONNES; i++) {
        tabCase[i] = malloc((LIGNES) * sizeof(CASE));
    }

    for (int y = 0; y < LIGNES; y++) {
        for (int x = 0; x < COLONNES; x++) {
            fscanf(ifs, "%d", &construction);
            tabCase[x][y].construction.type = construction; // 0: rien 1:route 2:Usine 3:chateauEau 4:caserne 5:terrain vague

        }
    }

    InitWindow(LARGEUR, HAUTEUR, "Projet");
    //SetWindowState(FLAG_WINDOW_RESIZABLE);

    Texture2D Tiles = LoadTexture("../tiles/tiles.png");
    Texture2D Routes = LoadTexture("../tiles/route.png");
    Texture2D monnaie = LoadTexture("../images/monnaie.png");
    Texture2D temps = LoadTexture("../images/timer.png");
    Texture2D eau = LoadTexture("../images/eau.png");
    Texture2D elec = LoadTexture("../images/elec.png");
    Texture2D souris = LoadTexture("../images/souris.png");
    Texture2D calendrier = LoadTexture("../images/calendrier.png");
Texture2D plusAccel = LoadTexture("../images/plusAccel.png");
    Texture2D moinsAccel = LoadTexture("../images/moinsAccel.png");
    Texture2D x1 = LoadTexture("../images/x1.png");
    Texture2D x2 = LoadTexture("../images/x2.png");
    Texture2D x5 = LoadTexture("../images/x5.png");
    Texture2D x10 = LoadTexture("../images/x10.png");
    Texture2D x15 = LoadTexture("../images/x15.png");
    Texture2D x30 = LoadTexture("../images/x30.png");
    Texture2D routeImage = LoadTexture("../images/route.png");
    Texture2D maisonImage = LoadTexture("../images/maison.png");
    Texture2D caserneImage = LoadTexture("../images/caserne.png");
    Texture2D puitImage = LoadTexture("../images/puit.png");
    Texture2D centraleImage = LoadTexture("../images/centrale.png");

    Image img = LoadImage("../tilesTest.png");
    Texture2D maison = LoadTexture("../images/terrain_vague.png");

    while (!WindowShouldClose()) {

        BeginDrawing();
        if (GetTime() - lastT > accelerateurTemps) {
            tempsVirtuelle++;
            lastT = GetTime();
        }
        mois = (tempsVirtuelle / 15) % 12;
        annee = 2022 + (tempsVirtuelle / 15) / 12;
        if (mois > 12) {
            mois = 1;
        }
        minute = tempsVirtuelle / 60 %60;
        seconde = tempsVirtuelle % 60;
        //heure = tempsVirtuelle%3600;


        coordSourisIso(&mouseIso, img);
        affichageGrille(mouseIso, Tiles);
        affichageRoute(Routes, tabCase, niveau);
        affichageTerrain(Tiles, tabCase);
        affichageBattiment(Tiles, tabCase);

        ClearBackground(BLACK);

        GetMousePosition();
        int PosXMouse = GetMouseX();
        int PosYMouse = GetMouseY();

        if (IsKeyPressed(KEY_SPACE) == true) {
            if (niveau != 2) {
                niveau++;
            } else {
                niveau = 0;
            }
        }
        /*if (IsKeyPressed(KEY_RIGHT) == true) {

            if (categorieConstruction != 4) {
                categorieConstruction++;
            } else {
                categorieConstruction = 0;
            }
        }*/
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true) {
            if (PosXMouse >= 10 && PosXMouse <= 30 && PosYMouse >= 200 && PosYMouse <= 220) {
                if (compteurAccele > 0) {
                    compteurAccele--;
                }
            }
            if (PosXMouse >= 80 && PosXMouse <= 100 && PosYMouse >= 200 && PosYMouse <= 220) {
                if (compteurAccele < 7) {
                    compteurAccele++;
                }
            }
        }

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) == true) {
            if (barre.etat == FERME && PosXMouse > 1520 && PosXMouse < 1600 && PosYMouse > 340 && PosYMouse < 400) {
                barre.etat = OUVERT;
            }
            if (barre.etat == OUVERT && PosXMouse > 1300 && PosXMouse < 1370 && PosYMouse > 340 && PosYMouse < 400) {
                barre.etat = FERME;
            }
            if (barre.etat == OUVERT && PosXMouse > 1380 && PosXMouse < 1480 && PosYMouse > 40 && PosYMouse < 140) {
                categorieConstruction = 0;
            }
            if (barre.etat == OUVERT && PosXMouse > 1380 && PosXMouse < 1480 && PosYMouse > 190 && PosYMouse < 290) {
                categorieConstruction = 1;
            }

        }

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) == true) {
            if (mouseIso.x >= 0 && mouseIso.y >= 0 && mouseIso.x < COLONNES && mouseIso.y < LIGNES) {
                coordSourisIso(&mouseIsoClic, img);
                niveau = 0;
                if (categorieConstruction == 0 &&
                    tabCase[mouseIso.x][mouseIso.y].construction.type == 0) {
                    if (compteEnBanque >= COUT_ROUTE) {
                        route(tabCase, mouseIsoClic.x, mouseIsoClic.y, &(compteur.nbRues));
                        compteEnBanque = compteEnBanque - COUT_ROUTE;
                    } else {
                        printf("Vous n'avez pas assez d'argent\n");
                    }
                }


                if (categorieConstruction == 1 &&
                    tabCase[mouseIso.x][mouseIso.y].construction.type == 0) {
                    if (compteEnBanque >= COUT_TERRAIN_VAGUE) {
                        habitation(tabCase, mouseIso.x, mouseIso.y, &(compteur.nbHab));
                        compteEnBanque = compteEnBanque - COUT_TERRAIN_VAGUE;
                    } else {
                        printf("Vous n'avez pas assez d'argent\n");
                    }
                }

                if (categorieConstruction == 2 &&
                    tabCase[mouseIso.x][mouseIso.y].construction.type == 0) {
                    if (compteEnBanque >= COUT_CHATEAU_DEAU) {
                        batiment(tabCase, mouseIso.x, mouseIso.y, &(compteur.nbUsines), 3);
                        compteEnBanque = compteEnBanque - COUT_CHATEAU_DEAU;
                    } else {
                        printf("Vous n'avez pas assez d'argent\n");
                    }
                }

                if (categorieConstruction == 3 &&
                    tabCase[mouseIso.x][mouseIso.y].construction.type == 0) {
                    if (compteEnBanque >= COUT_CENTRAL) {
                        batiment(tabCase, mouseIso.x, mouseIso.y, &(compteur.nbChateauO), 2);
                        compteEnBanque = compteEnBanque - COUT_CENTRAL;
                    } else {
                        printf("Vous n'avez pas assez d'argent\n");
                    }
                }
            }
        }
        if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){})){

        }
        afficherBarreOutils(&barre, seconde, monnaie, temps, eau, elec, souris, calendrier, minute, compteEnBanque,
                            heure, mois, annee, moinsAccel, plusAccel, routeImage, maisonImage, centraleImage, puitImage, caserneImage);
        switch (compteurAccele) {
            case 1 :
                accelerateurTemps = 1.00;
                DrawTexture(x1, 35, 190, BLUE);
                break;
            case 2 :
                accelerateurTemps = 0.50;
                DrawTexture(x2, 35, 190, BLUE);
                break;
            case 3 :
                accelerateurTemps = 0.20;
                DrawTexture(x5, 35, 190, BLUE);
                break;
            case 4 :
                accelerateurTemps = 0.10;
                DrawTexture(x10, 35, 190, BLUE);
                break;
            case 5 :
                accelerateurTemps = 0.06;
                DrawTexture(x15, 35, 190, BLUE);
                break;
            case 6 :
                accelerateurTemps = 0.03;
                DrawTexture(x30, 35, 190, BLUE);
                break;
        }
        construireBat(categorieConstruction, PosXMouse, PosYMouse, maison);
        EndDrawing();

    }
    UnloadTexture(maison);
    UnloadTexture(monnaie);
    UnloadTexture(temps);
    UnloadTexture(eau);
    UnloadTexture(elec);
    UnloadTexture(souris);
    UnloadTexture(calendrier);
    UnloadTexture(plusAccel);
    UnloadTexture(moinsAccel);
    UnloadTexture(x1);
    UnloadTexture(x2);
    UnloadTexture(x5);
    UnloadTexture(x10);
    UnloadTexture(x15);
    UnloadTexture(x30);
    UnloadTexture(routeImage);
    UnloadTexture(maisonImage);
    UnloadTexture(caserneImage);
    UnloadTexture(puitImage);
    UnloadTexture(centraleImage);
    return 0;
}
