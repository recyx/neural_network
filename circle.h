
class Circle {
	public:
		Circle(int _x, int _y, int _radius);

		int x, y;
		int radius;

		void render(SDL_Renderer* renderer);
};

