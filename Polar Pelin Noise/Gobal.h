#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;
using namespace  std;
#define TWO_PI 6.28318530718
#define PI 3.14159265

extern  RenderWindow* window;

extern float vector_length(Vector2f v);

extern Vector2f normalize(Vector2f v);

extern  double randMToN(double M, double N);

extern  float lerp(float a0, float a1, float w);

extern  float distance(Vector2f a, Vector2f b);