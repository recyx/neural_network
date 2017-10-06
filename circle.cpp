
#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "circle.h"

Circle::Circle() {
	Circle(0, 0, 0);
}

Circle::Circle(int _x, int _y, int _rad) {
	rad = _rad;
	x = _x;
	y = _y;
}

void Circle::render(SDL_Renderer* renderer) {

	SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0x0);

	for(int dx = -rad; dx <= rad; dx++) {
		for(int dy = -rad; dy <= rad; dy++) {
			if(dx*dx + dy*dy <= rad*rad) {
				SDL_RenderDrawPoint(renderer, x+dx, y+dy);
			}
		}
	}
}

