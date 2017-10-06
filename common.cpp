
#include "common.h"

int64_t curTime()
{
	struct timeval t;
	gettimeofday(&t, 0);
	return ((int64_t)((int64_t)t.tv_sec * (int64_t)1000 + (int64_t)t.tv_usec / (int64_t)1000));
}

