#include "ball.hpp"
#include "consts.hpp"

Ball::Ball()
{
  m_rect.w = BALL_SIDE;   
  m_rect.h = BALL_SIDE;   
  m_rect.x = (SCREEN_WIDTH - BALL_SIDE)/2;   
  m_rect.y = (SCREEN_HEIGHT - BALL_SIDE)/2;   

  
}
