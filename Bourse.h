#ifndef BOURSE_H_INCLUDED
#define BOURSE_H_INCLUDED
#include"Date.h"
#include"PrixJournalier.h"
#include<vector>
#include"PersistancePrixJournaliers.h"

using namespace std;

class Bourse {
protected:
    Date DateAujourdhui ;
public:
    Date getDateAujourdhui(){return DateAujourdhui;}
    virtual vector<string> getActionsDisponiblesParDate(Date d)=0;
    virtual vector<PrixJournalier> getPrixJournaliersParDate(Date& d)=0;
    virtual vector<string> getActionsDisponiblesAuj()=0;
    virtual vector<PrixJournalier> getPrixJournaliersAuj()=0;


#endif // BOURSE_H_INCLUDED
