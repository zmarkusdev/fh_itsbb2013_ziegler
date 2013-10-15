/**
 * Schreiben Sie folg. Programm so um, dass jede Ausgabezeile mit der Zeilennummer (6stelliges Feld) beginnt:
 * @author Markus Ziegler (Jahrgang: 2013)
 * @file HUE03_MYCAT.c
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

int main(){
	WINECLIPSE; // WinEclipse Workaround

	// Program start

	// Variable definition:
	int ch;
	int lineNumber = 1; // Line number count variable

	// INITIAL output current lineCount:
	printf("%-6d",lineNumber);
	lineNumber++;

	// Read user input and output line numbers after newline char
	while ( (ch= fgetc(stdin)) != EOF){
		fputc(ch, stdout);
		if(ch == '\n'){
			printf("%-6d",lineNumber); // Output linenumber with 6 digits left bound
			lineNumber++;
		}
	}


	// Program end
	PAUSE;
	return EXIT_SUCCESS;
}
