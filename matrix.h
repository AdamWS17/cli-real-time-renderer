typedef struct {
	float data[4][4];
} mat4;


void printMatrix4(mat4);
mat4 matmult(mat4 a, mat4 b);
