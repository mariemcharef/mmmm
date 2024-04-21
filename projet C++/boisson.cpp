#include <iostream>
#include <string>
#include"boisson.h"
using namespace std;
boisson:: boisson ( int IdB ,string nomb,float prixb,int stock)
{   this->IdB=IdB ;
    this->nomb=nomb;
    this->prixb=prixb;
    this->stock=stock;
}
void boisson ::saisir()
{   cout<<"donner lID    : ";
    cin>>IdB;
    cout<<"\n";
    cout<<"donner le nom : ";
    cin>>nomb;
    cout<<"\n";
    cout<<"donner le prix :";
    cin>>prixb;
    cout<<"\n";
    cout<<"donner la quantite en stock  :";
    cin>>stock;
}
void boisson::afficher_boisson()
{ cout<<"ID    : "<<IdB<<endl;
  cout<<" Nom  : "<<nomb<<endl;
  cout<<"Prix  : "<<prixb<<endl;
  cout<<"Stock : "<<stock<<endl;
}
ostream& operator<<(ostream&o,boisson&b)
{   o<<"ID    : "<<b.IdB<<endl;
    o<<"Nom   : "<<b.nomb<<endl;
    o<<"Prix  : "<<b.prixb<<endl;
    o<<"Stock : "<<b.stock<<endl;
    return o;
}
istream& operator>>(istream&in,boisson&b)
 {  cout<<"donner lID     : ";
    in>>b.IdB;
    cout<<"\n";
    cout<<"donner le nom : ";
    in>>b.nomb;
    cout<<"\n";
    cout<<"donner le prix :";
    in>>b.prixb;
    cout<<"\n";
    cout<<"donner la quantite en stock  :";
    in>>b.stock;
    return in;
}
float boisson::total_boisson() //calcul le prix total des boissons
{
    float prix_tot;
    prix_tot=prixb*stock;
    return prix_tot;
}
