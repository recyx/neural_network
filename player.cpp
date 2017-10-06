
#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "defines.h"
#include "circle.h"
#include "net.h"
#include "player.h"

Player::Player(Net _net, float _startX, float _startY) {
	rad = PLAYER_RADIUS;
	net = _net;
	x = startX = _startX;
	y = startY = _startY;
}

void Player::input(float _xInput, float _jumpInput) {
	xInput = _xInput;
	jumpInput = _jumpInput;
}

void Player::update(float dTime) {
	// Apply Input
	vx = MOVE_SPEED * xInput * dTime;
	vy += GRAVITY * dTime * dTime;

	if(jumpInput > 0.5 && y + rad >= SCREEN_HEIGHT - 1) {
		printf("jump\n");
		vy = -JUMP_FORCE;
	}


	// Collision
	if(x + vx < rad) {
		vx = -x + rad;
	} else if(x + vx > SCREEN_WIDTH - rad) {
		vx = (SCREEN_WIDTH - x - rad) * dTime;
	}

	if(x + rad + vx > net.left && x + rad + vx < net.right) {
		vx = (net.left - x - rad) * dTime;
	} else if(x - rad + vx < net.right && x - rad + vx > net.left) {
		vx = (net.right - x + rad) * dTime;
	}

	if(y + rad + vy > SCREEN_HEIGHT) {
		vy = (SCREEN_HEIGHT - y - rad) * dTime;
	}

	// Apply Velocity
	x += vx;
	y += vy;

}

void Player::resetPosition() {
	x = startX;
	y = startY;
	vx = vy = 0;
}

Vector Player::getPos() {
	Vector v;
	v.x = x;
	v.y = y;
	return v;
}

