#include "Flatform.h"


Flatform::Flatform(sf::Vector2f position, Vector2f size, Color color)
{
	this->setPosition(position);
	this->setSize(size);
	//this->setOrigin(size.x / 2, size.y / 2);
	this->setFillColor(color);
}

void Flatform::draw()
{
	window->draw(*this);
}

Flatform::Flatform()
{
}


Flatform::~Flatform()
{
}
