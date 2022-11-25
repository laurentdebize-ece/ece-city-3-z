
#include <math.h>
#include "bibliotheque.h"

int main() {
    int niveau = 0;
    int construction;
    int ordre;
    int detruire = 0;
    int rotationBattiment = 0;
    COMPTEUR compteur;

    compteur.nbChateauO=0;
    compteur.nbHab=0;
    compteur.nbRues=0;
    compteur.nbUsines=0;
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

    float tempsEcoule = 0;


    FILE *ifs = fopen("../map.txt", "r");
    FILE *ifs2 = fopen("../ordreConstruction.txt", "r");
    VECTEUR mouseIso;
    ECECITY *JEU = iniJeu(); //structure principal du jeu
    JEU->compteur.nbChateauO=0;
    JEU->compteur.nbHab=0;
    JEU->compteur.nbRues=0;
    JEU->compteur.nbUsines=0;


    int categorieConstruction = 0; // 0:route 1:habitation 2:usine 3:chateauEau 4:caserne
    animationBarre barre;
    barre.etat = FERME;
    barre.temps = 0;


    JEU->G->tabCase = malloc((COLONNES) * sizeof(CASE *));
    for (int i = 0; i < COLONNES; i++) {
        JEU->G->tabCase[i] = malloc((LIGNES) * sizeof(CASE));
    }

    for (int y = 0; y < LIGNES; y++) {
        for (int x = 0; x < COLONNES; x++) {
            fscanf(ifs, "%d", &construction);
            fscanf(ifs2, "%d", &ordre);
            JEU->G->tabCase[x][y].type = construction; // 0: rien 1:route 2:Usine 3:chateauEau 4:caserne 5:terrain vague
            JEU->G->tabCase[x][y].identite = ordre;
            JEU->G->tabCase[x][y].affichage = 0;
            initialisationOrdre(JEU->G->tabCase, ordre, x, y,&JEU->compteur);
        }
    }

    InitWindow(LARGEUR, HAUTEUR, "Projet");
    SetWindowState(FLAG_WINDOW_RESIZABLE);

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
        ClearBackground(BLACK);
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
        affichageRoute(Routes, JEU->G->tabCase, niveau);
        affichageTerrain(Tiles, JEU->G->tabCase);
        affichageBattiment(Tiles, JEU->G->tabCase);
        evolutionBat(JEU->G->tabCase, &tempsEcoule, JEU);



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
        if (IsKeyPressed(KEY_RIGHT) == true) {
            if (categorieConstruction != 4) {
                categorieConstruction++;
            } else {
                categorieConstruction = 0;
            }
        }
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

        if (IsKeyPressed(KEY_UP) == true) {
            if (rotationBattiment != 1) {
                rotationBattiment++;
            } else {
                rotationBattiment = 0;
            }
        }
        if (IsKeyPressed(KEY_KP_1) == true) {
            if (detruire != 1) {
                detruire++;
            } else {
                detruire = 0;
            }
        }

        if ((IsKeyDown(KEY_LEFT_CONTROL)) && (IsKeyPressed(KEY_S))) {
            enregistrerPartie(JEU->G->tabCase);
        }
        if ((IsKeyDown(KEY_LEFT_CONTROL)) && (IsKeyPressed(KEY_KP_0))) {
            recommencerPartie(JEU->G->tabCase,&JEU->compteur);
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true) {
            constructionSouris(&mouseIso, categorieConstruction, &niveau, JEU->G->tabCase, &compteEnBanque, &JEU->compteur, rotationBattiment, detruire, JEU);
            detruireConstruction(&mouseIso,JEU->G->tabCase,&JEU->compteur,rotationBattiment,detruire,JEU);
            barreOutilSouris(PosXMouse, PosYMouse, &barre, &categorieConstruction);
            printf("nb route: %d\nnb hab: %d\nnb usine: %d\nnb chateauO: %d\n ", JEU->compteur.nbRues,JEU->compteur.nbHab, JEU->compteur.nbUsines, JEU->compteur.nbChateauO);
            //CalculeElec(JEU);
            //CalculeO(JEU);
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
