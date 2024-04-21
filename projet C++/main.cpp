#pragma once
#include <iostream>
#include<string>
#include"poste.h"
#include"poste.cpp"
#include"machine.h"
#include"machine.cpp"
#include"personne.h"
#include"personne.cpp"
#include"client.h"
#include"client.cpp"
#include"membre.h"
#include"membre.cpp"
#include"admin.h"
#include"admin.cpp"
#include"admin_sys.h"
#include"admin_sys.cpp"
#include"statistic.h"
#include"statistics.cpp"
#include"boisson.h"
#include"boisson.cpp"
#include"service.h"
#include"service.cpp"
#include"facture.h"
#include"promotion.h"
#include"tarif.h"
#include"tarifboisson.h"
#include"tarifservice.h"
#include"session.h"
#include"session.cpp"
#include"facture.cpp"
#include"promotion.cpp"
#include"tarif.cpp"
#include"tarifboisson.cpp"
#include"tarifservice.cpp"
#include<fstream>
#include<iomanip>
#include<vector>
#include<map>
#include<list>
#include<fstream>
#include <cstdlib>
using namespace std;
void afficher(fstream&f){
    char ch[101];
    f.seekg(0);
while(1){
        f.getline(ch,100);
        if(f.eof())break;
        cout<<ch<<endl;
     }
f.close();
system("pause");
}
void menufacture()
{
int choix;
facture f;
do {
cout << "Menu de gestion de facture :" << endl;
cout << "1. Saisir une nouvelle facture" << endl;
cout << "2. Afficher la facture" << endl;
cout << "3. Ajouter un tarif à la facture" << endl;
cout << "4. Supprimer un tarif de la facture" << endl;
cout << "5. Calculer le montant de la facture" << endl;
cout << "6. Constructeur par recopie de la facture" << endl;
cout << "7. Quitter" << endl;
cout << "Saisir choix : ";
cin >> choix;
switch (choix) {
case 1: {
cout << "Saisie de la nouvelle facture :" << endl;
cin >> f; // Saisie d'une nouvelle facture
break;
}
case 2: {
cout << "Affichage de la facture :" << endl;
cout<<f; // Affichage de la facture
break;
}
case 3: {
tarif t;
tarifboisson tb;
tarifservice ts;
int choixt;
do{
cout << "Ajout d'un tarif à la facture :" << endl;
cout<<"1-ajouter un tarif"<<endl;
cout<<"2-ajouter un tarif boisson "<<endl;
cout<<"3-ajouter un tarif service"<<endl;
cout<<"4-quitter "<<endl;
cout<<"saisir choix "<<endl;
cin>>choixt;
switch(choixt)
{
case 1:
{
cout<<"ajouter un tarif"<<endl;
cin>>t;
f.ajouter_tarif(t);
break;
}
case 2:
{
cout<<"ajouter un tarif boisson "<<endl;
cin>>tb;
f.ajouter_tarif(tb);
break;
}
case 3:
{
cout<<"ajouter un tarif service "<<endl;
cin>>ts;
f.ajouter_tarif(ts);
break;
}
case 4 :
{
cout << "Fin du programme." << endl;
break;
}
default:
{
cout << "Choix invalide. Veuillez réessayer." << endl;
} ;
}
}while(choixt!=4);
break;
}
case 4: {
int code;
cout << "Suppression d'un tarif de la facture :" << endl;
cout << "Entrez le code du tarif à supprimer : ";
cin >> code;
f.supprimer(code);
break;
}
case 5: {
cout << "Calcul du montant de la facture :" << endl;
float montant = f.calculer_montant();
cout << "Le montant de la facture est de : " << montant << " dinars" << endl;
break;
}
case 6: {
cout << "Constructeur par recopie :" << endl;
facture fac =f;
cout<<"l'affichege de la nouvelle facture "<<endl;
cout<<fac;
break;
}
case 7: {
cout << "Fin du programme." << endl;
break;
}
default: {
cout << "Choix invalide. Veuillez réessayer." << endl;
continue;
}
}
} while (choix != 7);
}
void menupromotion()
{
promotion p; // Création d'un objet promotion pour effectuer les opérations
int choix;
do {
cout << "\nMenu de gestion de la promotion :" << endl;
cout << "1. Saisir une nouvelle promotion" << endl;
cout << "2. Afficher la promotion" << endl;
cout << "3. Modifier la promotion" << endl;
cout << "4. Quitter" << endl;
cout << "Choix : ";
cin >> choix;
switch (choix) {
case 1: {
cout << "Saisie de la nouvelle promotion :" << endl;
cin >> p; // Saisie d'une nouvelle promotion
break;
}
case 2: {
cout << "Affichage de la promotion :" << endl;
cout << p; // Affichage de la promotion
break;
}
case 3: {
cout << "Modification de la promotion :" << endl;
cout<<"Saisie le nouveau pourcentage de promotion"<<endl;
int x;
cin>>x;
p.set_promotion(x);
// Modification de la promotion
break;
}
case 4: {
cout << "Fin du programme." << endl;
break;
}
default: {
cout << "Choix invalide. Veuillez réessayer." << endl;
}
}
} while (choix != 4);
}
void menutarif()
{
tarif t; // Création d'un objet tarif pour effectuer les opérations
int choix;
do {
cout << "\nMenu de gestion du tarif :" << endl;
cout << "1. Saisir un nouveau tarif" << endl;
cout << "2. Afficher le tarif" << endl;
cout << "3. Modifier le tarif" << endl;
cout << "4. Quitter" << endl;
cout << "Choix : ";
cin >> choix;
switch (choix) {
case 1: {
cout << "Saisie du nouveau tarif :" << endl;
t.saisir(); // Saisie d'un nouveau tarif
break;
}
case 2: {
cout << "Affichage du tarif :" << endl;
t.afficher(); // Affichage du tarif
break;
}
case 3: {
cout << "Modification du tarif :" << endl;
t.modifier(); // Modification du tarif
break;
}
case 4: {
cout << "Fin du programme." << endl;
break;
}
default: {
cout << "Choix invalide. Veuillez réessayer." << endl;
}
}
} while (choix != 4);
}
void menutarifboisson()
{
tarifboisson tb;
int choix;
do {
cout << "\nMenu de gestion du tarif des boissons :" << endl;
cout << "1. saisir tarif boisson " << endl;
cout << "2. Ajouter une boisson au tarif" << endl;
cout << "3. Supprimer une boisson du tarif" << endl;
cout << "4. Afficher le tarif des boissons" << endl;
cout << "5. Rechercher une boisson par nom" << endl;
cout << "6. Calculer le prix total des boissons" << endl;
cout << "7. Trouver la boisson la plus chère" << endl;
cout << "8. Modifier le prix d'une boisson" << endl;
cout << "9. Modifier le stock d'une boisson" << endl;
cout << "10. Quitter" << endl;
cout << "Choix : ";
cin >> choix;
switch (choix) {
case 1:
{ cout << "saisir tarif boisson " << endl;
cin>>tb;
break;
}
case 2: {
cout << "Ajout d'une nouvelle boisson au tarif :" << endl;
boisson b;
cin >> b; // Saisie d'une nouvelle boisson
tb.ajouter(&b);
break;
}
case 3: {
int id;
cout << "Suppression d'une boisson du tarif :" << endl;
cout << "Entrez l'ID de la boisson à supprimer : ";
cin >> id;
tb.supprimer(id);
break;
}
case 4: {
cout << "Affichage du tarif des boissons :" << endl;
cout<<tb; // Affichage du tarif des tarif boisson
break;
}
case 5: {
string nom;
cout << "Recherche d'une boisson par nom :" << endl;
cout << "Entrez le nom de la boisson : ";
cin >> nom;
tb.rechercher_boisson(nom);
break;
}
case 6: {
cout << "Calcul du prix total des boissons : " << tb.calculer_prix() << " DT" << endl;
break;
}
case 7: {
cout << "La boisson la plus chère a un prix de : " << tb.boisson_plus_cher() << "DT" << endl;
break;
}
case 8: {
int id;
cout << "Modification du prix d'une boisson :" << endl;
cout << "Entrez l'ID de la boisson à modifier : ";
cin >> id;
tb.modifier_prix(id);
break;
}
case 9: {
int id;
cout << "Modification du stock d'une boisson :" << endl;
cout << "Entrez l'ID de la boisson à modifier : ";
cin >> id;
tb.modifier_stock(id);
break;
}
case 10: {
cout << "Fin du programme." << endl;
break;
}
default: {
cout << "Choix invalide. Veuillez réessayer." << endl;
continue;
}
}
} while (choix != 10);
}
void menutarifservice()
{ tarifservice ts;
int choix;
do {
cout << "\nMenu de gestion du tarif des services :" << endl;
cout << "1. Saisir un nouveau tarif service" << endl;
cout << "2. Ajouter un service au tarif" << endl;
cout << "3. Rechercher un service par ID" << endl;
cout << "4. Modifier le prix d'un service" << endl;
cout << "5. Modifier la durée d'un service" << endl;
cout << "6. Afficher le tarif des services" << endl;
cout << "7. Quitter" << endl;
cout << "Choix : ";
cin >> choix;
switch (choix) {
case 1: {
cout << "Saisie d'un nouveau tarif service :" << endl;
cin >> ts;
break;
}
case 2: {
cout << "Ajout d'un nouveau service au tarif :" << endl;
service s;
cin >> s; // Saisie d'un nouveau service
ts.ajout_fin(&s);
break;
}
case 3: {
int id;
cout << "Recherche d'un service par ID :" << endl;
cout << "Entrez l'ID du service : ";
cin >> id;
ts.recherche_service(id);
break;
}
case 4: {
int id;
cout << "Modification du prix d'un service :" << endl;
cout << "Entrez l'ID du service à modifier : ";
cin >> id;
ts.modifier_prix(id);
break;
}
case 5: {
int id;
cout << "Modification de la durée d'un service :" << endl;
cout << "Entrez l'ID du service à modifier : ";
cin >> id;
ts.modifier_duree(id);
break;
}
case 6: {
cout << "Affichage du tarif des services :" << endl;
cout<<ts; // Affichage du tarif des services
break;
}
case 7: {
cout << "Fin du programme." << endl;
break;
}
default: {
cout << "Choix invalide. Veuillez réessayer." << endl;
continue;
}
}
} while (choix != 7);
}
void menusession()
{
int choix;
session s1(0,0);
session s2(0,0);
session result(0,0);
session s(0,0);
do {
cout << "\nMenu de gestion des sessions :" << endl;
cout << "1. Creer une nouvelle session" << endl;
cout << "2. Afficher une session" << endl;
cout << "3. Additionner deux sessions" << endl;
cout << "4. Ajouter session dans fichier" << endl;
cout << "5. Quitter" << endl;
cout << "Choix : ";
cin >> choix;
switch (choix) {
case 1: {

cin>>s;
cout << "Nouvelle session créée." << endl;
break;
}
case 2: {

cout << "Affichage d'une session :" << endl;
cout<< s;
// Recherche et affichage de la session correspondante
break;
}
case 3: {
cout << "Addition de deux sessions :" << endl;
cout << "Entrez les informations de la première session :" << endl;
cin >> s1;
cout << "Entrez les informations de la deuxième session :" << endl;
cin >> s2;
result = s1 + s2;
cout << "Résultat de l'addition : " << result << endl;
break;
}
case 4:
    {  fstream f;
       s.creer_f(f);
       cin>>s;
       f<<&s;
       cout<<"afficher le fichier "<<endl;
       afficher(f);
        break;
    }
    case 5: {
cout << "Fin du programme." << endl;
break;
}
default: {
cout << "Choix invalide. Veuillez réessayer." << endl;
continue;
}
}
} while (choix != 5);
}
///////////////////////
void menupersonne()
{
   personne p;
    int choix;
    do {
        cout << "Menu Personne:" << endl;
        cout << "1. creer une personne" << endl;
        cout << "2. Ajouter une session" << endl;
        cout << "3. Supprimer une session" << endl;
        cout << "4. Afficher la duree totale des sessions" << endl;
        cout << "5. Afficher la personne"<<endl;
        cout << "6. Quitter" << endl;
        cout << "Entrez votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1: {
                cout << "Entrez les détails de la personne :" << endl;
                cin >> p; // suppose que vous avez une surcharge de l'opérateur >> pour la classe personne

                break;
            }case 2: {
                session s;
                cout << "Entrez les détails de la session :" << endl;
                cin >> s; // suppose que vous avez une surcharge de l'opérateur >> pour la classe session
                p.ajouter_session(s);
                break;
            }
            case 3: {
                int id;
                cout << "Entrez l'ID de la session à supprimer : ";
                cin >> id;
                p.supprimer_session(id);
                break;
            }
            case 4: {
                int duree_totale = p.duree_totale_session();
                cout << "La durée totale des sessions est de : " << duree_totale << " minutes." << endl;
                break;
            }
            case 5: {
                cout<<"afficher personne"<<endl;
                cout <<p<<endl;
                break;
            }
            case 6: {
                cout << "Au revoir !" << endl;
                break;
            }
            default:
                cout << "Choix invalide. Veuillez réessayer." << endl;
        }
    } while (choix != 6);
}
void menuClient()
{
    int choix;
    client c;
    do {
        cout << "Menu Client:" << endl;
        cout << "1. Ajouter un client" << endl;
        cout << "2. Ajouter une session" << endl;
        cout << "3. Supprimer une session" << endl;
        cout << "4. Afficher la durée totale des sessions" << endl;
        cout << "5. Afficher le client" << endl;
        cout << "6. Ajouter une facture" << endl;
        cout << "7. Gagner des points" << endl;
        cout << "8. Convertir en membre" << endl;
        cout << "9. Quitter" << endl;
        cout << "10.additionner des clients " << endl;
        cout << "Entrez votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1: {
                cout << "Entrez les détails de le client :" << endl;
                cin >> c;
                break;
            }
            case 2: {
                session s;
                cout << "Entrez les détails de la session :" << endl;
                cin >> s; // suppose que vous avez une surcharge de l'opérateur >> pour la classe session
                c.ajouter_session(s);
                break;
            }
            case 3: {
                int id;
                cout << "Entrez l'ID de la session à supprimer : ";
                cin >> id;
                c.supprimer_session(id);
                break;
            }
            case 4: {
                int duree_totale = c.duree_totale_session();
                cout << "La durée totale des sessions est de : " << duree_totale << " minutes." << endl;
                break;
            }
            case 5: {
                cout<<"le client: "<<endl;
                cout << c << endl;
                break;
            }
            case 6: {
                facture f;
                cout << "Entrez les détails de la facture :" << endl;
                cin >> f; // suppose que vous avez une surcharge de l'opérateur >> pour la classe facture
                c.ajouter_facture(f);
                break;
            }
            case 7: {
                c.gagner_points();
                break;
            }
            case 8: {
                c.convertir_en_membre();
                break;
            }
            case 9: {
                cout << "Au revoir !" << endl;
                break;

            case 10: {
                cout << "entrer les donner de deux clients" << endl;
             client c;
             client t;
             client p;
                cin>> c;
                cin>> t;
                p=c+t;
                cout<<p;
                break;
            }
            default:
                cout << "Choix invalide. Veuillez réessayer." << endl;
        }
        }
    } while (choix != 10);

}
void menuMembre()
 {
    membre m;
    int choix;
    do {
        cout << "Menu Membre:" << endl;
        cout << "1. Ajouter membre" << endl;
        cout << "2. Ajouter une session" << endl;
        cout << "3. Supprimer une session" << endl;
        cout << "4. Afficher la durée totale des sessions" << endl;
        cout << "5. Ajouter une facture" << endl;
        cout << "6. afficher le membre" << endl;
        cout << "7. Quitter" << endl;
        cout << "Entrez votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1: {

                cout << "Entrez les détails de membre :" << endl;
                cin >> m; // suppose que vous avez une surcharge de l'opérateur >> pour la classe session
                break;
            }
            case 2: {
                session s;
                cout << "Entrez les détails de la session :" << endl;
                cin >> s; // suppose que vous avez une surcharge de l'opérateur >> pour la classe session
                m.ajouter_session(s);
                break;
            }
            case 3: {
                int id;
                cout << "Entrez l'ID de la session à supprimer : ";
                cin >> id;
                m.supprimer_session(id);
                break;
            }
            case 4: {
                int duree_totale = m.duree_totale_session();
                cout << "La durée totale des sessions est de : " << duree_totale << " minutes." << endl;
                break;
            }
            case 5: {
                facture f;
                cout << "Entrez les détails de la facture :" << endl;
                cin >> f; // suppose que vous avez une surcharge de l'opérateur >> pour la classe facture
                m.ajouter_facture(f);
                break;
            }

            case 6: {
                cout<<m;
                break;
            }

            case 7: {
                cout << "Au revoir !" << endl;
                break;
            }
            default:
                cout << "Choix invalide. Veuillez réessayer." << endl;
        }
    } while (choix != 7);
}
void menuStatistiques(statistics &stat) {
    int choix;
    do {
        cout << "Menu Statistiques:" << endl;
        cout << "1. creer statistic" << endl;
        cout << "2. Ajouter une personne" << endl;
        cout << "3. Supprimer une personne" << endl;
        cout << "4. Afficher le total des sessions" << endl;
        cout << "5. Afficher statistic" << endl;
        cout << "6. Calculer la durée moyenne des sessions" << endl;
        cout << "7. Quitter" << endl;
        cout << "8. creer dans fichier" << endl;
        cout << "Entrez votre choix : ";
        cin >> choix;

        switch (choix) {

            case 1: {

                int mois, annee;
                    double dureeMoyenne;
                    cout << "Entrez le mois et l'année : ";
                    cin >> mois >> annee;
                    statistics stat(mois,annee,0,0.0);
                break;
            }
            case 2: {
                 int choixAjouter;
                             // Afficher le menu de gestion de personne
                             cout << "===== Menu Ajout =====" << endl;
                             cout << "1. Ajouter personne " << endl;
                             cout << "2. Ajouter client " << endl;
                             cout << "3. Ajouter membre " << endl;
                             cout << "4. Retour au menu principal" << endl;
                             cout << "Choix: ";
                             cin >> choixAjouter;
                             // Effectuer des actions basées sur le choix de l'utilisateur
                             switch (choixAjouter) {
                                case 1: {
                                    personne p(0," "," "," ");
                                    cin >> p;
                                    stat.ajouterPersonne(p);
                                    break;
                                }
                                case 2: {
                                    client c;
                                    cin >> c;

                                    stat.ajouterPersonne(c);
                                    break;
                                }
                                case 3: {
                                    membre m;
                                    cin >> m;
                                    stat.ajouterPersonne(m);
                                    break;
                                }
                                case 4: {
                                    // Retourner au menu principal
                                    break;
                                }
                                case 7: {
                                    cout << "Au revoir !" << endl;
                                    break;
                                }
                                default:{
                                    cout << "Choix invalide. Veuillez réessayer." << endl;
                                }
               } while (choix != 7);
                break;
            }
            case 3:{
                int id;
                cout<<"entrer l'identite"<<endl;
                cin>>id;
                stat.supprimer_personne(id);
            }
            case 4: {
                int total_sessions = stat.total_session();
                cout << "Le total des sessions est de : " << total_sessions << endl;
                break;
            }
            case 5:{

                cout<<stat<<endl;
            }
            case 6: {
                stat.calculerDureeMoyenneSession();
                double duree_moyenne = stat.get_dureeMoySession();
                cout << "La durée moyenne des sessions par client est de : " << duree_moyenne << " minutes." << endl;
                break;
            }

            case 7: {
                cout << "Au revoir !" << endl;
                break;
            }
            case 8: {
                fstream f;
                stat.creer(f);
                stat.remplir(f);
                afficher(f);
                break;
            }

            default:
                cout << "Choix invalide. Veuillez réessayer." << endl;
        }
    } while (choix != 8);
}
void menuPoste()
 {  poste p(0," ");
    int choix;
    do {
        cout << "Menu Poste:" << endl;
        cout << "1. Ajouter une machine" << endl;
        cout << "2. Supprimer une machine" << endl;
        cout << "3. Activer le poste" << endl;
        cout << "4. Désactiver le poste" << endl;
        cout << "5. Vérifier l'état du poste" << endl;
        cout << "6. Ajouter une session à la map" << endl;
        cout << "7. Afficher les sessions de la map" << endl;
        cout << "8. Quitter" << endl;
        cout << "Entrez votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1: {
                machine m;
                cout << "Entrez les détails de la machine :" << endl;
                cin >> m; // suppose que vous avez une surcharge de l'opérateur >> pour la classe machine
                p.ajouter_machine(m);
                break;
            }
            case 2: {
                int id;
                cout << "Entrez l'ID de la machine à supprimer : ";
                cin >> id;
                p.supprimer_machine(id);
                break;
            }
            case 3: {
                p.activer();
                cout << "Le poste a été activé." << endl;
                break;
            }
            case 4: {
                p.desactiver();
                cout << "Le poste a été désactivé." << endl;
                break;
            }
            case 5: {
                bool etat = p.verifier_etat_poste();
                if (etat)
                    cout << "Le poste est activé." << endl;
                else
                    cout << "Le poste est désactivé." << endl;
                break;
            }
            case 6: {
                session s;
                cout << "Entrez les détails de la session à ajouter à la map :" << endl;
                cin >> s; // suppose que vous avez une surcharge de l'opérateur >> pour la classe session
                p.ajout_fin(&s);
                break;
            }
            case 7: {
                p.afficher_map();
                break;
            }
            case 8: {
                cout << "Au revoir !" << endl;
                break;
            }
            default:
                cout << "Choix invalide. Veuillez réessayer." << endl;
        }
    } while (choix != 8);
}

using namespace std;
int main()
{

int choix;
do {
        cout << "\nMenu principal :" << endl;
        cout << "1. Gestion de facture" << endl;
        cout << "2. Gestion de promotion" << endl;
        cout << "3. Gestion de tarif" << endl;
        cout << "4. Gestion de sessions" << endl;
        cout << "5. Gestion des personnes" << endl;
        cout << "6. Gestion des clients" << endl;
        cout << "7. Gestion des membres" << endl;
        cout << "8. Gestion des statistiques" << endl;
        cout << "9. Gestion des postes" << endl;
        cout << "10. Quitter" << endl;
        cout << "Choix : ";
        cin >> choix;
                    switch (choix) {
            case 1: {
            menufacture();
            break;
            }
            case 2: {
            menupromotion();
            break;
            }
            case 3:{
                int choixTarif;
                do{
                cout << "\nMenu de gestion du tarif :" << endl;
                cout << "1. Gestion de tarif des boissons" << endl;
                cout << "2. Gestion de tarif des services" << endl;
                cout << "3. Quitter" << endl;
                cout << "Choix : ";
                cin >> choixTarif;
                switch (choixTarif) {
                    case 1: {
                            cout << "Gestion de tarif des boissons :" << endl;
                            menutarifboisson();
                            break;
                            }
                    case 2: {
                            cout << "Gestion de tarif des services :" << endl;
                            menutarifservice();
                            break;
                            }
                    case 3: { cout<<"quitter"<<endl;
                    break; // Quitter le menu de gestion du tarif
                            }
                    default: {
                            cout << "Choix invalide. Veuillez réessayer." << endl;
                            continue; // Retour au menu de gestion du tarif
                            }
                                    }
            }while(choixTarif!=3);
            break;
    }
            case 4: {

            menusession();
            break;
            }

            case 5: {
                menupersonne();
                break;
            }
            case 6: {
                menuClient();
                break;
            }
            case 7: {
                menuMembre();
                break;
            }
            case 8: {
                statistics stat(0,0,0,0.0);
                cin>>stat;
                menuStatistiques(stat);
                break;
            }
            case 9: {
                menuPoste();
                break;
            }
case 10: {
cout << "Fin du programme." << endl;
break;
}

default: {
cout << "Choix invalide. Veuillez réessayer." << endl;
continue;
}
}
} while (choix !=10 );


}
