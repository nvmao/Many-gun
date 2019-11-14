#include "Projectile_7.h"


Projectile_7::Projectile_7(Vector2f position, Vector2f size, Color color, float angle)
	:Projectile(position,size,color,angle)
{
	move_speed = randMToN(1.0f, 20.0f);
	target = Vector2f(0, 0);
}

void Projectile_7::update()
{
	if (clock.getElapsedTime().asSeconds() >= time_life)
	{
		dead = true;
	}
	else if(clock.getElapsedTime().asSeconds() >= 1 )
	{
		if(!enemies->empty())
		{
			int min = 0;
			float min_distance = 10000;

			for(int i = 0; i < enemies->size(); i++)
			{
				float current_dis = distance(enemies->at(i)->getPosition(), getPosition());
				if(current_dis <= min_distance)
				{
					min_distance = current_dis;
					min = i;
				}
			}

			target = enemies->at(min)->getPosition();

			Vector2f direction = Vector2f(target.x - getPosition().x,
				target.y - getPosition().y);

			float angle = atan2f(direction.y, direction.x);

			setRotation(angle * 180 / PI);

			float x = cos(angle);
			float y = sin(angle);

			speed.x = x * 20;
			speed.y = y * 20;
		}

	}

	check_collision();
	enemies_collision();

	this->move(speed.x, speed.y);
}

void Projectile_7::set_speed()
{
	float temp_angle = randMToN(angle - 30, angle + 30);
	float radian = temp_angle * PI / 180;

	this->speed.x = cos(radian) * move_speed;
	this->speed.y = sin(radian) * move_speed;
}


Projectile_7::Projectile_7()
{
}


Projectile_7::~Projectile_7()
{
}
