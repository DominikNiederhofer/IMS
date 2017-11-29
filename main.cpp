#include <iostream>
#include <fstream>
#include <unistd.h>
#include <getopt.h>

#include "matrix.h"

using namespace std;

int main(int argc, char *argv[])
{
	int width;
	int height;
	int startinf;
	int steps;
	int c;
	while((c = getopt(argc, argv, "w:h:p:s:")) != -1) {
		switch(c){
			case 'w':
				width = atoi(optarg);
				break;
			
			case 'h':
				height = atoi(optarg);
				break;

			case 'p':
				startinf = atoi(optarg);
				break;

			case 's':
				steps = atoi(optarg);
				break;
		}
	    
	}
	matrix mat(width, height);
	mat.fill();
	mat.fillinfected(startinf);
	mat.printmatrix();

	for (int i = 0; i < steps; i++)
	{
		sleep(2);
		mat.nextstep();
		mat.printmatrix();
	}
	return 0;
}