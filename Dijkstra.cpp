#include "Dijkstra.h"
#include <limits>

using namespace std;

float inf = std::numeric_limits<float>::infinity();

Dijkstra ::Dijkstra(Graphe & g){
    taille = g.get_taille_tab();
    PCD = new Noeud [taille];
    for(unsigned int i = 0; i<taille ; i++){
         PCD[i].dist =  inf;
         PCD[i].pred = 0;
         PCD[i].couleur = "blanc";
    }
}

Dijkstra::~Dijkstra(){
    delete [] PCD ;
}


bool Dijkstra::eltsGris(){
    bool x = false;
    for(unsigned int i = 0; i< taille; i++){
        if (PCD[i].couleur == "gris") {
            x = true;
            break;
        }
    }
    return x;
}


std::vector<int> Dijkstra :: tab_lib(Graphe & g ,const std::string & filename) { 

    // le noeud de départ un tableau de noeud S
    ifstream in(filename , ios::in);
    std::string ligne;
    int x, y ,n;
    in >> n ;
    vector <int> tabS;
    for(int i=0 ; i < n ; i++){
        in >> x >> y ;
        tabS.push_back(g.indiceSommet(x,y));
        cout << "Librairie : "  << tabS[i] << endl;
    }
    in.close(); // serait automatiquement fermé à la sortie du bloc
    return tabS;
}

void Dijkstra::initLib(Graphe& g ,int j ){
  //pour chaque librairie
    
    for (unsigned int i =0 ; i < taille ; i++){
        PCD[i].couleur = "blanc";
    }

    PCD[j].couleur = "gris";
    PCD[j].dist = 0;

        for(int i = 0 ; i < 4 ; i++){
            if(g.indiceVoisin(j,i) >=0 ){
            int voisin = g.indiceVoisin(j,i);
                if(PCD[voisin].dist > g.valuation(j,voisin) ){ // vérifier ses voisins
                    PCD[voisin].couleur = "gris" ;
                    PCD[voisin].pred = j ; 
                    PCD[voisin].dist = g.valuation(j,voisin);
                }
            }   
        }   
    //on modifie la couleur des S en noir
    //son pred est lui meme
    PCD[j].couleur = "noir";
}

void Dijkstra::updateGrille(Graphe& g){
  
    float min ;
    int nmin;
    while(eltsGris()){
        min = inf;
        for(unsigned int i = 0; i< taille; i++){
            if(PCD[i].couleur == "gris" && PCD[i].dist < min){
                min = PCD[i].dist;
                nmin = i;
            }
        }
        for(int i = 0 ; i< 4 ; i++){
                if(g.indiceVoisin(nmin,i) >= 0) { // vérifier ses voisins
                int voisinMin = g.indiceVoisin(nmin,i); //le voisin min du voisin
                    if(PCD[voisinMin].couleur == "blanc"){
                        PCD[voisinMin].couleur = "gris";
                    }

                    if(PCD[nmin].dist + g.valuation(nmin, voisinMin) < PCD[voisinMin].dist){
                        if(PCD[voisinMin].couleur != "noir"){
                        PCD[voisinMin].dist = PCD[nmin].dist + g.valuation(nmin,voisinMin);
                        PCD[voisinMin].pred = nmin ;
                        }
                    }
                }
            
            PCD[nmin].couleur = "noir";

        }  
    }
}

void Dijkstra :: algo_de_dijk(Graphe & g ,const std::string & filename) {

   
    vector<int> tabS = tab_lib( g , filename); //vector dindices de lib 
    
    for(long unsigned int j = 0 ; j < tabS.size() ; j++){

        initLib(g,tabS[j]);
        //mise à jour des librairies
        for(long unsigned int j = 0 ; j < tabS.size() ; j++){
            PCD[tabS[j]].couleur = "noir";
            PCD[tabS[j]].pred = tabS[j];
        }
        
        updateGrille(g);


        //affichage 
  
    }
    for(unsigned int i = 0; i< taille; i++){
             cout << " la distance a partir de " << i  <<"[" << g.altitudeIndice(i)<<"]" << " est " << PCD[i].dist <<endl;
             cout << " son predécesseur ::  " << PCD[i].pred  << endl;
                 }
             cout << endl;    

}


