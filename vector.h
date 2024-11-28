
typedef struct {
	float x;
	float y;
	float z;
	float w;
} Vector4;

Vector4 add(Vector4, Vector4);
Vector4 sub(Vector4, Vecotr4);
Vector4 mult(float, Vector4);
float dot(Vector4, Vector4);
Vector4 cross(Vector4, Vector4);
