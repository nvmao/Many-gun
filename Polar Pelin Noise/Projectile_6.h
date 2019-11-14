#pragma once
#include "Projectile.h"

class Projectile_6 : public Projectile
{
	bool falling = false;
	bool collided = false;
public:
	Projectile_6(Vector2f position, Vector2f size, Color color, float angle);

	void update() override;
	void set_speed() override;
	void check_collision() override;
	void enemies_collision() override;

	Projectile_6();
	~Projectile_6();
};

