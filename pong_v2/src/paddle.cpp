#include "paddle.hpp"
#include "consts.hpp"

Paddle::Paddle(Paddle_Type type):
  m_type(type)
{
  m_rect.w = PADDLE_WIDTH;
  m_rect.h = PADDLE_HEIGHT;
  switch(m_type)
  {
    case Paddle_Type::LEFT:
      m_rect.x = 30;
      break;
    case Paddle_Type::RIGHT:
      m_rect.x = SCREEN_WIDTH - (PADDLE_WIDTH + 30);
      break;
  }
  m_rect.y = ((float)(SCREEN_HEIGHT - PADDLE_HEIGHT))/2;

  m_speed = 0; 
}

void Paddle::handle_input(SDL_Event& input)
{
  SDL_Keycode up_key;
  SDL_Keycode down_key;

  switch (m_type)
  {
    case Paddle_Type::LEFT:
      up_key = SDLK_w;
      down_key = SDLK_s;
      break;
    case Paddle_Type::RIGHT:
      up_key = SDLK_UP;
      down_key = SDLK_DOWN;
      break;
    // case Paddle_Type::AI:
    //   handle_ai();
    //   return;
    //   break;
  }

  if (input.type == SDL_KEYDOWN && !input.key.repeat)
  {
    if (input.key.keysym.sym == up_key) m_speed -= PADDLE_SPEED;
    else if (input.key.keysym.sym == down_key) m_speed += PADDLE_SPEED;
  }
  else if (input.type == SDL_KEYUP && !input.key.repeat)
  {
    if (input.key.keysym.sym == up_key) m_speed += PADDLE_SPEED;
    else if (input.key.keysym.sym == down_key) m_speed -= PADDLE_SPEED;
  }
}

void Paddle::update(double delta_time)
{
  m_rect.y += m_speed * delta_time;

  if (m_rect.y < 0) m_rect.y = 0;
  else if(m_rect.y > SCREEN_HEIGHT - PADDLE_HEIGHT) m_rect.y = SCREEN_HEIGHT - PADDLE_HEIGHT;
}

void Paddle::draw(SDL_Renderer* p_renderer)
{
  SDL_RenderFillRectF(p_renderer, &m_rect);
}

void handle_ai()
{
  // TODO: implement AI
}
