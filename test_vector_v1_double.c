#include "vector_v1_double.h"
#include <stdio.h>


int main(int argc, char *argv[]){
	size_t size = 10;
	p_s_vector_v1_double p = vector_v1_double_alloc(size);
	printf("Taille du vecteur : %d\n", p->size);
	
	return 0;
}
