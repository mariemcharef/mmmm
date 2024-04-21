#include "tarifboisson.h"
#include"boisson.h"
#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

void tarifboisson::afficher()
{   tarif::afficher();
    int i=1;
    list<boisson>::iterator it;
    for (it = l.begin(); it != l.end(); ++it)
    {
        cout<<"boisson  "<<i<<endl;
        it->afficher_boisson();
        i+=1;
    }
}
void tarifboisson::supprimer(int id)
{   list<boisson>::iterator it;
    for (it = l.begin(); it != l.end(); ++it)
        {
        if (it->get_IdB() == id)
        {   cout<<"le boisson existe "<<endl;
            l.erase(it);
            break;
        }
    }
}
void tarifboisson::ajouter(boisson* b)
{   list<boisson>::iterator it;
    for (it = l.begin(); it != l.end(); ++it)
        {
        if (it->get_IdB() == b->get_IdB())
        {   cout<<"le boisson existe deja "<<endl;
        }
        }
    l.push_back(*b);
}

ostream& operator<<(ostream& o, tarifboisson& tarb)
{
    o << static_cast<tarif&>(tarb);
    list<boisson> ::iterator it;
    for(it=tarb.l.begin();it!=tarb.l.end();it++)
    {
        o<<*(it)<<endl;
    }

        return o;
}
istream& operator>>(istream& i, tarifboisson& tarb)
 {

    i >> static_cast<tarif&>(tarb);
   list <boisson> l;

    char rep ;
    do {
        boisson b;
        cout<<"saisir boisson"<<endl;
        i>>b;
        tarb.l.push_front(b);
        cout<<"voulez vous ajouter un autre boisson  ? (o/n)?"<<endl;
        i>>rep;

    } while(rep=='o'||rep=='O');

    return i;
    }



float tarifboisson::boisson_plus_cher()
{
        float prix_max=0.0;
        list<boisson>::iterator it;
        for(it=l.begin();it!=l.end();it++)
     {
         if (it->get_prixb()>prix_max)
         {
             prix_max=it->get_prixb();
         }
    }

     cout<<"le boisson le plus cher ";
     return prix_max ;
}

void tarifboisson::modifier_prix(int ID)
{   char choix ;
    float  nprix;
   cout <<"le changement de tarif boisson \n";
   cout <<"voulez vous vraiment changer  le prix?(o/n)\n";
   cin>>choix;
   if (choix=='o')
   {
        tarif::modifier();
        list<boisson>::iterator it;
        for(it=l.begin();it!=l.end();it++)
        { if(it->get_IdB()==ID)
        {
            cout<<"donner le nouveau prix  : "<<endl;
            cin>>nprix;
            it->set_prixb(nprix);
        }

        }
}
}
void tarifboisson ::rechercher_boisson(string nom)
{
    list<boisson>::iterator it;
    for(it=l.begin();it!=l.end();it++)
        { if(it->get_nomb()==nom)
            {   cout<<"le service existe \n ";
                it->afficher_boisson();
                break;
            }

        }
}

void tarifboisson::modifier_stock(int id)
{   char choix ;
    int nstock;
   cout <<"le changement de tarif boisson \n";
   cout <<"voulez vous changer la quantite en stock?(o/n)\n";
   cin>>choix;
   if (choix=='o')
   {
        tarif::modifier();
       list<boisson>::iterator it;
        for(it=l.begin();it!=l.end();it++)
        { if(it->get_IdB()==id)
            {
            cout<<"donner la nouvelle quantite: "<<endl;
            cin>>nstock;
            it->set_stock(nstock);
            }

        }
    }

}
double tarifboisson::calculer_prix()
{   double prix_total;
    list<boisson>::iterator it;
    for(it=l.begin();it!=l.end();it++)
    {
        prix_total+=it->total_boisson();
    }
    cout<<"le prix total   : "<<endl;
    return  prix_total;
}

