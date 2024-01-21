#pragma once

#include <SDL2/SDL.h>

// TODO: Implement second player logic
class Paddle
{
public:
  /**
   * @brief Paddle constructor
   */
  Paddle();

  /**
   * @brief Handles input
   */
  void handle_input(SDL_Event& input);

  /**
   * @brief Update method for the game paddle
   */
  void update(double delta_time);

  /**
   * @brief Draw method for the game paddle
   */
  void draw(SDL_Renderer* p_renderer);

private:
  SDL_FRect m_rect;
  float m_speed;
};
