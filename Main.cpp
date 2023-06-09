#include "Dijkstra.h"

using namespace std;
int main(int argc, char * argv[]){
    Graphe test;
    test.testeRegression();

    Graphe G (argv[1]) ;
    G.afficher();
    G.setAltitude(3,6);
    cout << "changement de Sommet[4] -> valeur 7 "  << endl;
    //s => Sud , n=> Nord , o => Ouest , e => Est 
    // G.afficherVoisin(3,2); //ya pas de voisin est
    // G.afficherVoisin(3,0); //retourne le voisin sud de 55.
    // G.afficherVoisin(2,1); //retourne le voisin nord de 18.
    // G.afficherVoisin(0,3); //erreur.
    
    // cout << G.valuation(1,3) << endl;
    // cout << G.valuation(1,4) << endl;
    // cout << G.valuation(0,2) << endl;
     cout << G.valuation(0,1) << endl;
     cout << G.valuation(0,2) <<endl;   
    Dijkstra D (G);
    D.algo_de_dijk(G , argv[2]);
    D.voronoi(G,argv[2]);
    return 0;

}