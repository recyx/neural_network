
#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "defines.h"
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

	Circle topCircle(topCenter.x, topCenter.y, width / 2);
}

void Net::render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0x0);
	SDL_RenderFillRect(renderer, &rect);

	topCircle.render(renderer);
}

