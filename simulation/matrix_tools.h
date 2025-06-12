/*****************************************************************************************
 * Nom ............ : matrix_tools.h
 * Auteur ......... : MLasserre
 ****************************************************************************************/

#ifndef MATRIX_TOOLS
#define MATRIX_TOOLS

real** declare_matr(int n_ligne, int n_colonne);

void free_matr(int n_ligne, real** matrice);

void print_matr(int n_ligne, int n_colonne, real** matrice);

void print_vecr(int size, real* vecteur);

/* Fonction calculant l'indice (i,j) d'une matrice applatie */
int kcm(const int nlin,const int ncol,const int ilin, const int jcol);

#endif /* MATRIX_TOOLS */
