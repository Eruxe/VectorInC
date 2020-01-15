all : vectorC vectorCv2 test_random bench_vector_v1_double bench_vector_v2_double  my_struct vector

my_struct: my_struct.o test_my_struct.o random.o
	gcc my_struct.o test_my_struct.o random.o -g -o my_struct

bench_vector_v1_double: bench_vector_v1_double.o vector_v1_double.o random.o
	gcc bench_vector_v1_double.o vector_v1_double.o random.o -g -o bench_vector_v1_double

bench_vector_v2_double: bench_vector_v2_double.o vector_v2_double.o random.o
	gcc bench_vector_v2_double.o vector_v2_double.o random.o -g -o bench_vector_v2_double

bench_vector: bench_vector.o vector.o random.o
	gcc bench_vector.o vector.o random.o -g -o bench_vector

test_random: test_random.o random.o
	gcc test_random.o random.o -g -o test_random

vector : test_vector.o vector.o random.o
	gcc test_vector.o vector.o random.o -g -o vector

vectorCv2 : test_vector_v2_double.o vector_v2_double.o
	gcc test_vector_v2_double.o vector_v2_double.o -g -o vectorCv2

vectorC : test_vector_v1_double.o vector_v1_double.o
	gcc test_vector_v1_double.o vector_v1_double.o -g -o vectorC

test_my_struct.o : test_my_struct.c
	gcc test_my_struct.c -c -Wall -g -o test_my_struct.o

my_struct.o: my_struct.c my_struct.h
	gcc my_struct.c -c -Wall -g -o my_struct.o


bench_vector_v1_double.o: bench_vector_v1_double.c
	gcc bench_vector_v1_double.c -c -Wall -g -o bench_vector_v1_double.o

bench_vector_v2_double.o: bench_vector_v2_double.c
	gcc bench_vector_v2_double.c -c -Wall -g -o bench_vector_v2_double.o

bench_vector.o: bench_vector.c
	gcc bench_vector.c -c -Wall -g -o bench_vector.o
	
random.o: random.c random.h
	gcc random.c -c -Wall -g -o random.o

test_random.o: test_random.c
	gcc test_random.c -c -Wall -g -o test_random.o

vector.o: vector.c vector.h
	gcc vector.c -c -Wall -g -o vector.o

test_vector.o : test_vector.c
	gcc test_vector.c -c -Wall -g -o test_vector.o

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
