#include <stdlib.h>
#include <stdio.h>


struct Point{
	double x, y; 
	int num; 
	struct Point* suivant;
};



struct Point* inserer_point_parTete(struct Point* lis, int n, int m, double L, double l){
	
	struct Point* p;
	int i, j;
	
	for(j=0;j<m;j++){
		for(i=0; i<n; i++){
			
			p = (struct Point*)malloc(sizeof(struct Point));
			p->num = (j * n) + i + 1;
			p->x   = (i)*L/(n-1);
			p->y   = (j)*l/(m-1);
			p->suivant = lis;
			lis = p;
		}
	}
	return lis;
}


void affiche(struct Point* lis , int n){
	struct Point* p;

	p= lis;
	int i;
	
	while(p){
		printf("%d: (%4.3lf , %4.3lf)\t", p->num, p->x, p->y);
		p = p->suivant;
		i++;
		if(i == n){
			printf("\n");
			i = 0;
		}
	}
}


///////////// search function using number

struct Point* recherche(struct Point* lis, int val){
	
	struct Point* p; 
	p = lis; 
	
	while(p){
		if(p->num == val) return p;
		p = p->suivant;
	}
	
	return p;	
}


