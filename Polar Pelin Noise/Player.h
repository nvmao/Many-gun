#pragma once
#include "Gobal.h"
#include "Gun.h"
class Gun;

class Player : public RectangleShape
{
	Color color = Color(123,13,123);
	float move_speed;
	float jump_height;

	Vector2f velocity;
	bool can_jump;
	Clock clock;
	Gun *gun;
	Flatform* flatform;
public:
	bool can_move[4];
	Player(Vector2f position, Vector2f size);
	void draw();
	void movement();
	void update();

	Vector2f get_previous_position() const;
	void set_previous_position(Vector2f previous_position);


	Gun* get_gun() const;
	void set_gun(Gun* gun);
	Player();
	~Player();
};

