#pragma once

#include <raylib.h>
#include "variables.h"

class Ball
{
private:
	Vector2 position;
public:
	static bool clicked;
	void resetBall();

	void drawBall(); // Draws a ball on the screen.
	void updateBall(); // Controls the ball movement and checks for collisions.
	void InitializeTexture(); // Loads a texture if you use.
	void deleteTexture(); // Unloads a texture if there is a texture
	Vector2 getPosition(); // Gets the posiiton of ball, used to check the collision with bricks in bricks.cpp
	Vector2 getSpeed(); // Gets the posiiton of ball
	float getSpeedX(); // Gets the speed of the ball at x axis
	float getSpeedY(); // Gets the speed of the ball at y axis
	void setSpeed(Vector2 speed); // Sets the speed of the ball
	void drawScore();
	void setBallPosition();
};