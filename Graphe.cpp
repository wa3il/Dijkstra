
#include"Graphe.h"

using namespace std;

Graphe::Graphe():l(0),c(0),Sommet(nullptr){}

Graphe::Graphe(unsigned int li , unsigned int ci):l(li),c(ci){
    assert((l*c)>=0);
    Sommet = new float [l*c] ;
}

//affectation
Graphe::Graphe(Graphe & G){
  this-> l = G.l ;
  this-> c = G.c ;
  this-> Sommet = G.Sommet ;
}


//a partir dun fichier
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

//destructeur
Graphe::~Graphe(){
    delete [] Sommet;
}

///////////////////////////////////////////////////////////////////////////////////////

//Renvoyer l'indice Global en fct de sa position (i,j)
int Graphe::indiceSommet(unsigned int i ,unsigned int  j)const{
    if(i< l && j < c) return i*c + j;
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

///////////////////////////////////////////////////////////////////////////////////

//Prend en paramètre un voisin et un sens 
//0 => Sud , 1=> Nord  , 2 => Est  , 3 => Ouest 
//S'il existe , renvoyer son indice
int Graphe::indiceVoisin(unsigned int i , int d){
    switch (d){
    case 0 :
    if (i + c <= l*c -1) return i+c ;
    else return -1;
    
    case 1 : 
    if(i>=c) return i-c ;
    else return -1;
    
    case 2 :
    if(i%c <c-1 ) return i+1 ;
    else return -1;
    
    case 3 :
    if(i%c > 0) return i-1;
    else return -1; 

    default : return -1; //il ya un problème qque part , chaque elt a au moins 2 voisins.
    }
   
}

void Graphe::afficherVoisin(unsigned int i , int d){
  
  cout << altitudeIndice(indiceVoisin(i , d)) << endl;
   
}

bool Graphe::checkVoisin(int a , int b ){
    bool trouve = false;
    for(int i =0 ; i <4 ;i++){
        if (Sommet[indiceVoisin(a,i)] == Sommet[b]) {  
        trouve = true ;    
        break;
        }
    }
    return trouve;
}

//fct membre calculant l'arrete entre 2sommets 2 indices.
    //cdt a et b existent et sont voisins 
float Graphe::valuation(unsigned int a ,unsigned int b ){
    if(checkVoisin(a,b))  return sqrt( 1 + pow((Sommet[a]-Sommet[b]),2)) ;
    else return -1;
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


//accesseur
unsigned int Graphe :: get_taille_l(){return l;}
unsigned int Graphe :: get_taille_c(){return c;}

float Graphe :: get_alt(unsigned int S ){return Sommet[S];}

void Graphe :: testeRegression(){
    Graphe g(2,1);
    g.setAltitude(0,5);
    g.setAltitude(1,2);

    //l'indice sur tableau 1D
    assert(g.indiceSommet(1,0) == 1);

    //l'altitude du première élément
    assert(g.altitude(0,0)==5);
    assert(g.altitudeIndice(1)==2);

    //on check si le premier et le deuxieme element sont voisin
    assert(g.checkVoisin(0,1) == true);

    //on a l'indice du voisin du sud
    assert(g.indiceVoisin(0,0)== 1);

    //teste de la valuation
    //assert(g.valuation(0,1)==3.16228);
    
}
