#include <iostream>
#include <string>
#include"service.h"
using namespace std;
service::service (int IdS ,string noms,float prixs,int duree)
{
    this->noms=noms;
    this->prixs=prixs;
    this->duree=duree;
    this->IdS=IdS;
}
service::~service()
{
}
void service ::saisir()
{   cout<<"donner lId  : ";
    cin>>IdS;
    cout<<"\n";
    cout<<"donner le nom : ";
    cin>>noms;
    cout<<"\n";
    cout<<"donner le prix :";
    cin>>prixs;
    cout<<"\n";
    cout<<"donner la duree en minute  :";
    cin>>duree;
}
void service::afficher_service()
{ cout<<"IDService: "<<IdS<<endl;
  cout<<" Nom     : "<<noms<<endl;
  cout<<"Prix     : "<<prixs<<endl;
  cout<<"Duree    : "<<duree<<endl;
}
ostream& operator<<(ostream&o,service&s)
{   o<<"IDService: "<<s.IdS<<endl;
    o<<"Nom      : "<<s.noms<<endl;
    o<<"Prix     : "<<s.prixs<<endl;
    o<<"Duree    : "<<s.duree<<endl;
}
istream& operator>>(istream&in,service&s)
 {  cout <<"donner lId  :";
    in>>s.IdS;
    cout<<"\n";
    cout<<"donner le nom : ";
    in>>s.noms;
    cout<<"\n";
    cout<<"donner le prix :";
    in>>s.prixs;
    cout<<"\n";
    cout<<"donner la duree de service estimee :";
    in>>s.duree;
}
