/*
 ============================================================================
 Name        : HUE3_U_ATOI.c
 Author      : Markus Ziegler
 Date		 : 12.10.2013
 Version     :
 Copyright   : Your copyright notice
 Description :
 Siehe auch: 03-c-grundlagen/02-ueben/01-ue-c-grundlagen-ohne-array/
 Bringen Sie das folgende Programm u_atoi.c zum Laufen:
 Liest einen Ziffernstring ein und wandelt diesen in eine INT-Zahl um und gibt
 diese aus
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

int main(void) {
	WINECLIPSE; // WinEclipse Workaround


	int ch, num=0; // starting number is 0

	ch=fgetc(stdin); // or   ch=getchar()
	while (ch != '\n'){
		if(ch >= '0' && ch <='9') // Only add the digit to the number if it is between 0 and 9
		{
			num= (10*num) + ch - '0'; // Add the digit to the number: old number * 10 + entered digit - '0' (Ascii symbol for 0)
		}
		ch= fgetc(stdin);
	}

	printf("\n Die eingegebene Zahl war %d\n", num);


	PAUSE;
	return EXIT_SUCCESS;
}
