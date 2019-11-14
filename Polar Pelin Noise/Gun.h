#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include "Gobal.h"
#include "Projectile.h"
#include "Flatform.h"
#include "Projectile_0.h"
#include "Enemy.h"
#include "Player.h"

class Player;
class Gun : public sf::RectangleShape
{
	enum Type
	{
		p0 = 0, p1, p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,p19,p20
	};
	Type type;
	vector<Projectile*> projectiles;
	Clock clock;
	Vector2f head;
	bool equiped;
	float shoot_delay;

	Flatform* flatform;
	vector<Enemy*>* enemies;
	Player* player;
public:
	Gun(Vector2f position, Vector2f size,int type,Flatform *flatform);
	void draw();
	void update();
	void projectile_move();
	void rotation();
	bool is_equiped() const;
	void set_equiped(bool equiped);
	float get_shoot_delay() const;
	void set_shoot_delay(float shoot_delay);


	Player* get_player() const;
	void set_player(Player* player);
	vector<Enemy*>* get_enemies() const;
	void set_enemies(vector<Enemy*>* enemies);
	vector<Projectile*> get_projectiles() const;
	void set_projectiles(vector<Projectile*> projectiles);

	
	Gun();
	~Gun();
};

