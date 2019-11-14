#pragma once
#include "Projectile.h"
#include "Gobal.h"

class Projectile_8 : public Projectile
{
	vector<Projectile*> small;
	Clock spawn_clock;
public:
	Projectile_8(Vector2f position, Vector2f size, Color color, float angle);

	void update() override;
	void draw() override;

	Projectile_8();
	~Projectile_8();
};

