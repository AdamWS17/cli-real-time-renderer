#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "cli_renderer.h"

#define WIDTH 20
#define HEIGHT 20

#define DEFAULT_ARR_SIZE 1024

char buffer[(WIDTH)*(HEIGHT)];
char luminosity[] = {' ', '`', '-', '*', '+', '?', 432, '@', 219};


/*
 * takes a string of a path to an object file
 * returns a tri array
 * only takes objects defined by triangels
 */
object3D* loadObject(char* fileName){ 
	FILE* fp;
	char buff[1024];
	float*** tris;
	float** verts;
	float x, y, z;
	int vertList[3];
	int currentTri, currentVert, numVerts, numTris;
	int v1, v2, v3;
	object3D* obj;

	fp = fopen((const char*) fileName, "r");
	
	if(fp == NULL){
		fprintf(stderr, "file \"%s\" could not be opened\n", fileName);
		return (object3D*) -1;
	}


	verts = malloc(sizeof(float**) * 1024);
	tris = malloc(sizeof(float***) * 1024);


	//[[[[x] [y] [z] [w]] [[x] [y] [z] [w]] [[][][]]], [etc]]

	//tringle: (point, point, point);
	//point: (x, y, z, w); w = 1
	
	currentTri = 0;
	currentVert = 0;
	while(fgets(buff, 1024, fp) != NULL){
		printf("linebuff: %s\n", buff);	
		printf("|%c|\n", buff[0]);

		switch(buff[0]){
			case 'v':
				printf("!v!\n");
				int test = sscanf(buff, "v %f %f %f", &x, &y, &z);
				printf("%d\n", test);
				printf("x:%f y:%f, z:%f\n", x, y, z); //TODO: this does not work sometimes?? figure out why

				verts[currentVert] = malloc(sizeof(float) * 4);
				verts[currentVert][0] = x;
				verts[currentVert][1] = y;
				verts[currentVert][2] = z;
				verts[currentVert][3] = 1; //w = 1 
				currentVert++;

				break;
			case 'f':
				printf("!f!\n");
				sscanf(buff, "f %d %d %d", &v1, &v2, &v3);
				//printf("f: %d ,%d, %d\n", v1, v2, v3);
				
				tris[currentTri] = malloc(sizeof(float*) * 3);
				tris[currentTri][0] = malloc(sizeof(float) * 4);
				tris[currentTri][1] = malloc(sizeof(float) * 4);
				tris[currentTri][2] = malloc(sizeof(float) * 4);

				vertList[0] = v1 - 1;
				vertList[1] = v2 - 1;
				vertList[2] = v3 - 1;
				printf("1\n");
				for(int i = 0; i < 3; i++){
					for(int j = 0; j < 3; j++){
						printf("2\n");
						tris[currentTri][i][j] = verts[vertList[i]][j];
					}
					printf("4\n");
					tris[currentTri][i][3] = 1; //w = 1
				}
				printf("3\n");
				currentTri++;
				break;
		}
	}
	for(int i = 0; i < currentVert; i++){
		printf("vert: x:%f, y:%f, z:%f, w:%f\n", verts[i][0], verts[i][1], verts[i][2], verts[i][3]);
	}
	printf("[");
	for(int i = 0; i < currentTri; i++){
		if(i != 0){
			printf(", ");
		}
		for(int j = 0; j < 3; j++){
			printf("[%f, %f, %f, %f]", tris[i][j][0], tris[i][j][1], tris[i][j][2], tris[i][j][3]);
		}
	}
	printf("]\n");

	fclose(fp);
	
	obj = malloc(sizeof(object3D));
	obj->tris = tris;
	obj->triLen = currentTri;
	return obj;
}

void freeObject(object3D* obj){
	//TODO: free the object arrays
}


int main(){

	printf("cli-renderer.c main\n");
	printf("test mode:\n");


	char* file = "cube.smf";
	
	object3D* obj = loadObject(file);

	printf("[1][2][1]: %f\n", obj->tris[1][2][1]);

	freeObject(obj);

	return 0;
}
