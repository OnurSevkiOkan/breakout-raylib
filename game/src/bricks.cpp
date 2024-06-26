#include "bricks.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ball.h>
#include <iostream>

#define LINES_OF_BRICKS 5
#define BRICKS_PER_LINE 5

Texture2D brick_texture; // declare as a global variable

typedef struct Brick {
    Vector2 position;
    bool active;
} Brick;

typedef struct Balls_f { // You can change the "balls_f" name
    Vector2 position;
    Vector2 speed;
    int radius;
    bool active;
} Balls_f;

static Brick brick[LINES_OF_BRICKS][BRICKS_PER_LINE] = { 0 };
static Vector2 brickSize = { 0 };

void Bricks::InitializeBricks()
{
    brickSize = { 106, 50 }; // Set brick size here

    // Initialize brick positions and activity
    for (int i = 0; i < LINES_OF_BRICKS; i++)
    {
        for (int j = 0; j < BRICKS_PER_LINE; j++)
        {
            brick[i][j].position = { 70 + j * (brickSize.x + 10), 100 + i * (brickSize.y + 10) };
            brick[i][j].active = true;
        }
    }
}

void Bricks::create_brick(Ball& ball)
{

    Balls_f balls;
    balls.position = ball.getPosition();
    balls.speed = ball.getSpeed();
    balls.radius = 10;


    // Collision ball vs bricks
    for (int i = 0; i < LINES_OF_BRICKS; i++)
    {
        for (int j = 0; j < BRICKS_PER_LINE; j++)
        {
            if (brick[i][j].active)
            {
                // Calculate the distance between the centers of the ball and brick
                float dx = balls.position.x - brick[i][j].position.x;
                float dy = balls.position.y - brick[i][j].position.y;

                // Calculate the combined half-widths and half-heights of the ball and brick
                float combinedHalfWidths = balls.radius + brickSize.x / 2;
                float combinedHalfHeights = balls.radius + brickSize.y / 2;

                // Check for collision along the x-axis
                bool collisionX = fabs(dx) < combinedHalfWidths;

                // Check for collision along the y-axis
                bool collisionY = fabs(dy) < combinedHalfHeights;

                // If there's a collision along both axes, there's a collision
                if (collisionX && collisionY)
                {
                    // Determine which side of the brick the ball collided with
                    float overlapX = combinedHalfWidths - fabs(dx);
                    float overlapY = combinedHalfHeights - fabs(dy);

                    if (overlapX >= overlapY)
                    {
                        // Collision from the top or bottom
                        balls.speed.y *= -1;
                        ball.setSpeed(balls.speed);
                        brick[i][j].active = false;
                    }
                    else
                    {
                        // Collision from the left or right
                        balls.speed.x *= -1;
                        ball.setSpeed(balls.speed);
                        brick[i][j].active = false;
                    }
                    // Deactivate the brick
                    brick[i][j].active = false;
                }

            }
        }
    }

    // Draw bricks
    for (int i = 0; i < LINES_OF_BRICKS; i++)
    {
        static bool isBrickTextureInitialized = false;

        if (isBrickTextureInitialized == false)
        {
            brick_texture = LoadTexture("resources/Brick.png");
            isBrickTextureInitialized = true;
        }


        for (int j = 0; j < BRICKS_PER_LINE; j++)
        {
            if (brick[i][j].active)
            {
                if ((i + j) % 2 == 0)
                {
                    DrawTexture(brick_texture, brick[i][j].position.x - brickSize.x / 2, brick[i][j].position.y - brickSize.y / 2 , WHITE);
                }
                else
                {
                    DrawTexture(brick_texture, brick[i][j].position.x - brickSize.x / 2, brick[i][j].position.y - brickSize.y / 2, WHITE);
                }
            }
        }
    }

}

void Bricks::resetBricks() {
    // Iterate through all bricks and set their active state to true
    for (int i = 0; i < LINES_OF_BRICKS; i++) {
        for (int j = 0; j < BRICKS_PER_LINE; j++) {
            brick[i][j].active = true;
        }
    }
}


bool Bricks::isAllBricksGone()
{
    for (int i = 0; i < LINES_OF_BRICKS; i++)
    {
        for (int j = 0; j < BRICKS_PER_LINE; j++)
        {
            if (brick[i][j].active == true) // If any brick is still active, return false
            {
                return false;
            }
        }
    }
    // If the loop completes without finding any active bricks, return true
    return true;
}

void Bricks::unloadBrickTexture()
{
    UnloadTexture(brick_texture); // Unloads bricks texture
}