#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "vector_v2_double.h"


p_s_vector_v2_double vector_v2_double_alloc(){
	int n=16;
	p_s_vector_v2_double p_vector = malloc(sizeof(s_vector_v2_double));
	p_vector->capacity = 16;
	p_vector->data = malloc(p_vector->capacity * sizeof(double));


	if(p_vector->data == NULL)
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
	if (i < p_vector->capacity){
		if (p_vector->capacity == p_vector->size){
			p_vector->capacity *= 2; 
			double *temp = realloc(p_vector->data, p_vector->capacity * sizeof(double));
			
			if (temp != NULL){
				p_vector->data = temp;
			}
			
			for (size_t j = p_vector->capacity - 1; j > i; j--){
				p_vector->data[j] = p_vector->data[j-1];
			}

			p_vector->data[i] = v;
		} else {
			for (size_t j = p_vector->capacity - 1; j > i; j--){
				p_vector->data[j] = p_vector->data[j-1];
				printf("je passe par la\n");
			}
			p_vector->data[i] = v;
		}
		p_vector->size++;
	}
}

void vector_v2_double_erase(p_s_vector_v2_double p_vector, size_t i){
	if (i < p_vector->size && p_vector->size > 1){
		if (p_vector->size <= p_vector->capacity / 4){
			p_vector->capacity /= 2;
			double *temp = malloc(sizeof(double) * p_vector->capacity);
			// On copie les données
			for (int j = 0; j < p_vector->size; j++){
				temp[j] = p_vector->data[j];
			}
			p_vector->data = temp;

		} else {
			for (size_t k = i+1; k < p_vector->size; k++){
				p_vector->data[k-1] = p_vector->data[k];
			}

			p_vector->size-=1;
			
			double *arr = malloc(sizeof(double) * p_vector->size);
			for (int i = 0; i < p_vector->size; i++){
				arr[i] = p_vector->data[i];
			}
			p_vector->data = arr;
		
		}
	
		
	p_vector->size--;	

	} else if (i < p_vector->size && p_vector->size == 1){
		p_vector->data = NULL;
		p_vector->size = 0;
	}

}

void vector_v2_double_push_back(p_s_vector_v2_double p_vector, double v){
	vector_v2_double_insert(p_vector, p_vector->size, v);	
}

void vector_v2_double_pop_back(p_s_vector_v2_double p_vector){
	vector_v2_double_erase(p_vector, p_vector->size);
}

void vector_v2_double_clear(p_s_vector_v2_double p_vector){
	p_vector->size = 0;
	p_vector->capacity = 16;
	
	double *temp = realloc(p_vector->data, (p_vector->capacity) * sizeof(double));
	if (temp != NULL){
		p_vector->data = temp;
	}
	
	// On reinitialise les valeurs à 0
	for (int i = 0; i < 16; i++){
		p_vector->data[i] = 0.0;
	}
 
}

int vector_v2_double_empty(p_s_vector_v2_double p_vector){
	return p_vector->size == 0;	

}

size_t vector_v2_double_size(p_s_vector_v2_double p_vector){
	return p_vector->capacity; // pour renvoyer le nb de slot utilisé faire : p_vector->size;
}

