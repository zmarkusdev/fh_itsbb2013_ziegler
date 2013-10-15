/**
 * Berechnung der Quadratwurzel der Zahl a durch die Newton-Iteration (=HERONsche Formel):
 * x n+1 =  ( x n + a / x n ) / 2
 * @author Markus Ziegler (Jahrgang: 2013)
 * @file HUE3_U_ATOI.c
 * @date 12.10.2013
 * @date_modified 15.10.2013
 * Geschätzter Zeitaufwand: 15 Minuten
 * Tatsächlicher Zeitaufwand: 15 Minuten
 * GIT-REPO: https://github.com/Kingviech/fh_itsbb2013_ziegler.git
 */

/*Includes:*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Defines:*/
#define PAUSE printf("Enter to continue...");fgetc(stdin);
/*
 * Eclipse console does not show output on Windows
 * In Eclipse CDT on Windows, standard output of the program being run or debugged is fully buffered,
 * because it is not connected to a Windows console, but to a pipe.
 * Either add fflush calls after every printf or add the following lines in the start of the main function:
 */
#define WINECLIPSE setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);

// Returns the square root of the given number in the given precision
double SqareRoot(double radicand, double precision){
	double old = 1.0;
	double new;
	int count = 0;

	new = (old + radicand / old ) / 2.0;

	while( fabs( new-old ) > precision){
		old = new;
		new = (old + radicand / old ) / 2.0;
		count++;
	}

	// Output of step count
	printf("Steps for sqrt operation: %i\n", count);

	return new;
}

int main(void) {
	WINECLIPSE; // WinEclipse Workaround

	// Variable definition
	double number;
	double precision;
	double result;

	// Input of number and precision
	printf("Please enter radicand:");
	scanf("%lf",&number);
	printf("Please enter precision (e.g. \"0.0001\"): ");
	scanf("%lf",&precision);


	// Calculation of the square root with the function SquareRoot
	result = SqareRoot(number,precision);

	// Output of the result:
	printf("Squareroot from radicand: %lf\t=\t%lf\tPrecision=%lf\n\n", number, result, precision);

	PAUSE;
	return EXIT_SUCCESS;
}
