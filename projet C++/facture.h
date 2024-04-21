
#ifndef FACTURE_H_INCLUDED
#define FACTURE_H_INCLUDED
#include<vector>
#include "tarif.h"
#include"tarifservice.h"
#include"tarifboisson.h"
#include"promotion.h"
using namespace std;
class facture
{
private:
    int id;
    vector<tarif*>tab;
public:
   facture(int id = 00000000);//
   ~facture();//
   void ajouter_tarif(tarif &);
   void supprimer(int code);
   void afficher();//
   void saisir();
   facture(const facture&);//
   facture&operator=(const facture&);//
   int  rechercher(int );
   void set_id(int idf ){id=idf;}//
   int get_id(){return id ;}//
   //facture operator+ (facture);
   float calculer_montant();
   //float montant_apres_promotion();

   friend ostream& operator<<(ostream&,facture&);
   friend istream& operator>>(istream&,facture&);
   //partie fichier
   //friend ostream& operator>>(ostream &o,facture*);
   //friend istream& operator<<(istream &i,facture*);
   //bool enregistrer(string file_name);
   //bool charger (string file_name);
};
#endif // FACTURE_H_INCLUDED
