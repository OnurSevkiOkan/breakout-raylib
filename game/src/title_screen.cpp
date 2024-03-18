#include <title_screen.h>
#include <raylib.h>
#include <variables.h>

#define NUM_FRAMES  3 

void TITLE_SCREEN::initPlayButton()
{
    play_button = LoadTexture("resources/play_button.png");
}

void TITLE_SCREEN::unloadPlayButtonTexture()
{
    UnloadTexture(play_button);
}

void TITLE_SCREEN::drawPlayButton()
{
    frameHeight = (float)play_button.height / NUM_FRAMES;
    Rectangle sourceRec = { 0, 0, (float)play_button.width, frameHeight };
    Rectangle destRec = { SCREEN_WIDTH / 2.0f - play_button.width / 2.0f, SCREEN_HEIGHT / 2.0f - frameHeight / 2.0f, (float)play_button.width, frameHeight };
    mousePoint = GetMousePosition();
    btnAction = false;

    btnBounds = { SCREEN_WIDTH / 2.0f - play_button.width / 2.0f, SCREEN_HEIGHT / 2.0f - frameHeight / 2.0f, (float)play_button.width, frameHeight };

    DrawTextureRec(play_button, sourceRec, { btnBounds.x, btnBounds.y }, WHITE);

    // Checks collisions
    if (CheckCollisionPointRec(mousePoint, btnBounds))
    {
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnState = 2;
        else btnState = 1;
    }
    else btnState = 0;
}

Rectangle& TITLE_SCREEN::getButtonBounds()
{
    return btnBounds;
}

int TITLE_SCREEN::getBtnState()
{
    return btnState;
}
