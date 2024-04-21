#ifndef PERSONNE_H_INCLUDED
#define PERSONNE_H_INCLUDED
#include"session.h"
#include<string>
#include<fstream>
class personne{
protected:

    int id_p;
    string nom;
    string prenom;
    string adresse;
    vector<session*>tab;//tableau d'objets

public:
    personne(int id_p=0,string nom="",string prenom="",string adresse="");//constructeur
    personne(const personne&);//constructeur par recopie
    virtual personne&operator=(const personne&);//m�thode virtuelle(polymorphisme dynamique)
    //les m�thodes get et set pour la modification
    int get_id_p(){return id_p;}
    string get_nom(){return nom;}
    string get_prenom(){return prenom;}
    string get_adresse(){return adresse;}
    void set_id_p(int id){id_p=id;}
    void set_nom(string n){nom=n;}
    void set_prenom(string p){prenom=p;}
    void set_adresse(string a){adresse=a;}
    void ajouter_session(session m);//on peut ajouter session au tableau
    //recherche de session dans le tableau pour la supprimer ou bien afficher
    int recherche(int id);
    void supprimer_session(int id);//supprimer session du vecteur
    int duree_totale_session();//m�thode fait le parcour du tab d'objet et calcule la dur�e totale des sessions pour faire des statistiques
    friend ostream& operator<<(ostream& o, const personne& p);
    friend istream& operator>>(istream& i, personne& p);
    //pour les fichiers
    static void creer(fstream&);
    static void remplir(fstream&);
    friend ostream& operator<<(ostream& o, const personne* p);
    friend istream& operator>>(istream& i, personne* p);
    virtual~personne();//destructeur
};




#endif // PERSONNE_H_INCLUDED
