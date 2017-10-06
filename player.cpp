
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
	vx = MOVE_SPEED * xInput;
	vy += GRAVITY * dTime;

	if(jumpInput > 0.5 && y + rad >= SCREEN_HEIGHT - 1) {
		//printf("jump\n");
		vy = -JUMP_FORCE;
	}


	// Collision
	if(x + vx * dTime < rad) {
		vx = (-x + rad) / dTime;
	} else if(x + vx * dTime > SCREEN_WIDTH - rad) {
		vx = (SCREEN_WIDTH - x - rad) / dTime;
	}

	if(x + rad + vx * dTime > net.left && x + rad + vx * dTime < net.right) {
		vx = (net.left - x - rad) / dTime;
	} else if(x - rad + vx * dTime < net.right && x - rad + vx * dTime > net.left) {
		vx = (net.right - x + rad) / dTime;
	}

	if(y + rad + vy * dTime > SCREEN_HEIGHT) {
		vy = (SCREEN_HEIGHT - y - rad) / dTime;
	}

	// Apply Velocity
	x += vx * dTime;
	y += vy * dTime;

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
