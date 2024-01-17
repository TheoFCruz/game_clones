#include <SDL2/SDL.h>
#include "math_utils.hpp"

class Paddle
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
  Vector2f velocity; 
};
