
#include "defines.h"
#include "vector.h"
#include "ball.h"

Ball::Ball(Net _net) {
	net = _net;
	startX = SCREEN_WIDTH / 2;
	startY = SCREEN_HEIGHT / 2;
	rad = BALL_RADIUS;
	
	reset(false);
}

void Ball::update(float dTime, Vector player1, Vector player2) { 
    Vector pos(x, y);
	
	v.y += GRAVITY * dTime;
	
	// Check for Collision
	if((player1 - pos).lengthSqr < (PLAYER_RADIUS + BALL_RADIUS) * (PLAYER_RADIUS + BALL_RADIUS)) {
		Bounce(player1, pos);
	} else if((player2 - pos).lengthSqr < (PLAYER_RADIUS + BALL_RADIUS) * (PLAYER_RADIUS + BALL_RADIUS)) {
		Bounce(player2, pos);
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

void Bounce(Vector player, Vector ball) {
	Vector distance = player - ball;
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
