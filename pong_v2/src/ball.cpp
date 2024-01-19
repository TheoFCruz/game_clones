#include "ball.hpp"
#include "consts.hpp"

Ball::Ball()
{
  m_rect.w = BALL_SIDE;   
  m_rect.h = BALL_SIDE;   
  m_rect.x = ((float)(SCREEN_WIDTH - BALL_SIDE))/2;   
  m_rect.y = ((float)(SCREEN_HEIGHT - BALL_SIDE))/2;   
  
  m_velocity = Vector2f(-1, 0);
}

Ball::~Ball()
{
  
}

void Ball::update(double delta_time)
{
  m_rect.x += BALL_SPEED * m_velocity.x * delta_time;
  m_rect.y += BALL_SPEED * m_velocity.y * delta_time;
}

void Ball::draw(SDL_Renderer* p_renderer)
{
  SDL_RenderFillRectF(p_renderer, &m_rect);
}
