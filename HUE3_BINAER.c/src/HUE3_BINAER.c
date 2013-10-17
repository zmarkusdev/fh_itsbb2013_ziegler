/*
 * Demo fuer bitorientierte Operatoren
 * @author Markus Ziegler (Jahrgang: 2013)
 * @file HUE3_BINAER.c
 * @date 17.10.2013
 * @date_modified 17.10.2013
 * Geschätzter Zeitaufwand: 15 Minuten
 * Tatsächlicher Zeitaufwand: 15 Minuten
 * GIT-REPO: https://github.com/Kingviech/fh_itsbb2013_ziegler.git
 */

#include <stdio.h>
#include <stdlib.h>

#define BITBREITE sizeof(unsigned int)*8

void binaer(unsigned int);
#define PAUSE printf("Enter to continue...");fgetc(stdin);
/*
 * Eclipse console does not show output on Windows
 * In Eclipse CDT on Windows, standard output of the program being run or debugged is fully buffered,
 * because it is not connected to a Windows console, but to a pipe.
 * Either add fflush calls after every printf or add the following lines in the start of the main function:
 */
#define WINECLIPSE setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);

/* void binaer(unsigned int a)
   konst= 1000 0000
   wenn a mit konst AND verknuepft wird,
   so ist das Ergebnis eine '1', wenn das MSB-Bit von a '1'
   sonst ist das Ergebnis '0' */

void binaer(unsigned int a){
	unsigned int i, konst= 0;

	konst= 1 << (BITBREITE-1);    /* 1 mit folgenden Nullen */
	for (i= 0; i<BITBREITE; i++){
		if ((a&konst) == konst){
			putchar('1');
		}
		else{
			putchar('0');
		}
		a= a << 1;      /* das naechste bit nach vorne */
	}
	putchar('\n');
}


int main(void) {
	WINECLIPSE;

	unsigned int x= 1, y= 2, z=0;

	printf("\nx=%u -> \n", x);
	binaer(x);

	printf("y=%u -> \n",y);
	binaer(y);

	printf("z=%u -> \n",z);
	binaer(z);

	z= ~(~z >> 1);    /*1 mit folgenden Nullen */
	printf("z= ~(~z >> 1); z=%u -> \n",z);
	binaer(z);

	z= ~y;
	printf("z= ~y; z=%u -> \n",z);
	binaer(z);

	z= z & y;
	printf("z= z & y; z=%u -> \n",z);
	binaer(z);

	z= x | y;
	printf("z= x | y; z=%u -> \n",z);
	binaer(z);

	z= z ^ y;
	printf("z= z ^ y; z=%u -> \n",z);
	binaer(z);

	z= z << y;
	printf("z= z << y; z=%u -> \n",z);
	binaer(z);

	z= z >> y;
	printf("z= z >> y; z=%u -> \n",z);
	binaer(z);

	/* Ausgabe:
	x=1 ->
	00000000000000000000000000000001
	y=2 ->
	00000000000000000000000000000010
	z=0 ->
	00000000000000000000000000000000
	z= ~(~z >> 1); z=2147483648 ->
	10000000000000000000000000000000
	z= ~y; z=4294967293 ->
	11111111111111111111111111111101
	z= z & y; z=0 ->
	00000000000000000000000000000000
	z= x | y; z=3 ->
	00000000000000000000000000000011
	z= z ^ y; z=1 ->
	00000000000000000000000000000001
	z= z << y; z=4 ->
	00000000000000000000000000000100
	z= z >> y; z=1 ->
	00000000000000000000000000000001
	*/


	PAUSE;
	return EXIT_SUCCESS;
}
