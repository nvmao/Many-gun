#include "Projectile_1.h"


Projectile_1::Projectile_1(Vector2f position, Vector2f size, Color color, float angle)
	:Projectile(position,size,color,angle)
{

}

void Projectile_1::set_speed()
{
	float temp_angle = randMToN(angle - 30, angle + 30);
	float radian = temp_angle * PI / 180;

	this->speed.x = cos(radian) * 15;
	this->speed.y = sin(radian) * 15;
}

Projectile_1::Projectile_1()
{
}


Projectile_1::~Projectile_1()
{
}
