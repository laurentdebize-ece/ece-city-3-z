//
// Created by Théophile Dutrey on 12/11/2022.
//

#include "bibliotheque.h"

void coordSourisIso (VECTEUR* mouseIso, Image image){
    VECTEUR mouseCartesien;

    mouseCartesien.x = GetMouseX()/LARGEUR_TUILE_ISO;
    mouseCartesien.y = GetMouseY()/HAUTEUR_TUILE_ISO;
    mouseIso->x = (mouseCartesien.x-ISO_DECALAGE_X) + (mouseCartesien.y-ISO_DECALAGE_Y) ;
    mouseIso->y = (mouseCartesien.x-ISO_DECALAGE_X) - (mouseCartesien.y-ISO_DECALAGE_Y) ;

    int couleurX = GetMouseX() % LARGEUR_TUILE_ISO;
    int couleurY = GetMouseY() % HAUTEUR_TUILE_ISO;

    Color color = GetImageColor(image, couleurX, couleurY);


    if (color.r && !color.g && !color.b) {

        mouseIso->x -= 1;
    } else if (!color.r && color.g && !color.b) {

        mouseIso->y -= 1;
    } else if (color.r && color.g && !color.b) {

        mouseIso->x += 1;
    } else if (!color.r && !color.g && color.b) {

        mouseIso->y += 1;
    }
}
