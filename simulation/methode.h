/*****************************************************************************************
 * Nom ............ : methode.h
 * Auteur ......... : MLasserre
 ****************************************************************************************/

#ifndef METHODE_H
#define METHODE_H

void euler(int p, real* u_i, real t_i, real h, real* (*ptr_f) (real, real*, int),
           real* u_i_plus);

void milieu(int p, real* u_i, real t_i, real h, real* (*ptr_f) (real, real*, int),
            real* u_i_plus);

void runge_kutta3(int p, real* u_i, real t_i, real h, real* (*ptr_f) (real, real*, int),
                  real* u_i_plus);

void runge_kutta4(int p, real* u_i, real t_i, real h, real* (*ptr_f) (real, real*, int),
                  real* u_i_plus);

#endif /* METHODE_H */
