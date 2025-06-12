/*****************************************************************************************
 * Nom ............ : matrix_tools.c
 * Role ........... : Fonction pour manipuler des matrices et des vecteurs
 * Auteur ......... : MLasserre
 ****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "precision.h"
#include "matrix_tools.h"


real** declare_matr(int n_ligne, int n_colonne){

	int i = 0;

	real** matrice = NULL;

	matrice = (real**)calloc((size_t)n_ligne, sizeof(real*));
	if(matrice == NULL){
		fprintf(stderr, "Erreur d'allocation !\n");
		exit(EXIT_FAILURE);
	}
	
	for(i=0;i<n_ligne;i++){
		matrice[i] = (real*)calloc((size_t)n_colonne, sizeof(real));
		if(matrice[i] == NULL){
			fprintf(stderr, "Erreur d'allocation !\n");
			exit(EXIT_FAILURE);
		}
	}

	return matrice;
}

void free_matr(int n_ligne, real** matrice){

	int i = 0;

	for(i=0;i<n_ligne;i++){
		free(matrice[i]);
	}

	free(matrice);
	return;
}

void print_matr(int n_ligne, int n_colonne, real** matrice){
	
	int i = 0;
	int j = 0;

	for(i=0;i<n_ligne;i++){
		for(j=0;j<n_colonne;j++){
			printf("%g  ", matrice[i][j]);
		}
		printf("\n");
	}
	return;
}

void print_vecr(int size, real* vecteur){

	int i = 0;

	for(i=0;i<size;i++){
		printf("%g  ", vecteur[i]);
	}
	printf("\n");
	return;
}


int kcm(const int nlin,const int ncol,const int ilin, const int jcol){
   int NCOL=ncol; NCOL++;
   return (ilin+nlin*jcol);
}
