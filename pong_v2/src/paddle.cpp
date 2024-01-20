#include "paddle.hpp"
#include "consts.hpp"

Paddle::Paddle()
{
  m_rect.w = PADDLE_WIDTH;
  m_rect.h = PADDLE_HEIGHT;
  m_rect.x = 30;
  m_rect.y = ((float)(SCREEN_HEIGHT - PADDLE_HEIGHT))/2;

  m_v_velocity = 0; 
}

void Paddle::handle_input(SDL_Event& input)
{
  if (input.type == SDL_KEYDOWN && !input.key.repeat)
  {
    switch (input.key.keysym.sym)
    {
      case SDLK_w:
        m_v_velocity -= PADDLE_SPEED; 
      break;

      case SDLK_s:
        m_v_velocity += PADDLE_SPEED; 
      break;
    }
  }
  else if (input.type == SDL_KEYUP && !input.key.repeat)
  {
    switch (input.key.keysym.sym)
    {
      case SDLK_w:
        m_v_velocity += PADDLE_SPEED; 
      break;

      case SDLK_s:
        m_v_velocity -= PADDLE_SPEED; 
      break;
    }
  }
}

void Paddle::update(double delta_time)
{
  m_rect.y += m_v_velocity * delta_time;
}

void Paddle::draw(SDL_Renderer* p_renderer)
{
  SDL_RenderFillRectF(p_renderer, &m_rect);
}
