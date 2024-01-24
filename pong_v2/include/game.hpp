#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "ball.hpp"
#include "paddle.hpp"

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

  /**
   * @brief Checks all possible collisions for the ball, and triggers the right functions
   */
  void check_collisions();

  /**
  * @brief Triggered when left player scores
  */
  void score_left(); 

  /**
  * @brief Triggered when left player scores
  */
  void score_right(); 
  
  // Members
  SDL_Window* m_window; 
  SDL_Renderer* m_renderer;

  Ball m_ball;
  Paddle m_right_paddle;
  Paddle m_left_paddle;
};
