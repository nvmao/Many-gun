#include "Game.h"



Game::Game()
{
	player = Player(Vector2f(1280 / 2, 720 / 2), Vector2f(20, 100));
	
	enemies = new vector<Enemy*>;

	flatform[0] = Flatform(Vector2f(1, 1), Vector2f(20, 720), Color::Blue);
	flatform[1] = Flatform(Vector2f(1480, 1), Vector2f(20, 720), Color::Blue);
	flatform[2] = Flatform(Vector2f(1, 1), Vector2f(1500, 20), Color::Blue);
	flatform[3] = Flatform(Vector2f(1, 720), Vector2f(1500, 20), Color::Blue);

	Gun *gun1 = new Gun(Vector2f(200, 700), Vector2f(50, 10),0,flatform);
	gun1->set_shoot_delay(0.0001f);
	gun1->set_enemies(enemies);
	gun1->setFillColor(Color(244, 100, 12));

	Gun *gun2 = new Gun(Vector2f(100, 700), Vector2f(50, 10), 0,flatform);
	gun2->set_shoot_delay(0.1f);
	gun2->set_enemies(enemies);

	Gun *gun3 = new Gun(Vector2f(300, 700), Vector2f(50, 10), 1,flatform);
	gun3->set_shoot_delay(0.1f);
	gun3->set_enemies(enemies);
	gun3->setFillColor(Color(100, 230, 80));

	Gun *gun4 = new Gun(Vector2f(400, 700), Vector2f(50, 10), 2, flatform);
	gun4->set_shoot_delay(0.1f);
	gun4->set_enemies(enemies);
	gun4->setFillColor(Color(30, 230, 200));

	Gun* gun5 = new Gun(Vector2f(500, 700), Vector2f(50, 10), 3, flatform);
	gun5->set_shoot_delay(0.5f);
	gun5->set_enemies(enemies);
	gun5->setFillColor(Color(100, 230, 10));

	Gun* gun6 = new Gun(Vector2f(600, 700), Vector2f(50, 10), 4, flatform);
	gun6->set_shoot_delay(0.1f);
	gun6->set_enemies(enemies);
	gun6->setFillColor(Color(50, 100, 50));

	Gun* gun7 = new Gun(Vector2f(700, 700), Vector2f(50, 10), 5, flatform);
	gun7->set_shoot_delay(0.1f);
	gun7->set_enemies(enemies);
	gun7->setFillColor(Color(10, 20, 100));

	Gun* gun8 = new Gun(Vector2f(800, 700), Vector2f(50, 10), 6, flatform);
	gun8->set_shoot_delay(0.1f);
	gun8->set_enemies(enemies);
	gun8->setFillColor(Color(255, 20, 40));

	Gun* gun9 = new Gun(Vector2f(900, 700), Vector2f(50, 10), 7, flatform);
	gun9->set_shoot_delay(0.1f);
	gun9->set_enemies(enemies);
	gun9->setFillColor(Color(40, 20, 40));

	Gun* gun10 = new Gun(Vector2f(100, 600), Vector2f(50, 10), 8, flatform);
	gun10->set_shoot_delay(0.1f);
	gun10->set_enemies(enemies);
	gun10->setFillColor(Color(100, 20, 40));

	Gun* gun11 = new Gun(Vector2f(200, 600), Vector2f(50, 10), 9, flatform);
	gun11->set_shoot_delay(0.01f);
	gun11->set_enemies(enemies);
	gun11->setFillColor(Color(100, 200, 40));

	Gun* gun12 = new Gun(Vector2f(300, 600), Vector2f(50, 10), 10, flatform);
	gun12->set_shoot_delay(0.6f);
	gun12->set_enemies(enemies);
	gun12->setFillColor(Color(100, 200, 200));

	Gun* gun13 = new Gun(Vector2f(400, 600), Vector2f(50, 10), 12, flatform);
	gun13->set_shoot_delay(0.1f);
	gun13->set_enemies(enemies);
	gun13->set_player(&player);
	gun13->setFillColor(Color(0, 200, 200));

	guns.push_back(gun1);
	guns.push_back(gun2);
	guns.push_back(gun3);
	guns.push_back(gun4);
	guns.push_back(gun5);
	guns.push_back(gun6);
	guns.push_back(gun7);
	guns.push_back(gun8);
	guns.push_back(gun9);
	guns.push_back(gun10);
	guns.push_back(gun11);
	guns.push_back(gun12);
	guns.push_back(gun13);
}

void Game::draw()
{
	
	for (auto& i : guns)
	{
		i->draw();
	}
	player.draw();

	for(auto&i : *enemies)
	{
		i->draw();
	}

	for(int i = 0 ; i < 4; i++)
	{
		flatform[i].draw();
	}
	
}

void Game::update()
{
	check_collisions();
	player.update();
	guns_update();
	spawn_enemies();
}

void Game::spawn_enemies()
{
	if(clock.getElapsedTime().asSeconds() > 1000000.f)
	{
		Enemy* temp = new Enemy(Vector2f(1500, randMToN(100,600)), Color::White);
		enemies->push_back(temp);
		clock.restart();
	}

	for(int i = 0 ; i < enemies->size();i++)
	{
		enemies->at(i)->update();
		if(enemies->at(i)->dead)
		{
			enemies->erase(enemies->begin() + i);
		}
	}

}

void Game::guns_update()
{
	for(int i = 0 ; i < guns.size();i++)
	{
		guns[i]->projectile_move();

		if(player.getGlobalBounds().intersects(guns[i]->getGlobalBounds()) && Keyboard::isKeyPressed(Keyboard::E))
		{
			guns[i]->set_equiped(true);
			player.set_gun(guns[i]);
		}
	}
}

void Game::check_collisions()
{
	for(int i = 0 ; i < 4;i++)
	{
		if(player.getGlobalBounds().intersects(flatform[i].getGlobalBounds()))
		{
			player.can_move[i] = false;
		}
		else
		{
			player.can_move[i] = true;
		}
	}
}

Vector2f Game::get_player_pos()
{
	return player.getPosition();
}


Game::~Game()
{
	guns.clear();
}
