#include"admin.h"
void admin::calcule_augmentation_salaire(int pourcentage,float augmentation){
    augmentation=salaire*pourcentage/100;
}
ostream& operator<<(ostream& o, const admin& a) {
    o << static_cast<const personne&>(a);
    o << "Salaire: " << a.salaire << endl;
    o << "Poste: " << a.poste << endl;
    return o;
}
ostream& operator<<(ostream& o, const admin* a) {
    o << static_cast<const personne&>(*a);
    o << "Salaire: " << a->salaire << endl;
    o << "Poste: " << a->poste << endl;
    return o;
}
istream& operator>>(istream& i, admin& a) {
    i >> static_cast<personne&>(a);
    cout << "Salaire: ";
    i >> a.salaire;
    cout << "Poste: ";
    i >> a.poste;
    return i;
}
istream& operator>>(istream& i, admin* a) {
    i >> static_cast<personne&>(*a);
    cout << "Salaire: ";
    i >> a->salaire;
    cout << "Poste: ";
    i >> a->poste;
    return i;
}
