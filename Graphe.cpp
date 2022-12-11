
#include"Graphe.h"

using namespace std;


Graphe::Graphe(unsigned int l , unsigned int c){
  this-> l = l ;
  this-> c = c ;
  Sommet = new float [l*c] ;
}

//affectation
Graphe::Graphe(Graphe & G){
  this-> l = G.l ;
  this-> c = G.c ;
  this-> Sommet = G.Sommet ;
}

//destructeur
Graphe::~Graphe(){
    delete [] Sommet;
}

//Renvoyer l'indice Global en fct de sa position (i,j)
int Graphe::indiceSommet(unsigned int i ,unsigned int  j)const{
    if(i<= l && j <= c) return i*c + j;
    else return -1;
}


//fct d'altitude
//altitude dans tab 2d
float Graphe::altitude(unsigned int i ,unsigned int  j)const{
    if(i<= l && j <= c) return Sommet[i*c + j];
    else return -1;
}

//altitude dans tab 1d
float Graphe::altitudeIndice( unsigned int i )const{
    if(i<= l*c) return Sommet[i];
    else return -1;
}

//Prend en paramètre un voisin et un sens 
//s => Sud , n=> Nord , o => Ouest , e => Est   
//S'il existe , renvoyer son indice
int Graphe::indiceVoisin(unsigned int i , const char d){
    switch (d){
    case 's' :
    if (i + c <= l*c -1) return i+c ;
    else return -1;
    
    case 'n' : 
    if(i>=c) return i-c ;
    else return -1;
    
    case 'e' :
    if(i%c <c-1 ) return i+1 ;
    else return -1;
    
    case 'o' :
    if(i%c > 0) return i-1;
    else return -1; 

    default : return -1; //il ya un problème qque part , chaque elt a au moins 2 voisins.
    }
   
}

void Graphe::afficherVoisin(unsigned int i , const char d){
  
  cout << altitudeIndice(indiceVoisin(i , d)) << endl;
   
}

Graphe::Graphe(const std::string & filename){

    ifstream fichier (filename.c_str());
    assert(fichier.is_open());

    fichier>> l >> c;
    Sommet = new float[l * c];

    for(unsigned int i=0 ; i<l*c ; i++){
          fichier>>Sommet[i];  
     } 
    
    fichier.close();

}


//fct d'affichage
void Graphe::afficher(){
    for(unsigned int i=0 ; i<l ; i++){
        for(unsigned int j=0 ; j<c ; j++){
            cout << "[" << Sommet[i*c + j] <<"]" ;
        }
        cout <<endl;
    }
    
}


//Fct membre pour modifier l'altitude d'un sommet 
void Graphe::setAltitude(unsigned int S , float v){
    Sommet[S] = v;
}




//fct membre calculant l'arrete entre 2sommets 
    //cdt a et b existent et sont voisins 
//float Graphe::valuation(unsigned int a){

//accesseur
unsigned int Graphe :: get_taille_tab(){return l*c;}

float Graphe :: get_alt(unsigned int S ){return Sommet[S];}
