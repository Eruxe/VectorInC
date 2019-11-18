#include <stddef.h>

#ifndef __VECTOR__
#define __VECTOR__

typedef struct {
	double *data;
	size_t size;
} s_vector_v1_double;

typedef s_vector_v1_double* p_s_vector_v1_double;

p_s_vector_v1_double vector_v1_double_alloc(size_t n);

void vector_v1_double_free(p_s_vector_v1_double p_vector);

void vector_v1_double_set(p_s_vector_v1_double p_vector, size_t i, double v);

double get(p_s_vector_v1_double p_vector, size_t i);

void vector_v1_double_insert(p_s_vector_v1_double p_vector, size_t i, double v);

void vector_v1_double_erase(p_s_vector_v1_double p_vector, size_t i);

void vector_v1_double_push_back(p_s_vector_v1_double p_vector, double v);

void vector_v1_double_pop_back(p_s_vector_v1_double p_vector);

void vector_v1_double_clear(p_s_vector_v1_double p_vector);

int vector_v1_double_empty(p_s_vector_v1_double p_vector);

size_t vector_v1_double_size(p_s_vector_v1_double p_vector);



#endif
