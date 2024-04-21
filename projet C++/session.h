#ifndef SESSION_H_INCLUDED
#define SESSION_H_INCLUDED
#include<fstream>
class session{
    int idS;
    int duree;//en minute

public:
    session(int id=0,int d=0);
    ~session(){}
    int get_id_s(){return idS;}
    int get_duree(){return duree;}
    friend session&operator+(const session&s1,const session&s2);//retourne la somme du deux sessions
    friend ostream& operator<<(ostream&o, session&s);
    friend istream& operator>>(istream&i, session&s);
    //pour l'écriture dans fichier
    static void creer_f(fstream&);
    friend ostream& operator<<(ostream&o, session*s);
    friend istream& operator>>(istream&i, session*s);

 };

#endif // SESSION_H_INCLUDED
