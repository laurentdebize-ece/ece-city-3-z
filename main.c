
#include <math.h>
#include "bibliotheque.h"

int main() {
    int niveau = 0;
    int construction;
    int ordre;
    int affichage;
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
    int construire = 1;

    float tempsEcoule = 0;
    float tempsDepart;
    int jeuEnCour = 0;
    int modeActuel = MENU;

    int quitter = 0;


    FILE *ifs = fopen("../map.txt", "r");
    FILE *ifs2 = fopen("../ordreConstruction.txt", "r");
    FILE *ifs3 = fopen("../affichage.txt", "r");
    VECTEUR mouseIso;
    ECECITY *JEU = iniJeu(); //structure principal du jeu
    JEU->compteur.nbChateauO = 0;
    JEU->compteur.nbHab = 0;
    JEU->compteur.nbRues = 0;
    JEU->compteur.nbUsines = 0;


    int categorieConstruction; // 0:route 1:habitation 2:usine 3:chateauEau 4:caserne
    animationBarre barre;
    barre.etat = FERME;
    barre.temps = 0;


    fscanf(ifs, "%d", &tempsVirtuelle); // Lecture du temps acuel enregistré dans le fichier texte
    cycle = tempsVirtuelle % TEMPS_CYCLE; // Le cycle correspond au nb de seconde restant avant la prochaine évolution, un cycle = 15 secondes
    for (int y = 0; y < LIGNES; y++) {  // Initialisation de la matrice du jeu en fonctions des types, des identités et des affichages enregistrés dans des fichiers texte différnets
        for (int x = 0; x < COLONNES; x++) {
            fscanf(ifs, "%d", &construction);
            fscanf(ifs2, "%d", &ordre);
            fscanf(ifs3, "%d", &affichage);
            JEU->G->tabCase[x][y].type = construction; // 0: rien 1:route 2:Usine 3:chateauEau 4:caserne 5:terrain vague
            JEU->G->tabCase[x][y].identite = ordre;
            JEU->G->tabCase[x][y].affichage = affichage;
            initialisationOrdre(JEU->G->tabCase, ordre, x, y, &JEU->compteur, JEU);
        }
    }

    InitWindow(LARGEUR, HAUTEUR, "Projet");
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    // Initialisation de ttes les Textures
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
    Texture2D centralEau = LoadTexture("../images/centralEau.png");
    Texture2D centralEauBis = LoadTexture("../images/centralEauBis.png");
    Texture2D centralElec = LoadTexture("../images/centralElec.png");
    Texture2D centralElecBis = LoadTexture("../images/centralElecBis.png");
    Texture2D rotation = LoadTexture("../images/rotation.png");
    Texture2D plage = LoadTexture("../images/plage.png");
    Texture2D plage2 = LoadTexture("../images/plage2.png");

    Image img = LoadImage("../tilesTest.png");
    Texture2D terrainVague = LoadTexture("../images/terrain_vague.png");
    Texture2D enregistrer = LoadTexture("../images/enregistrer.png");
    Texture2D demolition = LoadTexture("../images/demolition.png");
    Texture2D construireOn = LoadTexture("../images/construireOn.png");
    Texture2D construireOff = LoadTexture("../images/construireOff.png");
    Texture2D demolitionOff = LoadTexture("../images/demolitionOff.png");

    Texture2D team = LoadTexture("../Bitmap/Profile.png");
    Texture2D fontMenu = LoadTexture("../Bitmap/font.png");
    Texture2D rules = LoadTexture("../Bitmap/rules.png");
    Texture2D capitaliste = LoadTexture("../Bitmap/capitaliste.png");
    Texture communiste = LoadTexture("../Bitmap/communiste.png");


    while (!WindowShouldClose()) { // Lancement de la boucle du jeu

        BeginDrawing(); // On commence à dessiner
        ClearBackground(BLACK);
        GetMousePosition();
        int PosXMouse = GetMouseX(); // on stocke les coordonnées de la souris dans deux variavles
        int PosYMouse = GetMouseY();
        choixModeJeu(&modeActuel, &mode, &tempsDepart, &jeuEnCour); // On choisit si on veut lancer une partie, regarder les règles...

        switch (modeActuel) { //on affiche ce qu'on a choisit commme mode
            case MENU : {
                affichageMenu(fontMenu);
                break;
            }
            case RULES : {
                affichageRegles(rules);
                break;
            }
            case TEAM : {
                affichageTeam(team);
                break;
            }
            case MODE : {
                affichageMode(mode, capitaliste, communiste);
                choixMode(&mode);
                break;
            }
            case PLAY : {

                tempsJeu(&lastT, &tempsVirtuelle, &cycle, accelerateurTemps, &seconde, &minute, &mois, &annee);
                coordSourisIso(&mouseIso, img); // Passage des coordonnées de la souris en coordonnées isométriques
                affichageGrille(mouseIso, Tiles);// on affiche la grille
                affichageRoute(Routes, JEU->G->tabCase, niveau);// on affiche les route si il y en a qui ont été posé
                affichageTerrain(Tiles, JEU->G->tabCase, terrainVague, cabane, maison, hotel, gratteCiel);// on affiche les terrains si il y en a qui ont été posé
                affichageBattiment(Tiles, JEU->G->tabCase, centralEau, centralEauBis, centralElecBis, centralElec,// on affiche les battiments si il y en a qui ont été posé
                                   rotationBattiment);
                if (mode == 1){// En fonction du mode on chosit le type d'évolution
                    evolutionBatCapitaliste(JEU->G->tabCase, &tempsEcoule, JEU, &cycle);
                }else if (mode == 2){
                    evolutionCommuniste(JEU->G->tabCase, &tempsEcoule, JEU, &cycle);
                }


                demolitionBatiment(JEU->G->tabCase, &tempsEcoule, JEU, &cycle);


                construireBat(categorieConstruction, PosXMouse, PosYMouse, terrainVague, Routes, mouseIso,
                              JEU->G->tabCase, centralEau, centralEauBis, centralElecBis, centralElec,
                              rotationBattiment, construire, JEU);
                afficherBarreOutils(&barre, seconde, monnaie, temps, eau, elec, souris, calendrier, minute,
                                    compteEnBanque,
                                    heure, mois, annee, moinsAccel, plusAccel, routeImage, maisonImage,
                                    centraleImage,
                                    puitImage, caserneImage, rotation, enregistrer, demolition, construire, detruire,
                                    construireOn, construireOff, demolitionOff, plage, plage2, quitter, JEU);

                accelerationTemps(compteurAccele, &accelerateurTemps, x1,x2,x5,x10,x15,x30);
                CalculeElec(JEU);
                CalculeO(JEU);

                if (IsKeyPressed(KEY_SPACE) == true) {// Affichage des niveaux
                    if (niveau != 2) {
                        niveau++;
                    } else {
                        niveau = 0;
                    }
                }


                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true) { // Si le bouton de la souris est appuyé alors on réalise les fonctions suivantes
                    clicGaucheBarreOutil(PosXMouse, PosYMouse, &compteurAccele, &rotationBattiment, &detruire, &construire, JEU, &tempsVirtuelle, &cycle, &quitter, &modeActuel);
                    constructionSouris(&mouseIso, categorieConstruction, &niveau, JEU->G->tabCase, &compteEnBanque,
                                       &JEU->compteur, rotationBattiment, detruire, JEU);
                    detruireConstruction(&mouseIso, JEU->G->tabCase, &JEU->compteur, rotationBattiment, detruire,
                                         JEU);
                    barreOutilSouris(PosXMouse, PosYMouse, &barre, &categorieConstruction);

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
    UnloadTexture(centralEau);
    UnloadTexture(centralEauBis);
    UnloadTexture(centralElec);
    UnloadTexture(centralElecBis);
    UnloadTexture(rotation);
    UnloadTexture(enregistrer);
    UnloadTexture(demolition);
    UnloadTexture(construireOn);
    UnloadTexture(construireOff);
    UnloadTexture(demolitionOff);
    UnloadTexture(plage);
    UnloadTexture(plage2);
    return 0;
}
