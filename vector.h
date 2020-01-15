#include <stddef.h>

#ifndef __VECTOR2__
#define __VECTOR2__

typedef struct {
	void **data;
	size_t size;
	size_t capacity;
} s_vector;

typedef s_vector* p_s_vector;

p_s_vector vector_alloc(size_t n);

void vector_free(p_s_vector p_vector);

void vector_set(p_s_vector p_vector, size_t i, double v);

double get(p_s_vector p_vector, size_t i);

void vector_insert(p_s_vector p_vector, size_t i, double v);

void vector_erase(p_s_vector p_vector, size_t i);

void vector_push_back(p_s_vector p_vector, double v);

void vector_pop_back(p_s_vector p_vector);

void vector_clear(p_s_vector p_vector);

int vector_empty(p_s_vector p_vector);

size_t vector_size(p_s_vector p_vector);



#endif
