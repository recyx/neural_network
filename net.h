
#ifndef __NET_H
#define __NET_H


class Net {
	
	SDL_Rect rect;
	int width, height;
	
public:
	Net();
	
	void set(int _width, int _height);
	void render(SDL_Renderer* renderer);
	
	int left, right, top;
};

#endif // __NET_H

