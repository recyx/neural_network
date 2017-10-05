
class Circle {
	public:
		Circle(int _x, int _y, int _rad);

		int x, y;
		int rad;

		void render(SDL_Renderer* renderer);
};

