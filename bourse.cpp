#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "PersistancePrixJournaliers.h"
#include "date.h"


using namespace std;


class BourseVector {
public:
    BourseVector(vector<PrixJournalier>& pj)
    {
        for (PrixJournalier& p : pj)
        {
            historique.push_back(p);
        }
    }


private:
   vector<PrixJournalier> historique;
};

int main()
    ifstream fichier("prices_simple.csv");
    vector<PrixJournalier> prixJourn;
    string ligne;
    while (getline(fichier, ligne)) {
        istringstream iss(ligne);
        string dates, prixs;
        iss >> dates >> prixs;
        Date date = Date::parse_date(dates);
        double prix = stod(prixs);
        PrixJournalier pj(date, prix);
        prixJourn.push_back(pj);
    }
