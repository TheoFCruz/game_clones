#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "ball.hpp"
#include "paddle.hpp"
#include "scores.hpp"

/**
 * @brief The classes that wraps the entire game
 */
class Game
{
public:
  Game();

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

  /**
   * @brief Closes the libraries and frees renderer and window memory
   */
  void close();

  /**
   * @brief Triggered when left player scores
   */
  void left_score();

  /**
   * @brief Triggered when right player scores
   */
  void right_score();

  // Returns the renderer
  SDL_Renderer* get_renderer() { return m_renderer; }

private:

  /**
   * @brief Checks all possible collisions for the ball, and triggers the right functions
   */
  void check_collisions();

  // Members
  SDL_Window* m_window; 
  SDL_Renderer* m_renderer;

  Ball m_ball;
  Paddle m_right_paddle;
  Paddle m_left_paddle;

  Scores m_scores;
};
