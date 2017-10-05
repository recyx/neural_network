
#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "circle.h"

Circle::Circle(int _x, int _y, int _radius) {
	radius = _radius;
	x = _x;
	y = _y;
}

void Circle::render(SDL_Renderer* renderer) {
	int cx = radius-1;
	int cy = 0;
	int dx = 1;
	int dy = 1;
	int err = dx - (radius << 1);

	while(cx >= cy) {
		SDL_RenderDrawPoint(renderer, x + cx, y + cy);
		SDL_RenderDrawPoint(renderer, x + cx, y - cy);
		SDL_RenderDrawPoint(renderer, x - cx, y + cy);
		SDL_RenderDrawPoint(renderer, x - cx, y - cy);

		SDL_RenderDrawPoint(renderer, x + cy, y + cx);
		SDL_RenderDrawPoint(renderer, x + cy, y - cx);
		SDL_RenderDrawPoint(renderer, x - cy, y + cx);
		SDL_RenderDrawPoint(renderer, x - cy, y - cx);

		if(err <= 0)
		{
			y++;
			err += dy;
			dy += 2;
		}

		if(err > 0)
		{
			x--;
			dx += 2;
			err += (-radius << 1) + dx;
		}
	}
}

