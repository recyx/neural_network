
#ifndef __CIRCLE_H
#define __CIRCLE_H

class Circle {
	public:
		Circle();
		Circle(float _x, float _y, int _rad);

		float x, y;
		int rad;

		void render(SDL_Renderer* renderer);
};

#endif // __CIRCLE_H

