
#include "bibliotheque.h"

int main() {
    int niveau = 0;
    int construction;
    int ordre;
    int detruire = 0;
    int rotationBattiment;
    int compteEnBanque = 999999999;
    float tempsEcoule = 0;


    FILE *ifs = fopen("../map.txt", "r");
    FILE *ifs2 = fopen("../ordreConstruction.txt", "r");
    VECTEUR mouseIso;
    ECECITY *JEU = iniJeu();
    JEU->compteur.nbChateauO=0;
    JEU->compteur.nbHab=0;
    JEU->compteur.nbRues=0;
    JEU->compteur.nbUsines=0;


    int categorieConstruction = 0; // 0:route 1:habitation 2:usine 3:chateauEau 4:caserne


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
            initialisationOrdre(JEU->G->tabCase, ordre, x, y,&JEU->compteur);
        }
    }

    InitWindow(LARGEUR, HAUTEUR, "Projet");
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    Texture2D Tiles =  LoadTexture("../tiles/tiles.png");
    Texture2D Routes =  LoadTexture("../tiles/route.png");

    Image img =  LoadImage("../tilesTest.png");

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(BLACK);

        coordSourisIso(&mouseIso, img);
        affichageGrille(mouseIso, Tiles);
        affichageRoute(Routes, JEU->G->tabCase, niveau);
        affichageTerrain(Tiles, JEU->G->tabCase);
        affichageBattiment(Tiles, JEU->G->tabCase);
        //evolutionBat(JEU->G->tabCase, &tempsEcoule);



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
            printf("nb route: %d\nnb hab: %d\nnb usine: %d\nnb chateauO: %d\n ", JEU->compteur.nbRues,JEU->compteur.nbHab, JEU->compteur.nbUsines, JEU->compteur.nbChateauO);
            //CalculeElec(JEU);
            //CalculeO(JEU);
        }

        EndDrawing();

    }

    return 0;
}
