/*****************************************************************************************
 * Nom ............ : scd_mb.c
 * Role ........... : Definition des seconds membre pour les equations a resoudre
 * Auteur ......... : MLasserre
 ****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

#include "precision.h"
#include "parametre.h"
#include "scd_mb.h"


/* Fonction qui definie le second membre pour newton */
real* newton(real t, real* u, int p){

	real* second_membre = NULL;

	second_membre = (real*)calloc((size_t)p, sizeof(real));
	if(second_membre == NULL){
		fprintf(stderr, "Erreur d'allocation !\n");
		exit(EXIT_FAILURE);
	}

	second_membre[0] = u[2];
	second_membre[1] = u[3];
	second_membre[2] = u[0]*u[3]*u[3] - k/u[0]/u[0] - c/u[0]/u[0]/u[0]/u[0];
	second_membre[3] = -2*u[2]*u[3]/u[0];

	return second_membre;
}
