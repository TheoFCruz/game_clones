#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

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
   * @brief Handle keyup and keydown events
   */
  void handle_input(SDL_Event& input);
  
  /**
  * @brief Game update method
  */
  void update();

  /**
  * @brief Game draw method
  */
  void draw();

private:
  SDL_Window* m_window; 
  SDL_Renderer* m_renderer;
};
