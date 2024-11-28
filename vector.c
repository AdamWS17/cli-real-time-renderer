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
