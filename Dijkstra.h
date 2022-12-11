#ifndef _Dijkstra
#define _Dijkstra

#include "Graphe.h"
#include <queue>

struct Noeud
{
    float dist;
    int pred; 
    std::string couleur;
};

class Dijkstra{
    private:
        // tableau des plus courtes distance
        priority_queue <Noeud> PCD;

        
    public:
        //on initialise le tableau
        void init_Dijk(Graphe & graph);

        // on éffectue l'algo à partir d'un noeud de départ S
        void algo_de_dijk(Graphe & graph,int S);
};


#endif 