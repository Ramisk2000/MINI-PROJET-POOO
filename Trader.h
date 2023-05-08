#ifndef TRADER_H_INCLUDED
#define TRADER_H_INCLUDED
#include"Date.h"
#include"PrixJournalier.h"
#include<vector>
#include"PersistancePrixJournaliers.h"
#include"Bourse.h"
#include"BourseVector.h"
#include"Transaction.h"

class Trader
{
private:
    string nomTrader;
public:
    string getnomTrader(){return nomTrader;}
    Trader(string nom)
    {
        nomTrader=nom;
    }
    virtual Transaction prendreDecision(const Bourse& bourse,const Portefeuille &portefeuille)=0;

};

#endif // TRADER_H_INCLUDED
