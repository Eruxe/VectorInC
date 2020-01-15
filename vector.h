#include <stddef.h>

#ifndef __VECTOR2__
#define __VECTOR2__

typedef struct {
	void **data;
	size_t size;
	size_t capacity;
	void* (*data_alloc)();
	void (*data_free)(void*);
	void (*data_cpy)(void*, void*);
} s_vector;

typedef s_vector* p_s_vector;

p_s_vector vector_alloc(size_t n, void* (*allocator)(), void (*free)(void*), void (*copy)(void*, void*));

void vector_free(p_s_vector p_vector);

void vector_set(p_s_vector p_vector, size_t i, void* v);

void* get(p_s_vector p_vector, size_t i);

void vector_insert(p_s_vector p_vector, size_t i, void* v);

void vector_erase(p_s_vector p_vector, size_t i);

void vector_push_back(p_s_vector p_vector, void* v);

void vector_pop_back(p_s_vector p_vector);

void vector_clear(p_s_vector p_vector);

int vector_empty(p_s_vector p_vector);

size_t vector_size(p_s_vector p_vector);



#endif
