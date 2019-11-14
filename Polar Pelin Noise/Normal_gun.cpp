#include "Gun.h"
#include <iostream>


Gun::Gun(Vector2f position, Vector2f size, Color color)
{
	this->setPosition(position);
	this->setSize(size);
	this->setFillColor(color);
	this->setOrigin(0,getGlobalBounds().height/2);

	equiped = false;
}

void Gun::draw()
{
	window->draw(*this);
	for(auto &i : projectiles )
	{
		i.draw();
	}
}

void Gun::update()
{
	if (!equiped)
	{
		if (getPosition().y < 710)
		{
			move(0, 3);
		}
		if (getGlobalBounds().intersects(this->getGlobalBounds()) && Keyboard::isKeyPressed(Keyboard::E))
		{
			equiped = true;
		}
	}
	else
	{
		if (Keyboard::isKeyPressed(Keyboard::Q))
		{
			equiped = false;
		}
		setPosition(this->getPosition().x, getPosition().y - 20);
		rotation();
	}
	projectile_move();

}

void Gun::projectile_move()
{
	for (int i = 0; i < projectiles.size(); i++){
		projectiles[i].update();

		for(int p = 0 ; p < 4;p++)
		{
			if (projectiles[i].getGlobalBounds().intersects(flatforms[p].getGlobalBounds()))
			{
				projectiles[i].set_speed(Vector2f(0, 0));
			}
			
		}

		if(projectiles[i].dead)
		{
			projectiles.erase(projectiles.begin() + i);
		}
	}
}

void Gun::rotation()
{
	Vector2f direction = Vector2f(Mouse::getPosition(*window).x - getPosition().x,
		Mouse::getPosition(*window).y - getPosition().y);

	float angle = atan2f(direction.y, direction.x) * 180 / PI;

	if (Mouse::isButtonPressed(Mouse::Left) && clock.getElapsedTime().asSeconds() > 0.01f)
	{
		clock.restart();
		Projectile temp = Projectile(getPosition(), Vector2f(10, 10),
			Color(rand() % 255, rand() % 255, rand() % 255), angle);
		temp.set_speed(angle);
		projectiles.push_back(temp);
	}
	this->setRotation(angle);
}

void Gun::set_flatforms(Flatform* flatform)
{
	this->flatforms = flatform;
}

Gun::Gun()
{
}


Gun::~Gun()
{
}
