#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED
#include<string>

using namespace std;
class service
{
private :
    int IdS ;
    string noms;
    float prixs;
    int duree;
public :
    //constructeur
    service( int IdS =0000,string nomb="",float prix=0.0,int duree=0);
    //destructeur
    ~service();
    //setters
    void set_IDS(int i){IdS=i;}
    void set_noms(string n){noms=n;}
    void set_prixs(float p){prixs=p;}
    void set_duree(int d){duree=d;}
    //getters
    string get_noms(){return noms;}
    float get_prixs(){return prixs;}
    int get_duree(){return duree;}
    int get_IDS(){return IdS;}
    void saisir();
    void afficher_service();
    //surchage des operateurs << et >>
    friend ostream& operator<<(ostream&,service&);
    friend istream& operator>>(istream&,service&);








};


#endif // SERVICE_H_INCLUDED
