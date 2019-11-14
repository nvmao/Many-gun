#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include "Gobal.h"
#include "Projectile.h"
#include "Flatform.h"

class Gun : public sf::RectangleShape
{
	vector<Projectile> projectiles;
	Clock clock;
	Vector2f head;

	Flatform* flatforms;
	bool equiped;
public:
	Gun(Vector2f position, Vector2f size, Color color);
	void draw();
	void update();
	void projectile_move();
	void rotation();
	void set_flatforms(Flatform* flatform);
	Gun();
	~Gun();
};

