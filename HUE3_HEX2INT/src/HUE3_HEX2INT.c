/**
 * Erstellen Sie das Programm hex2int.c, das nur gueltige Hex-Ziffern zur Umwandlung
 * in eine int-Variable verwendet. Die umgewandelte int-Zahl soll dann ausgegeben werden.
 * @author Markus Ziegler (Jahrgang: 2013)
 * @file HUE3_HEX2INT.c
 * @date 12.10.2013
 * @date_modified 15.10.2013
 * Geschätzter Zeitaufwand: 15 Minuten
 * Tatsächlicher Zeitaufwand: 15 Minuten
 * GIT-REPO: https://github.com/Kingviech/fh_itsbb2013_ziegler.git
 */

/*Includes:*/
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

int main(void) {
	WINECLIPSE; // WinEclipse Workaround

	// Variable definition
	int ch;
	int num=0; // Starting number is 0

	ch=fgetc(stdin); // or   ch=getchar()
	while (ch != '\n'){
		if(ch >= '0' && ch <='9') {// Only add the entered digit if it was between 0 and 9
			num= (16*num) + ch - '0'; // Add new digit: Old number *16 + entered digit - '0' (Ascii for the value 0)
		}
		else if(ch >= 'A' && ch <='F') { // Only add the entered digit if it was between A and F
			num= (16*num) + 10 + ch - 'A'; // Add new digit: Old number *16 + entered digit - 'A' (Ascii for the value A)
		}
		else if (ch >= 'a' && ch <= 'f') {// Only add the entered digit if it was between a and f
			num= (16*num) + 10 + ch - 'a'; // Add new digit: Old number *16 + entered digit - 'a' (Ascii for the value a)
		}
		ch= fgetc(stdin);
	}

	printf("\nThe entered number was %d, in HEX: %x\n", num, num);


	PAUSE;
	return EXIT_SUCCESS;
}
