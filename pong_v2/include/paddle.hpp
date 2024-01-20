#pragma once

#include <SDL2/SDL.h>

#include "entity.hpp"

class Paddle: public Entity
{
public:
  /**
   * @brief Paddle constructor
   */
  Paddle();

  /**
   * @brief Handles input
   */
  void handle_input(SDL_Event& input) override;

  /**
   * @brief Update method for the game paddle
   */
  void update(double delta_time) override;

  /**
   * @brief Draw method for the game paddle
   */
  void draw(SDL_Renderer* p_renderer) override;

private:
  SDL_FRect m_rect;

  float m_v_velocity;
};
