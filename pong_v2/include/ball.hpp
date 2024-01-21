#pragma once

#include <SDL2/SDL.h>

#include "math_utils.hpp"
#include "paddle.hpp"

class Ball
{
public:
  /**
   * @brief Ball constructor
   */
  Ball();

  /**
   * @brief Update method for the game ball
   */
  void update(double delta_time);

  /**
   * @brief Draw method for the game ball
   */
  void draw(SDL_Renderer* p_renderer);

  /**
  * @brief Triggered on paddle collision
  */
  void on_paddle_collision(const Paddle& paddle);

private:
  SDL_FRect m_rect;
  Vector2f m_direction; 
};
