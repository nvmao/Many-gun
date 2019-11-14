#include "Projectile_10.h"
#include "Projectile_0.h"


Projectile_10::Projectile_10(Vector2f position, Vector2f size, Color color, float angle)
	:Projectile(position,size,color,angle)
{
	int n = 1 + (rand() % 7 - 1 + 1);
	int d = 1 + (rand() % 7 - 1 + 1);
	k = (float)n / d;
	almost_dead = false;
}

void Projectile_10::update()
{
	if (distance(target, getPosition()) <= 20 || clock.getElapsedTime().asSeconds() >= time_life )
	{
		if(!almost_dead)
		{
			speed.x = 0; speed.y = 0;
			int speed_t = rand() % 10;
			if(k == 1)
			{
				int size = 2 +( rand() % 6-1+2);
				for(float a = 0 ;a <= TWO_PI;a += 0.01)
				{
					float x = size * 16 * pow(sin(a), 3);
					float y = size * -(13 * cos(a) - 5 * cos(2 * a) - 2 * cos(3 * a) - cos(4 * a));

					Projectile* t = new Projectile_0(Vector2f(getPosition().x + x, getPosition().y + y), Vector2f(4, 4),
						Color(rand() % 255, rand() % 255, rand() % 255), angle );
					t->set_speed();
					t->set_move_speed(speed_t);
					t->set_flatform(flatform);
					t->set_time_life(2);
					t->set_enemies(enemies);
					small.push_back(t);
				}
			}
			else
			{
				for (float a = 0; a <= 40; a += 0.1)
				{
					float r = cos(k * a) * 100;
					float x = cos(a) * r;
					float y = sin(a) * r;

					Projectile* t = new Projectile_0(Vector2f(getPosition().x + x, getPosition().y + y), Vector2f(4, 4),
						Color(rand() % 255, rand() % 255, rand() % 255), angle );
					t->set_speed();
					t->set_move_speed(speed_t);
					t->set_flatform(flatform);
					t->set_time_life(2);
					t->set_enemies(enemies);
					small.push_back(t);
				}
			}
			

			almost_dead = true;
		}
	}

	if(almost_dead && small.empty())
	{
		dead = true;
	}

	check_collision();
	enemies_collision();

	this->move(speed.x, speed.y);
}

void Projectile_10::enemies_collision()
{

	for (int t = 0; t < small.size(); t++)
	{

		/*for (int i = 0; i < enemies->size(); i++)
		{
			if (enemies->at(i)->getGlobalBounds().intersects(small[t]->getGlobalBounds()))
				small[t]->set_dead(true);
		}*/

		small[t]->update();

		if (small[t]->is_dead())
		{
			small.erase(small.begin() + t);
		}
		

	}

}

void Projectile_10::draw()
{
	if(!almost_dead)
		window->draw(*this);
	for(auto &i : small)
	{
		i->draw();
	}
}

Vector2f Projectile_10::get_target() const
{
	return target;
}

void Projectile_10::set_target(Vector2f target)
{
	this->target = target;
}

Projectile_10::Projectile_10()
{
}


Projectile_10::~Projectile_10()
{
}
