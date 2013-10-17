/**
 * Schreiben Sie ein Programm namens kreisPunkt.c, das feststellt, ob ein gegebener Punkt P(Px,Py) auf der Kreislinie oder innerhalb oder auﬂerhalb liegt. Der Kreis wird durch seinen Mittelpunkt M(Mx- und My- Koordinate) und den Radius (r) bestimmt.
 *
 * Hinweis: Abstand 2-er Punkte P(Px,Py) und M(Mx,My)
 * sqrt((Px-Mx)*(Px-Mx) + (Py-My)*(Py-My));
 *
 * Hinweis: Mathematische Funktionen verwenden
 *  	#include <math.h>
 *
 * Hinweis: ‹bersetzen
 * 	gcc kreisPunkt.c -lm -o kreisPunkt.exe
 *
 * Hinweis: Dateiumlenkung
 * 	./kreisPunkt.exe < kreisPunkt.txt
 *
 * kreisPunkt.txt
 * 10.0 10.0
 * 5.0 5.0
 * 5.0
 *
 * Bei diesem Beispiel ist P(10.0,10.0) M(5.0,5.0) r=5.0
 *
 * @author Markus Ziegler (Jahrgang: 2013)
 * @file HUE3_KREISPUNKT.c
 * @date 17.10.2013
 * @date_modified 17.10.2013
 * Gesch‰tzter Zeitaufwand: 15 Minuten
 * Tats‰chlicher Zeitaufwand: 15 Minuten
 * GIT-REPO: https://github.com/Kingviech/fh_itsbb2013_ziegler.git
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PAUSE printf("Enter to continue...");fgetc(stdin);
/*
 * Eclipse console does not show output on Windows
 * In Eclipse CDT on Windows, standard output of the program being run or debugged is fully buffered,
 * because it is not connected to a Windows console, but to a pipe.
 * Either add fflush calls after every printf or add the following lines in the start of the main function:
 */
#define WINECLIPSE setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);

// Calculates the distance from Point(destX,destY) to the Point(sourceX,destY);
double CalculateDistance(double sourceX, double sourceY, double destX, double destY){
	double distance;
	distance = sqrt( (destX - sourceX) * (destX - sourceX) + (destY - sourceY) * (destY - sourceY) ); // Formula for point distance
	return distance;
}



int main(void) {
	WINECLIPSE;

	// Circle middle coordinate variables:
	double mx;
	double my;

	// Point to check coordinate variables:
	double px;
	double py;

	double radius;

	double distance;


	// Input:
	printf("Please enter Px:\t");
	scanf("%lf",&px);

	printf("Please enter Py:\t");
	scanf("%lf",&py);

	printf("Please enter Mx:\t");
	scanf("%lf",&mx);

	printf("Please enter My:\t");
	scanf("%lf",&my);

	printf("Please enter radius:\t");
	scanf("%lf",&radius);

	// Calculation:
	distance = CalculateDistance(mx, my, px, py);

	// Output:
	if(distance > radius) {
		printf("Point is not in circle!\n");
	} else if(distance < radius) {
		printf("Point is in circle!\n");
	} else if(distance == radius) {
		printf("Point is on the circle line!\n");
	}

	PAUSE;
	return EXIT_SUCCESS;
}
