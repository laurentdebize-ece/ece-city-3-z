//
// Created by Utilisateur on 01/11/2022.
//
#include "bibliotheque.h"
void payerTaxebanque(int * compteEnBanque, int NbrHabitant, int compteur){
    if (compteur %15==0){
        compteEnBanque = compteEnBanque + NbrHabitant * TAXE;
    }
}

void payerBanque(BATIMENT batiment);

