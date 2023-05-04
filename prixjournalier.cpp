#include <iostream>
#include <fstream>
#include <string>
#include "date.h"

using namespace std;


class PrixJournalier
{
private :
     string nomAction;
     Date date;
     float prix;
     friend istream& operator >>(istream& in,const PrixJournalier& p);
     friend ostream& operator<<(ostream& os, const PrixJournalier& p);
public:
    string getNomAction(){return nomAction;}
    Date getDate(){return date;}
    int getPrix(){return prix;}
    PrixJournalier(string na, Date d ,float p)
    {
      nomAction=na;
      date=d;
      prix=p;
    }

};
istream& operator >>(istream& in,PrixJournalier p)
{   PrixJournalier &tab[255];

    in.getline (tab,10);
    P.date=atoi(tab);
    in.getline(tab,)
    p.nomAction=atoi(tab);
    in.getline (tab,);
    p.prix=atoi(tab);


    return in;

}
ostream& operator<<(ostream& os, const PrixJournalier& p)
{
        os << p.date << " " << p.nomAction << " " << p.prix << ;
        return os;
}


int main()
{
    PrixJournalier p("fiat","5/6/2010",123456.8);
    ifstream fiche{"prices_simple.csv"};

    cin>>p;
    cout<<"hi";
    return 0;
}
