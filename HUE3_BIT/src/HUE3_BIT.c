/*
 * Ermittlung der Bitbreite ganzzahliger Datentypen
 * @author Markus Ziegler (Jahrgang: 2013)
 * @file HUE3_BIT.c
 * @date 17.10.2013
 * @date_modified 17.10.2013
 * Geschätzter Zeitaufwand: 15 Minuten
 * Tatsächlicher Zeitaufwand: 15 Minuten
 * GIT-REPO: https://github.com/Kingviech/fh_itsbb2013_ziegler.git
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

int main(void) {
	WINECLIPSE;

	unsigned int ganzzahl;
	long int lang;
	int breite= 0;

	ganzzahl = ~0;   /* alle bits setzen */
	while (ganzzahl != 0){
	  ganzzahl= ganzzahl << 1;  /* eine 0 von links shiften */
	  breite++;
	}
	printf("Die Breite einer INT-Zahl ist %d Bits\n", breite);

	lang = 1;
	for (breite= 1; lang > 0; breite ++){
		lang= lang << 1;
	}
	printf("Die Breite einer LONG-Zahl ist %d Bits\n", breite);


	PAUSE;
	return EXIT_SUCCESS;
}
