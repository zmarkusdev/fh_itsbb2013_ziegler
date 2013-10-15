/*
 ============================================================================
 Name        : HUE3_PHI.c
 Author      : Markus Ziegler
 Date		 : 13.10.2013
 Version     :
 Copyright   : Your copyright notice
 Description :
 Die Eulersche PHI-Funktion gibt für jede natürliche Zahl n an, wie viele zu n teilerfremde natürliche Zahlen es gibt, die nicht größer als n sind:
 Das Programm liest n ein und gibt die Anzahl der zu n teilerfremden natürlichen Zahlen aus.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define PAUSE printf("Enter to continue...");fgetc(stdin);
/*
 * Eclipse console does not show output on Windows
 * In Eclipse CDT on Windows, standard output of the program being run or debugged is fully buffered,
 * because it is not connected to a Windows console, but to a pipe.
 * Either add fflush calls after every printf or add the following lines in the start of the main function:
 */
#define WINECLIPSE setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);

// Calculates parameter base to the power of parameter exponent
// only for values >= 0 !
int Pow(int base, int exponent){
	int result = base;
	if(exponent==0)
	{
		return 1;
	} else {
		int i;
		for(i=1; i<exponent;i++){
			result *= base;
		}
		return result;
	}
}

/*
 * Euler phi function:
 * Counts the totatives of n, that is, the positive integers less than or equal to n that are relatively prime to n.
 * Source: http://en.wikipedia.org/wiki/Euler_phi
 */
int Phi(int number) {
	int factor=2;
	int sumFactors=1;
	int exponent = 0;

	while(factor <= number) // if factor is greater then the current number, break out of loop
	{
		// euler's phi function added to the standard prime factorization
		if(number % factor == 0){
			number /= factor;
			exponent++;
		} else {
			if(exponent > 0){
				sumFactors *= Pow(factor,exponent-1) * (factor-1); // for the formula for the euler's phi function look at wikipedia source link
				exponent = 0;
			}
			factor++;
		}
	}
	if(exponent > 0){
		// The last factor must be added to the sum, because the loop will exit on factor <= number and this causes the ignoration of the last factor.
		// Workaraound is this if.
		sumFactors *= Pow(factor,exponent-1) * (factor-1);
	}

	return sumFactors;
}

int main(void) {
	WINECLIPSE; // WinEclipse Workaround

	int number;
	int totativeCount;
	printf("Enter digit for Euler's phi function phi(n):\nn=");
	scanf("%d",&number);

	totativeCount = Phi(number);
	printf("\n\nphi(%d) = %d\n\n", number, totativeCount);


	PAUSE;
	return EXIT_SUCCESS;
}
