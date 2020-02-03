#include <stdio.h>
#include <time.h>
#include "vector.h"
#include "random.h"
#include "my_struct.h"

#define display_struct(a) \
	do {\
        	printf("string struct : %s\n", a->chaine);\
		printf("nb : %lf\n", a->nb);\
	} while (0)

int main(int argc, char *argv[]){
	/*
	 * Partie insertion des éléments dans le vecteur
	 */
	srand(time(0));

	p_s_vector p = vector_alloc(16, &my_struct_alloc, &my_struct_free, &my_struct_copy);
   	p_s_my_struct p0 = my_struct_alloc();
	my_struct_randoms_init(p0);
	vector_insert(p, 0, p0);
	p_s_my_struct p1 = my_struct_alloc();
	p_s_my_struct p2 = my_struct_alloc();
	display_struct(p1);	
	get(p, 0, p1);
	display_struct(p1);
	vector_erase(p, 1);
	get(p, 0, p2);
	display_struct(p2);
	return 0;
}
