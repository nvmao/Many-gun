#pragma once
#include "Gobal.h"
#include <SFML/Graphics/RectangleShape.hpp>

class Flatform : public sf::RectangleShape
{
	
public:
	Flatform(sf::Vector2f position, Vector2f size, Color color);
	void draw();
	Flatform();
	~Flatform();
};

