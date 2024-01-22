#pragma once

#include <SDL2/SDL.h>

// TODO: Implement second player logic

enum class Paddle_Type
{
  PLAYER_LEFT,
  PLAYER_RIGHT,
  AI
};

class Paddle
{
public:
  /**
   * @brief Paddle constructor
   */
  Paddle(Paddle_Type type);

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
  
  /**
   * @brief Gets a reference to the ball and handles the ai logic
   */
  void handle_ai();

  // Getters and Setters
  SDL_FRect& get_rect() {return m_rect;}
  Paddle_Type get_type() {return m_type;}

private:
  SDL_FRect m_rect;
  float m_speed;
  Paddle_Type m_type; 
};
