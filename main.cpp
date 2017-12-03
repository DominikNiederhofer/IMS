#include <iostream>
#include <fstream>
#include <unistd.h>
#include <getopt.h>

#include "matrix.h"

using namespace std;


void printoutput(matrix mat, FILE *f, int time){
	int pocet_inf = 0;
	int pocet_sus = 0;
	if (time == 0)
		fprintf(f, "time: infected: susceptibles:\n");
	for (int i = 0; i < mat.width*mat.height; i++)
	{
		if(mat.states[i].stav == 1) {
			pocet_sus++;
		}
		else if (mat.states[i].stav == 2){
			pocet_inf++;
		}
	}
	fprintf(f, "%i:\t%i\t|\t%i\n", time, pocet_inf, pocet_sus);
}

int main(int argc, char *argv[])
{
	int k;
	int height;
	double inf;
	double sus;
	int steps;
	int c;
	int mode;
	string file = "";

	while((c = getopt(argc, argv, "k:h:s:i:n:f:m:")) != -1) {
		switch(c){
			case 'k':
				k = atoi(optarg);
				break;
			
			case 'h':
				height = atoi(optarg);
				break;

			case 's':
				sus = atof(optarg);
				break;

			case 'i':
				inf = atof(optarg);
				break;

			case 'n':
				steps = atoi(optarg);
				break;

			case 'f':
				file = optarg;
				break;

			case 'm':
				mode = atoi(optarg);
				break;
		}
	    
	}
	matrix mat(height, height);
	mat.fill(inf, sus, k);
	//mat.printmatrix();
	FILE *f = fopen(file.c_str(), "w");
	printoutput(mat, f, 0);
	for (int i = 1; i < steps + 1; i++)
	{
		mat.nextstep();
	//	mat.printmatrix();
		printoutput(mat, f, i);
	}
	//mat.endprint();
	fclose(f);
	return 0;
}