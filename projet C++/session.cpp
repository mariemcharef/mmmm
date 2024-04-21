#include"session.h"
#include<fstream>
session::session(int id,int d){
        duree=d;
        idS=id;
}
ostream& operator<<(ostream& o,session& s) {
    o << "Session " << s.idS << " dure : " << s.duree/60 << " heures et " << s.duree%60 << " minutes"<<endl;
    return o;
}
// Implémentation de l'opérateur d'entrée pour la classe session
istream& operator>>(istream& i,session& s) {
    cout << " Entrez l'identifiant de la session : ";
    i >> s.idS;
    cout << "Entrez la durée de la session (en minute minutes) : ";
    i >> s.duree;
    return i;
}
void session::creer_f(fstream&f){
    f.open("fichiersession.txt",ios::in|ios::out|ios::trunc);
    if(!f.is_open()) exit (-1);
}
 session&operator+(const session& s1,const session& s2){
    int id = s1.idS+s2.idS ;
    int duree=s1.duree+s2.duree;
    return *new session(id,duree);
}
ostream& operator<<(ostream& o,session*s) {
    o << "Session " << s->idS << " dure : " << s->duree/60 << " heures et " << s->duree%60 << " minutes"<<endl;
    return o;
}

istream& operator>>(istream& i,session*s) {
    i.seekg(0);
    cout << " Entrez l'identifiant de la session : ";
    i >> s->idS;
    cout << "Entrez la durée de la session (en minute minutes) : ";
    i >> s->duree;
    return i;
}

