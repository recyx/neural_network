
#ifndef __CIRCLE_H
#define __CIRCLE_H

class Circle {
	public:
		Circle();
		Circle(int _x, int _y, int _rad);

		int x, y;
		int rad;

		void render(SDL_Renderer* renderer);
};

#endif // __CIRCLE_H

