#include "Projectile_12.h"


Projectile_12::Projectile_12(Vector2f position, Vector2f size, Color color, float angle)
	:Projectile(position,size,color,angle)
{
	back = false;
}

void Projectile_12::update()
{
	if (clock.getElapsedTime().asSeconds() >= time_life)
	{
		dead = true;
	}

	if((clock.getElapsedTime().asSeconds() >= 1.5f || distance(target,getPosition()) <= 15) && !back)
	{
		if(!back)
		{
			set_move_speed(2);
		}

		if (wait_clock.getElapsedTime().asSeconds() >= 0.5f) {
			back = true;
			Vector2f direction = Vector2f(player.x - getPosition().x, player.y - getPosition().y);

			angle = atan2f(direction.y, direction.x) * 180 / PI;
			set_move_speed(20);
		}
		
	}
	else
	{
		wait_clock.restart();
	}
	check_collision();
	enemies_collision();

	rotate(20);

	

	this->move(speed.x, speed.y);
}

void Projectile_12::enemies_collision()
{
	for (int i = 0; i < enemies->size(); i++)
	{
		if (enemies->at(i)->getGlobalBounds().intersects(getGlobalBounds()))
		{
			enemies->at(i)->hit(damage);
		}
	}
}

Vector2f Projectile_12::get_target() const
{
	return target;
}

void Projectile_12::set_target(Vector2f target)
{
	this->target = target;
}

Vector2f Projectile_12::get_player() const
{
	return player;
}

void Projectile_12::set_player(Vector2f player)
{
	this->player = player;
}


Projectile_12::Projectile_12()
{
}


Projectile_12::~Projectile_12()
{
}
