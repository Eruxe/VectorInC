#include "vector_v2_double.h"
#include <stdio.h>


int main(int argc, char *argv[]){
	/*
	 * Partie insertion des éléments dans le vecteur
	 */
	p_s_vector_v2_double p = vector_v2_double_alloc();
	
	// Lecture du vecteur après creation
	printf("**** Lecture après création ****\n");
	for (int i = 0; i < p->capacity; i++){
		printf("Valeur %d du vecteur : %d\n", i, p->data[i]);
	}
	
	printf("Taille du vecteur : %d\n", p->size);
	printf("Capacite du vecteur : %d\n",p->capacity);
	vector_v2_double_insert(p, 0, 2.3);
	printf("Valeur element position 2 : %.2lf\n", get(p, 2));
	return 0;
}
