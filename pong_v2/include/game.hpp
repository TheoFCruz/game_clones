#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Game
{
  public:
    Game();
    ~Game();

    /**
    * @brief Initializes SDL2 and SDL2_ttf and creates a window and a renderer
    */
    void init();

  private:
    SDL_Window* m_window; 
    SDL_Renderer* m_renderer;
};
