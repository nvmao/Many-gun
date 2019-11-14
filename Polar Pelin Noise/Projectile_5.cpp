#include "Projectile_5.h"

Projectile_5::Projectile_5(Vector2f position, Vector2f size, Color color, float angle)
	:Projectile(position, size, color, angle)
{
	setOrigin(size.x / 2, size.y / 2);
}

void Projectile_5::update()
{
	Projectile::update();
	setSize(Vector2f(getSize().x+4, getSize().y+4));
}

Projectile_5::Projectile_5()
{
}


Projectile_5::~Projectile_5()
{
}
