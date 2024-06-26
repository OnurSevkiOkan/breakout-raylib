#include <raylib.h>
#include "ball.h"

class Bricks
{
private:
	int brick_width = 100;
	int brick_height = 50;
	bool isGameOver = false;
public:
	void create_brick(Ball& ball); // Creates bricks
	void InitializeBricks(); // Initializes bricks
	void resetBricks(); // Resets bricks
	bool isAllBricksGone(); // Checks is gameover
	void unloadBrickTexture(); // Unloads brick texture
};