#include "Player.h"
#include <iostream>


Player::Player(Vector2f position, Vector2f size)
{

	this->setPosition(position);
	this->setSize(size);
	this->setOrigin(getSize().x / 2, getSize().y / 2);
	this->setFillColor(color);
	this->flatform = flatform;
	move_speed = 10;
	jump_height = 15; 

	for (int i = 0; i < 4; i++)
	{
		can_move[i] = true;
	} 
	can_jump = true;
	gun = nullptr;
}

void Player::draw()
{
	window->draw(*this);
	if(gun)
	gun->draw();
}

void Player::movement()
{
	velocity.x = 0;

	if(Keyboard::isKeyPressed(Keyboard::A))
	{
		if(!can_move[0])
		{
			velocity.x -= 0;
		}
		else
		{
			velocity.x -=move_speed ;
		}
	}
	else if(Keyboard::isKeyPressed(Keyboard::D))
	{
		if (!can_move[1])
		{
			velocity.x = 0;
		}
		else
		{
			velocity.x += move_speed;
		}
	}

	if(Keyboard::isKeyPressed(Keyboard::Space) && can_jump)
	{
		   can_jump = false;

		velocity.y = -sqrt(2.0f * 10 * jump_height);
	}
	else if(can_move[3])
	{
		velocity.y += 0.5f;
	}
	else
	{
		velocity.y = 0;
		can_jump = true;
	}

	this->move(velocity);
}

void Player::update()
{
	movement();
	if(gun != nullptr)
	{
		if(gun->is_equiped())
		{
			gun->setPosition(this->getPosition().x, this->getPosition().y - 20);
		}
		gun->update();

	}
		
}


Vector2f Player::get_previous_position() const
{
	return velocity;
}

void Player::set_previous_position(Vector2f previous_position)
{
	this->velocity = previous_position;
}


Gun* Player::get_gun() const
{
	return gun;
}

void Player::set_gun(Gun* gun)
{
	this->gun = gun;
}

Player::Player()
{
}


Player::~Player()
{
}
