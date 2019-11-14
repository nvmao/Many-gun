#include "Projectile_2.h"


Projectile_2::Projectile_2(Vector2f position, Vector2f size, Color color, float angle)
	:Projectile(position, size, color, angle)
{

}

void Projectile_2::check_collision()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->getGlobalBounds().intersects(flatform[i].getGlobalBounds()))
		{
			if (i == 0 || i == 1) {
				speed = Vector2f(speed.x * -1, speed.y );
			}
			else
			{
				speed = Vector2f(speed.x , speed.y*-1);
			}
		}
	}
}

Projectile_2::Projectile_2()
{
}


Projectile_2::~Projectile_2()
{
}
