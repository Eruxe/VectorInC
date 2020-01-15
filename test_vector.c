#include "vector.h"
#include <stdio.h>


int main(int argc, char *argv[]){
	/*
	 * Partie insertion des éléments dans le vecteur
	 */
	p_s_vector_v2_double p = vector_v2_double_alloc();

	// Lecture du vecteur après creation
	printf("**** Lecture après création ****\n");
	for (int i = 0; i < p->capacity; i++){
		printf("Valeur %d du vecteur : %.2lf\n", i, p->data[i]);	
	}

	printf("Taille du vecteur : %d\n", p->size);
	printf("Capacite du vecteur : %d\n", p->capacity);
	vector_v2_double_insert(p, 0, 2.3);
	printf("Valeur element position 2 : %.2lf\n", get(p, 2));
	printf("*** Lecture après ajout unique ***\n");
	for (int i = 0; i < p->capacity; i++){
		printf("Valeur %d du vecteur : %.2lf\n", i, p->data[i]);
	}

	// On remplie le vecteur
	for (int i = 1; i < p->capacity; i++){
		vector_v2_double_insert(p, 0, 2.3+i);
	}
	printf("*** Lecture après remplissage ***\n");
	for (int i = 0; i < p->capacity; i++){
		printf("Valeur %d du vecteur : %.2lf\n", i, p->data[i]);
	}
	printf("Taille du vecteur : %d\n", p->size);
	printf("Capacite du vecteur : %d\n", p->capacity);

	vector_v2_double_insert(p, 3, 10.8);
	printf("Taille du vecteur : %d\n", p->size);
	printf("Capacite du vecteur : %d\n", p->capacity);
	printf("*** Lecture après remplissage d'un element en trop ***\n");
	for (int i = 0; i < p->capacity; i++){
		printf("Valeur %d du vecteur : %.2lf\n", i, p->data[i]);
	}

	/*
	 * Test des fonctions de suppression
	 */

	 for (int i = 17; i < p->capacity; i++){
	 	vector_v2_double_erase(p, 0);
	 }

	 printf("Taille du vecteur : %d\n", p->size);
         printf("Capacite du vecteur : %d\n", p->capacity);

	 vector_v2_double_erase(p, 0);
	 vector_v2_double_erase(p, 0);
	 vector_v2_double_erase(p, 0);
	 vector_v2_double_erase(p, 0);
	 printf("Taille du vecteur : %d\n", p->size);
	 printf("Capacite du vecteur : %d\n", p->capacity);
	 for (int i = 0; i < p->capacity; i++){
		printf("Valeur %d du vecteur : %.2lf\n", i, p->data[i]);
	 }
	return 0;
}
