#include <stdio.h>
#include "vector.h"

Vector4 add(Vector4 a, Vector4 b){
	Vector4 result = {
		a.x + b.x, 
		a.y + b.y,
		a.z + b.z,
		a.w + b.w
	};
	return result;
}

Vector4 sub(Vector4 a, Vector4 b){
	Vector4 result = {
		a.x - b.x,
		a.y - b.y,
		a.z - b.z,
		a.w - b.w
	};
	return result;
}

Vector4 mult(float a, Vector4 b){
	Vector4 result = {
		a * b.x,
		a * b.y,
		a * b.z,
		a * b.w
	};
	return result;
}

float dot(Vector4 a, Vector4 b){
	float result = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	return result;
}

Vector4 cross(Vector4 a, Vector4 b){
	Vector4 result = {
		(a.y * b.z) - (a.z * b.y),
		(a.z * b.x) - (a.x * b.z),
		(a.x * b.y) - (a.y * b.x),
		0
	};
	return result;
}

void printVector4(Vector4 a){
	printf("vec4: ");
	printf("[%f %f %f %f]\n", a.x, a.y, a.z, a.w);
}
