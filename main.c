
#include <math.h>
#include "bibliotheque.h"

int main() {
    int niveau = 0;
    int construction;
    int ordre;
    int mode = 0;
    int detruire = 0;
    int rotationBattiment = 0;
    COMPTEUR compteur;

    compteur.nbChateauO = 0;
    compteur.nbHab = 0;
    compteur.nbRues = 0;
    compteur.nbUsines = 0;
    int compteEnBanque = 999999999;
    int minute = 0;
    int seconde = 0;
    int heure = 0;
    int mois = 11;
    int annee = 2022;
    int tempsVirtuelle;
    int cycle;
    float lastT = 0.0f;
    float accelerateurTemps = 1.00f;
    int compteurAccele = 1;
    int batimentSurvole;

    float tempsEcoule = 0;
    float tempsDepart;
    int jeuEnCour = 0;
    enum gameMode modeActuel = MENU;


    FILE *ifs = fopen("../map.txt", "r");
    FILE *ifs2 = fopen("../ordreConstruction.txt", "r");
    VECTEUR mouseIso;
    ECECITY *JEU = iniJeu(); //structure principal du jeu
    JEU->compteur.nbChateauO = 0;
    JEU->compteur.nbHab = 0;
    JEU->compteur.nbRues = 0;
    JEU->compteur.nbUsines = 0;


    int categorieConstruction = 0; // 0:route 1:habitation 2:usine 3:chateauEau 4:caserne
    animationBarre barre;
    barre.etat = FERME;
    barre.temps = 0;


    JEU->G->tabCase = malloc((COLONNES) * sizeof(CASE *));
    for (int i = 0; i < COLONNES; i++) {
        JEU->G->tabCase[i] = malloc((LIGNES) * sizeof(CASE));
    }
    fscanf(ifs, "%d", &tempsVirtuelle);
    cycle = tempsVirtuelle % TEMPS_CYCLE;
    for (int y = 0; y < LIGNES; y++) {
        for (int x = 0; x < COLONNES; x++) {
            fscanf(ifs, "%d", &construction);
            fscanf(ifs2, "%d", &ordre);
            JEU->G->tabCase[x][y].type = construction; // 0: rien 1:route 2:Usine 3:chateauEau 4:caserne 5:terrain vague
            JEU->G->tabCase[x][y].identite = ordre;
            JEU->G->tabCase[x][y].affichage = 0;
            initialisationOrdre(JEU->G->tabCase, ordre, x, y, &JEU->compteur, JEU);
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
    Texture2D maisonImage = LoadTexture("../images/maisonImage.png");
    Texture2D caserneImage = LoadTexture("../images/caserne.png");
    Texture2D puitImage = LoadTexture("../images/puit.png");
    Texture2D centraleImage = LoadTexture("../images/centrale.png");
    Texture2D testFond = LoadTexture("../images/fondtest.png");
    Texture2D Evolution = LoadTexture("../images/évolution_maison2.png");
    Texture2D cabane = LoadTexture("../images/cabane.png");
    Texture2D maison = LoadTexture("../images/maison.png");
    Texture2D hotel = LoadTexture("../images/hotel.png");
    Texture2D gratteCiel = LoadTexture("../images/gratte-ciel.png");

    Image img = LoadImage("../tilesTest.png");
    Texture2D terrainVague = LoadTexture("../images/terrain_vague.png");

    Texture2D team = LoadTexture("../Bitmap/Profile.png");
    Texture2D fontMenu = LoadTexture("../Bitmap/font.png");
    Texture2D rules = LoadTexture("../Bitmap/rules.png");
    Texture2D capitaliste = LoadTexture("../Bitmap/capitaliste.png");
    Texture communiste = LoadTexture("../Bitmap/communiste.png");


    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(BLACK);
        GetMousePosition();
        int PosXMouse = GetMouseX();
        int PosYMouse = GetMouseY();

        switch (modeActuel) {
            case MENU : {
                DrawTexturePro(fontMenu,
                               (Rectangle) {.x = 0, .y = 0, .width = fontMenu.width, .height =  fontMenu.height},
                               (Rectangle) {300, 0, .width = 1000, .height = 800}, (Vector2) {0, 0}, 0, WHITE);

                ///DESSINER LES 3 RECTANGLES DES MENUS

                DrawRectangle(556, 300, 512, 80, (Color) {255, 255, 0, 255});
                DrawRectangle(556, 400, 512, 80, (Color) {255, 255, 0, 255});
                DrawRectangle(556, 500, 512, 80, (Color) {255, 255, 0, 255});
                DrawRectangle(556, 600, 512, 80, (Color) {255, 255, 0, 255});

                DrawText("PLAY", 750, 318, 50, (Color) {0, 150, 0, 250});
                DrawText("RULES", 750, 418, 50, (Color) {0, 150, 0, 250});
                DrawText("TEAM", 750, 518, 50, (Color) {0, 150, 0, 250});
                DrawText("MODE", 750, 618, 50, (Color) {0, 150, 0, 250});


                ///On fait surbriller le rectangle sur lequelle se trouve la souris
                if (GetMouseX() > 556 && GetMouseY() > 300 && GetMouseX() < 1078 && GetMouseY() < 380) {
                    DrawRectangle(556, 300, 512, 80, (Color) {150, 150, 150, 115});
                } else if (GetMouseX() > 556 && GetMouseY() > 420 && GetMouseX() < 1078 && GetMouseY() < 480) {
                    DrawRectangle(556, 400, 512, 80, (Color) {150, 150, 150, 115});
                } else if (GetMouseX() > 556 && GetMouseY() > 500 && GetMouseX() < 1078 && GetMouseY() < 580) {
                    DrawRectangle(556, 500, 512, 80, (Color) {150, 150, 150, 115});
                } else if (GetMouseX() > 556 && GetMouseY() > 600 && GetMouseX() < 1078 && GetMouseY() < 680) {
                    DrawRectangle(556, 600, 512, 80, (Color) {150, 150, 150, 115});
                }
                break;
            }
            case RULES : {
                DrawTexturePro(rules,
                               (Rectangle) {.x = 0, .y = 0, .width = rules.width, .height =  rules.height},
                               (Rectangle) {260, 0, .width = 1000, .height = 800}, (Vector2) {0, 0}, 0, WHITE);


                ///FLECHES RETOUR
                DrawRectangle(50, 50, 140, 90, (Color) {87, 213, 241, 180});
                DrawText("RETURN", 55, 75, 30, (Color) {0, 0, 0, 255});

                ///On fait surbriller le rectangle sur lequelle se trouve la souris
                if (GetMouseX() > 50 && GetMouseY() > 50 && GetMouseX() < 200 && GetMouseY() < 150) {
                    DrawRectangle(50, 50, 140, 90, (Color) {162, 213, 268, 50});
                }
                break;
            }
            case TEAM : {
                DrawTexturePro(team,
                               (Rectangle) {.x = 0, .y = 0, .width = team.width, .height =  team.height},
                               (Rectangle) {260, 0, .width = 1000, .height = 800}, (Vector2) {0, 0}, 0, WHITE);

                ///FLECHES RETOUR
                DrawRectangle(50, 50, 140, 90, (Color) {87, 213, 241, 180});
                DrawText("RETURN", 55, 75, 30, (Color) {0, 0, 0, 255});

                ///On fait surbriller le rectangle sur lequelle se trouve la souris
                if (GetMouseX() > 50 && GetMouseY() > 50 && GetMouseX() < 200 && GetMouseY() < 150) {
                    DrawRectangle(50, 50, 140, 90, (Color) {162, 213, 268, 50});
                }
                break;
            }
            case MODE : {

                DrawTexturePro(capitaliste,
                               (Rectangle) {.x = 0, .y = 0, .width = capitaliste.width, .height =  capitaliste.height},
                               (Rectangle) {300, 300, .width = 300, .height = 300}, (Vector2) {0, 0}, 0, WHITE);
                if (GetMouseX() > 300 && GetMouseY() > 300 && GetMouseX() < 700 && GetMouseY() < 600) {
                    DrawTexturePro(capitaliste,
                                   (Rectangle) {.x = 0, .y = 0, .width = capitaliste.width, .height =  capitaliste.height},
                                   (Rectangle) {300, 300, .width = 400, .height = 400}, (Vector2) {0, 0}, 0, WHITE);
                }
                DrawTexturePro(communiste,
                               (Rectangle) {.x = 0, .y = 0, .width = communiste.width, .height =  communiste.height},
                               (Rectangle) {800, 300, .width = 300, .height = 300}, (Vector2) {0, 0}, 0, WHITE);
                if (GetMouseX() > 800 && GetMouseY() > 300 && GetMouseX() < 1200 && GetMouseY() < 600) {
                    DrawTexturePro(communiste,
                                   (Rectangle) {.x = 0, .y = 0, .width = communiste.width, .height =  communiste.height},
                                   (Rectangle) {800, 300, .width = 400, .height = 400}, (Vector2) {0, 0}, 0, WHITE);
                }
                DrawText("CHOISISSEZ UN MODE DE JEU :", 400, 50, 40, YELLOW);
                DrawText("MODE CAPITALISTE", 290, 150, 30, YELLOW);
                DrawText("MODE COMMUNISTE", 790, 150, 30, YELLOW);


                ///FLECHES RETOUR
                DrawRectangle(50, 50, 140, 90, (Color) {87, 213, 241, 180});
                DrawText("RETURN", 55, 75, 30, (Color) {0, 0, 0, 255});

                ///On fait surbriller le rectangle sur lequelle se trouve la souris
                if (GetMouseX() > 50 && GetMouseY() > 50 && GetMouseX() < 200 && GetMouseY() < 150) {
                    DrawRectangle(50, 50, 140, 90, (Color) {162, 213, 268, 50});
                }
                break;
            }
            case PLAY : {
                /* if (GetTime() - lastT > accelerateurTemps) {
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
                 //heure = tempsVirtuelle%3600; */

                tempsJeu(&lastT, &tempsVirtuelle, &cycle, accelerateurTemps, &seconde, &minute, &mois, &annee);
                coordSourisIso(&mouseIso, img);
                affichageGrille(mouseIso, Tiles);
                affichageRoute(Routes, JEU->G->tabCase, niveau);
                affichageTerrain(Tiles, JEU->G->tabCase, terrainVague, cabane, maison, hotel, gratteCiel);
                affichageBattiment(Tiles, JEU->G->tabCase);
                evolutionBat(JEU->G->tabCase, &tempsEcoule, JEU, &cycle);
                construireBat(categorieConstruction, PosXMouse, PosYMouse, terrainVague, Routes, mouseIso,
                              JEU->G->tabCase);


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
                }
                if (PosXMouse >= 80 && PosXMouse <= 100 && PosYMouse >= 200 && PosYMouse <= 220) {
                    if (compteurAccele < 7) {
                        compteurAccele++;
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
                    enregistrerPartie(JEU->G->tabCase, tempsVirtuelle);
                }
                if ((IsKeyDown(KEY_LEFT_CONTROL)) && (IsKeyPressed(KEY_KP_0))) {
                    recommencerPartie(JEU->G->tabCase, &JEU->compteur, &tempsVirtuelle, &cycle);
                }
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true) {
                    constructionSouris(&mouseIso, categorieConstruction, &niveau, JEU->G->tabCase, &compteEnBanque,
                                       &JEU->compteur, rotationBattiment, detruire, JEU);
                    detruireConstruction(&mouseIso, JEU->G->tabCase, &JEU->compteur, rotationBattiment, detruire, JEU);
                    barreOutilSouris(PosXMouse, PosYMouse, &barre, &categorieConstruction);
                    //printf("nb route: %d\nnb hab: %d\nnb usine: %d\nnb chateauO: %d\n ", JEU->compteur.nbRues,JEU->compteur.nbHab, JEU->compteur.nbUsines, JEU->compteur.nbChateauO);
                    CalculeElec(JEU);
                    //CalculeO(JEU);

                }
                if (CheckCollisionPointRec(GetMousePosition(), (Rectangle) {})) {

                }
                afficherBarreOutils(&barre, seconde, monnaie, temps, eau, elec, souris, calendrier, minute,
                                    compteEnBanque,
                                    heure, mois, annee, moinsAccel, plusAccel, routeImage, maisonImage, centraleImage,
                                    puitImage, caserneImage);
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


            }


        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true) {
            //Rectangle rectangle = {256, 300, 512, 80};
            //if (CheckCollisionPointRec(GetMousePosition(), rectangle)) {}

            switch (modeActuel) {
                case RULES : {
                    if (GetMouseX() > 50 && GetMouseY() > 50 && GetMouseX() < 200 && GetMouseY() < 150) {
                        modeActuel = MENU;
                    }
                    break;
                }
                case TEAM : {
                    if (GetMouseX() > 50 && GetMouseY() > 50 && GetMouseX() < 200 && GetMouseY() < 150) {
                        modeActuel = MENU;
                    }
                    break;
                }
                case MODE : {
                    if (GetMouseX() > 300 && GetMouseY() > 300 && GetMouseX() < 700 && GetMouseY() < 600) {
                        mode = 1;  ///MODE CAPITALISTE
                        DrawText("MODE CHOISI : CAPITALISTE", 400, 400, 30, BLACK);
                    } else if (GetMouseX() > 800 && GetMouseY() > 300 && GetMouseX() < 1200 && GetMouseY() < 600) {
                        mode = 2;  ///MODE COMMUNISTE
                        DrawText("MODE CHOISI : COMMUNISTE", 400, 400, 30, BLACK);
                    }
                    if (GetMouseX() > 50 && GetMouseY() > 50 && GetMouseX() < 200 && GetMouseY() < 150) {
                        modeActuel = MENU;
                    }
                    break;
                }
                case MENU : {
                    if (GetMouseX() > 556 && GetMouseY > 300 && GetMouseX() < 1078 && GetMouseY() < 380) {
                        modeActuel = PLAY;
                        tempsDepart = GetTime();
                        jeuEnCour = 1;
                    } else if (GetMouseX() > 556 && GetMouseY > 420 && GetMouseX() < 1078 && GetMouseY() < 480) {
                        modeActuel = RULES;

                    } else if (GetMouseX() > 556 && GetMouseY > 500 && GetMouseX() < 1078 && GetMouseY() < 580) {
                        modeActuel = TEAM;
                    } else if (GetMouseX() > 556 && GetMouseY > 620 && GetMouseX() < 1078 && GetMouseY() < 680) {
                        modeActuel = MODE;
                    }
                    break;
                }
            }
        }
        EndDrawing();
    }

    UnloadTexture(fontMenu);
    UnloadTexture(team);
    UnloadTexture(rules);
    UnloadTexture(capitaliste);
    UnloadTexture(communiste);
    UnloadTexture(terrainVague);
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
    UnloadTexture(testFond);
    UnloadTexture(Evolution);
    UnloadTexture(cabane);
    UnloadTexture(maison);
    UnloadTexture(hotel);
    UnloadTexture(gratteCiel);
    return 0;

}