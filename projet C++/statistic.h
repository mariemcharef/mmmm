#ifndef STATISTIC_H_INCLUDED
#define STATISTIC_H_INCLUDED
#include "membre.h"
#include"personne.h"
#include"client.h"
#include <string>
#include <typeinfo>
#include <map>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class statistics{
    int mois;//chaque mois on fait des statistiques des client et des dur�e des sessions
    int annee;
    int nombre_client_totale;
    double dureeMoySession;//par client
    vector<personne*>tabl;//parceque il a tableau d'objets dans la classe personne si typeid personne est client on calcule la moyenne des sessions et on calcule most frequente client et on calcule les points pour mentionner membre ou non
public:
    statistics(int mois,int annee,int nombre_client_totale,double dureeMoySession);
    statistics(const statistics&);
    void ajouterPersonne(personne& c);//utilisation de transtypage pour convertir un objet de classe de base (personne) en une classe d�riv�e(client ou membre)
    statistics&operator=(const statistics&);
    int recherche(int id);
    void supprimer_personne(int id);
    int get_mois(){return mois;}
    int get_annee(){return annee;}
    int get_nombre_client_totale(){return nombre_client_totale;}
    double get_dureeMoySession(){return dureeMoySession;}
    void set_mois(int m){mois=m;}
    void set_annee(int a){annee=a;}
    void set_nombre_client_totale(int n){nombre_client_totale=n;}
    void set_dureeMoySession(double d){dureeMoySession=d;}
    int total_session();
    void calculerDureeMoyenneSession();
    static void creer(fstream&);
    static void remplir(fstream&);
    void enregistrer();
    friend ostream& operator<<(ostream& o, const statistics& stat);
    friend istream& operator>>(istream& i, statistics& stat);
    friend ostream& operator<<(ostream& o, const statistics* stat);
    friend istream& operator>>(istream& i, statistics* stat);
    ~statistics();
};



#endif // STATISTIC_H_INCLUDED
