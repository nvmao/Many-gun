#pragma once
#include "Projectile.h"
#include "Flatform.h"

class Projectile_2 : public Projectile
{
	
public:
	Projectile_2(Vector2f position, Vector2f size, Color color, float angle);
	void check_collision() override;
	Projectile_2();
	~Projectile_2();
};

