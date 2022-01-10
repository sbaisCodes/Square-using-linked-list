#include<stdio.h>
#include<stdlib.h>
#include "Point_structure.h"


struct Carre{
	int numCarer; 
	struct Point* sommet[4]; 
	struct Carre* suiv;
};


struct Carre* inserer_carrer(struct Carre* lis_Care, struct Point* lis, int n, int m){
	
	
	struct Point* temp_lis = lis;
	struct Carre* carer_elementaire; 
	// pour boucler 
	int i, j;
	// compteur pour numero du careau
	int k = 1;
	
	for(j=0; j< m-1; j++){
		for(i=0; i< n-1; i++){
			carer_elementaire = (struct Carre*)malloc(sizeof(struct Carre));
			
			carer_elementaire->numCarer = k;
			carer_elementaire->sommet[0] = recherche(temp_lis, (j)*n+i+1);
			carer_elementaire->sommet[1] = recherche(temp_lis, (j)*n+i+2);
			carer_elementaire->sommet[2] = recherche(temp_lis, (j)*n+i+n+1+1);
			carer_elementaire->sommet[3] = recherche(temp_lis, (j)*n+i+n+1);
			carer_elementaire->suiv = lis_Care;
			lis_Care = carer_elementaire;
			k++;
		}
	}
	return lis_Care;
		
}



/////// afficher le maillage du carrer:



void affich_carer(struct Carre *lis){
	struct Carre *p=lis;

	printf("=============Squares=============\n");
	while(p!=NULL)
	      {
		printf("--------\n\t Square number : %d\n------------------------------------------------------------- \n",p->numCarer);
		printf("\t%d \t\t%d \t\t%d \t\t%d \n\t_____________________________________________________\n ",p->sommet[0]->num,p->sommet[1]->num,p->sommet[2]->num,p->sommet[3]->num);
		printf("\t%4.3f  \t\t%4.3f \t\t%4.3f \t\t%4.3f \n",p->sommet[0]->x,p->sommet[1]->x,p->sommet[2]->x,p->sommet[3]->x);
		printf("\t%4.3f  \t\t%4.3f \t\t%4.3f \t\t%4.3f \n",p->sommet[0]->y,p->sommet[1]->y,p->sommet[2]->y,p->sommet[3]->y);
		p=p->suiv;
        	}


}
