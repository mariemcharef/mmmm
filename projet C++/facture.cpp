
#include "facture.h"
#include<string>
#include <iostream>
#include<vector>
#include<typeinfo>

using namespace std;
facture::facture(int id )
{
    this->id=id;

}
void facture::saisir()
{
    cout<<"donner lid  :";
    cin>>id;
    for (unsigned int i=0 ; i<tab.size(); i++)
     {
         tab[i]->saisir();
     }

}
facture::~facture()
{
  for(unsigned int i=0;i<tab.size();i++)
  {
      delete tab[i];
  }
}
facture::facture(const facture&f )
{
    id=f.id;
    tarif *t ;
    for(unsigned int i=0;i<f.tab.size();i++)
    {
        if(typeid(*f.tab[i])==typeid(tarif))
        {
            t=new tarif(*f.tab[i]);
        }
        else if (typeid(*f.tab[i])==typeid(tarifservice))
        {
            t=new tarifservice(static_cast<const tarifservice&>(*f.tab[i]));
        }
        else if (typeid(*f.tab[i])==typeid(tarifboisson))
        {
            t=new tarifboisson(static_cast<const tarifboisson&>(*f.tab[i]));
        }

    tab.push_back(t);
      }
}

facture& facture ::operator=(const facture & A)
{
tarif *t;
    if (this != &A)
    {
        for (unsigned int i=0;i<tab.size();i++)
            {
                    delete tab[i];
                }
    tab.clear();
    for (unsigned int i=0;i<A.tab.size();i++)
       {
        if (typeid(*A.tab[i])==typeid(tarif))
            {
            t=new tarif (*A.tab[i]);
            }
        else if(typeid(*A.tab[i])==typeid(tarifservice))
            {
            t=new tarifservice(static_cast<const tarifservice&>(*A.tab[i]));
            }
    else if(typeid(*A.tab[i])==typeid(tarifboisson))
            {
            t=new tarifboisson(static_cast<const tarifboisson &>(*A.tab[i]));
            }
        tab.push_back(t);
       }
    }
       return *this;
}

void facture :: afficher()
{ cout<<"l'identifiant de la facture : " << id <<endl;
for( int i=0 ; i< tab.size();i++)
  {
      cout<<"tarif n : "<<i+1<<endl;
      tab[i]->afficher();
      cout<<"\n" ;
  }
}

void facture ::ajouter_tarif(tarif&t)
{
tarif *tar ;
if (typeid(t)==typeid(tarif))
{
    tar=new tarif(t);
}
else if (typeid(t)==typeid(tarifboisson))
{
    tar=new tarifboisson(static_cast<const tarifboisson&>(t));

}
else if (typeid (t)==typeid(tarifservice))
{
    tar=new tarifservice(static_cast <const tarifservice&>(t));

}
tab.push_back(&t);
}

int facture ::rechercher(int code )
{  int a=-1;
    for (unsigned int i=0;i<tab.size();i++ )
    {
        if(tab[i]->get_code()==code)
        {   cout<<"le code existe \n ";
            a=i;
        }
    }
return a ;

}

void facture::supprimer(int code)
{
   if (rechercher(code)!=-1)
   {    cout<<"le compte existe \n";
       tab.erase(tab.begin()+rechercher(code));


   }
}
ostream& operator<<(ostream&o,facture& f)
{
  o<< "Facture ID: " << f.id << endl;
   for (int  i = 0; i < f.tab.size(); i++)
    {    o << "Tarif " << i + 1 << ": " <<endl;
         if (typeid (*f.tab[i])==typeid(tarif))
         {
             o<<*f.tab[i]<<endl;
         }
         else if (typeid(*f.tab[i])==typeid(tarifboisson))
         {
             o<< static_cast< tarifboisson&>(*f.tab[i])<<endl;
         }
         else if (typeid(*f.tab[i])==typeid(tarifservice))
        {
            o<<static_cast< tarifservice &>(*f.tab[i])<<endl;
         }
    }

    return o;
}
istream& operator>>(istream&i,facture&f)
{
cout<<"entrer l'identifiant de facture \n"<<endl;
i>>f.id;
char rep ;
int choix;
do{
cout <<"entrer un choix :  1-tarif   2-tarif boisson   3-tarif service";
cin>>choix ;
switch (choix){
case 1:
{
  tarif*t=new tarif ();
  i>>*t;
  f.tab.push_back(t);
  break;
}
case 2:

{
tarifboisson*tb=new tarifboisson();
i>>*tb;
f.tab.push_back(tb);
 break;
}
case 3:
{
    tarifservice*ts=new tarifservice();
    i>>*ts;
    f.tab.push_back(ts);
     break;
}
default:
cout << "choix invalide reessayer  : ";
}
    cout <<"ajouter un autre tarif tapez (o/n)";
    cout<<"\n";
    cin>>rep;
}
while(rep=='o'|| rep=='O');
return i;

}
float facture::calculer_montant()
{   promotion p;
    float x;
    float montanti ,montantf ;
    cout<<"donner le pourcentage de la promotion entre [0,1]  : ";
    cin>>x;
    p.set_promotion(x);
    for (int  i = 0; i < tab.size(); i++)
    {
        montanti=tab[i]->get_montant();
    }
    montantf=montanti*(1-p.get_promotion());

    cout<<"montant apres la promotion "<<endl;
    return montantf;
   }

//partie fichier
