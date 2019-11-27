#include "vector_v2_double.h"
#include <stdio.h>


int main(int argc, char *argv[]){
	size_t size = 10;
	p_s_vector_v2_double p = vector_v2_double_alloc(size);
	printf("Taille du vecteur : %d\n", p->size);
	vector_v2_double_insert(p, 2, 2.3);
	vector_v2_double_insert(p, 3, 6.3);
	vector_v2_double_insert(p, 4, 7.3);
	printf("Valeur de l'element position 4 : %lf\n", get(p, 4));
	vector_v2_double_set(p, 4, 0.7);
	printf("Valeur de l'element position 4 apres changement : %lf\n", get(p, 4));
	printf("Valeur de l'element hors du tableau : %lf\n", get(p, 111));
	vector_v2_double_push_back(p, 2.3);
	printf("Valeur du dernier elem : %lf\n", get(p, p->size - 1));
	printf("Taille du vecteur : %d\n", p->size);
	vector_v2_double_pop_back(p);
	printf("Valeur du dernier elem : %lf\n", get(p, p->size - 1));
	printf("Taille du vecteur : %d\n", p->size);
	vector_v2_double_clear(p);
	printf("Le vecteur est vide :  %s\n", vector_v2_double_empty(p) ? "Oui" : "Non");
	printf("Taille du vecteur : %d\n", vector_v2_double_size(p));

	return 0;
}
