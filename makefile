all : vectorC vectorCv2 test_random bench_vector_v1_double

bench_vector_v1_double: bench_vector_v1_double.o vector_v1_double.o random.o
	gcc bench_vector_v1_double.o vector_v1_double.o random.o -g -o bench_vector_v1_double

test_random: test_random.o random.o
	gcc test_random.o random.o -g -o test_random

vectorCv2 : test_vector_v2_double.o vector_v2_double.o
	gcc test_vector_v2_double.o vector_v2_double.o -g -o vectorCv2

vectorC : test_vector_v1_double.o vector_v1_double.o
	gcc test_vector_v1_double.o vector_v1_double.o -g -o vectorC

bench_vector_v1_double.o: bench_vector_v1_double.c
	gcc bench_vector_v1_double.c -c -Wall -g -o bench_vector_v1_double.o
	
random.o: random.c random.h
	gcc random.c -c -Wall -g -o random.o

test_random.o: test_random.c
	gcc test_random.c -c -Wall -g -o test_random.o

vector_v2_double.o: vector_v2_double.c vector_v2_double.h
	gcc vector_v2_double.c -c -Wall -g -o vector_v2_double.o

test_vector_v2_double.o : test_vector_v2_double.c
	gcc test_vector_v2_double.c -c -Wall -g -o test_vector_v2_double.o

vector_v1_double.o: vector_v1_double.c vector_v1_double.h
	gcc vector_v1_double.c -c -Wall -g -o vector_v1_double.o

test_vector_v1_double.o : test_vector_v1_double.c
	gcc test_vector_v1_double.c -c -Wall -g -o test_vector_v1_double.o

clean :
	rm -f *.o
