#pragma once
#include "Projectile.h"
#include "Projectile_0.h"

class Projectile_3 : public Projectile
{
	vector<Projectile*> small;
	bool almost_die;
	Vector2f explore_pos;
	
public:
	bool faster;
	Projectile_3(Vector2f position, Vector2f size, Color color, float angle);

	void update() override;
	void draw() override;
	void enemies_collision() override;

	vector<Projectile*> get_small() const;
	void set_small(vector<Projectile*> projectiles);
	Vector2f get_explore_pos() const;
	void set_explore_pos(Vector2f explore_pos);
	Projectile_3();
	~Projectile_3();
};

