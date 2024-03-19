#include <raylib.h>
#include <iostream>
#include <variables.h>
#include "ball.h"
#include "bricks.h"
#include "title_screen.h"
#include "gameplay_screen.h"

Ball ball;
Bricks brick;
TITLE_SCREEN title_screen;
GAMEPLAY_SCREEN gameplay_screen;

typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;

int main(void)
{
    GameScreen currentScreen = TITLE;
    int framesCounter = 0;
    bool isPlayButtonInitialized = false;
    bool isExitButtonInitialized = false;

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
            int button_state = title_screen.getBtnState();

            // Press enter to change to GAMEPLAY screen
            if (button_state == 2)
            {
                currentScreen = GAMEPLAY;
            }

        } break;
        case GAMEPLAY:
        {
            int ExitButton_State = gameplay_screen.getExitBtnState();

            gameplay_screen.drawExitButton();

            if (ExitButton_State == 2)
            {
                currentScreen = ENDING;
                click_counter = 0;
                ball.setBallPosition();
                brick.resetBricks();
            }
        } break;
        case ENDING:
        {
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
            if (!isPlayButtonInitialized && currentScreen == TITLE)
            {
                title_screen.initPlayButton();
                isPlayButtonInitialized = true;
            }

        } break;

        case GAMEPLAY:
        {
            brick.create_brick(ball);

            ball.drawBall();
            ball.updateBall();
            ball.drawScore();

            if (click_counter >= 10)
            {
                click_counter = 0;

                
                
                if (!isExitButtonInitialized && currentScreen == GAMEPLAY)
                {
                    gameplay_screen.initExitButton();
                    isExitButtonInitialized = true;
                }
            }

        } break;
        case ENDING:
        {
            if (isExitButtonInitialized && currentScreen == ENDING)
            {
                gameplay_screen.unloadExitButtonTexture();
                isExitButtonInitialized = false;
            }
           
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