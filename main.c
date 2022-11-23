
#include "bibliotheque.h"

int main() {
    int niveau = 0;
    int construction;
    int detruire = 0;
    int rotationBattiment;
    COMPTEUR compteur;
    compteur.nbChateauO=0;
    compteur.nbHab=0;
    compteur.nbRues=0;
    compteur.nbUsines=0;
    int compteEnBanque = 999999999;

    FILE *ifs = fopen("../map.txt", "r");
    VECTEUR mouseIso;
    //ECECITY *JEU = iniJeu();

    
    int categorieConstruction = 0; // 0:route 1:habitation 2:usine 3:chateauEau 4:caserne
   
    
    CASE **tabCase = malloc((COLONNES) * sizeof(CASE *));
    for (int i = 0; i < COLONNES; i++) {
        tabCase[i] = malloc((LIGNES) * sizeof(CASE));
    }

    for (int y = 0; y < LIGNES; y++) {
        for (int x = 0; x < COLONNES; x++) {
            fscanf(ifs, "%d", &construction);
            tabCase[x][y].construction.type = construction; // 0: rien 1:route 2:Usine 3:chateauEau 4:caserne 5:terrain vague
            tabCase[x][y].construction.compteur.nbChateauO = 0;
            tabCase[x][y].construction.compteur.nbUsines = 0;
            tabCase[x][y].construction.compteur.nbHab = 0;
            tabCase[x][y].construction.compteur.nbRues = 0;
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
        affichageRoute(Routes, tabCase, niveau);
        affichageTerrain(Tiles, tabCase);
        affichageBattiment(Tiles, tabCase);



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
            enregistrerPartie(tabCase);
        }
        if ((IsKeyDown(KEY_LEFT_CONTROL)) && (IsKeyPressed(KEY_KP_0))) {
            recommencerPartie(tabCase);
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true) {
            constructionSouris(&mouseIso, categorieConstruction, &niveau, tabCase, &compteEnBanque, &compteur, rotationBattiment, detruire/*, JEU*/);
            detruireConstruction(&mouseIso,tabCase,&compteur,rotationBattiment,detruire);
            printf("nb route: %d\nnb hab: %d\nnb usine: %d\nnb chateauO: %d\n ", compteur.nbRues,compteur.nbHab, compteur.nbUsines, compteur.nbChateauO);
            //CalculeElec(JEU);
            //CalculeO(JEU);
        }

        EndDrawing();

    }

    return 0;
}
