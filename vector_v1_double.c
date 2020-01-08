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

	if( i < p_vector->size){
		p_vector->data[i] = v;
	}
}

double get(p_s_vector_v1_double p_vector, size_t i){
	if ( i >= p_vector->size) return -123456789.987654321;
	return p_vector->data[i];

}

void vector_v1_double_insert(p_s_vector_v1_double p_vector, size_t i, double v){

	
	if (i < p_vector->size){
		double * temp = realloc(p_vector->data, (++p_vector->size) * sizeof(double));
		if (temp != NULL){
			p_vector->data = temp;
		}
	
		for(size_t j=p_vector->size-1;j>i;j--){
			p_vector->data[j]=p_vector->data[j-1];
		}
		p_vector->data[i] = v;

	} else {
		double *temp = realloc(p_vector->data, (++p_vector->size) * sizeof(double));
		if (temp != NULL){
			p_vector->data =  temp;
			p_vector->data[i]=v;
		}
		
	}
	

	
}

void vector_v1_double_erase(p_s_vector_v1_double p_vector, size_t i){
	// On copie la data puis on realloue
	if (i < p_vector->size && p_vector->size > 1){

		for (size_t k = i; k < p_vector->size-1; k++){
			p_vector->data[k] = p_vector->data[k+1];
		}

		p_vector->size-=1;
		double *arr = malloc(sizeof(double) * p_vector->size);
		for (int i = 0; i < p_vector->size; i++){
			arr[i] = p_vector->data[i];
		}
		p_vector->data = arr;

		//p_vector->data = realloc(p_vector->data, sizeof(double)*p_vector->size);
		
		

	} else if (i < p_vector->size && p_vector->size == 1){
		p_vector->data = NULL;
		p_vector->size = 0;
	}
}

void vector_v1_double_push_back(p_s_vector_v1_double p_vector, double v){
	double *temp =  realloc(p_vector->data, (++p_vector->size) * sizeof(double));
	if (temp != NULL){
		p_vector->data = temp;
		p_vector->data[p_vector->size - 1] = v;
	}
}

void vector_v1_double_pop_back(p_s_vector_v1_double p_vector){
	if (p_vector->size ==  1){
		p_vector->data = NULL;
	} else {
		double *temp = realloc(p_vector->data, (--p_vector->size) * sizeof(double));
		if (temp != NULL){
			p_vector->data = temp;
		}
	}
}

void vector_v1_double_clear(p_s_vector_v1_double p_vector){
	p_vector->data = NULL;
	p_vector->size = 0;
}

int vector_v1_double_empty(p_s_vector_v1_double p_vector){
	return p_vector->data == NULL;
}

size_t vector_v1_double_size(p_s_vector_v1_double p_vector){
	return p_vector->size;
}

