#include "Circle.h"
#include <iso646.h>


Circle::Circle(Vector2f position)
{
	int radius = 3;
	setOrigin(3, 3);
	this->origin_pos = position;
	
	setRadius(10);
	velocity = Vector2f(0, 0);
	setPosition(position);
	setPosition(rand() % 1500, rand() % 720);

	max_velocity = 30;
	seek_force = 0.05;
}

void Circle::draw()
{
	window->draw(*this);
}

void Circle::update()
{
	

	if(distance((Vector2f)Mouse::getPosition(*window),getPosition()) <= 100)
	{
		Vector2f dif( Mouse::getPosition(*window).x - getPosition().x,  Mouse::getPosition(*window).y -getPosition().y );

		desired_velocity.x = dif.x ;
		desired_velocity.y = dif.y ;

		desired_velocity = normalize(desired_velocity) * max_velocity;

		steering = -desired_velocity - velocity;
		if(vector_length(steering) > seek_force)
		{
			steering.x *= seek_force;
			steering.y *= seek_force;
		}

		velocity.x += steering.x;
		velocity.y += steering.y;
		clock.restart();
		
	}
	/*else if(distance(getPosition(),origin_pos) <= 0.5)
	{
		velocity = Vector2f(0, 0);
	}*/
	else if (getPosition().x != origin_pos.x || getPosition().y != origin_pos.y)
	{
		if (clock.getElapsedTime().asSeconds() > 2.0f) {
			Vector2f dif(origin_pos.x - getPosition().x, origin_pos.y - getPosition().y);

			desired_velocity.x = dif.x;
			desired_velocity.y = dif.y;
			

			float dist = vector_length(desired_velocity);
			desired_velocity = normalize(desired_velocity);

			if(dist < 800)
			{
				desired_velocity *= dist / 800 * max_velocity;
			}
			else
			{
				desired_velocity *= max_velocity;

			}

			steering = desired_velocity - velocity;
			if (vector_length(steering) > seek_force)
			{
				steering.x *= seek_force;
				steering.y *= seek_force;
			}

			velocity.x += steering.x;
			velocity.y += steering.y;
		}
	}
	
	move(velocity);
}


Circle::Circle()
{
}


Circle::~Circle()
{
}
