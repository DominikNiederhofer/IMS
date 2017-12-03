CC=g++
CFLAGS= -Wall -Wextra -g
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

run:
	./simulator -h 100 -n 50 -i 0.7 -s 0.1 -m 0 -k 10 -f vysledek1
	./simulator -h 100 -n 50 -i 0.7 -s 0.1 -m 0 -k 20 -f vysledek2
	./simulator -h 100 -n 50 -i 0.7 -s 0.1 -m 0 -k 30 -f vysledek3

