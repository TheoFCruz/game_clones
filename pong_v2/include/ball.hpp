#pragma once

#include <SDL2/SDL.h>

#include "entity.hpp"
#include "math_utils.hpp"

class Ball: public Entity
{
public:
  /**
   * @brief Ball constructor
   */
  Ball();

  /**
   * @brief Ball's empty handle_input for polymorphism purposes
   */
  void handle_input(SDL_Event& event) override {}

  /**
   * @brief Update method for the game ball
   */
  void update(double delta_time) override;

  /**
   * @brief Draw method for the game ball
   */
  void draw(SDL_Renderer* p_renderer) override;

private:
  SDL_FRect m_rect;
  Vector2f m_velocity; 
};
