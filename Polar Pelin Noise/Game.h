#pragma once
#include "Player.h"
#include "Flatform.h"
#include "Enemy.h"

class Game
{
	Player player;
	Flatform flatform[4];
	vector<Gun*> guns;
	vector<Enemy*> *enemies;
	Clock clock;
	
public:
	Game();

	void draw();
	void update();
	void spawn_enemies();
	void guns_update();
	void check_collisions();
	Vector2f get_player_pos();
	~Game();
};

