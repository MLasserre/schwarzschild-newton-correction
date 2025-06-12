/*****************************************************************************************
 * Nom ............ : parametre.h
 * Auteur ......... : MLasserre
 ****************************************************************************************/
#ifndef DEFVAR
#define EXTERN extern

#else 
#define EXTERN

#endif /* DEFVAR */
#include "precision.h"

EXTERN real r0, r0_point, theta0, theta0_point, k, c;      /* Parametres de Newton */
