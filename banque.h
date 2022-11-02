

#ifndef ECE_CITY_3_Z_BANQUE_H
#define ECE_CITY_3_Z_BANQUE_H

typedef struct{
    int coutTV, coutCentrale, coutC_D_E, coutRoute, coutCaserne;
}BANQUE;

typedef struct{
    int terrain_vague, cabane, maison, immeuble, gratteciel;
    int centrale, chateau_deau, route;
    int etat;
    BANQUE cout;
}BATIMENT;


void payerTaxebanque(int * compteEnBanque, int NbrHabitant, int compteur);

#endif //ECE_CITY_3_Z_BANQUE_H
