#ifndef Date_H_INCLUDED
#define Date_H_INCLUDED
#include <iostream>
#include<iomanip>
#include<fstream>
using namespace std;

class Date
{
private :
    int jour , mois, annee ;

    public :
    friend ostream& operator<<(ostream& out,Date d);
    friend istream& operator>>(istream& in,Date d);

    Date(int jj, int mm, int aaaa)
    {
        jour = jj;
        mois = mm;
        annee = aaaa;

    }
    bool dateValide()const
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

    int getJour()const{return jour;}
    int getMois()const{return mois ;}
    int getAnnee()const{return annee;}
    void incremDate();
    bool bissextile() const {
        return (annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0);
    }
   int nbjours () const {
     switch (mois) {
     case 2 :
     return bissextile()? 29 : 28;
     case 4: case 6: case 8: case 10:
     return 30;
     default:
     return 31;
        }
}
};

ostream& operator<<(ostream& out,Date d)
    {
       out<<setw(2)<<setfill('0')<<d.getJour()<<'/'<<setw(2)<<setfill('0') <<d.getMois()<<'/'<<d.getAnnee()<<endl;
       return out;
    }
istream& operator >>(istream& in,Date d)
{
    /*char tab[100];
    in.getline (tab,2,'/');
    d.jour=atoi(tab);
    in.getline (tab,2,'/');
    d.mois=atoi(tab);
    in.getline (tab,4);
    d.annee=atoi(tab);*/
    ifstream fichier("prices_simple.csv");
    while (getline(fichier,d,'/'))
    {

    }

    return in;
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



int main()

{   Date d(3,5,2004);
    cin>>d;
    if (d.dateValide())
     {
    int j=d.getJour();
    cout<<j<<endl;
    int m=d.getMois();
    cout<<m<<endl;
    int a=d.getAnnee();
    cout<<a<<endl;
    d.incremDate();
    cout<<d;
     }
    else
        cout <<"date est invalide"<<endl;


    return 0;
}'
#endif
