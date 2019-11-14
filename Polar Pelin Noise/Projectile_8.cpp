#include "Projectile_8.h"
#include "Projectile_0.h"


Projectile_8::Projectile_8(Vector2f position, Vector2f size, Color color, float angle)
	:Projectile(position,size,color,angle)
{

}

void Projectile_8::update()
{
	if (clock.getElapsedTime().asSeconds() >= time_life)
	{
		dead = true;
	}
	else if(clock.getElapsedTime().asSeconds() >= 0.5f && spawn_clock.getElapsedTime().asSeconds() >= 0.01f)
	{
		speed.x = 0;
		speed.y = 0;

		int x = 1 + (rand() % 10 + 1);
		float angle = randMToN(-180, 180);
		Projectile* temp = new Projectile_0(Vector2f(getPosition()), Vector2f(x, x),
			Color(rand() % 255, rand() % 255, rand() % 255), angle);
		temp->set_move_speed(randMToN(1, 20));
		temp->set_flatform(flatform);
		temp->set_time_life(8);
		temp->set_enemies(enemies);
		small.push_back(temp);
		spawn_clock.restart();
	}

	for(int i = 0 ; i < small.size();i++)
	{
		small[i]->update();
		if(small[i]->is_dead())
		{
			small.erase(small.begin() + i);
		}
	}

	check_collision();
	enemies_collision();

	this->move(speed.x, speed.y);
}

void Projectile_8::draw()
{
	window->draw(*this);
	for(auto& i : small)
	{
		i->draw();
	}
}

Projectile_8::Projectile_8()
{
}


Projectile_8::~Projectile_8()
{
}
