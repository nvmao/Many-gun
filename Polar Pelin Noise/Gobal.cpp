#include "Gobal.h"

RenderWindow* window;

float vector_length(Vector2f v)
{
	return sqrt(pow(v.x, 2) + pow(v.y, 2));
}

extern Vector2f normalize(Vector2f v)
{
	float d = sqrt(pow(v.x, 2) + pow(v.y, 2));

	v.x = 1.0 / d * v.x;
	v.y = 1.0 / d * v.y;

	return v;
}

 extern  double randMToN(double M, double N)
 {
	 return M + (rand() / (RAND_MAX / (N - M)));
 }

 extern  float lerp(float a0, float a1, float w) {
	 return (1.0f - w) * a0 + w * a1;
 }

 extern  float distance(Vector2f a, Vector2f b)
 {
	 return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
 }
