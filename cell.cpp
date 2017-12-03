#include "cell.h"

bunka::bunka(){
	k = 0;
	stav = 0;
	birth_clock = 0;
	death_clock = 0;
};

void bunka::nastav(int stav){
	this->stav = stav;
	this->birth_clock = (rand() % (this->k) + 1); 
	this->death_clock = (rand() % (this->k) + 1);
};

void bunka::obnov(int stav){
	this->stav = stav;
}

void bunka::nul(){
	this->k = 0;
	this->stav = 0;
	this->birth_clock = 0;
	this->death_clock = 0;
}