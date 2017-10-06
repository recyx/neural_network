
#include "defines.h"

class Net {
	
	int width, height;
	
public:
	Net(int _width, int _height);
	
	int left, right, top;
};

Net::Net(int _width, int _height) {
	width = _width;
	height = _height;
	
	left = (SCREEN_WIDTH - width) / 2;
	right = (SCREEN_WIDTH + width) / 2;
	top = SCREEN_HEIGHT - height;
}