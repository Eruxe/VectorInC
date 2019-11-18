all : vectorC

vectorC : test_vector_v1_double.o vector_v1_double.o
	gcc test_vector_v1_double.o vector_v1_double.o -o vectorC

vector_v1_double.o: vector_v1_double.c vector_v1_double.h
	gcc vector_v1_double.c -c -o vector_v1_double.o

test_vector_v1_double.o : test_vector_v1_double.c
	gcc test_vector_v1_double.c -c -o test_vector_v1_double.o

clean :
	rm -f * .o vectorC
