#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "vector_v2_double.h"


p_s_vector_v2_double vector_v2_double_alloc(){
	p_s_vector_v2_double p_vector = malloc(sizeof(s_vector_v2_double));
	p_vector->capacity = 16;
	p_vector->data =malloc(p_vector->capacity * sizeof(double));


	if(p_vector->data==NULL)
		return NULL;

	for(size_t i=0;i<n;i++){
		p_vector->data[i] = 0;
	}

	p_vector->size = 0; // Nombre d'element ref au depart

	return p_vector;
}

void vector_v2_double_free(p_s_vector_v2_double p_vector){
	free(p_vector->data);
	p_vector->data=NULL;
	free(p_vector);
	p_vector=NULL;
}

void vector_v2_double_set(p_s_vector_v2_double p_vector, size_t i,double v){
	// On ajoute rien si la capacite est ful
	if(i < p_vector->capacity){
		if (p_vector->data[i] == 0.0){
			p_vector->size++;
		} 
		p_vector->data[i] = v;
	}
}

double get(p_s_vector_v2_double p_vector, size_t i){
	if ( i >= p_vector->capacity) return -123456789.987654321;
	return p_vector->data[i];

}

void vector_v2_double_insert(p_s_vector_v2_double p_vector, size_t i, double v){

	
	//verifier que i est possible dans la data
	if (i < p_vector->size){
		p_vector->data =  realloc(p_vector->data,(p_vector->size+1)*sizeof(double));
		

		for(size_t j=p_vector->size-1;j>i;j--){
			p_vector->data[j]=p_vector->data[j-1];
		}
		p_vector->data[i] = v;

	} else {
		p_vector->data =  realloc(p_vector->data, (p_vector->size+1)*sizeof(double));
		p_vector->data[i]=v;

	}	
}

void vector_v2_double_erase(p_s_vector_v2_double p_vector, size_t i){
	if (i < p_vector->capacity){
		p_vector->data[i] = 0.0;
	}
}

void vector_v2_double_push_back(p_s_vector_v2_double p_vector, double v){
	p_vector->data[p_vector->capacity - 1] = v;
}

void vector_v2_double_pop_back(p_s_vector_v2_double p_vector){
	p_vector->data[p_vector->capacity - 1] = 0.0;
}

void vector_v2_double_clear(p_s_vector_v2_double p_vector){
	for (size_t i = 0; i < p_vector->capacity; i++){
		p_vector->data[i] = 0.0;
	} 
}

int vector_v2_double_empty(p_s_vector_v2_double p_vector){
	int flag = 1;
	for (size_t i = 0; i < p_vector->capacity; i++){
		if (p_vector->data[i] != 0.0)  {
			return 0;
		}
	}
	return flag;
}

size_t vector_v2_double_size(p_s_vector_v2_double p_vector){
	return p_vector->capacity; // pour renvoyer le nb de slot utilise faire : p_vector->size;
}

