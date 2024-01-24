#pragma once

#include <SDL2/SDL.h>

#include "math_utils.hpp"
#include "consts.hpp"
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
  void on_paddle_collision(Paddle& paddle);

  /**
   * @brief Returns the balls rect
   * @return A reference to the balls SDL_Frect
   */
  SDL_FRect& get_rect() {return m_rect;}

  /**
  * @brief Inverts y in m_dire
  */
  void vertical_bounce(Wall_Type wall);

  /**
  * @brief Resets ball position
  */
  void reset();

private:
  SDL_FRect m_rect;
  Vector2f m_direction; 
};
