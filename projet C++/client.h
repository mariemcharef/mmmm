#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED
#include"personne.h"
#include"facture.h"
#include<fstream>
#include<iostream>
class client:public personne{//classe h�rit� du personne
    int points;
    vector<facture*>tabb;
public:
   // constructeur
    client(int id_p=0,string nom="",string prenom="",string adresse="",int points=0):personne(id_p,nom,prenom,adresse){
        this->points=points;
        string repp;
        cout<<"voulez-vous ajouter factures?"<<endl;
        cin>>repp;
        if (repp=="oui"){
        cout<<"les factures"<<endl;
        do
        {   facture*f=new facture();
            cin>>*f;
            tabb.push_back(f);
            cout<<"voulez-vous ajouter factures?"<<endl;
            cin>>repp;
        }while (repp=="oui");
}
}
    client(const client&);//constructeur par recopie
    virtual client&operator=(const client&);
    int get_points(){return points;}
    void set_points(int p){points=p;}
    void ajouter_facture(facture m);
    void gagner_points();//lorsque un client atteint une dur�e totale des sessions (=xxx minutes) des points seront ajout�s
    void convertir_en_membre();//lorsque un client atteint un nbre des points(=1000)il devient membre et peut b�nificier des promotions
    friend client&operator+(const client&,const client&);//retourne la somme des points si un client veut donner ses points � un autre client
    friend ostream& operator<<(ostream& os, const client& c);
    friend istream& operator>>(istream& is, client& c);
    //lire et �crire dans fichier
    friend ostream& operator<<(ostream& os, const client* c);
    friend istream& operator>>(istream& is, client* c);
    static void remplir(fstream&);
    virtual ~client();//destructeur

};

#endif // CLIENT_H_INCLUDED
