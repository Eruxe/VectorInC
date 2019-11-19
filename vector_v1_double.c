#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "vector_v1_double.h"


p_s_vector_v1_double vector_v1_double_alloc(size_t n){
	p_s_vector_v1_double p_vector = malloc(sizeof(s_vector_v1_double));

	p_vector->data =malloc(n*sizeof(double));

	if(p_vector->data==NULL)
		return NULL;

	for(size_t i=0;i<n;i++){
		p_vector->data[i] = 0;
	}

	p_vector->size = n;

	return p_vector;
}

void vector_v1_double_free(p_s_vector_v1_double p_vector){
	free(p_vector->data);
	p_vector->data=NULL;
	free(p_vector);
	p_vector=NULL;
}

void vector_v1_double_set(p_s_vector_v1_double p_vector, size_t i,double v){

	if(i<p_vector->size){
		p_vector->data[i] = v;
	}
}

double get(p_s_vector_v1_double p_vector, size_t i){
	if ( i >= p_vector->size) return -123456789.987654321;
	return p_vector->data[i];

}

void vector_v1_double_insert(p_s_vector_v1_double p_vector, size_t i, double v){

	//verifier que i est possible dans la data
	
	//Verifier l'adresse apres realloc pour ne pas avoir de bug
	p_vector->data = realloc((p_vector->size+1)*sizeof(double));

	for(size_t j=p_vector->size-1;j>i;j--){
		p_vector->data[j]=p_vector->data[j-1];
	}

	p_vector->data[i]=v;

}

void vector_v1_double_erase(p_s_vector_v1_double p_vector, size_t i){
	if (i < p_vector->size){
		p_vector->data[i] = 0.0;
	}
}

void vector_v1_double_push_back(p_s_vector_v1_double p_vector, double v){
	p_vector->data[p_vector->size - 1];
}

void vector_v1_double_pop_back(p_s_vector_v1_double p_vector){
	p_vector->data[p_vector->size - 1] = 0.0;
}

void vector_v1_double_clear(p_s_vector_v1_double p_vector){
	for (size_t i = 0; i < p_vector->size; i++){
		p_vector->data[i] = 0.0;
	} 
}

int vector_v1_double_empty(p_s_vector_v1_double p_vector){
	int flag = 1;
	for (size_t i = 0; i < p_vector->size; i++){
		if (p_vector->data[i] != 0.0)  {
			return 0;
		}
	}
	return flag;
}

size_t vector_v1_double_size(p_s_vector_v1_double p_vector){
	return p_vector->size;
}

