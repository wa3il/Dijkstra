#include "Dijkstra.h"

using namespace std;
int main(){

    Graphe G ("./ExempleGraphe.txt") ;
    G.afficher();
    G.setAltitude(3,55);
    cout << "changement de Sommet[4] -> valeur 55 "  << endl;
    G.afficher();
    //s => Sud , n=> Nord , o => Ouest , e => Est 
    G.afficherVoisin(3,'e'); //ya pas de voisin est
    G.afficherVoisin(3,'s'); //retourne le voisin sud de 55.
    G.afficherVoisin(2,'n'); //retourne le voisin nord de 18.
    G.afficherVoisin(0,'o'); //erreur.
    
    Dijkstra(G);

    return 0;
}