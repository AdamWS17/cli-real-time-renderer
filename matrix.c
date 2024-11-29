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
			printf("%f", a.data[j][i]);
		}
		printf("\n");
	}
	printf("]\n");
}

mat4 matmult(mat4 a, mat4 b){
	mat4 result;
	int i, j, k;
	float element;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			element = 0;
			for(k = 0; k < 4; k++){
				element += a.data[k][i] * b.data[j][k];
				printf("%f\n", b.data[j][k]);
			}
			printf("i: %d;j: %d;k: %d;element: %f\n", i, j, k, element);
			result.data[j][i] = element;
		}
	}
	return result;
}
