/*
 ============================================================================
 Name        : HUE3_PRIMZERLEGUNG.c
 Author      : Markus Ziegler
 Date        : 12.10.2013
 Version     :
 Copyright   : Your copyright notice
 Description :
 Siehe auch: 03-c-grundlagen/02-ueben/01-ue-c-grundlagen-ohne-array/
Nach Eingabe einer natürlichen Zahl n soll die Zerlegung von n in Primfaktoren ausgegeben werden.
Beispiel für eine Ausgabe zu n = 100:
        100 = 2 * 2 * 5 * 5 .

Hinweis: Teste die Teiler d = 2, 3, ...
im Erfolgsfalle, d.h wenn d ein Teiler von n ist, dann: n= n / d   (mit n > 1)
sonst: nimm den nächsten Teiler
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


void PrintPrimFactors(int number) {
	int factor = 2;
	printf("Primfactors of %d:",number);
	while(factor <= number) // if factor is greater then the current number, break out of loop
	{
		if(number % factor == 0){
			number /= factor;
			printf(" %d",factor);
		} else {
			factor++;
		}
	}
}

int main(void) {
	WINECLIPSE; // WinEclipse Workaround


	int number;
	printf("Input number for prim factor output: ");
	scanf("%d",&number);
	PrintPrimFactors(number);


	PAUSE;
	return EXIT_SUCCESS;
}
