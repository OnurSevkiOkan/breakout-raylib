#include <raylib.h>
#include "ball.h"

class Bricks
{
private:
	int brick_width = 100;
	int brick_height = 50;
	bool isGameOver = false;
public:
	void create_brick(Ball& ball);
	void InitializeBricks();
	void resetBricks();
	bool isAllBricksGone();
	void unloadBrickTexture();
};