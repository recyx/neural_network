
#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <stdio.h>
#include <string>

#include "circle.h"

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;



void init() {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

int main(int argc, char* args[]) {
	bool quit = false;

	init();

	SDL_Event e;


	Circle circle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 40);

	
	while(!quit) {

		//Input
		while(SDL_PollEvent(&e) != 0) {
			if(e.type == SDL_QUIT) {
				quit = true;
			}
		}

		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);

		circle.render(renderer);

		SDL_RenderPresent(renderer);
	}
}
