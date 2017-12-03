#ifndef CELL_H
#define CELL_H

#include <cstdlib>


using namespace std;
class bunka {
public:
	bunka();
	void nastav(int);
	void obnov(int);
	void nul();
	int k;
	int birth_clock;
	int death_clock;
	int stav;
};

#endif // CELL_H
