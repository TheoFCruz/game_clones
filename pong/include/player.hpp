#pragma once

#include <SFML/Graphics.hpp>

class Player{
private:
	sf::RectangleShape _player_shape;
	float _speed = 0.5f;

public:
	Player();

	void draw(sf::RenderWindow& window);
	void update();
};
	
