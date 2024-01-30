#include "ball.hpp"
#include "consts.hpp"

Ball::Ball()
{
  m_rect.w = BALL_SIDE;   
  m_rect.h = BALL_SIDE;   
  m_rect.x = ((float)(SCREEN_WIDTH - BALL_SIDE))/2;   
  m_rect.y = ((float)(SCREEN_HEIGHT - BALL_SIDE))/2;   
  
  m_direction = Vector2f(-1 , 0);

  m_current_speed = SERVE_SPEED;
}

void Ball::update(double delta_time)
{
  m_rect.x += m_current_speed * m_direction.x * delta_time;
  m_rect.y += m_current_speed * m_direction.y * delta_time;
}

void Ball::draw(SDL_Renderer* p_renderer)
{
  SDL_RenderFillRectF(p_renderer, &m_rect);
}

void Ball::on_paddle_collision(Paddle& paddle)
{
  // Doing this every collision cause I couldn't find a better way
  m_current_speed = BALL_SPEED;

  // There must be a better way to do this
  switch (paddle.get_type())
  {
    case Paddle_Type::LEFT:
      m_rect.x = paddle.get_rect().x + PADDLE_WIDTH;
      break;
    case Paddle_Type::RIGHT:
      m_rect.x = paddle.get_rect().x - BALL_SIDE;
      break;
  }

  m_direction.x = - m_direction.x;
  // Linear regression to alter a little the ball's direction
  m_direction.y += -0.5 + (m_rect.y - paddle.get_rect().y)/PADDLE_HEIGHT;
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

void Ball::reset(Paddle_Type type)
{
  m_rect.x = ((float)(SCREEN_WIDTH - BALL_SIDE))/2;   
  m_rect.y = ((float)(SCREEN_HEIGHT - BALL_SIDE))/2;   
  
  switch (type)  
  {
    case Paddle_Type::RIGHT:
      m_direction = Vector2f(-1,0);
      break;
    case Paddle_Type::LEFT:
      m_direction = Vector2f(1,0);
      break;
  }

  m_current_speed = SERVE_SPEED;
}
