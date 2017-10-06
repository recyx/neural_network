
#ifndef __COMMON_H
#define __COMMON_H

// INCLUDES ---------------------------------------------------------------

#include <sys/types.h>
#include <sys/time.h>


// DEFINES ---------------------------------------------------------------

#define PI 3.14159265
  
#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480

#define MOVE_SPEED 500

#define JUMP_FORCE 800
#define GRAVITY 1300

#define PLAYER_RADIUS 30

#define BALL_RADIUS 30
#define BALL_STARTING_VELOCITY 300

#define BOUNCE_RATE 0.7


// FUNCTIONS ---------------------------------------------------------------

int64_t curTime();


#endif // __COMMON_H

