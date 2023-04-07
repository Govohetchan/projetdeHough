#ifndef TYPES_PROJETH
#define TYPES_PROJETH

#include <iostream>
#include <vector>
#include <stdbool.h>
#include <math.h>
#include <fstream>
#include <string>

typedef std::vector<std::vector<int>> IMAGE;

struct POINT{
    int x = 0;
    int y = 0;


    void construire_point(int x,int y);
};


struct DROITE{

int m = 0;
int p = 0;

};

DROITE transf_Hough_un_m_p(POINT );

IMAGE vec_init_zero(unsigned int );

void initAlea_droite(IMAGE* );

void initAlea_droite_inverse(IMAGE* );

void initAlea_droite_y_2x(IMAGE* );

bool appartient_droite(IMAGE , int , int );

int translate_abscisse(int taille_image, float abscisse);

int translate_ordonnee(int taille_image, float ordonnee);

void tranceur_Hough_bis(IMAGE& imageMP, POINT pixel, int N );

void tranceur_Hough_dans_mp(IMAGE image, IMAGE& imageMP,int N);

void affichage(std::vector<int> vec, int taille);

void affichage_vec_vec(IMAGE vec);

void separateur(int longueur);
void image_gimp(std::string mon_Fichier,IMAGE image_mat);

#endif
