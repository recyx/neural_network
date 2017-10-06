
class Player : Circle {
	
	Net net;
	float vx, vy;
    float xInput, jumpInput;

public:
	Player(Net _net, float _startX, float _startY);
	
	float startX, startY;
	
	void input(float _xInput, float _jumpInput);
	void update(double dTime);
	void resetPosition();
};
