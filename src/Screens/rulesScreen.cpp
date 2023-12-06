#include "rulesScreen.h"

#include <string>

#include "raylib.h"

namespace game
{
static int fontSize;

int getXPos(std::string text);

void printRules()
{
    Color textColor = WHITE;
    fontSize = 40;

    std::string text1 = "WELCOME TO XEVIOUS!";
    std::string text2 = "Use ARROW keys to move your ship";
    std::string text3 = "Press SPACE to shoot down the enemies";
    std::string text4 = "Avoid enemy collisions to stay alive";
    std::string text5 = "Press ESC to pause the game";

    DrawText(text1.c_str(), getXPos(text1), 70, fontSize, textColor);
    DrawText(text2.c_str(), getXPos(text2), 210, fontSize, textColor);
    DrawText(text3.c_str(), getXPos(text3), 310, fontSize, textColor);
    DrawText(text4.c_str(), getXPos(text4), 410, fontSize, textColor);
    DrawText(text5.c_str(), getXPos(text5), 510, fontSize, textColor);
}

int getXPos(std::string text)
{
    return (GetScreenWidth() - MeasureText(text.c_str(), fontSize)) / 2;
}
}