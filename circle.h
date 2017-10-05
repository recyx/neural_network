
#ifndef __CIRCLE_H
#define __CIRCLE_H

class Circle {
	public:
		Circle(int _x, int _y, int _radius);
		~Circle();

		int x, y;
		int radius;

		void render(SDL_Renderer* renderer);
};

#endif // __CIRCLE_H

