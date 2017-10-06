
#ifndef __BALL_H
#define __BALL_H

class Ball : Circle {
	Net net;
	Vector v, pos;
	int startX, startY;

	public:
	Ball(Net _net);

	void update(float dTime, Vector player1, Vector player2);
	void reset(bool side); // 0 left, 1 right
	void bounce(Vector point);

};


#endif // __BALL_H

