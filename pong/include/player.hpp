#pragma once

#include <SFML/Graphics.hpp>

// Constants
const float BASE_SPEED = 0.5f;
const float PLAYER_WIDTH = 10.f;
const float PLAYER_HEIGHT = 60.f;

class Player{
private:
	sf::RectangleShape _player_shape;
	sf::RenderWindow& _window;

	float _speed = BASE_SPEED;

	void check_window_collisions();

public:
	// Constructor
	Player(sf::RenderWindow& window);

	// Getters
	sf::RectangleShape get_shape() {return _player_shape;}	

	// Draw and update
	void draw();
	void update(sf::Time delta_time);
};
	
