#pragma once

#include "ball.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

/**
 * @brief The classes that wraps the entire game
 */
class Game
{
public:
  Game();
  ~Game();

  /**
  * @brief Initializes SDL2 and SDL2_ttf and creates a window and a renderer
  */
  bool init();

  /**
   * @brief Handle inputs in the form of events
   */
  void handle_input(SDL_Event& input);
  
  /**
  * @brief Game update method
  */
  void update(double delta_time);

  /**
  * @brief Game draw method
  */
  void draw();

private:
  SDL_Window* m_window; 
  SDL_Renderer* m_renderer;

  Ball m_ball; 
};
