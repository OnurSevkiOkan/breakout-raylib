#ifndef GAMEPLAY_SCREEEN_H
#define GAMEPLAY_SCREEEN_H

#include <raylib.h>
#include <variables.h>

class GAMEPLAY_SCREEN {
private:
    Texture2D exitButton;
    Vector2 ExitButtonMousePoint;
    Rectangle ExitBtnBounds; // Declare btnBounds as a private member variable
    int ExitBtnState;
    bool ExitBtnAction;
    float ExitButtonframeHeight;

public:
    void initExitButton();
    void unloadExitButtonTexture();
    void drawExitButton();
    Rectangle& getExitButtonBounds(); // Function to return a reference to btnBounds
    int getExitBtnState();
    void addCoin();
};

#endif GAMEPLAY_SCREEEN_H