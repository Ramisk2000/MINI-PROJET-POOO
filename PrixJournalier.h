#ifndef PrixJournalier_H_INCLUDED
#define PrixJournalier_H_INCLUDED
#include <iostream>
#include "Date.h"
#include <stdlib.h>


using namespace std;

class PrixJournalier
{
private :
     string nomAction;
     Date date;
     double prix;

public:
    friend istream& operator>>(istream& in, PrixJournalier& prix);
    string getNomAction(){return nomAction;}
    Date getDate(){return date;}
    double getPrix(){return prix;}
    PrixJournalier() {};
    PrixJournalier (string na, const Date d ,double p):date(d)
    {
      nomAction=na;
      prix=p;
    }

};
istream& operator>>(istream& in, PrixJournalier& p)
{
    char tab[100];
    in.getline(tab, 100, ';');
    p.nomAction= atoi(tab);
    in.getline(tab, 100, '/');
    int jour = atoi(tab);
    in.getline(tab, 100, '/');
    int mois = atoi(tab);
    in.getline(tab, 100, ';');
    int annee = atoi(tab);
    Date d(jour,mois,annee);
    p.date=d;
    in.getline(tab, 100, ';');
    p.prix = atoi(tab);
    return in;
}

#endif
