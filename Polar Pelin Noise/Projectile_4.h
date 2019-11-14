#pragma once
#include "Projectile.h"

class Projectile_4 : public Projectile
{
	RectangleShape* edge;
	int s;
public:
	Projectile_4(Vector2f position, Vector2f size, Color color, float angle);

	void set_edge_position();
	void update() override;
	void draw() override;
	void enemies_collision() override;

	Projectile_4();
	~Projectile_4();
};

