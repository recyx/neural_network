
#ifdef _WIN32
#include <SDL.h>
#include <iostream>
#else
#include <SDL2/SDL.h>
#endif

#include <stdio.h>
#include <string>

#include "common.h"
#include "vector.h"
#include "circle.h"
#include "net.h"
#include "player.h"
#include "ball.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

double lastTime, dTime;
bool w, a, d;

void init() {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

void keyDown(int keycode) {
	switch(keycode) {
		case SDLK_w:
			w = true;
			break;

		case SDLK_a:
			a = true;
			break;

		case SDLK_d:
			d = true;
			break;
	}
}

void keyUp(int keycode) {
	switch(keycode) {
		case SDLK_w:
			w = false;
			break;

		case SDLK_a:
			a = false;
			break;

		case SDLK_d:
			d = false;
			break;
	}
}

int main(int argc, char* args[]) {
	bool quit = false;

	lastTime = curTime();

	init();

	SDL_Event e;

	Net net;
	net.set(29, 200);

	Player player1(net, 100, SCREEN_HEIGHT - PLAYER_RADIUS * 2 - 20);
	Ball ball(net);


	while(!quit) {
		dTime = curTime() - lastTime;
		dTime = dTime / 1000;
		lastTime = curTime();

		printf("dTime: %f\n", dTime);

		//Input
		while(SDL_PollEvent(&e) != 0) {
			if(e.type == SDL_QUIT) {
				quit = true;
			}

			if(e.type == SDL_KEYDOWN && e.key.repeat == 0) {
         	keyDown(e.key.keysym.sym);
			}

			if(e.type == SDL_KEYUP && e.key.repeat == 0) {
				keyUp(e.key.keysym.sym);
			}
		}

		if(!a && !d) {
			player1.input(0, w);
		} else if(a && d) {
			player1.input(0, w);
		} else if(a) {
			player1.input(-1, w);
		} else if(d) {
			player1.input(1, w);
		}

		player1.update(dTime);
		ball.update(dTime, player1.getPos(), player1.getVel(), player1.getPos(), player1.getVel());

		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);

		/*
		if(!ball.hit) {
			player1.update(0.0166);
			ball.update(0.0166, player1.getPos(), player1.getPos());
		}
		*/



		player1.render(renderer);
		net.render(renderer);
		ball.render(renderer);

		SDL_SetRenderDrawColor(renderer, 0xFF, 0x0, 0x0, 0x0);
		SDL_RenderDrawLine(renderer, player1.x, player1.y, ball.x, ball.y);
		SDL_SetRenderDrawColor(renderer, 0x0, 0xFF, 0x0, 0x0);
		SDL_RenderDrawLine(renderer, ball.x - ball.v.x * 0.0166 * 5, ball.y - ball.v.y * 0.0166 * 5, ball.x + ball.v.x * 0.0166 * 5, ball.y + ball.v.y * 0.0166 * 5);
		//SDL_RenderDrawLine(renderer, ball.x, ball.y, ball.x + ball.v.x * 0.0166 * 5, ball.y + ball.v.y * 0.0166 * 5);
		SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0xFF, 0x0);
		SDL_RenderDrawLine(renderer, ball.x - ball.oldV.x * 0.0166 * 5, ball.y - ball.oldV.y * 0.0166 * 5, ball.x + ball.oldV.x * 0.0166 * 5, ball.y + ball.oldV.y * 0.0166 * 5);
		//SDL_RenderDrawLine(renderer, ball.x, ball.y, ball.x + ball.oldV.x * 0.0166 * 5, ball.y + ball.oldV.y * 0.0166 * 5);


		//printf("OldLen: %f\n", ball.oldV.len());
		//printf("NewLen: %f\n", ball.v.len());

		SDL_RenderPresent(renderer);

	}
}

