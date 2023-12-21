#pragma once

#include <SFML/Graphics.hpp>


class Ball{
private:
	sf::CircleShape _ball_shape;
	float _v_speed = 1.f;
	float _h_speed = 1.f;

public:
	Ball(float radius);

	void draw();
	void update();
};
