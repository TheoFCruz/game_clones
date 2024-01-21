#include "ball.hpp"
#include "consts.hpp"

Ball::Ball()
{
  m_rect.w = BALL_SIDE;   
  m_rect.h = BALL_SIDE;   
  m_rect.x = ((float)(SCREEN_WIDTH - BALL_SIDE))/2;   
  m_rect.y = ((float)(SCREEN_HEIGHT - BALL_SIDE))/2;   
  
  m_direction = Vector2f(-1, 0);
  m_direction.normalize();
}

void Ball::update(double delta_time)
{
  m_rect.x += BALL_SPEED * m_direction.x * delta_time;
  m_rect.y += BALL_SPEED * m_direction.y * delta_time;
}

void Ball::draw(SDL_Renderer* p_renderer)
{
  SDL_RenderFillRectF(p_renderer, &m_rect);
}

void Ball::on_paddle_collision(const Paddle& paddle)
{
  m_direction.x *= -1;
  m_direction.normalize();
}
