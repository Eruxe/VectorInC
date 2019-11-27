#include <stdio.h>
#include "random.h"
#include "vector_v1_double.h"


int main(int argc, char *argv[]){
    
    if(argc>3){
        char* test_type = argv[1];
        char* init_size_s= argv[2];
        char* n_s = argv[3];

        
        size_t init_size=0;
        sscanf(init_size_s,"%lu",&init_size);
        size_t n=0;
        sscanf(n_s,"%lu",&n);

        printf("Test type: %s \n",test_type);
        printf("init_size: %lu \n",init_size);
        printf("n: %lu \n",n);

        p_s_vector_v1_double vector1 = vector_v1_double_alloc(init_size);
        for(size_t i=0;i<init_size;i++){
            vector_v1_double_set(vector1,i,random_double(0,100));
        }

        for(size_t i=0;i<init_size;i++){
            printf("%lf ; ",vector1->data[i]);
        }

    }
    else{
        printf("pas assez d'arguments \n");
    }


}
