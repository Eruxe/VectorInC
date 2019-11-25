#include <stdio.h> 
#include "random.h"

int main(int argc, char *argv[]){
	
	srand(time(NULL));
	printf("%d",random_int(5,0));
	return 0;
}
