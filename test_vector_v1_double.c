#include "vector_v1_double.h"

int main(int argc, char *argv[]){
	p_s_vector_v1_double p = vector_v1_double_alloc(10);
	printf("Taille du vecteur : %d\n", vector_v1_double_size(p));
	
	return 0;
}
