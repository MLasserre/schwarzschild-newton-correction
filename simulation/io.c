/************************************************************************************
 * Name ................... : io.c
 * Description ............ : Defines the `write_data` function, which writes the
 *                            arrays `tt`, numerical and exact, into a file, one
 *                            element per line.
 * Author ................. : MLasserre
 **************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

#include "precision.h"
#include "io.h"


void scan_real(real* in){

	if(sizeof(real)==sizeof(float))
		scanf("%f", (float*)in);
	else if(sizeof(real)==sizeof(double))
		scanf("%lf", (double*)in);
	else
		fprintf(stderr, "Error: invalid size for type 'real'\n");
}


void write_data(const char* filename, int n, const real* tt, real** numerical){

	FILE* file = NULL;
	int i = 0;

	file = fopen(filename, "wb");

	if(file == NULL){
		fprintf(stderr, "Error opening file %s\n", filename);
		exit(EXIT_FAILURE);
	}

    /* Write the arrays into the file as three columns */
	for(i=0;i<n;i++){
		fprintf(file, "%g   %g   %g\n", tt[i], numerical[i][0], numerical[i][1]);
	}

	fclose(file);
	return;
}
