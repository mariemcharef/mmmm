#include"statistic.h"
#include"personne.h"
#include"client.h"
#include"membre.h"
statistics&statistics::operator=(const statistics & other){
        if (this != &other) {
            mois = other.mois;
            annee = other.annee;
            nombre_client_totale=other.nombre_client_totale;
            dureeMoySession=other.dureeMoySession;
            for (auto& personne_ptr : tabl) {
                delete personne_ptr;
            }
            tabl.clear();
           for (unsigned int i = 0; i < other.tabl.size(); i++) {
            personne* p = nullptr; // Initialisez p à nullptr ici
            // Utilisez dynamic_cast pour vérifier le type des objets
            if (typeid(*other.tabl[i]) == typeid(personne)) {
                p = new personne(*dynamic_cast<personne*>(other.tabl[i]));
            } else if (typeid(*other.tabl[i]) == typeid(client)) {
                p = new client(*dynamic_cast<client*>(other.tabl[i]));
            } else if (typeid(*other.tabl[i]) == typeid(membre)) {
                p = new membre(*dynamic_cast<membre*>(other.tabl[i]));
            }

            // Ajoutez p à tabl si p est valide
            if (p != nullptr) {
                tabl.push_back(p);
            }
    }
}
return *this;
}
statistics::statistics(int mois,int annee,int nombre_client_totale,double dureeMoySession){
    this->mois=mois;
    this->annee=annee;
    this->dureeMoySession=dureeMoySession;
    this->nombre_client_totale=nombre_client_totale;
    string r;
    cout<<"voulez-vous ajouter personnes?"<<endl;
    cin>>r;
    if (r=="oui"){
    cout<<"les personnes"<<endl;
    do
    {   int id;
            string no;
            string preno;
            string adress;

            cout << "Entrez l'ID de la personne : ";
            cin >> id;
            cout << "Entrez le nom de la personne : ";
            cin >> no;
            cout << "Entrez le prénom de la personne : ";
            cin >> preno;
            cout << "Entrez l'adresse de la personne : ";
            cin >> adress;

            personne* p = new personne(id, no, preno, adress);
            tabl.push_back(p);

            cout << "Voulez-vous ajouter une autre personne ? (oui/non)" << endl;
            cin >> r;
    }while (r=="oui");
}
}
statistics::statistics(const statistics& s){
    mois=s.mois;
    annee=s.annee;
    nombre_client_totale=s.nombre_client_totale;
    dureeMoySession=dureeMoySession;
    personne *p;
    for (unsigned int i=0;i<s.tabl.size();i++)
    {
        if (typeid (*s.tabl[i])==typeid(personne))
            {p=new personne(*s.tabl[i]);}
        else if (typeid (*s.tabl[i])==typeid(client))
            {p=new client(static_cast<const client&>(*s.tabl[i]));}
        else if (typeid(*s.tabl[i])==typeid(membre))
            {p=new membre(static_cast<const membre&>(*s.tabl[i]));}
    }
    tabl.push_back(p);
}
void statistics::ajouterPersonne(personne& c) {
    personne *p;
    if(typeid(c)==typeid(personne))
        {p=new personne(c);}
    else if(typeid(c)==typeid(client))
        {p=new client(static_cast<const client&>(c));
        nombre_client_totale++;}
    else if(typeid(c)==typeid(membre))
        {p=new membre(static_cast<const membre&>(c));
        nombre_client_totale++;;}
    tabl.push_back(p);

}

void statistics::calculerDureeMoyenneSession(){
        double totalDuree = 0.0;
        double d;
        for (personne* p : tabl) {
                if (typeid(*p)==typeid(client))//si la personne est client
                totalDuree += p->duree_totale_session();
        }
        dureeMoySession = totalDuree / nombre_client_totale;
}
int statistics::total_session(){
    double totalDuree = 0.0;
    for (personne* p : tabl) {
                if (typeid(*p)==typeid(client))
                totalDuree += p->duree_totale_session();
        }
    return totalDuree;
}
int statistics::recherche(int id){
        int a=-1;
        for (unsigned int i=0;i<tabl.size();i++){
            if(tabl[i]->get_id_p()==id)
                    {return i;}
        }
    return a;
}
void statistics::supprimer_personne(int id){
       int index = recherche(id); // Recherche l'index de la personne avec l'id spécifié
    if (index != -1) { // Si la personne est trouvée
        if (typeid(*tabl[index]) == typeid(client) || typeid(*tabl[index]) == typeid(membre)) {
            nombre_client_totale--;
        }
        tabl.erase(tabl.begin() + index); // Supprime la personne du vecteur
    }
}
void statistics::creer(fstream&f){
    f.open("fichierStatistiques.txt",ios::in|ios::out|ios::trunc);
    if(!f.is_open()) exit (-1);
}
void statistics::enregistrer(){
    fstream f;
    f.open("fichierStatistiques.txt",ios::in|ios::out|ios::trunc);
    if(!f.is_open())exit(-1);
    f<<this;
    f.close();
}
void statistics::remplir(fstream&f){
    statistics p(0,0,0,0.0);
    int n;
    cout<<"saisir le nbre de statistiques"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"saisir une statistique"<<endl;
        cin>>p;
        f<<&p<<endl;
    }
}
statistics::~statistics(){
        for (unsigned int i=0;i<tabl.size();i++)
 { delete tabl[i]; }
}
ostream& operator<<(ostream& os, const statistics& stat) {
    os << "Mois: " << stat.mois << endl;
    os << "Année: " << stat.annee << endl;
    os << "Nombre total de clients: " << stat.nombre_client_totale << endl;
    os << "Durée moyenne de session: " << stat.dureeMoySession << endl;
    os<<"les personnes: "<<endl;
    for (unsigned i=0;i<stat.tabl.size();i++){

        if(typeid(*stat.tabl[i])==typeid(personne))
            os<<*stat.tabl[i];
        else if (typeid(*stat.tabl[i])==typeid(client))
            os<<static_cast<client&>(*stat.tabl[i]);
        else if (typeid(*stat.tabl[i])==typeid(membre))
            os<<static_cast<membre&>(*stat.tabl[i]);
    }
    return os;
}
ostream& operator<<(ostream& o, const statistics* s) {
    o << "Mois: " << s->mois << endl;
    o << "Année: " << s->annee << endl;
    o << "Nombre total de clients: " << s->nombre_client_totale << endl;
    o << "Durée moyenne de session: " << s->dureeMoySession << endl;
    o<<"les personnes: "<<endl;
    for (unsigned i=0;i<s->tabl.size();i++){
        if(typeid(*s->tabl[i])==typeid(personne))
            o<<"la personne : "<<*s->tabl[i];
        else if (typeid(*s->tabl[i])==typeid(client))
            o<<"le client: "<<static_cast<client&>(*s->tabl[i]);
        else if (typeid(*s->tabl[i])==typeid(membre))
            o<<"le membre: "<<static_cast<membre&>(*s->tabl[i]);
    }
    return o;
}
istream& operator>>(istream& i, statistics& stat) {
    cout << "Mois: ";
    i >> stat.mois;
    cout << "Année: ";
    i >> stat.annee;
    cout << "Nombre total de clients: ";
    i >> stat.nombre_client_totale;
    cout << "Durée moyenne de session: ";
    i >> stat.dureeMoySession;
    int choix;string rep;
    do
    {
        cout<<"\n taper 1:personne, 2:client ,3:membre"<<endl;
        i>>choix;
        if(choix==1)
        {
            personne* p=new personne();
            i>>*p;
            stat.tabl.push_back(p);
        }
        else if (choix==2)
        {
            client*p=new client();
            i>>*p;
            stat.tabl.push_back(p);
        }
        else if(choix==3)
        {
            membre*p=new membre();
            i>>*p;
            stat.tabl.push_back(p);
        }
        cout<<"\n ajouter?"<<endl;
        i>>rep;
    }while(rep=="oui");
    return i;
}
istream& operator>>(istream& i, statistics* stat) {
    cout << "Mois: ";
    i >> stat->mois;
    cout << "Année: ";
    i >> stat->annee;
    cout << "Nombre total de clients: ";
    i >> stat->nombre_client_totale;
    cout << "Durée moyenne de session: ";
    i >> stat->dureeMoySession;
    int choix;
    while(1)
    {
        cout<<"\n taper 1:personne, 2:client ,3:membre"<<endl;
        i>>choix;
        if(i.eof()) break;
        if(choix==1)
        {
            personne* p=new personne();
            i>>*p;
            stat->tabl.push_back(p);
        }
        else if (choix==2)
        {
            client*p=new client();
            i>>*p;
            stat->tabl.push_back(p);
        }
        else if(choix==3)
        {
            membre*p=new membre();
            i>>*p;
            stat->tabl.push_back(p);
        }
    }
    return i;
}
