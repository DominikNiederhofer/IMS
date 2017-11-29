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
	void fill();
	void printmatrix();
	void refill();
	int getstate(int, int);
	void fillinfected(int);
	void setnewstate(int, int, int);
	int getnewstate(int, int);
	void nextstep();
	int width;
	int height;
	std::vector<bunka> states;
	std::vector<bunka> nextstates;
		
};
#endif //MATRIX_H