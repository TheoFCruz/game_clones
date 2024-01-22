#include "ball.hpp"
#include "consts.hpp"

Ball::Ball()
{
  m_rect.w = BALL_SIDE;   
  m_rect.h = BALL_SIDE;   
  m_rect.x = ((float)(SCREEN_WIDTH - BALL_SIDE))/2;   
  m_rect.y = ((float)(SCREEN_HEIGHT - BALL_SIDE))/2;   
  
  m_direction = Vector2f(-1 , 1);
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

void Ball::on_paddle_collision(Paddle& paddle)
{
  // TODO: there must be a better way to do this
  switch (paddle.get_type())
  {
    case Paddle_Type::PLAYER_LEFT:
      m_rect.x = paddle.get_rect().x + PADDLE_WIDTH;
      break;
    case Paddle_Type::PLAYER_RIGHT:
      m_rect.x = paddle.get_rect().x - BALL_SIDE;
      break;
    case Paddle_Type::AI:
      m_rect.x = paddle.get_rect().x - BALL_SIDE;
      break;
  }

  // TODO: implement direction change logic
  m_direction.x = - m_direction.x;
  m_direction.normalize();
}

void Ball::vertical_bounce(Wall_Type wall)
{
  switch (wall)
  {
    case Wall_Type::TOP:
      m_rect.y = 0;
      break;
    case Wall_Type::BOTTOM:
      m_rect.y = SCREEN_HEIGHT - BALL_SIDE;
      break;
  }
   m_direction.y = -m_direction.y;
}
