#include "Gun.h"
#include <iostream>
#include "Projectile_1.h"
#include "Projectile_2.h"
#include "Projectile_3.h"
#include "Projectile_4.h"
#include "Projectile_5.h"
#include "Projectile_6.h"
#include "Projectile_7.h"
#include "Projectile_8.h"
#include "Projectile_9.h"
#include "Projectile_10.h"
#include "Projectile_11.h"
#include "Projectile_12.h"


Gun::Gun(Vector2f position, Vector2f size, int type, Flatform* flatform)
{
	this->setPosition(position);
	this->setSize(size);
	this->setOrigin(0, getGlobalBounds().height / 2);
	this->type = (Type)type;
	equiped = false;
	shoot_delay = 0.01f;
	this->flatform = flatform;
}

void Gun::draw()
{
	window->draw(*this);
	for(auto &i : projectiles )
	{
		i->draw();
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
	}
	else
	{
		if (Keyboard::isKeyPressed(Keyboard::Q))
		{
			equiped = false;
		}
		
		rotation();
	}

}

void Gun::projectile_move()
{
	for (int i = 0; i < projectiles.size(); i++){
		projectiles[i]->update();

		if(projectiles[i]->is_dead())
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

	if (Mouse::isButtonPressed(Mouse::Left) && clock.getElapsedTime().asSeconds() > shoot_delay)
	{
		clock.restart();

		Projectile* temp = nullptr;
		switch (type)
		{
		case p0:
		{
			temp = new Projectile_0(getPosition(), Vector2f(10, 10),
				Color(rand() % 255, rand() % 255, rand() % 255), angle);
			temp->set_speed();
			temp->set_enemies(enemies);
			temp->set_flatform(flatform);
			projectiles.push_back(temp);
			break;
		}
		case p1:
			{
			for (int i = 0; i < 30; i++) {
				temp = new Projectile_1(getPosition(), Vector2f(10, 10),
					Color(rand() % 255, rand() % 255, rand() % 255), angle);
				temp->set_speed();
				temp->set_enemies(enemies);
				temp->set_flatform(flatform);
				projectiles.push_back(temp);
			}
			break;
			}
		case p2:
		{
			temp = new Projectile_2(getPosition(), Vector2f(10, 10),
				Color(rand() % 255, rand() % 255, rand() % 255), angle);
			temp->set_speed();
			temp->set_enemies(enemies);
			temp->set_flatform(flatform);
			projectiles.push_back(temp);
			break;
		}

		case p3:
			{
			Projectile_3* t = new Projectile_3(getPosition(), Vector2f(10, 10),
				Color(rand() % 255, rand() % 255, rand() % 255), angle);
			t->set_speed();
			t->set_enemies(enemies);
			t->set_flatform(flatform);
			t->set_time_life(1.2);
			t->set_explore_pos(Vector2f(Mouse::getPosition(*window)));
			projectiles.push_back(t);
			break;
			}

		case p4:
			{
			Projectile* t = new Projectile_4(getPosition(), Vector2f(10, 10),
				Color(rand() % 255, rand() % 255, rand() % 255), angle);
			t->set_speed();
			t->set_flatform(flatform);
			t->set_time_life(10);
			t->set_enemies(enemies);
			projectiles.push_back(t);
			break;
			}

		case p5:
			{
			Projectile* t = new Projectile_5(getPosition(), Vector2f(10, 10),
				Color(rand() % 255, rand() % 255, rand() % 255), angle);
			t->set_speed();
			t->set_flatform(flatform);
			t->set_time_life(8);
			t->set_damage(100);
			t->set_enemies(enemies);
			projectiles.push_back(t);
			break;
			}
		case p6:
			{
			Projectile* t = new Projectile_6(getPosition(), Vector2f(10, 10),
				Color(rand() % 255, rand() % 255, rand() % 255), angle);
			t->set_speed();
			t->set_flatform(flatform);
			t->set_time_life(8);
			t->set_enemies(enemies);
			projectiles.push_back(t);
			break;
			}
		case p7:
			{
			for (int i = 0; i < 20; i++) {
				Projectile* t = new Projectile_7(getPosition(), Vector2f(70, 5),
					Color(rand() % 255, rand() % 255, rand() % 255), angle);
				t->set_speed();
				t->set_flatform(flatform);
				t->set_time_life(8);
				t->set_enemies(enemies);
				projectiles.push_back(t);
			}
			break;
			}
		case p8:
			{
			Projectile* t = new Projectile_8(getPosition(), Vector2f(10, 10),
				Color(rand() % 255, rand() % 255, rand() % 255), angle);
			t->set_speed();
			t->set_flatform(flatform);
			t->set_time_life(8);
			t->set_enemies(enemies);
			projectiles.push_back(t);
			break;
			}
		case p9:
			{
			Projectile_9* t = new Projectile_9(getPosition(), Vector2f(10, 10),
				Color(rand() % 255, rand() % 255, rand() % 255), angle);
			t->set_speed();
			t->set_target(Vector2f(Mouse::getPosition(*window)));
			t->set_flatform(flatform);
			t->set_time_life(8);
			t->set_enemies(enemies);
			projectiles.push_back(t);
			break;
			}
		case p10:
			{
			Projectile_10* t = new Projectile_10(getPosition(), Vector2f(10, 10),
				Color(rand() % 255, rand() % 255, rand() % 255), angle);
			t->set_speed();
			t->set_target(Vector2f(Mouse::getPosition(*window)));
			t->set_flatform(flatform);
			t->set_time_life(8);
			t->set_enemies(enemies);
			projectiles.push_back(t);
			break;
			}
		case 12:
			{
			Projectile_12* t = new Projectile_12(getPosition(), Vector2f(30, 10),
				Color(rand() % 255, rand() % 255, rand() % 255), angle);
			t->set_speed();
			t->set_flatform(flatform);
			t->set_time_life(8);
			t->set_player(player->getPosition());
			t->set_target(Vector2f(Mouse::getPosition(*window)));
			t->set_enemies(enemies);
			projectiles.push_back(t);
			break;
			}
		}
		
	}
	this->setRotation(angle);
}

bool Gun::is_equiped() const
{
	return equiped;
}

void Gun::set_equiped(bool equiped)
{
	this->equiped = equiped;
}

float Gun::get_shoot_delay() const
{
	return shoot_delay;
}

void Gun::set_shoot_delay(float shoot_delay)
{
	this->shoot_delay = shoot_delay;
}

Player* Gun::get_player() const
{
	return player;
}

void Gun::set_player(Player* player)
{
	this->player = player;
}

vector<Enemy*>* Gun::get_enemies() const
{
	return enemies;
}

void Gun::set_enemies(vector<Enemy*>* enemies)
{
	this->enemies = enemies;
}


vector<Projectile*> Gun::get_projectiles() const
{
	return projectiles;
}

void Gun::set_projectiles(vector<Projectile*> projectiles)
{
	this->projectiles = projectiles;
}

Gun::Gun()
{
}


Gun::~Gun()
{
}
