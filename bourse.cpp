#ifndef BOURSEVECTOR_H_INCLUDED
#define BOURSEVECTOR_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "PersistancePrixJournaliers.h"
#include "date.h"
#include "prixJournaliers"


using namespace std;


class BourseVector
{
private:
     vector<PrixJournalier> prixJournaliers;
public:
    BourseVector(const  string& fichier) {
         ifstream f(fichier);
         string nom;
        int jj, mm , aaaa;
        double prix;
        while (f >> nom >> jj >> mm >> aaaa >> prix)
        {
            PrixJournalier pj(nom, Date(j, m, a), prix);
            prixJournaliers.push_back(pj);
        }
         sort(prixJournaliers.begin(), prixJournaliers.end(), [](const PrixJournalier& pj1, const PrixJournalier& pj2) {
            return pj1.getDate() < pj2.getDate();
        });
    }

     vector< string> getActionsDisponiblesParDate(const Date& d) const {
         vector< string> actions;
        for (const auto& pj : prixJournaliers) {
            if (pj.getDate() == d) {
                actions.push_back(pj.getNom());
            }
        }
        return actions;
    }

     vector<PrixJournalier> getPrixJournaliersParDate(const Date& d) const {
         vector<PrixJournalier> prixJournaux;
        for (const auto& pj : prixJournaliers) {
            if (pj.getDate() == d) {
                prixJournaux.push_back(pj);
            }
        }
        return prixJournaux;
    }


};


#endif // BOURSEVECTOR_H_INCLUDED
