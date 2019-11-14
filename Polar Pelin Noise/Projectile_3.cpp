#include "Projectile_3.h"
#include "Projectile_0.h"
#include "Projectile_2.h"
#include "Projectile_1.h"


Projectile_3::Projectile_3(Vector2f position, Vector2f size, Color color, float angle)
	:Projectile(position,size,color,angle)
{
	almost_die = false;
	
}

void Projectile_3::update()
{
	if (distance(explore_pos,this->getPosition()) < 10 || clock.getElapsedTime().asSeconds() > time_life)
	{
		if (!almost_die)
		{
			if (faster) {
				for (int i = 0; i < 10; i++)
				{
					float angle = randMToN(-180, 180);
					Projectile_3* temp = new Projectile_3(getPosition(), Vector2f(getSize().x - 4, getSize().y - 4),
						getFillColor(), angle);
					temp->set_speed();
					temp->set_flatform(flatform);
					temp->set_enemies(enemies);
					temp->set_move_speed(4);
					temp->set_time_life(2);

					if (temp->getSize().x < 0)
					{
						dead = true;
						return;
					}
					small.push_back(temp);
				}
			}
			else
			{
				for (int i = 0; i < 25; i++)
				{
					float angle = randMToN(-180, 180);
					Projectile_3* temp = new Projectile_3(getPosition(), Vector2f(getSize().x - 4, getSize().y - 4),
						getFillColor(), angle);
					temp->set_speed();
					temp->set_flatform(flatform);
					temp->set_enemies(enemies);
					temp->set_move_speed(3);
					temp->set_time_life(1);
					temp->faster = true;

					if (temp->getSize().x < 0)
					{
						dead = true;
						return;
					}
					small.push_back(temp);
				}
			}
			
			almost_die = true;
		}
			
		if (small.empty() && almost_die) {
			dead = true;
		}
	}
	check_collision();
	enemies_collision();

	if(!faster)
	{
		Color t = getFillColor();
		t.a -= 1;
		setFillColor(t);
	}

	for (int i = 0; i < small.size(); i++) {
		small[i]->update();

		if (small[i]->is_dead())
		{
			small.erase(small.begin() + i);
		}
	}

	this->move(speed.x, speed.y);
}

void Projectile_3::draw()
{
	if (!almost_die) {
		window->draw(*this);
	}

	for(auto & i : small)
	{
		i->draw();
	}

}

void Projectile_3::enemies_collision()
{
	for (int i = 0; i < enemies->size(); i++)
	{
		for(int k = 0 ; k < small.size(); k++)
		{
			if (enemies->at(i)->getGlobalBounds().intersects(small[k]->getGlobalBounds()))
			{
				enemies->at(i)->hit(damage);
				small[k]->set_dead(true);
			}
		}

	}
}

vector<Projectile*> Projectile_3::get_small() const
{
	return small;
}

void Projectile_3::set_small(vector<Projectile*> projectiles)
{
	small = projectiles;
}

Vector2f Projectile_3::get_explore_pos() const
{
	return explore_pos;
}

void Projectile_3::set_explore_pos(Vector2f explore_pos)
{
	this->explore_pos = explore_pos;
}

Projectile_3::Projectile_3()
{
}


Projectile_3::~Projectile_3()
{
}
