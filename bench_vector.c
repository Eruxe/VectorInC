#include <stdio.h>
#include "random.h"
#include "vector.h"
#include "my_struct.h"


#define MAXINB 100

void insert_erase_random(p_s_vector p_vector, size_t n){
    for(int i=0;i<n;i++){
        size_t size = p_vector->size;
        vector_erase(p_vector,random_int(0,size-1));
    }

}

void insert_erase_head(p_s_vector p_vector, size_t n){
    for(int i=0;i<n;i++){
        size_t size = p_vector->size;
        vector_erase(p_vector,size-1);
    }
}

void insert_erase_tail(p_s_vector p_vector, size_t n){
    for(int i=0;i<n;i++){
        vector_erase(p_vector,0);
    }
}

void read_write_random(p_s_vector p_vector, size_t n){
    for(int i=0;i<n;i++){
        size_t index = random_int(0,p_vector->size-1);
        vector_erase(p_vector,index);
       	p_s_my_struct p_s;
	my_struct_randoms_init(p_s);
	vector_set(vector1,i,p_s);
       	vector_insert(p_vector, index,p_s);
    }
}

void read_write_sequential(p_s_vector p_vector, size_t n){
    for(int i=0;i<n;i++){
        size_t index = i%p_vector->size;
        vector_erase(p_vector,index);
       	p_s_my_struct p_s;
	my_struct_randoms_init(p_s);
	vector_set(vector1,i,p_s);
       	vector_insert(p_vector, index,p_s);
    }
}

void bubble_sort(p_s_vector p_vector, size_t n){
    //ECRITURE
     for(int i=0;i<n;i++){
         read_write_sequential(p_vector,p_vector->size);
     }

    //SORTING
     for(int i=0;i<p_vector->size-1;i++){
         for(int j=0;j<p_vector->size-1-i;j++){
             if(my_struct_cmp(p_vector->data[j],p_vector->data[j+1])){
                 double memo=p_vector->data[j];
                 p_vector->data[j]=p_vector->data[j+1];
                 p_vector->data[j+1]=memo;
             }
         }
     }
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

        //Init du vectori
	p_s_my_struct p_s;
        p_s_vector vector1 = vector_alloc(init_size, &my_struct_alloc, &my_struct_free, &my_struct_copy);
        for(size_t i=0;i<init_size;i++){
		p_s = my_struct_alloc();
		my_struct_randoms_init(p_s);
		vector_set(vector1,i,p_s);
        }


        //Modif du vector
        if(strcmp(test_type,"insert_erase_random") == 0){
            insert_erase_random(vector1,n);
        }
        else if(strcmp(test_type,"insert_erase_head") == 0){
            insert_erase_head(vector1,n);
        }
        else if(strcmp(test_type,"insert_erase_tail") == 0){
            insert_erase_tail(vector1,n);
        }
        else if(strcmp(test_type,"read_write_random") == 0){
            read_write_random(vector1,n);
        }
        else if(strcmp(test_type,"read_write_sequential") == 0){
            read_write_sequential(vector1,n);
        }
        else if(strcmp(test_type,"bubble_sort") == 0){
            bubble_sort(vector1,n);
        }
        else{
            printf("Test type inexistant\n");
        }



        //Affichage apres modif
        }
    else{
        printf("pas assez d'arguments \n");
    }

    printf("----------------------------\n");
    printf("\n");
}
