/**
 * Das Programm soll unter Verwendung von Schleifen folgende Folge ausgeben:
 * 1 1 2 3 5 8 13 21 34 55 …
 * Es sollen die ersten 30 Zahlen ausgegeben werden.

 * @author Markus Ziegler (Jahrgang: 2013)
 * @file HUE3_FIB.c
 * @date 15.10.2013
 * @date_modified 15.10.2013
 * Geschätzter Zeitaufwand: 5 Minuten
 * Tatsächlicher Zeitaufwand: 5 Minuten
 * GIT-REPO: https://github.com/Kingviech/fh_itsbb2013_ziegler.git
 */

#include <stdio.h>
#include <stdlib.h>

/*Defines:*/
#define PAUSE printf("Enter to continue...");fgetc(stdin);
/*
 * Eclipse console does not show output on Windows
 * In Eclipse CDT on Windows, standard output of the program being run or debugged is fully buffered,
 * because it is not connected to a Windows console, but to a pipe.
 * Either add fflush calls after every printf or add the following lines in the start of the main function:
 */
#define WINECLIPSE setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);

// Write Fibonnaci numbers till the given border
void WriteFibNumbers(int border){
	int first = 0;
	int second = 1;
	int next = first + second;
	int count = 2;

	printf("Fibonnaci numbers till border: %i\n",border);
	printf("%i\n",first);
	printf("%i\n",second);

	while(count < border) {
		printf("%i\n",next);
		first = second;
		second = next;
		next = first + second;
		count++;
	}
}


int main(void) {
	WINECLIPSE;

	// Variable Definitions:
	int border;

	printf("Please enter border for fibonnaci number output: ");
	scanf("%i",&border);

	WriteFibNumbers(border);

	PAUSE;
	return EXIT_SUCCESS;
}
