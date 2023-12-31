#include "../include/ball.hpp"

//-------------------Private Functions--------------------------

void Ball::check_window_collisions()
{
	float max_y = _window.getSize().y - 2 * _ball_shape.getRadius();

	if (_ball_shape.getPosition().y < 0 || _ball_shape.getPosition().y > max_y)
	{
		_v_speed *= -1;
	}

	if (_ball_shape.getPosition().x > _window.getSize().x - _ball_shape.getRadius() * 2)
	{
		_h_speed *= -1;
	}
}

//-------------------Public Functions---------------------------

Ball::Ball(float radius, sf::RenderWindow& window):
	_window(window)
{	
	_ball_shape.setRadius(radius);

	// Setting position to the center of the window
	float center_x = ((float)_window.getSize().x / 2) - _ball_shape.getRadius();	
	float center_y = ((float)_window.getSize().y / 2) - _ball_shape.getRadius();	

	_ball_shape.setPosition(center_x, center_y);
}

void Ball::draw()
{
	_window.draw(_ball_shape);
}

void Ball::update(sf::Time delta_time)
{
	_ball_shape.move(sf::Vector2f(_h_speed * delta_time.asMilliseconds(), 
															 _v_speed * delta_time.asMilliseconds()));

	check_window_collisions();
}

void Ball::restart()
{
	// Setting position to the center of the window
	float center_x = ((float)_window.getSize().x / 2) - _ball_shape.getRadius();	
	float center_y = ((float)_window.getSize().y / 2) - _ball_shape.getRadius();	

	_ball_shape.setPosition(center_x, center_y);
}
