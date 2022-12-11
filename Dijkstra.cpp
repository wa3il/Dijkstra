#include "Dijkstra.h"
#include <limits>

using namespace std;

float inf = std::numeric_limits<float>::infinity();

void Dijkstra :: init_Dijk(Graphe & graph){
    for(unsigned int i = 0; i< graph.get_taille_tab(); i++){
         PCD[i].dist =  inf;
         PCD[i].pred = 0;
         PCD[i].couleur = "blanc";
    }
}

// S : indice de noeud de départ
void Dijkstra :: algo_de_dijk(Graphe & graph, int S){
    // le noeud de départ 
    PCD[S].couleur = "gris";
    PCD[S].dist = 0;

    while (PCD[i])
    {
        /* code */
    }
    
}