#pragma once
#include "Projectile.h"

class Projectile_5 : public Projectile
{

public:
	Projectile_5(Vector2f position, Vector2f size, Color color, float angle);
	void update() override;
	Projectile_5();
	~Projectile_5();
};

