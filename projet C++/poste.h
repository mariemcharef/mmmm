#ifndef POSTE_H_INCLUDED
#define POSTE_H_INCLUDED
#include"machine.h"
#include<list>
#include<iterator>
#include<algorithm>
#include<map>
#include"session.h"
using namespace std;
class poste{
    int id_pos;
    list<machine>tab;//conteneur liste
    string etat_poste;//avtivé si tous les machines sont activées et disactivée sinon
    map<int,session> m;//conteneur map
public:
    poste(int id_pos,string etat_poste);//constructeur pour l'allocation des paties dynamiques
    poste(const poste&);//constructeur par recopie
    ~poste();//destructeur
    poste&operator=(const poste&);//affectation
    //les méthodes get et set
    int get_id_p(){return id_pos;}
    string get_etat_poste(){return etat_poste;}
    void set_idp(int i){id_pos=i;}
    void set_etat_pos(string e){etat_poste=e;}
    void ajouter_machine(machine m);//ajouter machine à la liste
    int recherche(int id);//recherche d'une machine dans tab
    void supprimer_machine(int id);
    void activer(){etat_poste="activee";}
    void desactiver(){etat_poste="desactivee";}
    bool verifier_etat_poste();//vrai lorsque tous les machines sont activés
    void ajout_fin(session*);//ajout des session à la map
    void afficher_map();//affichage des sessions dans le map
 //pour lire et écrire à l'écran
    friend ostream& operator<<(ostream& , poste& );
    friend istream& operator>>(istream&, poste& );
    void compter(string);//compter les nbr des machines qui ont le meme logiciel
    friend class session;
};

#endif // POSTE_H_INCLUDED
