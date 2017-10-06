
#include "defines.h"

class Net {
	
	SDL_Rect rect;
	int width, height;
	
public:
	Net(int _width, int _height);
	
	void render(SDL_Renderer& renderer);
	
	int left, right, top;
};

Net::Net(int _width, int _height) {
	width = _width;
	height = _height;
	
	rect.x = (SCREEN_WIDTH - width) / 2;
	rect.y = SCREEN_HEIGHT - height;
	rect.width = width;
	rect.height = height;
	
	left = (SCREEN_WIDTH - width) / 2;
	right = (SCREEN_WIDTH + width) / 2;
	top = SCREEN_HEIGHT - height;
}

void Net::render(SDL_Renderer& renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderFillRect(renderer, rect);
}


