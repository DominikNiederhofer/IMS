#ifndef MATRIX_H
#define MATRIX_H

#include "cell.h"
#include <iostream>
#include <vector>
#include <cstdlib>


using namespace std;

class matrix {
public:
	matrix(int, int);
	void fill(double, double, int);
	void zabij(int, int);
	void rozmnoz(int, int);
	void printmatrix();
	void refill();
	void nakaz(int, int);
	void presun(int, int, int, int, int);
	void nextstep();
	void endprint();
	void rozhod();
	void pohyb(int, int);
	int getstate(int, int);
	int width;
	int height;
	std::vector<bunka> states;
	std::vector<bunka> nextstates;
		
};
#endif //MATRIX_H