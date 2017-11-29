CC=g++
CFLAGS= -g -lGLU -lGL
OBJ_FILES= main.o matrix.o cell.o

all:simulator

simulator:	$(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $@ $(CFLAGS)

main.o: main.cpp matrix.h cell.h
	$(CC) -o $@ -c $<  $(CFLAGS)

matrix.o: matrix.cpp matrix.h
	$(CC) -o $@ -c $<  $(CFLAGS)

cell.o: cell.cpp cell.h
	$(CC) -o $@ -c $<  $(CFLAGS)

clean:
	rm -f *.o simulator