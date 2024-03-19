#include <gameplay_screen.h>
#include <raylib.h>
#include <variables.h>

#define NUM_FRAMES  3 

void GAMEPLAY_SCREEN::initExitButton()
{
    exitButton = LoadTexture("resources/exit_button.png");
}

void GAMEPLAY_SCREEN::unloadExitButtonTexture()
{
    UnloadTexture(exitButton);
}

void GAMEPLAY_SCREEN::drawExitButton()
{
    ExitButtonframeHeight = (float)exitButton.height / NUM_FRAMES;
    Rectangle sourceRec = { 0, 0, (float)exitButton.width, exitButton.height };
    Rectangle destRec = { SCREEN_WIDTH / 2.0f - exitButton.width / 2.0f, SCREEN_HEIGHT / 2.0f - ExitButtonframeHeight / 2.0f + 100, (float)exitButton.width, ExitButtonframeHeight };
    ExitButtonMousePoint = GetMousePosition();
    ExitBtnAction = false;

    ExitBtnBounds = { (float)GetScreenWidth() / 2.0f - exitButton.width / 2.0f, (float)GetScreenHeight() / 2.0f - exitButton.width / 2.0f + 100, (float)exitButton.width, (float)exitButton.height };

    DrawTextureRec(exitButton
        , sourceRec, { ExitBtnBounds.x, ExitBtnBounds.y }, WHITE);

    // Checks collisions
    if (CheckCollisionPointRec(ExitButtonMousePoint, ExitBtnBounds))
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) ExitBtnState = 2;
        else ExitBtnState = 1;
    }
    else ExitBtnState = 0;
}

Rectangle& GAMEPLAY_SCREEN::getExitButtonBounds()
{
    return ExitBtnBounds;
}

int GAMEPLAY_SCREEN::getExitBtnState()
{
    return ExitBtnState;
}