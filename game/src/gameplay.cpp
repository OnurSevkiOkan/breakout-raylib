#include <raylib.h>
#include <iostream>
#include <variables.h>
#include "ball.h"
#include "bricks.h"
#include "title_screen.h"

Ball ball;
Bricks brick;
TITLE_SCREEN title_screen;

typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;

int main(void)
{
    GameScreen currentScreen = TITLE;
    int framesCounter = 0;
    bool isButtonInitialized = false;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Brick Breaker"); // Defines a window.
    SetTargetFPS(target_FPS); // Sets the FPS to 60.

    // Load necessary resources
    brick.InitializeBricks();

    while (!WindowShouldClose())
    {
        switch (currentScreen)
        {
        case TITLE:
        {
            // TODO: Update TITLE screen variables here!
            title_screen.drawPlayButton();

            int button_state = title_screen.getBtnState();
            // Press enter to change to GAMEPLAY screen
            if (button_state == 2)
            {
                currentScreen = GAMEPLAY;
            }
        } break;
        case GAMEPLAY:
        {
            // TODO: Update GAMEPLAY screen variables here!

            // Press enter to change to ENDING screen
        } break;
        case ENDING:
        {
            // TODO: Update ENDING screen variables here!

            // Press enter to return to TITLE screen
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {
                currentScreen = TITLE;
            }
        } break;
        default: break;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (currentScreen)
        {
        case TITLE:
        {
            title_screen.drawPlayButton();

            // Load play button texture when entering the title screen
            if (!isButtonInitialized && currentScreen == TITLE)
            {
                title_screen.initPlayButton();
                isButtonInitialized = true;
            }

            // TODO: Draw TITLE screen here!
        } break;

        case GAMEPLAY:
        {
            if (isButtonInitialized && currentScreen == GAMEPLAY)
            {
                title_screen.unloadPlayButtonTexture();
                isButtonInitialized = false;
            }

            // TODO: Draw GAMEPLAY screen here!
            brick.create_brick(ball);

            ball.drawBall();
            ball.updateBall();

        } break;
        case ENDING:
        {
            // TODO: Draw ENDING screen here!
            DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, BLUE);
            DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
            DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);
        } break;
        default: break;
        }

        EndDrawing();
    }

    // Unload resources

    return 0;
}
