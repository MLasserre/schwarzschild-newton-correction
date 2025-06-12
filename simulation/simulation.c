/*****************************************************************************************
 * Nom ............ : simulation.c
 * Role ........... : 
 * Auteur ......... : MLasserre
 ****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "precision.h"
#include "scd_mb.h"
#include "methode.h"
#include "io.h"
#include "matrix_tools.h"

#define DEFVAR
#include "parametre.h"

#define FILENAME "solution_einstein.dat"


int main(void){

	/* ------------------------- DECLARATION DES VARIABLES ---------------------- */

    r0 = 0.;                  /* Conditions initiales */
    r0_point = 0.;
	theta0 = 0.;
	theta0_point = 0.;

    k = 0.;                   /* Ici dans le cas gravitationnel k = G x M */
	c = 0.;

    int i = 0;                /* Compteur */
	int p = 0;                /* Ordre des EDO x nombre de variables */
    int m = 0;                /* Ordre de la methode a employer */
    int taille = 0;           /* Contient la taille des tableaux calculee a partir */
	                          /* des temps initial et final et du pas h */

    real t_0 = 0.f;           /* Temps initial */
    real t_fin = 0.f;         /* Temps final */
    real h = 0.f;             /* Pas de discretisation */

    real *tt = NULL;          /* Tableau des abscisses */
    real **numerique = NULL;  /* Matrice contenant la solution numerique */
	                          /* Les elements (i,1) contiennent la position */
							  /* Les elements (i,2) contiennent la vitesse */

	/* -------------------------------------------------------------------------- */


    /* Debut dialogue avec utilisateur */
	printf("Valeur de p (dimension du probleme x ordre des EDO) : ");
    scanf("%d", &p);
    printf("p = %d\n\n", p);

    printf("Valeur initiale t_0 : ");
    scan_real(&t_0);
    printf("t_0 = %g\n\n", t_0);

    printf("Valeur finale t_fin : ");
    scan_real(&t_fin);
    printf("t_fin = %g\n\n", t_fin);

    printf("Valeur du pas h : ");
    scan_real(&h);
    printf("h = %g\n\n", h);

    printf("Valeur de r0 : ");
    scan_real(&r0);
    printf("r0 = %g\n\n", r0);

    printf("Valeur de r0_point : ");
    scan_real(&r0_point);
    printf("r0_point = %g\n\n", r0_point);

	printf("Valeur de theta0 : ");
    scan_real(&theta0);
    printf("theta0 = %g\n\n", theta0);

	printf("Valeur de theta0_point : ");
    scan_real(&theta0_point);
    printf("theta0_point = %g\n\n", theta0_point);

    printf("Valeur de k : ");
    scan_real(&k);
    printf("k = %g\n\n", k);

	printf("Valeur de c : ");
    scan_real(&c);
    printf("c = %g\n\n", c);

    printf("Ordre de la methode m : ");
    scanf("%d", &m);
    printf("m = %d\n\n", m);

    /* Fin dialogue avec utilisateur */


    taille = (int)((t_fin - t_0) / h + 1);

    tt = (real*)calloc((size_t)taille, sizeof(real));
	if(tt == NULL){
		fprintf(stderr, "Erreur lors de l'allocation !\n");
		exit(EXIT_FAILURE);
	} /* Test du bon fonctionnement de l'allocation */

	numerique = declare_matr(taille, p);

	for(i=0;i<taille;i++){
		tt[i] = t_0 + (real)i*h;
	} /* Remplissage du tableau des abscisses */

	/* Debut du remplissage de la matrice des
	ordonees numeriques en fonction de l'ordre choisi */
	numerique[0][0] = r0;
	numerique[0][1] = theta0;
	numerique[0][2] = r0_point;
	numerique[0][3] = theta0_point;

	printf("Calcul en cours...\n");
    switch(m){
		case 1 :            /* Methode d'euler explicite */
			for(i=1;i<taille;i++){
				euler(p, numerique[i-1], tt[i-1], h, &newton, numerique[i]);
			}
			break;

		case 2 :            /* Methode du point milieu */
			for(i=1;i<taille;i++){
				milieu(p, numerique[i-1], tt[i-1], h, &newton, numerique[i]);
			}
			break;

		case 3 :            /* Methode de Runge-Kutta d'ordre 3 */
			for(i=1;i<taille;i++){
				runge_kutta3(p, numerique[i-1], tt[i-1], h, &newton, numerique[i]);
			}
			break;

		case 4 :            /* Methode de Runge-Kutta d'ordre 4 */
			for(i=1;i<taille;i++){
				runge_kutta4(p, numerique[i-1], tt[i-1], h, &newton, numerique[i]);
			}
			break;

		default :
			fprintf(stderr, "Erreur !\n");
			exit(EXIT_FAILURE);
			break;
	}
	printf("Calcul termine.\n");
	/* Fin du remplissage */
	
	/* Ecriture des tableaux 1D tt */
    /* et du tableau 2D numerique dans un fichier */
	write_data(FILENAME, taille, tt, numerique); 

	free_matr(taille, numerique);
    free(tt);

    exit(EXIT_SUCCESS);
}
