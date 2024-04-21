
#ifndef TARIFSERVICE_H_INCLUDED
#define TARIFSERVICE_H_INCLUDED
#include<string>
#include <map>
#include"tarif.h"
#include"service.h"
using namespace std;
class tarifservice : public tarif
{
private:
    map <int ,service> m ;
public:
    tarifservice(int code =0000 , float montant =0.0):tarif(code,montant){}
    virtual ~tarifservice(){m.clear();}
    void ajout_fin(service *s);
    void recherche_service(int id);
    void modifier_prix(int id);
    void modifier_duree(int id);
    virtual void afficher();
    friend ostream& operator<<(ostream&, tarifservice&tars);
    friend istream& operator>>(istream&,tarifservice &tars);

};

#endif // TARIFSERVICE_H_INCLUDED
