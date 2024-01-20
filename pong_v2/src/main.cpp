#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "game.hpp"

int main(int argc, char** argv)
{
  Game game;
  game.init();

  Uint64 current_counter = SDL_GetPerformanceCounter();
  Uint64 last_counter = 0;
  double delta_time = 0;
  
  SDL_Event event;
  bool running = true;
  while (running)
  {
    // Calculates delta_time in milliseconds
    last_counter = current_counter;
    current_counter = SDL_GetPerformanceCounter();
    delta_time = ((double)(current_counter - last_counter))/((double)(SDL_GetPerformanceFrequency()));

    // Event loop
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT) running = false;
      else game.handle_input(event);
    }

    //Game update and draw
    game.update(delta_time);
    game.draw();
  }
}
