#include <raylib.h>
#include "ball.h"

class Bricks
{
private:
	int brick_width = 100;
	int brick_height = 50;
public:
	void create_brick(Ball& ball);
	void InitializeBricks();
};