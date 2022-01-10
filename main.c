#include <stdio.h>
#include <stdlib.h>
#include "Carre.h"


int main(int argc, char *argv[]) {
	
	struct Point * tete;
	
	tete = inserer_point_parTete(tete, 3, 4, 3.2, 4.2);
	affiche(tete, 3);
	
	struct Carre *square;
	
	square = inserer_carrer(square, tete, 3, 4);
	affich_carer(square);
	
	
	
	return 0;
}
