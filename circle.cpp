
#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "circle.h"

Circle::Circle(int _x, int _y, int _rad) {
	rad = _rad;
	x = _x;
	y = _y;
}

void Circle::render(SDL_Renderer* renderer) {

	SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0x0);

	//SDL_RenderDrawLine(renderer, x - rad, y, x);
}

