#include "matrix.h"
#include <cstring>

int smer = 1;

matrix::matrix(int width, int height){
	this->width = width;
	this->height = height;
	this->states.reserve(this->width * this->height);
	this->nextstates.reserve(this->width * this->height);

}

void matrix::rozhod()
{
	srand(time(NULL));
    int temp; 
	int random;  
	int numLength = this->width * this->height;
	for(int i = 1; (i <= numLength); i++)
	{
		for (int j=0; j < (numLength -1); j++)
		{
      		random = rand() % 100;
			if (random < 50) { 
				temp = this->states[j].stav;             // swap elements
				this->states[j].stav = this->states[j+1].stav;
				this->states[j+1].stav = temp;
            }
        }
    }
}

void matrix::fill(double inf, double sus, int k){

	bunka tmp;
	tmp.k = k;
	int in = (this->width * this->height)*inf;
	int su = (this->width * this->height)*sus;
	


	for (int i = 0; i < su; i++)
	{
		tmp.nastav(1);
		this->states.push_back(tmp);
	}
	
	for (int i = 0; i < in; i++)
	{
		tmp.nastav(2);
		this->states.push_back(tmp);
	}
	
	for (int i = 0; i < (this->width * this->height) - in - su; i++)
	{
		tmp.nastav(0);
		this->states.push_back(tmp);
	}
	rozhod();
}


void matrix::refill(){
	for (int i = 0; i < this->width * this->height; i++)
	{
		this->states[i].stav = this->nextstates[i].stav;
	}
	
}
int matrix::getstate(int x, int y){
	if (x < 0){
		x = this->width - 1;
	}
	else if (x >= this->width){
		x = 0;
	}

	if (y < 0){
		y = this->height - 1;
	}
	else if (y >= this->height){
		y = 0;
	}

	return this->states[x + y * width].stav;
}

void matrix::presun(int x1, int y1, int x2, int y2, int rezim){
	if (x1 < 0){
		x1 = this->width - 1;
	}
	else if (x1 >= this->width){
		x1 = 0;
	}

	if (y1 < 0){
		y1 = this->height - 1;
	}
	else if (y1 >= this->height){
		y1 = 0;
	}

	if (x2 < 0){
		x2 = this->width - 1;
	}
	else if (x2 >= this->width){
		x2 = 0;
	}

	if (y2 < 0){
		y2 = this->height - 1;
	}
	else if (y2 >= this->height){
		y2 = 0;
	}
	if (rezim == 0)
		this->nextstates[x1 + y1 * this->width] = this->states[x2 + y2* this->width];
	else
		this->states[x1 + y1 * this->width] = this->states[x2 + y2* this->width];

}


void matrix::pohyb(int x, int y){
	if (this->states[x + y * width].stav == 0){
		if (smer == 1){
			if (getstate(x, y + 1) != 0){
				presun(x, y, x, y + 1, 0);
			}
			else{
				presun(x, y, x, y, 0);
			}
		}
		else if (smer == 2){
			if (getstate(x - 1, y) != 0){
				presun(x, y, x - 1, y, 0);
			}
			else{
				presun(x, y, x, y, 0);
			}
		}
		else if (smer == 3){
			if (getstate(x, y - 1) != 0){
				presun(x, y, x, y - 1, 0);
			}
			else{
				presun(x, y, x, y, 0);
			}
		}
		else if (smer == 4){
			if (getstate(x + 1, y) != 0){
				presun(x, y, x + 1, y, 0);
			}
			else{
				presun(x, y, x, y, 0);
			}
		}
	}
	else {
		if (smer == 1){
			if (getstate(x, y - 1) == 0){
				this->nextstates[x + y * width].nul();	
			}
			else
				presun(x, y, x, y, 0);
		}
		else if (smer == 2){
			if (getstate(x + 1, y) == 0){
				this->nextstates[x + y * width].nul();
			}
			else
				presun(x, y, x, y, 0);
		}
		else if (smer == 3){
			if (getstate(x, y + 1) == 0){
				this->nextstates[x + y * width].nul();
			}
			else
				presun(x, y, x, y, 0);
		}
		else if (smer == 4){
			if (getstate(x - 1, y) == 0){
				this->nextstates[x + y * width].nul();
			}
			else
				presun(x, y, x, y, 0);
		}
	}
}

void matrix::zabij(int x, int y){
	if (this->states[x + y * width].death_clock <= 0 &&
		this->states[x + y * width].stav != 0){
		this->states[x + y * width].nul();
	}

	this->states[x + y * width].death_clock--;
}

void matrix::rozmnoz(int x, int y){
	int con = 1;
	int random = rand() % 8 + 1;
	int pom = random;
	if (this->states[x + y * width].birth_clock <= 0 &&
		this->states[x + y * width].stav != 0){
		while(con){
			switch (random){
				case 1:
					if (getstate(x + 1, y + 1) == 0){
						presun(x + 1, y + 1, x, y, 1);				 
						con = 0;
					}
					break;
				case 2:	
					if (getstate(x + 1, y) == 0){
						presun(x + 1, y, x, y, 1);				 
						con = 0;
					}
					break;
				case 3:
					if (getstate(x + 1, y - 1) == 0){
						presun(x + 1, y - 1, x, y, 1);				 
						con = 0;
					}
					break;
				case 4:
					if (getstate(x, y - 1) == 0){
						presun(x, y - 1, x, y, 1);				 
						con = 0;
					}
					break;
				case 5:
					if (getstate(x, y + 1) == 0){
						presun(x, y + 1, x, y, 1);				 
						con = 0;
					}
					break;
				case 6:
					if (getstate(x - 1, y + 1) == 0){
						presun(x - 1, y + 1, x, y, 1);				 
						con = 0;
					}
					break;
				case 7:
					if (getstate(x - 1, y) == 0){
						presun(x - 1, y, x, y, 1);				 
						con = 0;
					}
					break;
				case 8:
					if (getstate(x - 1, y - 1) == 0){
						presun(x - 1, y - 1, x, y, 1);				 						
						con = 0;
					}
					break;	
			}
			random = random % 8 + 1;
			if (random == pom){
				con = 0;
			}		
		}
		this->states[x + y * width].nastav(1);
	}
	this->states[x + y * width].birth_clock--;
}

void matrix::nakaz(int x, int y){
	int random;
	if (this->states[x + y * width].stav == 1){
		if (getstate(x + 1, y) == 2 || getstate(x + 1, y + 1) == 2 || getstate(x + 1, y - 1) == 2 ||
		 getstate(x, y + 1) == 2 || getstate(x, y - 1) == 2 ||
		 getstate(x - 1, y - 1) == 2 || getstate(x - 1, y) == 2 || getstate(x - 1, y + 1) == 2){
				random = rand() % 1000 + 1;
				if (random <= 125)
					this->states[x + y * width].stav = 2;
			}
		
	}

}

void matrix::nextstep(){
	int c;
	srand(time(NULL));
	for (int x = 0; x < this->width; x++)
	{
		for (int y = 0; y < this->height; y++)
		{
			zabij(x, y);
			rozmnoz(x, y);
			nakaz(x, y);
			pohyb(x, y);

		}
	}
	smer = (smer) % 4 + 1;
	refill();
}

void matrix::printmatrix()
{
    for (int y = 0; y < this->height; y++) //for col in matrix
    {
	    for(int x = 0; x < this->width; x++) //for row in matrix
	    {
            if(this->states[y * this->width + x].stav == 1) //cell contain plant
            {
                cout << "\033[1;32m" << 1 << " \033[0m ";
            }
            else if(this->states[y * this->width + x].stav == 2) //cell is vacant
            {
                cout << "\033[1;35m" << 2 << " \033[0m ";
            }
            else //cell contain stone
            {
                cout << "\033[1;34m"<< 0 <<" \033[0m ";
            }
        }
        cout << endl;
    }
    for(int k = 0; k < this->width; k++)
    {
        cout << "\033[F";
        flush(cout);
    }
}

void matrix::endprint()
{
    for(int i = 0; i < this->width; i++)
    {
        cout << endl;
    }
}