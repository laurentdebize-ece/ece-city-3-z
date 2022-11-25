#include "bibliotheque.h"
#include "graphe.h"

CASE **CreerArete(CASE **sommet, int s1X, int s1Y, int s2X, int s2Y, int valeurs) {
    if (sommet[s1X][s1Y].arc == NULL) {
        pArc Newarc = (pArc) malloc(sizeof(struct Arc));
        Newarc->sommetX = s2X;
        Newarc->sommetY = s2Y;
        Newarc->arc_suivant = NULL;
        Newarc->valeur = valeurs; //on ajoute la lecture des valeurs des arrète
        sommet[s1X][s1Y].arc = Newarc;
        return sommet;
    } else {
        pArc temp = sommet[s1X][s1Y].arc;
        while (!(temp->arc_suivant == NULL)) {
            temp = temp->arc_suivant;
        }
        pArc Newarc = (pArc) malloc(sizeof(struct Arc));
        Newarc->sommetX = s2X;
        Newarc->sommetY = s2Y;
        Newarc->valeur = valeurs; //ici aussi
        Newarc->arc_suivant = NULL;

        if (temp->sommetX * 100 + temp->sommetY > s2X * 100 + s2Y) {
            Newarc->arc_suivant = temp->arc_suivant;
            Newarc->sommetX = temp->sommetX;
            Newarc->sommetY = temp->sommetY;
            Newarc->sommetX = s2X;
            Newarc->sommetY = s2Y;
            temp->valeur = valeurs; //ici aussi
            temp->arc_suivant = Newarc;
            return sommet;
        }

        temp->arc_suivant = Newarc;
        return sommet;
    }
}

void CalculeConnexe(CASE **tabCase, int i, int j, int *nbConnexe) {
    pArc temp = tabCase[i][j].arc;
    int x = tabCase[i][j].arc->sommetX;
    int y = tabCase[i][j].arc->sommetY;
    while (temp != NULL) {
        if (tabCase[x][y].connexe != 0) {
            tabCase[i][j].connexe = tabCase[x][y].connexe;
            return;
        }
        temp = temp->arc_suivant;
    }
    if (tabCase[x][y].type>0) {
        tabCase[i][j].connexe = *nbConnexe;
        (*nbConnexe)++;
    }
}


void iniTabHab(CASE **tabCase, int i, int j, ECECITY *JEU) {
    if (JEU->tabHab[tabCase[i][j].identite].connexe == 0) {
        JEU->tabHab[tabCase[i][j].identite].connexe = tabCase[i][j].connexe;
        if (tabCase[i][j].type == 5) {
            JEU->tabHab[tabCase[i][j].identite].nbHabitant = 0;
        }
        if (tabCase[i][j].type == 6) {
            JEU->tabHab[tabCase[i][j].identite].nbHabitant = 10;
        }
        if (tabCase[i][j].type == 7) {
            JEU->tabHab[tabCase[i][j].identite].nbHabitant = 50;
        }
        if (tabCase[i][j].type == 8) {
            JEU->tabHab[tabCase[i][j].identite].nbHabitant = 100;
        }
        if (tabCase[i][j].type == 9) {
            JEU->tabHab[tabCase[i][j].identite].nbHabitant = 1000;
        }
        JEU->tabHab[tabCase[i][j].identite].QO = 0;
        JEU->tabHab[tabCase[i][j].identite].QE = 0;
    } else {
        JEU->compteur.nbHab--;
    }
}

void iniTabE(CASE **tabCase, int i, int j, ECECITY *JEU) {
    if (JEU->tabE[tabCase[i][j].identite].connexe == 0) {
        JEU->tabE[tabCase[i][j].identite].connexe = tabCase[i][j].connexe;
        JEU->tabE[tabCase[i][j].identite].QEmax = 5000;
        JEU->tabE[tabCase[i][j].identite].QErestant = 5000;
    } else {
        JEU->compteur.nbUsines--;
    }
}

void iniTabO(CASE **tabCase, int i, int j, ECECITY *JEU) {
    if (JEU->tabO[tabCase[i][j].identite].connexe == 0) {
        JEU->tabO[tabCase[i][j].identite].connexe = tabCase[i][j].connexe;
        JEU->tabO[tabCase[i][j].identite].QOmax = 5000;
        JEU->tabO[tabCase[i][j].identite].QOrestant = 5000;
    } else {
        JEU->compteur.nbChateauO--;
    }
}

void CalculeCompteurEtTab(CASE **tabCase, int i, int j, ECECITY *JEU) {
    if (tabCase[i][j].type == 1) {
        JEU->compteur.nbRues++;
    }
    if (tabCase[i][j].type == 2) {
        JEU->compteur.nbUsines++;
        iniTabE(tabCase, i, j, JEU);
    }
    if (tabCase[i][j].type == 3) {
        JEU->compteur.nbChateauO++;
        iniTabO(tabCase, i, j, JEU);
    }
    if (tabCase[i][j].type >= 5) {
        JEU->compteur.nbHab++;
        iniTabHab(tabCase, i, j, JEU);
    }
}

Graphe *CreerGraphe(FILE *ifs, FILE *ifsID, ECECITY *JEU) {
    int construction;
    int ID;
    int nbConnexe = 1;
    CASE **tabCase = malloc((QUADRILIGNE) * sizeof(CASE *));
    for (int i = 0; i < QUADRILIGNE; i++) {
        tabCase[i] = malloc((QUADRICOLONNE) * sizeof(CASE));
    }
    for (int i = 0; i < QUADRILIGNE; i++) {
        for (int j = 0; j < QUADRICOLONNE; j++) {
            CASE *check = &tabCase[i][j];
            fscanf(ifs, "%d", &construction);
            fscanf(ifsID, "%d", &ID);
            tabCase[i][j].type = construction;// 0: rien 1:route 2:habitation 3:usine 4:chateauEau 5:caserne
            tabCase[i][j].identite = ID;
            tabCase[i][j].connexe = 0;
            fflush(stdout);
        }
    }
    for (int i = 0; i < QUADRILIGNE; i++) {
        for (int j = 0; j < QUADRICOLONNE; j++) {
            CASE *check = &tabCase[i][j];
            tabCase[i][j].x = TUILE / 2 + i * TUILE;
            tabCase[i][j].y = TUILE / 2 + j * TUILE;
            tabCase[i][j].etat = 0;
            tabCase[i][j].arc = NULL;//il n'y a aucune construction au debut
            //on créer les arretes pour les 4cases adjacente de la case ij
            if (j != 0 && tabCase[i][j - 1].type != 0) {
                tabCase = CreerArete(tabCase, i, j, i, j - 1, 1);
            }
            if (i != 0 && tabCase[i - 1][j].type != 0) {
                tabCase = CreerArete(tabCase, i, j, i - 1, j, 1);
            }
            if (j != QUADRICOLONNE - 1) {
                if (tabCase[i][j + 1].type != 0) {
                    tabCase = CreerArete(tabCase, i, j, i, j + 1, 1);
                }
            }
            if (i != QUADRILIGNE - 1) {
                if (tabCase[i + 1][j].type != 0) {
                    tabCase = CreerArete(tabCase, i, j, i + 1, j, 1);
                }
            }
            //CalculeConnexe(tabCase, i, j, &nbConnexe);
            CalculeCompteurEtTab(tabCase, i, j, JEU);
        }

    }
    Graphe *Newgraphe = (Graphe *) malloc(sizeof(Graphe));
    Newgraphe->nbConnexe = nbConnexe;
    Newgraphe->tabCase = tabCase;
    return Newgraphe;
}

Graphe *lire_graphe(char *nomFichier, char *nomFichierid, ECECITY *JEU) {
    Graphe *graphe;
    FILE *ifs = fopen(nomFichier, "r+");
    FILE *ifs2 = fopen(nomFichierid, "r+");//r+ pour lecture ET ecriture dans un fichier texte déjà crée
    if (!ifs) {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }

    graphe = CreerGraphe(ifs, ifs2, JEU); // pn creer un graphe de 1444 sommets (38*38)
    return graphe;
}

ECECITY *iniJeu() {
    ECECITY *JEU = malloc((QUADRILIGNE) * sizeof(JEU));
    JEU->tabHab = malloc((QUADRILIGNE*QUADRICOLONNE/9) * sizeof(Habitations));
    JEU->tabE = malloc((QUADRILIGNE*QUADRICOLONNE/24) * sizeof(Usines));
    JEU->tabO = malloc((QUADRILIGNE*QUADRICOLONNE/24) * sizeof(ChateauO));
    JEU->compteur.nbRues = 0;
    JEU->compteur.nbHab = 0;
    JEU->compteur.nbUsines = 0;
    JEU->compteur.nbChateauO = 0;
    Graphe *g = lire_graphe("../map.txt", "../ordreConstruction.txt", JEU); //penser a modifier le nom du txt
    JEU->G = g;

    return JEU;
}

void afficher_successeurs(CASE **sommet, int i, int j) {

    printf("sommet %d:\n", i * 100 + j);

    pArc arc = sommet[i][j].arc;

    while (arc != NULL) {
        printf("%d\t", arc->sommetX * 100 + arc->sommetY);
        arc = arc->arc_suivant;
    }

}

void graphe_afficher(Graphe *graphe) {
    printf("graphe\n");

    printf("QUADRICOLONNE = %d\n", QUADRICOLONNE);

    printf("listes d'adjacence :\n");

    for (int i = 0; i < QUADRICOLONNE; i++) {
        for (int j = 0; j < QUADRILIGNE; j++) {
            afficher_successeurs(graphe->tabCase, i, j);
            printf("\n");
        }
    }

}

int defilement(File F) {
    Cellule cellule;
    int sommet;
    if (F == NULL || F->longueur == 0) printf("File existe pas - defilement");
    cellule = F->tete;
    sommet = cellule->element;
    if (F->longueur == 1) {
        F->tete = F->queue = NULL;
    } else {
        F->tete = F->tete->suivant;
    }
    free(cellule);
    --(F->longueur);
    return (sommet);
}

File CreerFile() {
    File F;
    F = (File) malloc(sizeof(struct _file));
    if (F == NULL) printf("erreur allocation fileVide");
    F->longueur = 0;
    F->tete = F->queue = NULL;
    return (F);
}

void enfiler(File F, int sommet) {
    Cellule cellule;
    if (F == NULL) printf("file existe pas - enfiler");
    cellule = (Cellule) malloc(sizeof(struct _cellule));
    if (cellule == NULL) printf("erreur allocation memoire - enfiler");
    cellule->element = sommet;
    cellule->suivant = NULL;
    if (F->longueur == 0) {
        F->tete = F->queue = cellule;
    } else {
        F->queue->suivant = cellule;
        F->queue = cellule;
    }
    ++(F->longueur);
}

void ecrireFile(File F) {
    Cellule cellule;
    if (F == NULL) printf("erreur ecrireFile");
    for (int i = F->longueur; i > 0; i--) {
        cellule = F->tete;
        for (int j = 0; j < i - 1; j++) {
            cellule = cellule->suivant;
        }
        if (i == 1) {
            printf("%d\t", cellule->element);
        } else {
            printf("%d   <--\t", cellule->element);
        }
    }
    printf("\n");
}

int checkBlanc(Graphe *G, int num) {
    for (int i = 0; i < QUADRICOLONNE; i++) {
        if (G->tabCase[i]->couleur == 0) {
            return i;
        }
    }
    return QUADRICOLONNE + 1;
}

void BFS(Graphe *G, int SommetX, int SommetY, int *compte) {
    *compte = 0;
    File f = CreerFile();
    pArc arc = G->tabCase[SommetX][SommetY].arc;
    G->tabCase[SommetX][SommetY].couleur = 1;
    enfiler(f, SommetX * 100 + SommetY);
    ++(*compte);
    while (f->longueur != 0) {
        while (arc != NULL) {
            if (G->tabCase[arc->sommetX][arc->sommetY].couleur == 0 && G->tabCase[arc->sommetX][arc->sommetY].type >0) {
                enfiler(f, arc->sommetX * 100 + arc->sommetY);
                G->tabCase[arc->sommetX][arc->sommetY].couleur = 1;
                G->tabCase[arc->sommetX][arc->sommetY].predX = arc->sommetX;//a potentiellement changé en SommetX
                G->tabCase[arc->sommetX][arc->sommetY].predY = arc->sommetY;// same
            }
            arc = arc->arc_suivant;
        }
        G->tabCase[SommetX][SommetY].couleur = 2;
        //on récupère
        float num = defilement(f);
        SommetX = num / 100;
        SommetY = num - SommetX;
        arc = G->tabCase[SommetX][SommetY].arc;
    }
}

void afficheBFS(int tab[], int compte, int *c) {

    printf("composante connexe %d QUADRICOLONNE de découverte : \n", *c);
    for (int i = 0; i < compte; i++) {
        printf("%d\t", tab[i]);
    }
    printf("\n");
    (*c)++;
}

void touBlancs(Graphe *G) {
    for (int i = 0; i < QUADRICOLONNE; i++) {
        for (int j = 0; j < QUADRILIGNE; j++) {
            G->tabCase[i][j].couleur = 0;
            G->tabCase[i][j].distance = 0;
        }
    }
}

void CalculDistance(Graphe *G, int SommetX, int SommetY, int con) {
    for (int i = 0; i < QUADRICOLONNE; i++) {
        for (int j = 0; j < QUADRILIGNE; j++) {
            if (G->tabCase[i][j].type >= 5 && G->tabCase[i][j].connexe == con) {
                int tempX = i;
                int tempY = j;
                while (tempX != SommetX && tempY != SommetY) {
                    G->tabCase[i][j].distance++;
                    tempX = G->tabCase[tempX][tempY].predX;
                    tempY = G->tabCase[tempX][tempY].predY;
                }
            }
        }
    }
}

bool checkIdO(int *ordre, int nbHabitationCon, int id){
    for (int i=0; i<nbHabitationCon; i++){
        if(id==ordre[i]){
            return false;
        }
    }
    return true;
}

void triDistance(int *ordre, ECECITY *JEU, int nbHabitationCon) {
    int a = 0;
    while (a != nbHabitationCon) {
        int distancemin = 999;
        int id=0;
        for (int i = 0; i < QUADRICOLONNE; i++) {
            for (int j = 0; j < QUADRILIGNE; j++) {
                if (JEU->G->tabCase[i][j].distance!=0 && JEU->G->tabCase[i][j].distance<distancemin) {
                    distancemin = JEU->G->tabCase[i][j].distance;
                    id = JEU->G->tabCase[i][j].identite;
                }
            }
        }
        if(checkIdO(ordre, nbHabitationCon, id)) {
            ordre[a] = id;
            a++;
        }
    }
}

void repartitionO(ECECITY *JEU, int* ordre, int nbHabitationCon, int id) {
    for(int i =0 ; i<nbHabitationCon; i++){
        if(JEU->tabO[id].QOrestant==0){
            return;
        }
        if (JEU->tabHab[ordre[i]].nbHabitant<JEU->tabO[id].QOrestant){
            JEU->tabHab[ordre[i]].QO=JEU->tabHab[ordre[i]].nbHabitant;
            JEU->tabO[id].QOrestant=JEU->tabO[id].QOrestant-JEU->tabHab[ordre[i]].nbHabitant;
        }
        else if (JEU->tabHab[ordre[i]].nbHabitant==JEU->tabO[id].QOrestant){
            JEU->tabHab[ordre[i]].QO=JEU->tabHab[ordre[i]].nbHabitant;
            JEU->tabO[id].QOrestant=0;
        }
        else {
            JEU->tabHab[ordre[i]].QO=JEU->tabO[id].QOrestant;
            JEU->tabO[id].QOrestant=0;
        }
    }
}

void ECEBFS(int con, int id, ECECITY *JEU, int nbHabitationCon) {
    int compte;
    //chercher dans le graphe le chateau O qu'on évalu et faire le BFS a partir de ce sommet
    int SommetX = 0;
    int SommetY = 0;
    int *ordre = malloc(nbHabitationCon * sizeof(int));

    for (int i = 0; i < QUADRILIGNE; i++) {
        for (int j = 0; j < QUADRICOLONNE; j++) {
            if (JEU->G->tabCase[i][j].type == 3 && JEU->G->tabCase[i][j].identite == id) {
                SommetX = i;
                SommetY = j;
                //on fait le BFS a partir du sommet trouver
                touBlancs(JEU->G);
                BFS(JEU->G, SommetX, SommetY, &compte);
                CalculDistance(JEU->G, SommetX, SommetY, con);
                triDistance(ordre, JEU, nbHabitationCon);
                repartitionO(JEU, ordre, nbHabitationCon, id);
                return;
            }
        }
    }
}

bool checkApproO(int i, ECECITY *JEU) {
    for (int j = 1; j < JEU->compteur.nbHab; ++j) {
        if (JEU->tabHab[j].connexe == i && JEU->tabHab[j].QO == 0) {
            return false;
        }
    }
    return true;
}

void CalculeO(ECECITY *JEU) {
    //On test d'abord si dans une composante connexe on a plus de QO que de nbHabitant
    //on récupére code CalculElec
    for (int i = 1; i < JEU->G->nbConnexe; i++) {
        //Calcul du nombre d'habitant et des ressources en O de la composante connexe
        int QOcon = 0;
        int nbHabitantCon = 0;

        for (int j = 1; j < JEU->compteur.nbChateauO; ++j) {
            if (JEU->tabO[j].connexe == i) {
                QOcon = QOcon + 5000;
            }
        }
        for (int j = 1; j < JEU->compteur.nbHab; ++j) {
            if (JEU->tabHab[j].connexe == i) {
                nbHabitantCon = nbHabitantCon + JEU->tabHab[j].nbHabitant;
            }
        }

        //Cas spéciaux ou on a pas besoin de faire une distribution en BFS car on à + ou = d'O que de nb habitants
        if (QOcon > nbHabitantCon) {
            for (int j = 1; j < JEU->compteur.nbHab; ++j) {
                if (JEU->tabHab[j].connexe == i) {
                    JEU->tabHab[j].QO = JEU->tabHab[j].nbHabitant;
                }
            }
            for (int j = 1; j < JEU->compteur.nbChateauO; ++j) {
                if (JEU->tabO[j].connexe == i) {
                    JEU->tabO[j].QOrestant = 0;
                    QOcon = QOcon - 5000;
                }
            }
        } else if (QOcon == nbHabitantCon) {
            for (int j = 1; j < JEU->compteur.nbHab; ++j) {
                if (JEU->tabHab[j].connexe == i) {
                    JEU->tabHab[j].QO = JEU->tabHab[j].nbHabitant;
                }
            }
            QOcon = 0;
            for (int j = 1; j < JEU->compteur.nbUsines; ++j) {
                if (JEU->tabO[j].connexe == i) {
                    JEU->tabO[j].QOrestant = 0;
                }
            }
        }
            //SINON Pour chaque chateau d'O on fait un BFS
        else {
            bool touApproO = checkApproO(i, JEU);
            for (int j = 1; j < JEU->compteur.nbChateauO; j++) {
                if (JEU->tabO[j].connexe == i) {
                    while (JEU->tabO[j].QOrestant < 0 && !touApproO) {
                        ECEBFS(i, j, JEU, nbHabitantCon);
                        touApproO = checkApproO(i, JEU);
                    }
                }
            }
        }
    }


}

//changer nb connexe

void CalculeElec(ECECITY *JEU) {
    //int QE = JEU->compteur.nbUsines*5000;
    //int QErestant= 0;

    for (int i = 1; i < JEU->G->nbConnexe; i++) {
        int QEcon = 0;
        int nbHabitantCon = 0;

        //P1 on calcule la quantité d'élec disponible dans la composante connexe et son nombre d'habitant.
        for (int j = 1; j < JEU->compteur.nbUsines; ++j) {
            if (JEU->tabE[j].connexe == i) {
                QEcon = QEcon + 5000;
            }
        }
        for (int j = 1; j < JEU->compteur.nbHab; ++j) {
            if (JEU->tabHab[j].connexe == i) {
                nbHabitantCon = nbHabitantCon + JEU->tabHab[j].nbHabitant;
            }
        }

        //P2 on répartie l'elec
        if (QEcon > nbHabitantCon) {
            for (int j = 1; j < JEU->compteur.nbHab; ++j) {
                if (JEU->tabHab[j].connexe == i) {
                    JEU->tabHab[j].QE = JEU->tabHab[j].nbHabitant;
                }
            }
            for (int j = 1; j < JEU->compteur.nbUsines; ++j) {
                if (JEU->tabE[j].connexe == i) {
                    JEU->tabE[j].QErestant = 0;
                    QEcon = QEcon - 5000;
                }
            }
        } else if (QEcon == nbHabitantCon) {
            for (int j = 1; j < JEU->compteur.nbHab; ++j) {
                if (JEU->tabHab[j].connexe == i) {
                    JEU->tabHab[j].QE = JEU->tabHab[j].nbHabitant;
                }
            }
            QEcon = 0;
            for (int j = 1; j < JEU->compteur.nbUsines; ++j) {
                if (JEU->tabE[j].connexe == i) {
                    JEU->tabE[j].QErestant = 0;
                }
            }
        } else {
            int QEcon1 = QEcon;
            for (int j = 1; j < JEU->compteur.nbHab; ++j) {
                if (JEU->tabHab[j].connexe == i && QEcon >= JEU->tabHab[j].nbHabitant) {
                    JEU->tabHab[j].QE = JEU->tabHab[j].nbHabitant;
                    QEcon = QEcon - JEU->tabHab[j].nbHabitant;
                } else if (JEU->tabHab[j].connexe == i && QEcon < JEU->tabHab[j].nbHabitant) {
                    JEU->tabHab[j].QE = 0;
                }
            }
            for (int j = 1; j < JEU->compteur.nbUsines; ++j) {
                if (JEU->tabE[j].connexe == i) {
                    if (QEcon1 > 5000) {
                        JEU->tabE[j].QErestant = 0;
                        QEcon1 = QEcon1 - 5000;
                    } else {
                        JEU->tabE[j].QErestant = 5000 - QEcon1;
                    }
                }
            }
        }
    }
}

void modifGraphe(VECTEUR *mouseIso, CASE **tabCase){
    //A faire
    //mettre absolument la nouvelles constru en connexe 0
}
void eraseSupp(ECECITY* JEU, int erase){
    for(int i=1; i<175; i++){
        if(JEU->tabHab[i].connexe>erase){
            JEU->tabHab[i].connexe--;
        }
    }for(int i=1; i<(QUADRILIGNE*QUADRICOLONNE/24); i++){
        if(JEU->tabE[i].connexe>erase){
            JEU->tabE[i].connexe--;
        }
        if(JEU->tabO[i].connexe>erase){
            JEU->tabO[i].connexe--;
        }
    }
}

void modifConnexe(ECECITY* JEU, int X, int Y, int categorieConstruction, int rotation){
    pArc temp = JEU->G->tabCase[X][Y].arc;
    if (categorieConstruction==0) {
        while (temp != NULL) {
            if (JEU->G->tabCase[temp->sommetX][temp->sommetY].type == 1 && JEU->G->tabCase[X][Y].connexe == 0) {
                JEU->G->tabCase[X][Y].connexe = JEU->G->tabCase[temp->sommetX][temp->sommetY].connexe;
            }
            else if(JEU->G->tabCase[temp->sommetX][temp->sommetY].type == 1 && JEU->G->tabCase[temp->sommetX][temp->sommetY]
            .connexe >0 && JEU->G->tabCase[X][Y].connexe!=JEU->G->tabCase[temp->sommetX][temp->sommetY].connexe){
                if(JEU->G->tabCase[X][Y].connexe > JEU->G->tabCase[temp->sommetX][temp->sommetY].connexe){
                    int erase=JEU->G->tabCase[X][Y].connexe;
                    eraseSupp(JEU, erase);
                }
                if(JEU->G->tabCase[X][Y].connexe < JEU->G->tabCase[temp->sommetX][temp->sommetY].connexe){
                    int erase=JEU->G->tabCase[temp->sommetX][temp->sommetY].connexe;
                    eraseSupp(JEU, erase);
                }
            }
            temp = temp->arc_suivant;
        }
        JEU->G->tabCase[X][Y].connexe=JEU->G->nbConnexe;
        JEU->G->nbConnexe++;
    }
    if(categorieConstruction==1) {
        for (int i = 0; i < LONGUEURE_TERRAIN_VAGUE; i++) {
            for (int j = 0; j < LARGEUR_TERRAIN_VAGUE; j++) {
                if(i==0 || i==LONGUEURE_TERRAIN_VAGUE || j==0 || j==LARGEUR_TERRAIN_VAGUE) {
                    while (temp != NULL) {
                        if (JEU->G->tabCase[temp->sommetX][temp->sommetY].type == 1 && JEU->G->tabCase[X][Y].connexe == 0) {
                            for (int a = 0; a < LONGUEURE_TERRAIN_VAGUE; a++) {
                                for (int b = 0; b < LARGEUR_TERRAIN_VAGUE; b++) {
                                    JEU->G->tabCase[X + a][Y + b].connexe = JEU->G->tabCase[temp->sommetX][temp->sommetY].connexe;
                                }
                            }
                            return;
                        }
                        temp = temp->arc_suivant;
                    }
                    temp = JEU->G->tabCase[X][Y].arc;
                }
            }
        }
        for (int a = 0; a < LONGUEURE_TERRAIN_VAGUE; a++) {
            for (int b = 0; b < LARGEUR_TERRAIN_VAGUE; b++) {
                JEU->G->tabCase[X + a][Y + b].connexe = JEU->G->nbConnexe;
            }
        }
        JEU->G->nbConnexe++;
    }
    if(categorieConstruction==2 ||categorieConstruction==3) {
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
        for (int i = 0; i < longueureBatX; i++) {
            for (int j = 0; j < longueureBatY; j++) {
                if(i==0 || i==longueureBatX || j==0 || j==longueureBatY) {
                    while (temp != NULL) {
                        if (JEU->G->tabCase[temp->sommetX][temp->sommetY].type == 1 && JEU->G->tabCase[X][Y].connexe == 0) {
                            for (int a = 0; a < longueureBatX; a++) {
                                for (int b = 0; b < longueureBatY; b++) {
                                    JEU->G->tabCase[X + a][Y + b].connexe = JEU->G->tabCase[temp->sommetX][temp->sommetY].connexe;
                                }
                            }
                            return;
                        }
                        temp = temp->arc_suivant;
                    }
                    temp = JEU->G->tabCase[X][Y].arc;
                }
            }
        }
        for (int a = 0; a < LONGUEURE_TERRAIN_VAGUE; a++) {
            for (int b = 0; b < LARGEUR_TERRAIN_VAGUE; b++) {
                JEU->G->tabCase[X + a][Y + b].connexe = JEU->G->nbConnexe;
            }
        }
        JEU->G->nbConnexe++;
    }

}
/*
int minimain() {
    printf("DEBUG 0\n");
    fflush(stdout);
    ECECITY *JEU = iniJeu();

    //int nbHabitant=300;
    CalculeElec(JEU);
    CalculeO(JEU);
    return 0;
}*/

