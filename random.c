#include "random.h"
#include <time.h>
#include <stdlib.h>
#define MAX(a,b) ((a) < (b) ? (b) : (a))
#define MIN(a,b) ((a) < (b) ? (a) : (b))


double random_double(double a, double b){

}

int random_int(int a, int b){

    return (int) (rand() % (MAX(a,b)-MIN(a,b)+1))+MIN(a,b);

}

float random_float(float a, float b){
    return (((float)rand() / (float)RAND_MAX) * MAX(a,b)-MIN(a,b))+MIN(a,b);
}
