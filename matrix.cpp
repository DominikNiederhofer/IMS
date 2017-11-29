#include "matrix.h"


matrix::matrix(int width, int height){
	this->width = width;
	this->height = height;
	this->states.reserve(this->width * this->height);
	this->nextstates.reserve(this->width * this->height);

}

void matrix::fill(){
	bunka tmp;
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			tmp.nastav(x, y, 0);
			this->states.push_back(tmp);
		}
	}
}


void matrix::refill(){
	for (int i = 0; i < this->width * this->height; i++)
	{
		this->states[i].stav = this->nextstates[i].stav;
	}
	
}
int matrix::getstate(int x, int y){
	if (x < 0 || x >= width)
		return 3;
	if (y < 0 || y >= height)
		return 3;

	return this->states[x + y * width].stav;
}

void matrix::setnewstate(int x, int y, int hodnota){
	if (x < 0 || x >= width)
		return;

	if (y < 0 || y >= height)
		return;

	this->nextstates[x + y * width].stav = hodnota;
}

void matrix::fillinfected(int procent){
	int random;
	for (int x = 0; x < this->width; x++)
	{
		for (int y = 0; y < this->height; y++)
		{
			random = rand() % 100 + 1;
			if (random <= procent)
				this->states[x + y * width].stav = 1;
		}
	}
}

int matrix::getnewstate(int x, int y){
	if (this->states[x + y * width].stav == 0){
		if (x == 0 && y == 0){
			if (getstate(x + 1, y) || getstate(x, y + 1) || getstate(x + 1, y + 1))
				return 1;
		}
		else if (x == 0 && y == this->height - 1){
			if (getstate(x + 1, y) || getstate(x + 1, y - 1) || getstate(x, y - 1))
				return 1;
		}
		else if (x == this->width - 1 && y == 0){
			if (getstate(x, y + 1) || getstate(x - 1, y + 1) || getstate(x - 1, y))
				return 1;
		}
		else if (x == this->width- 1 && y == this->height - 1){
			if (getstate(x - 1, y) || getstate(x, y - 1) || getstate(x - 1, y - 1))
				return 1;
		}
		else if (x == 0){
			if (getstate(x + 1, y + 1) || getstate(x + 1, y) || getstate(x + 1, y - 1) || getstate(x, y + 1) || getstate(x, y - 1))
				return 1;
		}
		else if (y == 0){
			if (getstate(x + 1, y + 1) || getstate(x, y + 1) || getstate(x - 1, y + 1) || getstate(x + 1, y) || getstate(x - 1, y))
				return 1;
		}
		else if (y == this->height - 1){
			if (getstate(x + 1, y) || getstate(x - 1, y) || getstate(x + 1, y - 1) || getstate(x, y - 1) || getstate(x - 1, y - 1))
				return 1;
		}
		else if (x == this->width - 1){
			if (getstate(x, y + 1) || getstate(x, y - 1) || getstate(x - 1, y - 1) || getstate(x - 1, y + 1) || getstate(x - 1, y))
				return 1;
		}
		else {
			if (getstate(x + 1, y) == 1 || getstate(x + 1, y + 1) == 1 || getstate(x + 1, y - 1) == 1 ||
			 getstate(x, y + 1) == 1 || getstate(x, y - 1) == 1 ||
			 getstate(x - 1, y - 1) == 1 || getstate(x - 1, y) == 1 || getstate(x - 1, y + 1) == 1)
				return 1;
		}



	}
	else if(this->states[x + y * width].stav == 1 || this->states[x + y * width].stav == 2) {
		return 3;
	}
	else if (this->states[x + y * width].stav == 3) {
		return 0;
	}
}

void matrix::nextstep(){
	int c;
	for (int x = 0; x < this->width; x++)
	{
		for (int y = 0; y < this->height; y++)
		{
			c = getnewstate(x, y); 
			setnewstate(x, y, c);
		}
	}
	refill();
}

void matrix::printmatrix()
{
    for (int y = 0; y < this->height; y++) //for col in matrix
    {
	    for(int x = 0; x < this->width; x++) //for row in matrix
	    {
            if(this->states[y * this->width + x].stav == 0) //cell contain plant
            {
                cout << "\033[1;32m" << 0 << " \033[0m ";
            }
            else if(this->states[y * this->width + x].stav == 1) //cell is vacant
            {
                cout << "\033[1;35m" << 1 << " \033[0m ";
            }
            else //cell contain stone
            {
                cout << "\033[1;34m"<< 3 <<" \033[0m ";
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