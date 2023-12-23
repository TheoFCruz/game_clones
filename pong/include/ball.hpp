#pragma once

#include <SFML/Graphics.hpp>

const float V_SPEED = 0.4f;
const float H_SPEED = -0.4f;

class Ball{
private:
	sf::CircleShape _ball_shape;
	sf::RenderWindow& _window;

	float _v_speed = V_SPEED;
	float _h_speed = H_SPEED;

	void check_window_collisions();

public:
	// Constructor
	Ball(float radius, sf::RenderWindow& window);

	// Getters
	sf::CircleShape get_shape() {return _ball_shape;}	

	// Draw and update
	void draw();
	void update(sf::Time delta_time);

	// Own functions
	void paddle_bounce() {_h_speed *= -1;}
};
