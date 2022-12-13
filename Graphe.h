#ifndef _Graphe
#define _Graphe

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <cassert>
#include <math.h>


class Graphe{

    private:

    //dimensions
    unsigned int l, c ;
    
    //L*C sommets - tab[i*l+j] = altitude 
    float *Sommet;
    

    public:

    //initialisation/Constructeur
    Graphe(unsigned int l ,unsigned int c);
    Graphe(const std::string & filename);
    Graphe();

    //affectation
    Graphe(Graphe & G);
    //destructeur
    ~Graphe();

    //Renvoyer l'indice Global en fct de sa position (i,j)
    int indiceSommet(unsigned int i ,unsigned int j)const;
    
    float altitude( unsigned int i , unsigned int  j)const;

    float altitudeIndice(unsigned int i)const;
    
    //Vérifier si un sommet est voisin
    //S'il existe , et si il est voisin , renvoyer son indice
    int indiceVoisin(unsigned  int i , int d);
    void afficherVoisin(unsigned int i , int d);
    
    bool checkVoisin(int a , int b );
    //fct membre calculant l'arrete entre 2sommets 2 indices.
    //cdt a et b existent et sont voisins 
    float valuation(unsigned int a ,unsigned int b );
    
    //Fct d'affichage de la grille 
    void afficher();

    

    //Fct membre pour modifier l'altitude d'un sommet 
    void setAltitude(unsigned int S,float v);

    //accesseurs
    unsigned int get_taille_tab();

    float get_alt(unsigned int S );
};

#endif