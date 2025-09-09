#include "SDL2/SDL.h"

#include "universe.hpp"

Universe::Universe(const int height, const int width) {
  SDL_Init(SDL_INIT_AUDIO | SDL_INIT_TIMER | SDL_INIT_VIDEO);

  SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);

  SDL_SetWindowTitle(window, "Universe");

  Run();
}

void Universe::Run() {

  while (true) {
    const double now = ((double)SDL_GetTicks()) /
                       1000.0; /* convert from milliseconds to seconds. */
    /* choose the color for the frame we will draw. The sine wave trick makes it
     * fade between colors smoothly. */
    const int red = (128 + 128 * SDL_sin(now));
    const int green = (128 + 128 * SDL_sin(now + 3.1415 * 2 / 3));
    const int blue = (128 + 128 * SDL_sin(now + 3.1415 * 4 / 3));
    SDL_SetRenderDrawColor(renderer, red, green, blue,
                           SDL_ALPHA_OPAQUE); /* new color, full alpha. */

    /* clear the window to the draw color. */
    SDL_RenderClear(renderer);

    /* put the newly-cleared rendering on the screen. */
    SDL_RenderPresent(renderer);
  }
}
