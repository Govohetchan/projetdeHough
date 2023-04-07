
#include "Types_projet.hpp"





DROITE transf_Hough_un_m_p(POINT A){  // le point doit appartenire à la droite
    DROITE d;

    d.m = -A.x;
    d.p = A.y;

    return d;
}


IMAGE vec_init_zero(unsigned int taille){
   IMAGE image(taille);

   unsigned int i,j;
   for(i=0; i < taille; ++i){
    for(j = 0; j < taille; ++j){
        image[i].push_back(0);
    }
   }
   return image;
}

void initAlea_droite(IMAGE* t){
    /*
    la fonction initAlea_vec_vec() permet d'initialiser l'image de départ.

    */

    srand(time(NULL));

    unsigned int i;

    for( i= 0; i<(*t).size(); ++i){
        std::vector<int> vectCourant;
        for(unsigned int j= 0; j < (*t)[i].size(); ++j){
            if(i==j){
                vectCourant.push_back(rand()%256);
            }else{
                vectCourant.push_back(0);
            }
            
        }
        (*t)[i] = vectCourant;
    }
      
}

void initAlea_droite_inverse(IMAGE* t){
    /*
    la fonction initAlea_vec_vec() permet d'initialiser l'image de départ.

    */

    srand(time(NULL));

    unsigned int i;

    for( i= 0; i<(*t).size(); ++i){
        std::vector<int> vectCourant;
        for(unsigned int j= 0; j < (*t)[i].size(); ++j){
            if(i+j==(*t).size() -1){
                vectCourant.push_back(rand()%256);
            }else{
                vectCourant.push_back(0);
            }
            
        }
        (*t)[i] = vectCourant;
    }
      
}

void initAlea_droite_y_2x(IMAGE* t){
    /*
    la fonction initAlea_vec_vec() permet d'initialiser l'image de départ.

    */

    srand(time(NULL));

    unsigned int i;

    for( i= 0; i<(*t).size(); ++i){
        std::vector<int> vectCourant;
        for(unsigned int j= 0; j < (*t)[i].size(); ++j){
            if(abs(j-2.0*i)==0 ){
                vectCourant.push_back(rand()%256);
            }else{
                vectCourant.push_back(0);
            }
            
        }
        (*t)[i] = vectCourant;
    }
      
}


bool appartient_droite(IMAGE image, int x, int y){
    
    if(image[y][x] != 0){
        return true;    
    }

    return false;
    
}



int translate_abscisse(int taille_image, float abscisse){

    float milieu_nul = (taille_image/2) +1;
    return  (int)((milieu_nul + abscisse));
}

int translate_ordonnee(int taille_image, float ordonnee){

    float milieu_nul = (taille_image/2) - 1;
    return  (int)((milieu_nul + ordonnee));
}

void tranceur_Hough_bis(IMAGE& imageMP, POINT pixel, int N ){
    unsigned int i,j;
    
    DROITE dmp =  transf_Hough_un_m_p(pixel);


        if(abs(dmp.m) <= 0){

            for(j = 0; j < imageMP.size(); ++j){
                int p_c;
                float p_teste = dmp.m*j + dmp.p;
               
                p_c = translate_ordonnee(imageMP.size(),p_teste);
                
                if(p_c >= 0 && p_c < N){
                    imageMP[p_c][j]+=1;
                }   
            }

        }else{

            for(i = 0; i < imageMP.size(); ++i){

                int m_c;
                
                float m_teste = (float)((int)i - dmp.p)/dmp.m;
                m_c = translate_abscisse(imageMP.size(),m_teste);
                if(m_c >= 0 && m_c < N){
                    imageMP[i][m_c]+=1;
                }
                

            }
        }

}
        

void tranceur_Hough_dans_mp(IMAGE image, IMAGE& imageMP,int N){

    unsigned int i,j;

    for(i=0; i < image.size(); ++i){

        for(j=0; j < image[i].size(); ++j){

            if(appartient_droite(image,j,i)){
    
                    POINT pixel;
                    pixel.x = j;
                    pixel.y = i;
                    tranceur_Hough_bis(imageMP,pixel,N);
                
                

            }
        }
    }

}

void affichage(std::vector<int> vec, int taille) 
{   
    /*
    affichage() permet d'afficher les elements d'un vecteur d'entiers.
    parametres: un vecteur d'entiers et sa taille entier.
    */
    int i;
    for (i = 0 ; i < taille; ++i )
        std::cout << vec[i]<<" ";
    std::cout << std::endl;
}


void affichage_vec_vec(IMAGE vec){

    /*
    affichage_vec_vec() permet d'afficher les elements d'un vecteur de vecteurs d'entiers.
    parametres: un vecteur de vecteurs d'entiers.
    */
    
    for (std::vector<int> val:vec){
        affichage(val, val.size());
        
    }

}

void separateur(int longueur){

    /*
    separatuer() sÃ©pare les affichages pour plus de visibilitÃ©s.
    parametres : un entier longueur d'affichage.
    */
    int i;
    for (i = 0; i < longueur; ++i){
        std::cout << "#";

    }
    std::cout << std::endl;
}
void image_gimp(std::string mon_Fichier,IMAGE image_mat){

    std::string const nomFichier(mon_Fichier);
    std::ofstream monFlux(nomFichier.c_str());

    unsigned int taille = image_mat.size();

    unsigned int i,j;

    if(monFlux)    
    {
        monFlux << "P3" << std::endl;
        monFlux << "#taille" << std::endl;
        monFlux << taille << " "<< taille << std::endl;
        monFlux << "#val max" << std::endl;
        monFlux << 255 << std::endl;
        monFlux << "#rvb" << std::endl;

        for(i = 0; i < taille; ++i){
            for(j= 0; j < taille; ++j){
                if (image_mat[i][j] != 0)
                {
                    monFlux << 255 << std::endl;
                    monFlux << 0 << std::endl;
                    monFlux << 0 << std::endl;
                }else{
                    monFlux << 255 << std::endl;
                    monFlux << 255 << std::endl;
                    monFlux << 0 << std::endl;
                }
                
            }
        }
        


    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }

}
