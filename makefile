all : vectorC vectoCv2 test_random benchvectorv1double

benchvectorv1double: benchvectorv1double.o vector_v1_double.o random.o
	gcc benchvectorv1double.o vector_v1_double.o random.o -o benchvectorv1double

test_random: test_random.o random.o
	gcc test_random.o random.o -o test_random

vectorCv2 : test_vector_v2_double.o vector_v2_double.o
	gcc test_vector_v2_double.o vector_v2_double.o -o vectorCv2

vectorC : test_vector_v1_double.o vector_v1_double.o
	gcc test_vector_v1_double.o vector_v1_double.o -o vectorC

benchvectorv1double.o: benchvectorv1double.c
	gcc benchvectorv1double.o -c -o benchvectorv1double.c
	
random.o: random.c random.h
	gcc random.c -c -o random.o

test_random.o: test_random.c
	gcc test_random.c -c -o test_random.o

vector_v2_double.o: vector_v2_double.c vector_v2_double.h
	gcc vector_v2_double.c -c -o vector_v2_double.o

test_vector_v2_double.o : test_vector_v2_double.c
	gcc test_vector_v2_double.c -c -o test_vector_v2_double.o

vector_v1_double.o: vector_v1_double.c vector_v1_double.h
	gcc vector_v1_double.c -c -o vector_v1_double.o

test_vector_v1_double.o : test_vector_v1_double.c
	gcc test_vector_v1_double.c -c -o test_vector_v1_double.o

clean :
	rm -f * .o vectorC test_random benchvectorv1double
