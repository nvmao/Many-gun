#include "Projectile.h"


Projectile::Projectile(Vector2f position, Vector2f size, Color color,float angle)
{
	this->setPosition(position);
	this->setSize(size);
	this->setFillColor(color);
	this->setOrigin(size.x / 2, size.y / 2);
	this->setRotation(angle);
	this->angle = angle;
	this->time_life = 5.0f;
	this->move_speed = 15.0f;
	damage = 2.5;
}

void Projectile::draw()
{
	window->draw(*this);
}

void Projectile::update()
{
	if(clock.getElapsedTime().asSeconds() >= time_life)
	{
		dead = true;
	}
	check_collision();
	enemies_collision();

	this->move(speed.x, speed.y);
}

void Projectile::set_speed()
{
	float radian = angle * PI / 180;
	this->speed.x = cos(radian) * move_speed;
	this->speed.y = sin(radian) * move_speed;
}

void Projectile::check_collision()
{
	for(int i = 0 ; i < 4;i++)
	{
		if(this->getGlobalBounds().intersects(flatform[i].getGlobalBounds()))
		{
			speed = Vector2f(0, 0);
		}
	}

}

void Projectile::enemies_collision()
{
	for (int i = 0; i < enemies->size(); i++)
	{
		if (enemies->at(i)->getGlobalBounds().intersects(getGlobalBounds()))
		{
			enemies->at(i)->hit(damage);
			dead = true;
		}
	}
}

int Projectile::get_damage() const
{
	return damage;
}

void Projectile::set_damage(int damage)
{
	this->damage = damage;
}

vector<Enemy*>* Projectile::get_enemies() const
{
	return enemies;
}

void Projectile::set_enemies(vector<Enemy*>* enemies)
{
	this->enemies = enemies;
}


float Projectile::get_move_speed() const
{
	return move_speed;
}

void Projectile::set_move_speed(float move_speed)
{
	this->move_speed = move_speed;
	set_speed();
}

float Projectile::get_time_life() const
{
	return time_life;
}

void Projectile::set_time_life(float time_life)
{
	this->time_life = time_life;
}

void Projectile::set_flatform(Flatform* flatform)
{
	this->flatform = flatform;
}

void Projectile::set_speed(Vector2f s)
{
	this->speed = s;
}

Vector2f Projectile::get_speed()
{
	return speed;
}

bool Projectile::is_dead() const
{
	return dead;
}

void Projectile::set_dead(bool dead)
{
	this->dead = dead;
}

Projectile::Projectile()
{
}


Projectile::~Projectile()
{
}
