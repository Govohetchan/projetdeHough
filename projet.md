# Semestre 2
# Projet C++ Année Académique 2022-2023
# Groupe 2 -Léon GOVOHETCHAN & Omar Ndiaye

# Objectif

Le but du notre projet est d'implémenter en language C++ un programme permettant de dectecter des segments (au format ppm). Notre programme doit être composé de fichiers .cpp et .hpp
 Ceci étant, nous devons écrire des programmes qui satisfont les points suivants:
 1- la transformée de Hough dans l'espace des paramètres (m,p) sur une image avec un format donnée ( ce format est contenu dans le document qui pose le problème qui nous est soumis).
 2- la transformée de Hough dans l'espace des paramètres (r, thêta) sur une image (un tableau 2D de C++) avec un format donné(ce format est contenu dans le document qui pose le problème qui nous est soumis)
 3-Supprime les doublons et choisir la meilleure droite.


#  Travail réalisé
#  Etape 1
Dans un premier temps, nous avons créé deux structures: POINT et DROITE puis un type de nom IMAGE. 
la droite est déterminée par un couple d'entier dont son coéfficient directeur et son ordonnée à l'origine, le point aussi par un couple d'entier qui sont l'abscisse et l'ordonnée.

# Etape 2

 A ce niveau nous avons une fonction "initAlea_droite()" qui prend en paramètre IMAGE et trace la droite d'équation y=x où les valeurs des pixels sont données de façon aléatoire. La fonction "initAlea_droite_inverse()" prenant en paramètre IMAGE se charge d'inverser la droite initilement tracée.

# Etape 3
Dans l'espace des paramètres (m,p), chaque point de la droite tracée dans l'espace (x,y) devient une droite, ainsi la fonction appartient_droite() qui prend IMAGE et deux entiers (coordonnées de points fournies au hasard) vérifie l'appartenance du point à l'image avant de le transformer en droite si nécessaire.

# Etape 4

Lors du tracé, la fonction "tranceur_Hough_bis()" se charge de faire la transformation (point en droite). Tout point dont l'abscisse ou l'ordonnée sort de la taille du tableau 2D sur laquelle l'image a été tracée subit une translation suivant les fonctions "translate_abscisse()" et "translate_ordonnée()".

# Etape 5
Pour vérifier le bon fonctionnement de la fonction codée, nous traçons la droite déquation y=2x.

 Le point fort de ce projet si nous pouvons nous exprimer de cette façon, est de réussir la première partie (le numéro 1 ci-dessus). Ainsi nous avons réussir cette partie sauf que notre code n'est pas très fin pour certaines droites en passant de l'espace de coordonnées (x,y) pour l'espace (m,p).

# Non réaliser
 Pour éradiquer les problèmes qui se posent à nous pour les points de l'espace (x,y) où les coéfficients directeurs de certaines droites obtenues sont très grands et l'ordonnée à l'origine n'apparait forcement pas dans le tableau, nous devons utiliser un autre espace de paramètre: l'espace (r, thêta) des coordonnées polaire. Cette partie n'est pas pu être réalisée dans notre projet.

 # Difficultés

Nous n'avons pas réussi les points suivants:
1- La fonction qui fait la transformation de l'espace de coordonnées (x,y) vers l'espace (m,p) ne marche pas pour toutes les droites. 
2- Elimination des doublons afin de selectionner la meilleure droite.


# Conclusion

En somme, nous nous sentons heureux à l'isuue de ce projet, bien qu'on a pas pu réeliser tout le travail qui a été demander, nous avons appris les  bases  techniques de traitement d'images.

