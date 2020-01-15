#include "vector.h"
#include "random.h"
#include <stdio.h>


int main(int argc, char *argv[]){
	/*
	 * Partie insertion des éléments dans le vecteur
	 */
	p_s_vector p = vector_alloc(16);

	size_t adressLeft = (size_t)&p;
	size_t adressRight = adressLeft+99999;

	// Lecture du vecteur après creation
	printf("**** Lecture après création ****\n");
	for (int i = 0; i < p->capacity; i++){
		printf("Valeur %d du vecteur : %p\n", i, p->data[i]);	
	}

	printf("Taille du vecteur : %d\n", p->size);
	printf("Capacite du vecteur : %d\n", p->capacity);

	size_t randomAdress1 = random_size_t(adressLeft, adressRight);
	vector_insert(p, 0, &randomAdress1);

	printf("Valeur element position 2 : %p\n", get(p, 2));

	printf("*** Lecture après ajout unique ***\n");
	for (int i = 0; i < p->capacity; i++){
		printf("Valeur %d du vecteur : %p\n", i, p->data[i]);
	}

	// On remplie le vecteur
	for (int i = 1; i < p->capacity; i++){
		size_t randomAdress2 = random_size_t(adressLeft, adressRight);
		vector_insert(p, 0, &randomAdress2);
	}

	printf("*** Lecture après remplissage ***\n");
	for (int i = 0; i < p->capacity; i++){
		printf("Valeur %d du vecteur : %p\n", i, p->data[i]);
	}

	printf("Taille du vecteur : %d\n", p->size);
	printf("Capacite du vecteur : %d\n", p->capacity);

	size_t randomAdress3 = random_size_t(adressLeft, adressRight);
	vector_insert(p, 3, &randomAdress3);

	printf("Taille du vecteur : %d\n", p->size);
	printf("Capacite du vecteur : %d\n", p->capacity);

	printf("*** Lecture après remplissage d'un element en trop ***\n");
	for (int i = 0; i < p->capacity; i++){
		printf("Valeur %d du vecteur : %p\n", i, p->data[i]);
	}

	/*
	 * Test des fonctions de suppression
	 */

	 for (int i = 17; i < p->capacity; i++){
	 	vector_erase(p, 0);
	 }

	 printf("Taille du vecteur : %d\n", p->size);
         printf("Capacite du vecteur : %d\n", p->capacity);

	 vector_erase(p, 0);
	 vector_erase(p, 0);
	 vector_erase(p, 0);
	 vector_erase(p, 0);
	 printf("Taille du vecteur : %d\n", p->size);
	 printf("Capacite du vecteur : %d\n", p->capacity);
	 for (int i = 0; i < p->capacity; i++){
		printf("Valeur %d du vecteur : %p\n", i, p->data[i]);
	 }
	return 0;
}
