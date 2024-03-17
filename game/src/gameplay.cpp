#include <raylib.h>
#include <iostream>
#include <variables.h>
#include "ball.h"
#include "bricks.h"

Ball ball;
Bricks brick;

int main(void)
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Brick Breaker"); // Defines a windows.
	SetTargetFPS(target_FPS); // Sets the fps to 60.
	
	//ball.InitializeTexture(); // Loads texture if you use.
	brick.InitializeBricks();

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ball.drawBall();
		ball.updateBall();
		brick.create_brick(ball);
		EndDrawing();
	}

	//ball.deleteTexture();


	return 0;
}