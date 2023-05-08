#ifndef Date_H_INCLUDED
#define Date_H_INCLUDED
#include <iostream>
#include<iomanip>
#include <stdlib.h>

using namespace std;

class Date
{
private :
  int jour , mois, annee ;
public :
    friend ostream& operator<<(ostream& out,Date d);
    friend istream& operator>>(istream& in, Date& d);
    friend bool operator<(Date &d1,Date &d2);
    friend bool operator==(Date &d1,Date &d2);
    int getJour()const{return jour;}
    int getMois()const{return mois ;}
    int getAnnee()const{return annee;}
    bool dateValide()const;
    bool bissextile() const;
    void incremDate();
    int nbjours () const ;
    Date& operator=(const Date& d)
    {
        jour = d.jour;
        mois = d.mois;
        annee = d.annee;
         return *this ;
    }

    Date(int jj, int mm, int aaaa)
    {
        jour = jj;
        mois = mm;
        annee = aaaa;
    }
    Date(){};
};

    bool Date::dateValide()const
    {
        if ((jour<=0) || (jour> nbjours()))
        {
            cout<<"jour invalide ! "<<endl;
            return false;
        }
        else
          {
            if ((mois<=0) || (mois>12))
            {
               cout<<"mois invalide ! "<<endl;
               return false;
             }
            else
            {
             if ((annee<=0)|| (annee >2023))
              {
                cout<<"annee invalide ! "<<endl;
                return false ;
              }
              else
                return true;
            }
          }
    }

    bool Date::bissextile() const {
        return (annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0);
    }
     int Date::nbjours () const {
     switch (mois) {
     case 2 :
     return bissextile()? 29 : 28;
     case 4: case 6: case 9: case 11:
     return 30;
     default:
     return 31;
        }
}
istream& operator>>(istream& in, Date& d)
{
    char tab[100];
    in.getline(tab, 100, '/');
    d.jour = atoi(tab);
    in.getline(tab, 100, '/');
    d.mois = atoi(tab);
    in.getline(tab, 100, ';');
    d.annee = atoi(tab);
    return in;
}


ostream& operator<<(ostream& out,Date d)
    {
       out<<setw(2)<<setfill('0')<<d.getJour()<<'/'<<setw(2)<<setfill('0') <<d.getMois()<<'/'<<d.getAnnee()<<endl;
       return out;
    }
bool operator<(Date &d1,Date &d2)
{
    if (d1.getAnnee()<d2.getAnnee())
        return true;
    else if (d1.getAnnee()==d2.getAnnee()&&(d1.getMois()<d2.getMois()))
           return true;
             else if ((d1.getAnnee()==d2.getAnnee())&&(d1.getMois()==d2.getMois())&&(d1.getJour()<d2.getJour()))
               return true;
                else
                return false;
}

bool operator==(Date &d1,Date &d2)
{
      if ((d1.getJour()==d2.getJour())&&(d1.getMois()==d2.getMois())&&(d1.getAnnee()==d2.getAnnee()))
        return true;
    else
        return false;

}

void Date::incremDate()
{
    if (jour<nbjours())
    {
        jour++;
    }
    else
    {
      if (((jour== nbjours())&& (mois<12)))
      {
          jour=1;
          mois++;
      }
      else
       {
        jour=1;
        mois=1;
        annee++;
       }
    }
}

#endif
