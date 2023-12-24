#include "../include/player.hpp"

//-------------------Private Functions-----------------------

void Player::check_window_collisions()
{
	float max_y = _window.getSize().y - PLAYER_HEIGHT;

	if (_player_shape.getPosition().y < 0)
	{
		_player_shape.setPosition(_player_shape.getPosition().x, 0);
	}
	else if (_player_shape.getPosition().y > max_y)
	{
		_player_shape.setPosition(_player_shape.getPosition().x, max_y);
	}
}

//-------------------Public Functions------------------------

Player::Player(sf::RenderWindow& window):
	_window(window)
{
	_player_shape.setFillColor(sf::Color::White);
	_player_shape.setSize(sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT));
	_player_shape.setPosition(sf::Vector2f(50.f, (window.getSize().y-PLAYER_HEIGHT)/2));
}

void Player::draw()
{
	_window.draw(_player_shape);
}

void Player::update(sf::Time delta_time)
{
	// Check inputs
	int up = sf::Keyboard::isKeyPressed(sf::Keyboard::W) ? 1 : 0;
	int down = sf::Keyboard::isKeyPressed(sf::Keyboard::S) ? 1 : 0;

	// Move
	_player_shape.move(0, (down - up) * _speed * delta_time.asMilliseconds());

	// Check collisions
	check_window_collisions();
}

