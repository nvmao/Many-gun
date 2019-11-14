#pragma once

#include "Gobal.h"
class Enemy : public sf::RectangleShape
{
	sf::Clock clock;
	Clock color_clock;
	Vector2f speed;
	float move_speed;
	int hp;
public:
	bool dead;
	Enemy(Vector2f position, Color color);
	void draw();
	void update();
	void hit(int amount);


	int get_hp() const;
	void set_hp(int hp);
	Enemy();
	~Enemy();
};

