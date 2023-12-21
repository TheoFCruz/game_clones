#pragma once

#include <SFML/Graphics.hpp>

class Player{
private:
	sf::RectangleShape _player_shape;
	float _v_speed = 0;

public:
	Player();

	void draw();
	void update();
};
	
