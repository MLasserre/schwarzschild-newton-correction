/*****************************************************************************************
 * Nom ............ : methode.c
 * Role ........... : 
 * Auteur ......... : MLasserre
 ****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

#include "precision.h"
#include "methode.h"


void euler(int p, real* u_i, real t_i, real h, real* (*ptr_f) (real, real*, int),
           real* u_i_plus){

	int j = 0;

	real* stock = NULL;

	stock = (real*)calloc((size_t)p, sizeof(real));
	if(stock == NULL){
		fprintf(stderr, "Erreur d'allocation !\n");
		exit(EXIT_FAILURE);
	}
	
	stock = (*ptr_f)(t_i, u_i, p);

	for(j=0;j<p;j++){
		u_i_plus[j] = u_i[j] + h*stock[j];
	}

	free(stock);
}

void milieu(int p, real* u_i, real t_i, real h, real* (*ptr_f) (real, real*, int), real* u_i_plus){

	int j = 0;

	real* k1 = NULL;
	real* k2 = NULL;
	real* stock = NULL;

	stock = (real*)calloc((size_t)p, sizeof(real));
	if(stock == NULL){
		fprintf(stderr, "Erreur d'allocation !\n");
		exit(EXIT_FAILURE);
	}

	k1 = (*ptr_f)(t_i, u_i, p);

	for(j=0;j<p;j++){
		stock[j] = u_i[j] + k1[j]*h/2;
	}

	k2 = (*ptr_f)(t_i + h/2, stock, p);

	for(j=0;j<p;j++){
		u_i_plus[j] = u_i[j] + h*k2[j];
	}
	
	free(k1);
	free(k2);
	free(stock);

}

void runge_kutta3(int p, real* u_i, real t_i, real h, real* (*ptr_f) (real, real*, int), real* u_i_plus){

	int j = 0;

	real* k1 = NULL;
	real* k2 = NULL;
	real* k3 = NULL;
	real* stock = NULL;

	stock = (real*)calloc((size_t)p, sizeof(real));
	if(stock == NULL){
		fprintf(stderr, "Erreur d'allocation !\n");
		exit(EXIT_FAILURE);
	}

	k1 = (*ptr_f)(t_i, u_i, p);

	for(j=0;j<p;j++){
		stock[j] = u_i[j] + k1[j]*h/2;
	}

	k2 = (*ptr_f)(t_i + h/2, stock, p);

	for(j=0;j<p;j++){
		stock[j] = u_i[j] + (2*k2[j] - k1[j])*h;
	}

	k3 = (*ptr_f)(t_i + h, stock, p);

	for(j=0;j<p;j++){
		u_i_plus[j] = u_i[j] + (k1[j] + 4*k2[j] + k3[j])*h/6;
	}

	free(k1);
	free(k2);
	free(k3);
	free(stock);
}

void runge_kutta4(int p, real* u_i, real t_i, real h, real* (*ptr_f) (real, real*, int), real* u_i_plus){

	int j = 0;

	real* k1 = NULL;
	real* k2 = NULL;
	real* k3 = NULL;
	real* k4 = NULL;
	real* stock = NULL;
	
	stock = (real*)calloc((size_t)p, sizeof(real));
	if(stock == NULL){
		fprintf(stderr, "Erreur d'allocation !\n");
		exit(EXIT_FAILURE);
	}

	k1 = (*ptr_f)(t_i, u_i, p);
	
	for(j=0;j<p;j++){
		stock[j] = u_i[j] + k1[j]*h/2;
	}
	
	k2 = (*ptr_f)(t_i + h/2, stock, p);

	for(j=0;j<p;j++){
		stock[j] = u_i[j] + k2[j]*h/2;
	}

	k3 = (*ptr_f)(t_i + h/2, stock, p);

	for(j=0;j<p;j++){
		stock[j] = u_i[j] + k3[j]*h;
	}

	k4 = (*ptr_f)(t_i + h, stock, p);

	for(j=0;j<p;j++){
		u_i_plus[j] = u_i[j] + (k1[j] + 2*(k2[j] + k3[j]) + k4[j])*h/6;
	}

	free(k1);
	free(k2);
	free(k3);
	free(k4);
	free(stock);
}
