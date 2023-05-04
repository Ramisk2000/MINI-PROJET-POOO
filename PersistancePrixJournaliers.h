#define PERSISTANCEPRIXJOURNALIERS_H_INCLUDED
#include<iostream>
#include<vector>
#include<fstream>
#include "prixjournaliers.h"
using namespace std;

class PersistancePrixJournaliers
{
    public:
            static vector<PrixJournalier> lirePrixJournaliersDUnFichier(string chemin)
            {
            vector<PrixJournalier> historique;
            ifstream f(chemin);
            int nbLignes= 0;
            string entete;
            if(f.is_open())
            {
                f>>entete;
                while(!f.eof())
                {
                    PrixJournalier pj;
                    f>>(pj);
                    historique.push_back(pj);
                    nbLignes++;
                }
            }
            return historique;
        }
};


#endif // PERSISTANCEPRIXJOURNALIERS_H_INCLUDED
