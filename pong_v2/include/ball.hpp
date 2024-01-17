#include <SDL2/SDL.h>
#include "math_utils.hpp"

class Ball
{
public:
  /**
   * @brief Ball constructor
   */
  Ball();

  /**
   * @brief Ball desctructor
   */
  ~Ball();

  /**
   * @brief Update method for the game ball
   */
  void update(double delta_time);

  /**
   * @brief Draw method for the game ball
   */
  void draw(SDL_Renderer* p_renderer);

private:
  SDL_FRect m_rect;
  Vector2f velocity; 
};
