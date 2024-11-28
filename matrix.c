#include <stdio.h>
#include "matrix.h"

void printMatrix4(mat4 a){
	printf("mat4:");
	printf("[\n");
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(j != 0){
				printf(" ");
			}
			printf("%f", a.data[i][j]);
		}
		printf("\n");
	}
	printf("]\n");
}
