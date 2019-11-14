#pragma once
#include "Projectile.h"

class Projectile_10 : public Projectile
{
	float k;
	vector<Projectile*> small;
	bool almost_dead;
	Vector2f target;
	float t_speed;
	
public:
	Projectile_10(Vector2f position, Vector2f size, Color color, float angle);

	void update() override;
	void enemies_collision() override;
	void draw() override;

	Vector2f get_target() const;
	void set_target(Vector2f target);
	Projectile_10();
	~Projectile_10();
};

