#pragma once
#include "Projectile.h"

class Projectile_9 : public Projectile
{
	RectangleShape rectangle;
	float r_angle;
	Vector2f target;
public:
	Projectile_9(Vector2f position, Vector2f size, Color color, float angle);

	void enemies_collision() override;
	void draw() override;


	Vector2f get_target() const;
	void set_target(Vector2f target);
	Projectile_9();
	~Projectile_9();
};

