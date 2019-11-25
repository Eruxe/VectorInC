#include <stdio.h>  
#include "random.h"

int main(int argc, char *argv[]){
	
	srand(time(NULL));
	printf("double : %lf \n",random_double(1,5));
	printf("float : %f \n",random_float(1,5));
	printf("int : %d \n", random_int(1,5));
	printf("size_t : %d \n", random_size_t(1,5));
	printf("size_t : %c \n", random_uchar('a','e'));
	
	size_t size_c = 10;
	unsigned char * c = malloc(sizeof(unsigned char)*size_c);
	random_init_string(c, size_c);
	printf("string: %s \n", c);

	return 0;
}
