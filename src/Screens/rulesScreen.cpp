#include "rulesScreen.h"

#include <string>

#include "raylib.h"

#include "Menu/backButton.h"

namespace game
{
static std::string text1;
static std::string text2;
static std::string text3;
static std::string text4;
static std::string text5;
static std::string text6;

static int fontSize;
static Color textColor;

int getXPos(std::string text);

void initRules()
{
    fontSize = 40;
    textColor = WHITE;

    text1 = "WELCOME TO XYPHORIA!";
    text2 = "Use ARROW keys to move your ship";
    text3 = "Press SPACE to shoot down the enemies";
    text4 = "Avoid enemy collisions to stay alive";
    text5 = "Press ESC to pause the game";
    text6 = "Press ENTER to play, resume or play again";
}

void printRules()
{    
    DrawText(text1.c_str(), getXPos(text1), 70, fontSize, textColor);
    DrawText(text2.c_str(), getXPos(text2), 210, fontSize, textColor);
    DrawText(text3.c_str(), getXPos(text3), 310, fontSize, textColor);
    DrawText(text4.c_str(), getXPos(text4), 410, fontSize, textColor);
    DrawText(text5.c_str(), getXPos(text5), 510, fontSize, textColor);
    DrawText(text6.c_str(), getXPos(text6), 610, fontSize, textColor);

    printBackButton(false);
}

int getXPos(std::string text)
{
    return (GetScreenWidth() - MeasureText(text.c_str(), fontSize)) / 2;
}
}