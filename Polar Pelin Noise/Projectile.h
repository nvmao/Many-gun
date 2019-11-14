#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include "Gobal.h"
#include "Flatform.h"
#include "Enemy.h"

class Projectile : public sf::RectangleShape
{
protected:
	Clock clock;
	float time_life;
	Vector2f speed;
	bool dead = false;
	float angle;
	Flatform* flatform;
	float move_speed;
	int damage;

	vector<Enemy*>* enemies;
public:
	Projectile(Vector2f position, Vector2f size, Color color,float angle);
	virtual void draw();
	virtual void update();
	virtual void set_speed();
	virtual void check_collision();
	virtual void enemies_collision();


	int get_damage() const;
	void set_damage(int damage);
	vector<Enemy*>* get_enemies() const;
	void set_enemies(vector<Enemy*>* enemies);
	float get_move_speed() const;
	void set_move_speed(float move_speed);
	float get_time_life() const;
	void set_time_life(float time_life);
	void set_flatform(Flatform* flatform);
	void set_speed(Vector2f s);
	Vector2f get_speed();
	bool is_dead() const;
	void set_dead(bool dead);
	Projectile();
	~Projectile();
};

