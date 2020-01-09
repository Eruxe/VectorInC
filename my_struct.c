#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "my_struct.h"
#include "random.h"

#define STRSIZE 10
#define MAXVAL 100

p_s_my_struct my_struct_alloc(){
  p_s_my_struct p = malloc(sizeof(s_my_struct));
  p->chaine = NULL;
  p->nb = 0;
  return p;
}

void my_struct_free(p_s_my_struct p_vector){
  free(p_vector);
  p_vector = NULL;
}

void my_struct_copy(p_s_my_struct p_dest, p_s_my_struct p_src){
  strcpy(p_dest->chaine, p_src->chaine);
  p_dest->nb = p_src->nb;
}

void my_struct_randoms_init(p_s_my_struct p_vector){
  p_vector->nb = random_double(0, MAXVAL);
  random_init_string(p_vector->chaine, STRSIZE);
}

int my_struct_cmp(p_s_my_struct p_vector_a, p_s_my_struct p_vector_b){
  if (p_vector_a->nb == p_vector_b->nb){
    return strcmp(p_vector_a->chaine, p_vector_b->chaine) == 0;
  } else {
    return p_vector_a->nb - p_vector_b->nb;
  }
}
