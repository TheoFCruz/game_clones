#pragma once

#include <SFML/Graphics.hpp>

const float V_SPEED = 5.f;
const float H_SPEED = 0.f;

class Ball{
private:
	sf::CircleShape _ball_shape;
	sf::RenderWindow& _window;

	float _v_speed = V_SPEED;
	float _h_speed = H_SPEED;

	void check_collisions();

public:
	Ball(float radius, sf::RenderWindow& window);

	void draw();
	void update();
};
