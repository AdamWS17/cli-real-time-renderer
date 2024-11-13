#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int width = 20;
int height = 20;
char buffer[(20)*(20)];
char luminosity[] = {' ', '`', '-', '*', '+', '?', 432, '@', 219};


//takes a string of a path to an object file
//returns a tri array
float** loadObject(char* fileName){ 
	FILE* fp;
	char buff[1024];
	fp = fopen((const char*) fileName, "r");	

//tringle: (point, point, point);
//point: (x, y, z, w);

	float** obj;
	float* point;
	int currentTri;

	obj = malloc(sizeof(float*) * 1024);
	currentTri = 0;

	while(fgets(buff, 1024, fp) != NULL){
		printf("linebuff: %s\n", buff);	

		printf("|%c|\n", buff[0]);

		switch(buff[0]){ //try fscanf("v %f %f %f ")??
			case 'v':
				printf("!v!\n");
				//point = malloc(sizeof(float) * 4);

				/*
				point[0] = //oh no how do i do this?
				obj[currentTri] = point;
				*/
				//make vertice


				break;
			case 'f':
				printf("!f!\n");
				//make face
				break;
		}
	}

	fclose(fp);
}

void freeObject(){
	//TODO: free the object arrays
}


int main(){
	printf("cli-renderer.c main\n");
	printf("test mode:\n");


	char* file = "cube.smf";
	loadObject(file);


	return 0;
}
