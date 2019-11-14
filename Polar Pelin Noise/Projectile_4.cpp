#include "Projectile_4.h"


Projectile_4::Projectile_4(Vector2f position, Vector2f size, Color color, float angle)
	:Projectile(position, size, color, angle)
{
	s = 2 + (rand() % 20 -2 +1);
	edge = new RectangleShape[s];
	for(int i = 0 ; i < s;i++)
	{
		edge[i].setSize(Vector2f(30, 5));
		edge[i].setFillColor(color);
		edge[i].setOrigin(size.x/2,0);
	}
	damage = 1;

	set_edge_position();
}

void Projectile_4::set_edge_position()
{
	float r = 4;
	float angle = 0;
	for(int i = 0 ; i < s;i++)
	{
		float x = cos(angle) * r;
		float y = sin(angle) * r;

		edge[i].setPosition(getPosition().x + x,getPosition().y + y);

		edge[i].setRotation(angle * 180 / PI);

		angle += TWO_PI / s;
	}
}

void Projectile_4::update()
{
	Projectile::update();
	
	for(int i = 0 ; i <s;i++)
	{
		edge[i].rotate(-10);
		edge[i].move(speed.x, speed.y);
	}
}

void Projectile_4::draw()
{
	Projectile::draw();
	for(int i = 0 ; i < s;i++)
	{
		window->draw(edge[i]);
	}
}

void Projectile_4::enemies_collision()
{
	for (int i = 0; i < enemies->size(); i++)
	{
		if (enemies->at(i)->getGlobalBounds().intersects(getGlobalBounds()))
		{
			enemies->at(i)->hit(damage);
			speed.x = speed.y = 0;
		}
	}
}

Projectile_4::Projectile_4()
{
}


Projectile_4::~Projectile_4()
{
	delete edge;
}
