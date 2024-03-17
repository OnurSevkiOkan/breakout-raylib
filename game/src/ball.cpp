#include "ball.h"
#include <raylib.h>
#include <math.h>
#include "variables.h"

Vector2 ball_position = { 300, 750 }; // Initial ball position.
Texture2D ball_texture; // Texture for the ball.

// Velocity vector for ball movement
Vector2 ball_velocity = { 0, 0 };

void Ball::InitializeTexture()
{
    // Load the ball texture.
    ball_texture = LoadTexture("resources/ball.png");
}

void Ball::drawBall()
{
    ClearBackground(BLACK);
    /*DrawTexturePro(ball_texture, Rectangle{0, 0, (float)ball_texture.width, (float)ball_texture.height},
        Rectangle{ ball_position.x, ball_position.y, 30, 30 }, // Adjust the size as needed
        Vector2{ 15, 15 }, 90, WHITE); // Apply rotation
        */
    DrawCircle(ball_position.x, ball_position.y, 10, WHITE);
}
void Ball::updateBall()
{
    static bool clicked = false; 

    // Update ball position
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !clicked)
    {
        clicked = true;

        Vector2 cursorPos = GetMousePosition();

        ball_velocity.x = cursorPos.x - ball_position.x;
        ball_velocity.y = cursorPos.y - ball_position.y;

        float magnitude = sqrt(ball_velocity.x * ball_velocity.x + ball_velocity.y * ball_velocity.y);
        if (magnitude != 0) {
            ball_velocity.x /= magnitude;
            ball_velocity.y /= magnitude;
        }

        // Set the velocity based on the normalized direction
        ball_velocity.x *= BALL_SPEED;
        ball_velocity.y *= BALL_SPEED;
    }

    if (clicked)
    {
        // Update the ball position with the velocity
        ball_position.x += ball_velocity.x * GetFrameTime();
        ball_position.y += ball_velocity.y * GetFrameTime();

        // Check collision with vertical edges of the screen and reverse direction if needed
        if (ball_position.x >= GetScreenWidth() - ball_texture.width || ball_position.x <= 0)
        {
            ball_velocity.x *= -1;
        }

        // Check collision with horizontal edges of the screen and reverse direction if needed
        if (ball_position.y >= GetScreenHeight() - ball_texture.height || ball_position.y <= 0)
        {
            ball_velocity.y *= -1;
        }
    }
}



//These functions used to control ball from bricks.cpp


Vector2 Ball::getPosition()
{
    return ball_position;
}

Vector2 Ball::getSpeed() {
    return ball_velocity;
}

float Ball::getSpeedX()
{
    return ball_velocity.x;
}

float Ball::getSpeedY()
{
    return ball_velocity.y;
}

void Ball::setSpeed(Vector2 speed) // Used to change direction when there is a collision.
{
    ball_velocity = speed;
}

void Ball::deleteTexture() // Unloads texture if you use one.
{
    UnloadTexture(ball_texture);
}
