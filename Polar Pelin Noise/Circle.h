#pragma once
#include <SFML/Graphics/CircleShape.hpp>
#include "Gobal.h"

class Circle : public sf::CircleShape
{
	Vector2f origin_pos;
	Vector2f velocity;
	float max_velocity;
	Vector2f desired_velocity;
	Vector2f steering;
	float seek_force;
	Clock clock;
public:
	Circle(Vector2f position);
	void draw();
	void update();
	
	Circle();
	~Circle();
};

