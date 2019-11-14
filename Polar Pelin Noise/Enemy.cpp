#include "Enemy.h"


Enemy::Enemy(Vector2f position, Color color)
{
	this->setSize(Vector2f(20, 100));
	this->setOrigin(getSize().x / 2,getSize().y / 2);
	this->setPosition(position);

	move_speed = 5;
	dead = false;
	hp = 10;

	this->speed = Vector2f(-move_speed, 0);

}

void Enemy::draw()
{
	window->draw(*this);
}

void Enemy::update()
{
	if(getPosition().x < 1)
	{
		speed.x *= -1;
	}
	else if(getPosition().x > 1600)
	{
		dead = true;
	}

	if(getFillColor()== Color::Red && color_clock.getElapsedTime().asSeconds() > 0.05f)
	{
		setFillColor(Color::White);
		color_clock.restart();
	}

	move(speed);
}

void Enemy::hit(int amount)
{
	if (clock.getElapsedTime().asSeconds() > 0.01f && hp > 0)
	{
		hp -= amount;
		setFillColor(Color::Red);
		clock.restart();
		color_clock.restart();
	}

	if (hp <= 0)
	{
		dead = true;
	}
}



int Enemy::get_hp() const
{
	return hp;
}

void Enemy::set_hp(int hp)
{
	this->hp = hp;
}

Enemy::Enemy()
{

}


Enemy::~Enemy()
{
}
