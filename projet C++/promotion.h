#ifndef PROMOTION_H_INCLUDED
#define PROMOTION_H_INCLUDED
#include<iostream>
using namespace std;
class promotion
{
private :
    float pourcentage ;
    int idp;
public:
    promotion(float pourcentage =0.0, int idp=0);
    float get_promotion();
    void set_promotion(float);
    int get_idp(){return idp;}
    void afficher();
    friend ostream& operator<<(ostream&,promotion&p);
    friend istream& operator>>(istream&,promotion&p);
    friend ostream& operator<<(ostream&,promotion*p);
    friend istream& operator>>(istream&,promotion*p);
    friend class facture ;//pour modifier les attributs de classe
                         //promotion ainsi que utiliser les set et get
};


#endif // PROMOTION_H_INCLUDED
