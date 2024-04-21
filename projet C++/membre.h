#ifndef MEMBRE_H_INCLUDED
#define MEMBRE_H_INCLUDED
#include"client.h"
#include<fstream>
#include<string>
#include<iostream>
class membre:public client{//classe h�rit�e du client
    string type_abonnement;
    int idfidelite;
public:
    membre(const membre&);
    membre(int id_p=0,string nom="",string prenom="",string adresse="",int points=0,string type_abonnement="",int idfidelite=0):client(id_p,nom,prenom,adresse,points){
    this->type_abonnement=type_abonnement;
    this->idfidelite=idfidelite;
    }
    string get_type_abonnement(){return type_abonnement;}
    membre&operator=(const membre&);
    friend ostream& operator<<(ostream& os, const membre& m);
    friend istream& operator>>(istream& is, membre& m);
    friend ostream& operator<<(ostream& os, const membre* m);
    friend istream& operator>>(istream& is, membre* m);
    static void remplir(fstream&);
    ~membre(){};

};


#endif // MEMBRE_H_INCLUDED
