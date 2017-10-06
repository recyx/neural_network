
#ifndef __BALL_H
#define __BALL_H

class Ball : public Circle {
	Net net;
	int startX, startY;

public:
	Ball(Net _net);
	Vector v, oldV, pos;


	bool hit = false;

	void update(float dTime, Vector player1, Vector velocity1, Vector player2, Vector velocity2);
	void reset(bool side); // 0 left, 1 right
	void bounce(Vector point, Vector vel, float dTime);

};


#endif // __BALL_H

