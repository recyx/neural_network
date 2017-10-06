
#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "common.h"
#include "net.h"
#include "circle.h"

Net::Net() {
	width = height = 0;
}

void Net::set(int _width, int _height) {
	width = _width;
	height = _height;

	rect.x = (SCREEN_WIDTH - width) / 2;
	rect.y = SCREEN_HEIGHT - height;
	rect.w = width;
	rect.h = height;

	left = (SCREEN_WIDTH - width) / 2;
	right = (SCREEN_WIDTH + width) / 2;
	top = SCREEN_HEIGHT - height;

	topCenter.x = SCREEN_WIDTH / 2;
	topCenter.y = top;

	//Circle topCircle(topCenter.x, topCenter.y, width / 2);
}

void Net::render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0x0);
	SDL_RenderFillRect(renderer, &rect);

	//topCircle.render(renderer);

	for(int dx = - width / 2; dx < width / 2; dx++) {
		for(int dy = - width / 2; dy <= top; dy++) {
			if(dx*dx + dy*dy < (width / 2) * (width / 2)) {
				SDL_RenderDrawPoint(renderer, topCenter.x + dx - 1, topCenter.y+dy);
			}
		}
	}
}

