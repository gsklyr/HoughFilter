#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void printM(int ***data, int h, int w, int r);
void initialize(int ***array, int height, int width, int range);


int main(int argc, char** argv) {
	
	int HEIGHT = 2;
	int WIDTH = 2;
	int RANGE = 3;
	
	printf("Hello world\n");
	
	int ***data;

  	// Allocate memory
  	data = new int**[HEIGHT];  // layer 1
  	for (int i = 0; i < HEIGHT; ++i) {  // layer 2
    	data[i] = new int*[WIDTH];
    	for (int j = 0; j < WIDTH; ++j)  // layer 3
    		data[i][j] = new int[RANGE];
  	}	
	initialize(data, HEIGHT, WIDTH, RANGE);
	
	printM(data, HEIGHT, WIDTH, RANGE);
	printf("DONE PRINTING\n");
	
	printM(data, HEIGHT, WIDTH, RANGE);
	
	// De-Allocate memory to prevent memory leak
  	for (int i = 0; i < HEIGHT; ++i) {
    	for (int j = 0; j < WIDTH; ++j)
      		delete [] data[i][j];

    	delete [] data[i];
  	}
  	delete [] data;
  	printf("DEALLOCATED\n");
	
	return 0;

}


void initialize(int ***array, int height, int width, int range)
{
	cout << "beginning of init" << endl;

	for (int i = 0; i < height; i++) //go through every row
	{
		for (int j = 0; j < width; j++) //go through every column
		{
			for (int k = 0; k < range; k++) //go through every radius
			{
				array[i][j][k] = 0;
			}
		}
	}
	
	cout << "end of init" << endl;
}

void printM(int ***data, int h, int w, int r) {
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			for(int k = 0; k < r; k++) {
				printf("[%d][%d][%d] = %d | ", i, j, k, data[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
}
