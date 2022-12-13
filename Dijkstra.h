#ifndef _Dijkstra
#define _Dijkstra

#include "Graphe.h"
#include <queue>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <cassert>
#include <math.h>
#include <vector>

struct Noeud
{
    float dist;
    unsigned int pred; 
    std::string couleur;
};

class Dijkstra{
   
    private:
        // tableau des plus courtes distance
        Noeud *PCD;
        unsigned int taille ;
    
    public:
        
        //on initialise le tableau
        Dijkstra(Graphe & g ); //à partir d'un graphe

        //destructeur
        ~Dijkstra();
        
        //Check elets gris
        bool eltsGris();

        //fct pour créer un vector a partir dun fichier
        std::vector<int> tab_lib(Graphe & g ,const std::string & filename);

        //fct initialisant une lob donnée 
        void initLib(Graphe& g , int j);

        //maj de la grille (PCD)
        void updateGrille(Graphe& g );

        //algorithme de dijkstra a  partie dun graphe et un fichier
        void algo_de_dijk(Graphe & G ,const std::string & filename );


        int ancestre(unsigned int i);

        //pour chaque noeud on affiche son ancestre
        void voronoi(Graphe & g,const std::string & filename);
        
     
};


#endif 