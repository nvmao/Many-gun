#include "Projectile_6.h"


Projectile_6::Projectile_6(Vector2f position, Vector2f size, Color color, float angle)
	:Projectile(position,size,color,angle)
{

}

void Projectile_6::update()
{
	if (clock.getElapsedTime().asSeconds() >= time_life)
	{
		dead = true;
	}
	else if(!falling )
	{
		int height =  abs(Mouse::getPosition(*window).y - getPosition().y)/10;
		speed.y *= sqrt(2.0f * 6 * height);
		falling = true;
	}
	check_collision();
	enemies_collision();

	if (falling) {
		speed.y += 0.5;
	}
	
	this->move(speed.x, speed.y);
}

void Projectile_6::set_speed()
{
	float radian = angle * PI / 180;
	this->speed.x = cos(radian) * move_speed;
	this->speed.y = sin(radian) ;
	
}

void Projectile_6::check_collision()
{

	
	float distance = 500;

	if (getPosition().x < 0 + distance)
	{
		speed.x -= 1;
	}
	else if (getPosition().x > window->getSize().x - distance)
	{
		speed.x += 1;
	}
	else if (getPosition().y < 0 + 300)
	{
		speed.y -= 1;
	}


	for (int i = 0; i < 4; i++)
	{
		if (this->getGlobalBounds().intersects(flatform[i].getGlobalBounds()))
		{
			speed = Vector2f(0, 0);
			collided = true;
		}
	}
}

void Projectile_6::enemies_collision()
{
	for (int i = 0; i < enemies->size(); i++)
	{
		if (distance(enemies->at(i)->getPosition(), getPosition()) < 1000 && collided) {

			Vector2f direction = Vector2f(getPosition().x - enemies->at(i)->getPosition().x,
				getPosition().y - enemies->at(i)->getPosition().y);

			float angle = atan2f(direction.y, direction.x);
			float x = cos(angle);
			float y = sin(angle);
			enemies->at(i)->move(x, y);
		}

		if(enemies->at(i)->getGlobalBounds().intersects(getGlobalBounds()) && collided)
		{
			enemies->at(i)->hit(damage);
		}


	}
}

Projectile_6::Projectile_6()
{
}


Projectile_6::~Projectile_6()
{
}
