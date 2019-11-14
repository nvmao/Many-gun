#pragma once
#include "Projectile.h"

class Projectile_7: public Projectile
{
	Vector2f target;

public:
	Projectile_7(Vector2f position, Vector2f size, Color color, float angle);

	void update() override;
	void set_speed() override;

	Projectile_7();
	~Projectile_7();
};

