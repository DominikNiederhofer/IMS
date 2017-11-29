#include "cell.h"

bunka::bunka(){
	x = 0;
	y = 0;
	stav = 0;
};

void bunka::nastav(int x, int y, int stav){
	this->x = x;
	this->y = y;
	this->stav = stav;
};

void bunka::obnov(int stav){
	this->stav = stav;
}