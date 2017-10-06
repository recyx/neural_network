
#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <math.h>

#include "defines.h"
#include "vector.h"
#include "net.h"
#include "circle.h"
#include "ball.h"

Ball::Ball(Net _net) {
	net = _net;
	startX = SCREEN_WIDTH / 2;
	startY = SCREEN_HEIGHT / 2;
	rad = BALL_RADIUS;

	reset(false);
}

void Ball::update(float dTime, Vector player1, Vector player2) { 
	pos.x = x;
	pos.y = y;

	v.y += GRAVITY * dTime;

	// Check for Collision
	if((player1 - pos).lenSqr() < (PLAYER_RADIUS + BALL_RADIUS) * (PLAYER_RADIUS + BALL_RADIUS)) {
		Bounce(player1);
	} else if((player2 - pos).lenSqr() < (PLAYER_RADIUS + BALL_RADIUS) * (PLAYER_RADIUS + BALL_RADIUS)) {
		Bounce(player2);
	}

	// TODO Net Collision

	x += v.x;
	y += v.y;
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

void Ball::Bounce(Vector point) {
	Vector distance = point - pos;
	float velocity = v.len();

	// Angle of Impact
	float a = acos((v.x * distance.x + v.y * distance.y) / velocity * distance.len() );

	// Angle of Velocity to Ground
	float b = asin(v.y / velocity); 

	// Angle of Deflection
	float c = a + b;

	// New Velocity
	v.x = cos(c) * v.x;
	v.y = sin(c) * v.y;
}

