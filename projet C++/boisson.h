#ifndef BOISSON_H_INCLUDED

#define BOISSON_H_INCLUDED
#include<string>
using namespace std;
class boisson
{
private:
    int IdB ;
    string nomb;
    float prixb;
    int stock;

public:
    //constructeur
    boisson (int IdB=0000,string nomb="",float prixb=0.0,int stock=10);
    //destructeur
    ~boisson(){}
    float total_boisson();
    void  set_nomb(string n){nomb=n;}
    void  set_prixb(float p){prixb=p;}
    void  set_stock(int s){stock=s;}
    string get_nomb(){return nomb;}
    float get_prixb(){return prixb;}
    int get_stock(){return stock;}
    int get_IdB(){return IdB;}
    void afficher_boisson();
    void saisir();
    //surcharge des operateurs << et >>
    friend ostream& operator<<(ostream&,boisson&);
    friend istream& operator>>(istream&,boisson&);


};


#endif // BOISSON_H_INCLUDED
