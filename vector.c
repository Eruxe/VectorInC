#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"


p_s_vector vector_alloc(size_t n, void* (*allocator)(), void (*free)(void*), void (*copy)(void*, void*)){
	p_s_vector p_vector = malloc(sizeof(s_vector));
	p_vector->capacity = n;
	p_vector->data = malloc(p_vector->capacity * sizeof(void*));
	// On associe les pointeurs sur fonction à la structure
	p_vector->data_alloc = allocator;
	p_vector->data_free = free;
	p_vector->data_cpy = copy;

	if(p_vector->data == NULL)
		return NULL;

	for(size_t i=0;i<n;i++){
		p_vector->data[i] = p_vector->data_alloc();
	}

	p_vector->size = 0; // Nombre d'element ref au depart

	return p_vector;
}

void vector_free(p_s_vector p_vector){
	for (int i = 0; i < p_vector->capacity; i++){
		p_vector->data_free(p_vector->data[i]);
	}
	free(p_vector->data);
	p_vector->data=NULL;
	free(p_vector);
	p_vector=NULL;
}

void vector_set(p_s_vector p_vector, size_t i,void* v){
	// On ajoute rien si la capacite est ful
	if(i < p_vector->capacity){
		if (p_vector->data[i] == NULL){
			p_vector->size++;
		} 
		p_vector->data_cpy(p_vector->data[i], v);
	}
}

void get(p_s_vector p_vector, size_t i, void *p_data){
	if ( i >= p_vector->capacity) return;
	p_vector->data_cpy(p_data, p_vector->data[i]);

}

void vector_insert(p_s_vector p_vector, size_t i, void* v){
	if (i < p_vector->capacity){
		if (p_vector->capacity == p_vector->size){
			p_vector->capacity *= 2; 
			void **temp = realloc(p_vector->data, p_vector->capacity * sizeof(void*));
			
			if (temp != NULL){
				p_vector->data = temp;
			}
			
			for (size_t j = p_vector->capacity - 1; j > i; j--){
				p_vector->data[j] = p_vector->data[j-1];
			}

			p_vector->data_cpy(p_vector->data[i], v);
		} else {
			for (size_t j = p_vector->capacity - 1; j > i; j--){
				p_vector->data[j] = p_vector->data[j-1];
			}
			p_vector->data_cpy(p_vector->data[i], v);
		}
		p_vector->size++;
	}
}

void vector_erase(p_s_vector p_vector, size_t i){
	if (i < p_vector->size && p_vector->size > 1){
		if (p_vector->size <= p_vector->capacity / 4){
			p_vector->capacity /= 2;
			void **temp = malloc(sizeof(void*) * p_vector->capacity);
			// On initialise les données 
			for (int j = 0; j < p_vector->size; j++){
				temp[j] = p_vector->data_alloc();
			}
			// On copie les données
			for (int j = 0; j < p_vector->size; j++){
				p_vector->data_cpy(temp[j], p_vector->data[j]);
			}

			p_vector->data = temp;

		} else {
			for (size_t k = i+1; k < p_vector->size; k++){
				p_vector->data[k-1] = p_vector->data[k];
			}

			
			void **arr = malloc(sizeof(void*) * p_vector->size);
			
			// On initialise les données 
			for (int j = 0; j < p_vector->size; j++){
				arr[j] = p_vector->data_alloc();
			}

			for (int j = 0; j < p_vector->size; j++){
				p_vector->data_cpy(arr[j], p_vector->data[j]);
			}
			p_vector->data = arr;
		
		}
	
		
	p_vector->size--;	

	} else if (i < p_vector->size && p_vector->size == 1){
		p_vector->data = NULL;
		p_vector->size = 0;
	}

}

void vector_push_back(p_s_vector p_vector, void* v){
	vector_insert(p_vector, p_vector->size, v);	
}

void vector_pop_back(p_s_vector p_vector){
	vector_erase(p_vector, p_vector->size);
}

void vector_clear(p_s_vector p_vector){
	p_vector->size = 0;
	p_vector->capacity = 16;
	
	void **temp = realloc(p_vector->data, (p_vector->capacity) * sizeof(void*));
	if (temp != NULL){
		p_vector->data = temp;
	}
	
	// On reinitialise les valeurs à 0
	for (int i = 0; i < 16; i++){
		p_vector->data[i] = p_vector->data_alloc();
	}
 
}

int vector_empty(p_s_vector p_vector){
	return p_vector->size == 0;	

}

size_t vector_size(p_s_vector p_vector){
	return p_vector->capacity; // pour renvoyer le nb de slot utilisé faire : p_vector->size;
}
