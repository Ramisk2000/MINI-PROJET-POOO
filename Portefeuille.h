#ifndef PORTEFEUILLE_H_INCLUDED
#define PORTEFEUILLE_H_INCLUDED
#include"Date.h"
#include"PrixJournalier.h"
#include<vector>
#include"PersistancePrixJournaliers.h"
#include"Bourse.h"
#include"BourseVector.h"
#include"Trader.h"
#include"TraderAleatoire.h"

using namespace std;

class Portefeuille
{
private:
    double Montant;
public:
    Portefeuille(double Mt){Montant=Mt;}
    double getMontant(){return Montant;}
    void ajouterTitre(Titre t);
    void retirerTitre(Titre t);
    void deposerMontant(double mnt);
    void retirerMontant(double mnt);

};


#endif // PORTEFEUILLE_H_INCLUDED
