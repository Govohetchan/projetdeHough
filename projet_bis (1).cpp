#include "Types_projet.hpp"
#include <iostream>






const int N = 50;
const int separ = N+30;


int main(){

IMAGE image_1 = vec_init_zero(N);

IMAGE image_2 = vec_init_zero(N);

IMAGE image_3 = vec_init_zero(N);

IMAGE imageMP_1 = vec_init_zero(N);

IMAGE imageMP_2 = vec_init_zero(N);

IMAGE imageMP_3 = vec_init_zero(N);


initAlea_droite(&image_1);

initAlea_droite_inverse(&image_2);

initAlea_droite_y_2x(&image_3);
separateur(separ);

std::cout <<"Image 1" << std::endl;
affichage_vec_vec(image_1);
separateur(separ);

std::cout <<"Transformation de Hough :Image 1" << std::endl;
tranceur_Hough_dans_mp(image_1,imageMP_1,N);
affichage_vec_vec(imageMP_1);
separateur(separ);

std::cout <<"Image 2" << std::endl;
affichage_vec_vec(image_2);
separateur(separ);

std::cout <<"Transformation de Hough :Image 2" << std::endl;
tranceur_Hough_dans_mp(image_2,imageMP_2,N);
affichage_vec_vec(imageMP_2);
separateur(separ);

std::cout <<"Image 3" << std::endl;
affichage_vec_vec(image_3);
separateur(separ);

std::cout <<"Transformation de Hough :Image 3" << std::endl;
tranceur_Hough_dans_mp(image_3,imageMP_3,N);
affichage_vec_vec(imageMP_3);
separateur(separ);

std::cout << " Images dans gimp: image et imageMP !" << std::endl;

image_gimp("p_image_1.ppm" ,image_1);

image_gimp("p_imageMP_1.ppm" ,imageMP_1);

image_gimp("p_image_2.ppm" ,image_2);

image_gimp("p_imageMP_2.ppm" ,imageMP_2);

image_gimp("p_image_3.ppm" ,image_3);

image_gimp("p_imageMP_3.ppm" ,imageMP_3);




    



return 0;
}