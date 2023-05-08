#ifndef BOURSEVECTOR_H_INCLUDED
#define BOURSEVECTOR_H_INCLUDED
#include"Date.h"
#include"PrixJournalier.h"
#include<vector>
#include"PersistancePrixJournaliers.h"
#include"Bourse.h"

using namespace std;

class BourseVector: public Bourse
{
private:
    vector<PrixJournalier> historique;
public:
    BourseVector(const vector<PrixJournalier>& VPJ, Date d):Bourse(d)
    {
        historique=VPJ;
    }
    vector<PrixJournalier> getPrixJournaliersParDate(Date& d)  override
    {
        if (getDateAujourdhui()<d)
        {
            vector<PrixJournalier> Vide;
            return Vide;
        }
        else
        {
            vector<PrixJournalier> PrixJ;
            for ( auto& pj : historique)
                {
                if (pj.getDate()== d)
                    PrixJ.push_back(pj);
                }
            return PrixJ;
        }
    }
    vector<string> getActionsDisponiblesParDate(Date d)  override
    {
        if (getDateAujourdhui()<d)
            {
            vector<string> Vid;
            return Vid;
            }
        else
        {
          vector<string> ActDispos ;
          for (auto& pj:historique)
           {
            if (pj.getDate()==d)
            ActDispos.push_back(pj.getNomAction());
        }
       return ActDispos;
       }
    }
    vector<string> getActionsDisponiblesAuj()
    {
        getActionsDisponiblesParDate(getDateAujourdhui());
    }
    vector<PrixJournalier> getPrixJournaliersAuj()
    {
        getPrixJournaliersParDate(&getDateAujourdhui());
    }
};

#endif
