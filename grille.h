#ifndef_Graphe
#define_Graphe

struct Sommet{
    int altitude;  
}



Class Graphe{

    public:

    //dimensions
    int l, h ;
    
    //L*H sommets - tab[i*l+j] = altitude
    Sommet tab[l*h]; 


    //initialisation/Constructeur
    Graphe();
    
    //affectation
    Graphe(Graphe G);

    //Renvoyer l'indice Global en fct de sa position (i,j)
    int indiceSommet(int i , int j);
    
    
    //Vérifier si un sommet est voisin
    //S'il existe , et si il est voisin , renvoyer son indice
    int indiceVoisin(Sommet V);

    //destructeur
    ~Graphe();

    //fct membre calculant l'arrete entre 2sommets 
    //cdt a et b existent et sont voisins 
    float arrete(sommet a , sommet b );

    //Fct membre pour modifier l'altitude d'un sommet 
    void modifierAltitude(Sommet S);

    //Fct d'affichage de la grille 
    void afficher();
}

#endif