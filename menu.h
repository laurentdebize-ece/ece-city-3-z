//
// Created by Ilayda Kocer on 04/11/2022.
//

#ifndef ECE_CITY_3_Z_MENU_H
#define ECE_CITY_3_Z_MENU_H


#include <stdio.h>

#include <time.h>


///Déclaration importantes

enum gameMode {PLAY, RULES, TEAM, MENU, END};

#define PI 3.141592
#define RULESPAGEMAX 10

///STRUCTURE QU'ON PEUT METTRE EN PARAMETRES DE FONCTION POUR EVITER TROP DE PARAMETRES
typedef struct {
    int mouse_x, mouse_y ;
    double height, width ;
} InfoEcran;






#endif //ECE_CITY_3_Z_MENU_H
