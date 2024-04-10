#include <title_screen.h>
#include <raylib.h>
#include <variables.h>
#include <string>

#define NUM_FRAMES  3 

void TITLE_SCREEN::initPlayButton()
{
    play_button = LoadTexture("resources/play_button.png"); // Loads Play Button texture
}

void TITLE_SCREEN::unloadPlayButtonTexture()
{
    UnloadTexture(play_button); // Unloads Play Button texture
}

void TITLE_SCREEN::drawPlayButton()
{
    // Defines position and size of button
    frameHeight = (float)play_button.height / NUM_FRAMES;
    Rectangle sourceRec = { 0, 0, (float)play_button.width, play_button.height };
    Rectangle destRec = { SCREEN_WIDTH / 2.0f - play_button.width / 2.0f, SCREEN_HEIGHT / 2.0f - frameHeight / 2.0f, (float)play_button.width, frameHeight };
    mousePoint = GetMousePosition();
    btnAction = false;

    btnBounds = { (float)GetScreenWidth() / 2.0f - play_button.width / 2.0f, (float)GetScreenHeight() / 2.0f - play_button.width / 2.0f, (float)play_button.width, (float)play_button.height };

    //Draws button
    DrawTextureRec(play_button, sourceRec, { btnBounds.x, btnBounds.y }, WHITE);

    // Checks collisions of buttons.
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

void TITLE_SCREEN::drawTexts()
{
    DrawText("Made by OnurSevkiOkan", 350, 850, 20, BLACK);
}

void TITLE_SCREEN::drawCoinAmount()
{
    std::string coinAmount = "Coins: ";
    coinAmount.append(std::to_string(COINS));
    DrawText(coinAmount.c_str(), GetScreenWidth() / 2 - 80, 20, 50, BLACK);
}
