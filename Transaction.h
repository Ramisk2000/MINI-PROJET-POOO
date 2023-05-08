#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED
#include"Date.h"
#include"PrixJournalier.h"
#include<vector>
#include"PersistancePrixJournaliers.h"
#include"Bourse.h"
#include"BourseVector.h"

enum TypeTx {RIEN,ACHAT,VENTE};

class Transaction
{
private:
    string nomActionn;
    int quantite;
    TypeTx typetrans;
public:
    Transaction (string nA,int qte,TypeTx t)
    {
        nomActionn=nA;
        quantite=qte;
        typetrans=t;
    }


};



#endif // TRANSACTION_H_INCLUDED
