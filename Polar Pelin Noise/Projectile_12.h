#pragma once
#include "Projectile.h"
#include "Player.h"

class Projectile_12 : public Projectile
{
	bool back;
	Vector2f target;
	Vector2f player;
	Clock wait_clock;
	
	
public:
	Projectile_12(Vector2f position, Vector2f size, Color color, float angle);

	void update() override;
	void enemies_collision() override;


	Vector2f get_target() const;
	void set_target(Vector2f target);
	Vector2f get_player() const;
	void set_player(Vector2f player);
	Projectile_12();
	~Projectile_12();
};

