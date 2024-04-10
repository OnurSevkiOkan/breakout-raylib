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
    bool isGameOver = false;
    bool isCoinIncreased = false;
    
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Brick Breaker"); // Defines a window.
    SetTargetFPS(target_FPS); // Sets the FPS to 60.

    // Ininitalize bricks.
    brick.InitializeBricks();
    

    while (!WindowShouldClose())
    {
        switch (currentScreen)
        {
        case TITLE:
        {
            int button_state = title_screen.getBtnState();
            
            if (button_state == 2)
            {
                currentScreen = GAMEPLAY;
                ball.resetBall();
                isGameOver = false;
            }

        } break;
        case GAMEPLAY:
        {
            if (click_counter > 10)
            {
                ball.resetBall();
                isGameOver = true;
            }

            int ExitButton_State = gameplay_screen.getExitBtnState();

            if (isExitButtonInitialized == true)
            {
                gameplay_screen.drawExitButton();
            }


            if (ExitButton_State == 2)
            {
                currentScreen = ENDING;
                ball.resetBall();
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
            title_screen.drawTexts();
            title_screen.drawCoinAmount();

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

            // To prevent the ball position change when the button is clicked
            if (click_counter <= 10 && isGameOver == false && brick.isAllBricksGone() == false)
            {
                ball.updateBall();
            }
            
            ball.drawScore();

            if (brick.isAllBricksGone() == true)
            {
                ball.resetBall();

                if (!isCoinIncreased)
                {
                    gameplay_screen.addCoin();
                    isCoinIncreased = true;
                }

                DrawText("CONGRATULATIONS!", GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 50, 30, WHITE);

                if (!isExitButtonInitialized && currentScreen == GAMEPLAY)
                {
                    gameplay_screen.initExitButton();
                    isExitButtonInitialized = true;
                }
            }

            if (click_counter > 10)
            {
                ball.resetBall();
                DrawText("HaHaHaHA LOOOSER B!TCHES", GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 - 50, 30, WHITE);

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
                click_counter = 0;
            }

            DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, BLUE);
            DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
            DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);
        } break;
        default: break;
        }

        EndDrawing();
    }

    return 0;
}