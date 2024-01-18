#pragma once

#include <SDL2/SDL.h>

#include "entity.hpp"
#include "math_utils.hpp"

class Paddle: public Entity
{
public:
  /**
   * @brief Paddle constructor
   */
  Paddle();

  /**
   * @brief Paddle desctructor
   */
  ~Paddle();

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
  Vector2f velocity; 
};
