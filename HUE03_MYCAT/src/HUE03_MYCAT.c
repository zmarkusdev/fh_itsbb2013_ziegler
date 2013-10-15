/*
 ============================================================================
 Name        : HUE03_MYCAT.c
 Author      : Markus Ziegler
 Date		 : 12.10.2013
 Version     :
 Copyright   : Your copyright notice
 Description :
	Schreiben Sie folg. Programm so um, dass jede Ausgabezeile mit der Zeilennummer (6stelliges Feld) beginnt:

		//mycat.c  Eingabe nach Ausgabe
		#include <stdio.h>
		int main(){
			int ch;
			while ( (ch= fgetc(stdin)) != EOF)
				fputc(ch, stdout);

			return 0;
		}

	Aufruf: mycat.exe < eingabedatei.txt

		Eingabedatei: eingabedatei.txt
		Ein recht bekanntes Spiel ist das Nimm-Spiel (mit zwei m):
		Es werden z.B. 20 Münzen auf den Tisch gelegt, und die beiden Spieler

		Ausgabe:
		1     Ein recht bekanntes Spiel ist das Nimm-Spiel (mit zwei m):
		2     Es werden z.B. 20 Münzen auf den Tisch gelegt, und die beiden Spieler

 ============================================================================
 */


//mycat.c  Eingabe nach Ausgabe
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

int main(){
	WINECLIPSE; // WinEclipse Workaround


	int ch;
	int lineNumber = 1;

	printf("%-6d",lineNumber); // INITIAL output current lineCount
	lineNumber++;

	while ( (ch= fgetc(stdin)) != EOF){
		fputc(ch, stdout);
		if(ch == '\n'){
			printf("%-6d",lineNumber); // Output linenumber with 6 digits left bound
			lineNumber++;
		}
	}


	PAUSE;
	return EXIT_SUCCESS;
}
