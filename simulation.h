#ifndef SIMULATION_H_INCLUDED
#define SIMULATION_H_INCLUDED
#include"Date.h"
#include"PrixJournalier.h"
#include<vector>
#include"PersistancePrixJournaliers.h"
#include"Bourse.h"
#include"BourseVector.h"
#include"Trader.h"
#include"TraderAleatoire.h"

class Simulation
{
private:
    Date dateDebut, dateFin, dateCourante;
    double Montant;
public:
    Simulation(Date d1,Date d2,double Mnt)
    {
        dateDebut=d1;
        dateFin=d2;
        dateCourante=getDateAujourdhui();
        Montant=Mnt;

    }
    void executer(Bourse& bourse, Trader& trader, Date dateDebut, Date dateFin, double solde)
    {


    }
};



#endif // SIMULATION_H_INCLUDED
