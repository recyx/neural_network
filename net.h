
#ifndef __NET_H
#define __NET_H

#include "circle.h"
#include "vector.h"


struct Net {

	SDL_Rect rect;
	int width, height;

	Net();

	void set(int _width, int _height);
	void render(SDL_Renderer* renderer);

	int left, right, top;

	Vector topCenter;
	Circle topCircle;
};

#endif // __NET_H
