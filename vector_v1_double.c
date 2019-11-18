#include <stddef.h>
#include <stdio.h>
#include "vector_v1_double.h"


p_s_vector_v1_double vector_v1_double_alloc(size_t n){
	p_s_vector_v1_double* p_vector = malloc(sizeof(p_s_vector_v1_double));

	p_vector->data =malloc(n*sizeof(double));

	if(p_vector->data==NULL)
		return NULL;

	for(size_t i=0;i<n;i++){
		*(p_vector->data+i)=0;
	}

	p_vector->size=n;

	return p_vector;
}

void vector_v1_double_free(p_s_vector_v1_double p_vector){
	free(p_vector->data);
	*p_vector->data=NULL;
	free(p_vector);
	*p_vector=NULL;
}
