#include <stdio.h>
#include "random.h"
#include "vector_v1_double.h"

void insert_erase_random(p_s_vector_v1_double p_vector, size_t n){
    for(int i=0;i<n;i++){
        size_t size = p_vector->size;
        vector_v1_double_erase(p_vector,random_int(0,size-1));
    }

}

void insert_erase_head(p_s_vector_v1_double p_vector, size_t n){

}

void insert_erase_tail(p_s_vector_v1_double p_vector, size_t n){

}

void read_write_random(p_s_vector_v1_double p_vector, size_t n){

}

void read_write_sequential(p_s_vector_v1_double p_vector, size_t n){

}

void bubble_sort(p_s_vector_v1_double p_vector, size_t n){

}

int main(int argc, char *argv[]){

    printf("\n");
    printf("----------------------------\n");

    srand(time(0));
    
    if(argc>3){
        //Recuperation des args
        char* test_type = argv[1];
        char* init_size_s= argv[2];
        char* n_s = argv[3];

        //Conversion des args
        size_t init_size=0;
        sscanf(init_size_s,"%lu",&init_size);
        size_t n=0;
        sscanf(n_s,"%lu",&n);

        //Affichage des args
        printf("Test type: %s \n",test_type);
        printf("init_size: %lu \n",init_size);
        printf("n: %lu \n",n);

        //Init du vector
        p_s_vector_v1_double vector1 = vector_v1_double_alloc(init_size);
        for(size_t i=0;i<init_size;i++){
            vector_v1_double_set(vector1,i,random_double(0,100));
        }

        //affichage du vector avant modif
        printf("Before modification: \n");
        printf("size: %d \n",vector1->size);
        for(size_t i=0;i<vector1->size;i++){
            printf("%.2lf ; ",vector1->data[i]);
        }
        printf("\n");

        //Modif du vector
        if(strcmp(test_type,"insert_erase_random") == 0){
            insert_erase_random(vector1,n);
        }
        else{
            printf("Test type inexistant\n");
        }



        //Affichage apres modif
        printf("After modification: \n");
        printf("size: %d \n",vector1->size);
        for(size_t i=0;i<vector1->size;i++){
            printf("%.2lf ; ",vector1->data[i]);
        }
        printf("\n");

    }
    else{
        printf("pas assez d'arguments \n");
    }

    printf("----------------------------\n");
    printf("\n");
}
