all : vectorC

test_random: test_random.o random.o
	gcc test_random.o random.o -o test_random

vectorC : test_vector_v1_double.o vector_v1_double.o
	gcc test_vector_v1_double.o vector_v1_double.o -o vectorC

random.o: random.c random.h
	gcc random.c -c -o random.o

test_random.o: test_random.c
	gcc test_random.c -c -o test_random.o

vector_v1_double.o: vector_v1_double.c vector_v1_double.h
	gcc vector_v1_double.c -c -o vector_v1_double.o

test_vector_v1_double.o : test_vector_v1_double.c
	gcc test_vector_v1_double.c -c -o test_vector_v1_double.o

clean :
	rm -f * .o vectorC
