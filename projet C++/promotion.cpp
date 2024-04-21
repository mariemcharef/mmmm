#include "promotion.h"
#include <iostream>
using namespace std;

promotion::promotion(float pourcentage,int idp)
{
    this->pourcentage=pourcentage;
    this->idp=idp;

}
void promotion::set_promotion(float p)
{
    pourcentage=p ;
}
float promotion::get_promotion()
{
    return pourcentage ;
}
void promotion::afficher()
{   cout<<"******la promotion *********\n";
    cout<<"l'id :     "<<idp<<"\n";
    cout<<"le pourcentage  :   "<<pourcentage<<"\n";
}
ostream& operator<<(ostream&o,promotion&p)
{   o<<"identifiant :";
    o<<p.idp;
    cout<<"\n";
    o<<"pourcentage ";
    o<<p.pourcentage;
    cout<<"\n";
    return o ;
}
istream& operator>>(istream&i,promotion&p)
{    cout<<"saisir l'dentifiant :   "<<endl;
    i>>p.idp;
    cout<<"saisir le pourcentage de la remise"<<endl;
    i>>p.pourcentage;
    return i;
}
ostream& operator<<(ostream&o,promotion*p)
{
    o<<p->pourcentage;
    cout<<"\n";
    o<<p->idp;
    return o ;
}
istream& operator>>(istream&i,promotion*p)
{    cout<<"saisir l'dentifiant :   "<<endl;
    i>>p->idp;
    cout<<"saisir le pourcentage de la remise"<<endl;
    i>>p->pourcentage;
    return i;
}
