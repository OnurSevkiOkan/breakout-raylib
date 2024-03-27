#ifndef TITLE_SCREEN_H
#define TITLE_SCREEN_H

#include <raylib.h>
#include <variables.h>

class TITLE_SCREEN {
private:
    Texture2D play_button;
    Vector2 mousePoint;
    Rectangle btnBounds; // Declare btnBounds as a private member variable
    int btnState;
    bool btnAction;
    float frameHeight;

public:
    void initPlayButton();
    void unloadPlayButtonTexture();
    void drawPlayButton();
    Rectangle& getButtonBounds(); // Function to return a reference to btnBounds
    int getBtnState();
    void drawTexts();
};

#endif TITLE_SCREEN_H