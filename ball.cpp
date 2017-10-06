
#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <math.h>

#include "common.h"
#include "vector.h"
#include "net.h"
#include "circle.h"
#include "ball.h"

Ball::Ball(Net _net) {
	net = _net;
	startX = SCREEN_WIDTH / 2;
	startY = SCREEN_HEIGHT / 2 - 200;
	rad = BALL_RADIUS;

	reset(false);
}

void Ball::update(float dTime, Vector player1, Vector velocity1, Vector player2, Vector velocity2) {
	Vector zero;
	zero.x = 0;
	zero.y = 0;

	pos.x = x;
	pos.y = y;

	v.y += GRAVITY * dTime;

	x += v.x * dTime;
	y += v.y * dTime;

	//printf("X: %f\n", x);
	//printf("Y: %f\n", y);

	bool bounced = false;
	oldV = v;

	//printf("X: %d\n Y: %d\n", x, y);

	// Check for Collision
	if((player1 - pos).lenSqr() < (PLAYER_RADIUS + BALL_RADIUS) * (PLAYER_RADIUS + BALL_RADIUS)) {
		bounce(player1, velocity1, dTime);
	} else if((player2 - pos).lenSqr() < (PLAYER_RADIUS + BALL_RADIUS) * (PLAYER_RADIUS + BALL_RADIUS)) {
		bounce(player2, velocity2, dTime);
	}

	// Wall Collision
	if(x - rad < 0) {
		v.x = -v.x * BOUNCE_RATE;
		x = 2 * rad - x;
	} else if (x + rad > SCREEN_WIDTH) {
		v.x = -v.x * BOUNCE_RATE;
		x = SCREEN_WIDTH - 2 * rad + (SCREEN_WIDTH - x);
	}


	// Net Collision Side
	if(x + rad > net.left && x + rad < net.right && y > net.top) {
		v.x = -v.x * BOUNCE_RATE;
		x = net.left - 2 * rad + (net.left - x);
	} else if(x - rad < net.right && x - rad > net.left && y > net.top) {
		v.x = -v.x * BOUNCE_RATE;
		x = net.right + 2 * rad - (x - net.right);
	}

	// Net Collision top
	if((net.topCenter - pos).lenSqr() < (BALL_RADIUS + net.width / 2) * (BALL_RADIUS + net.width / 2)) {
		bounce(net.topCenter, zero, dTime);
	}


	//Ground Collision
	if(y + rad > SCREEN_HEIGHT) {
		v.y = -v.y * BOUNCE_RATE;
		v.x = v.x * BOUNCE_RATE;
		y = SCREEN_HEIGHT - 2 * rad + (SCREEN_HEIGHT - y);
		//reset(0);
	}
}

void Ball::reset(bool side) {
	x = startX;
	y = startY;
	v.y = 0;

	if(side) {
		v.x = BALL_STARTING_VELOCITY;
	} else {
		v.x = -BALL_STARTING_VELOCITY;
	}
}

void Ball::bounce(Vector point, Vector vel, float dTime) {
	//hit = true;
	Vector distance = point - pos;
	v.x *= dTime;
	v.y *= dTime;
	float velocity = v.len();

	// Angle of Impact
	float a = atan2(point.y - pos.y, point.x - pos.x);
	
	// Angle of Velocity to Ground
	float b = atan2(v.y, v.x);

	// Angle of Deflection
	float c = 2 * a - b;

	// New Velocity and Position
	//x -= v.x + 30;
	//y -= v.y + 30;

	v.x = -(cos(c) * velocity / dTime) + vel.x;
	v.y = -(sin(c) * velocity / dTime) + vel.y;

	x += v.x * dTime - 3;
	y += v.y * dTime - 3;
}

