#include "Projectile_9.h"


Projectile_9::Projectile_9(Vector2f position, Vector2f size, Color color, float angle)
	:Projectile(position, size, color, angle)
{
	rectangle = RectangleShape(Vector2f(4, 50));
	rectangle.setOrigin(size.x / 2, 0);
	rectangle.setFillColor(color);
	r_angle = 0;
}

void Projectile_9::enemies_collision()
{

	if(distance(getPosition(),target) <= 15)
	{
		speed.x = 0;
		speed.y = 0;

		int r = 200;

		float x = cos(r_angle) * r;
		float y = sin(r_angle) * r;

		rectangle.setPosition(getPosition().x + x, getPosition().y + y);
		rectangle.setRotation(r_angle * 180 / PI);

		r_angle += 0.1f;
	}

	for(int i = 0 ; i < enemies->size();i++)
	{
		if(enemies->at(i)->getGlobalBounds().intersects(rectangle.getGlobalBounds()))
		{
			enemies->at(i)->hit(1);
		}
	}
}

void Projectile_9::draw()
{
	if (distance(getPosition(), target) > 15)
		window->draw(*this);
	window->draw(rectangle);
}

Vector2f Projectile_9::get_target() const
{
	return target;
}

void Projectile_9::set_target(Vector2f target)
{
	this->target = target;
}

Projectile_9::Projectile_9()
{
}


Projectile_9::~Projectile_9()
{
}
