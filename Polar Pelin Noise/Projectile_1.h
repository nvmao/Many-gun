#pragma once
#include "Projectile.h"

class Projectile_1 : public Projectile
{
	
public:
	Projectile_1(Vector2f position, Vector2f size, Color color, float angle);
	void set_speed() override;
	Projectile_1();
	~Projectile_1();
};

