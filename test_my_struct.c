#include <stdio.h>
#include <stdlib.h>
#include "my_struct.h"
#include <assert.h>
#include <time.h>

int main(void) {
  srand(time(0));
  p_s_my_struct p = my_struct_alloc();
  assert(p->chaine == NULL);
  assert(p->nb == 0);
  my_struct_randoms_init(p);
  assert(p->nb != 0);
  assert(p->chaine != NULL);
  p_s_my_struct p1 = my_struct_alloc();
  my_struct_copy(p1, p);
  assert(my_struct_cmp(p, p1)==0);
  return 0;
}
