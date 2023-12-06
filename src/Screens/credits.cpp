#include "credits.h"

#include <string>

#include "raylib.h"

namespace game
{
static int fontSize = 40;
static Color textColor = WHITE;
static Color secondTextColor = BLUE;

void checkMouseHoverCredits(Vector2 textPos, std::string text, std::string url);
int getXPosCredits(std::string text);

void printCredits()
{
    const int total = 5;

    std::string texts[total] = { "Game developed by Daniela Gonzalez",
                                 "Player spritesheet by Snappery",
                                 "Enemies spritesheet by Fulas",
                                 "music 8-bit Gabber Piece by RutgerMuller",
                                 "Sci-fi Sounds laserSmall001 by Kenney" };

    std::string urls[total] = { "https://danui.itch.io",
                                 "https://www.gamedevmarket.net/asset/animated-emojis",
                                 "https://www.gamedevmarket.net/asset/mobs-creatures-animals",
                                 "https://freesound.org/people/RutgerMuller/sounds/51241/",
                                 "https://kenney.nl/assets/sci-fi-sounds" };

    Vector2 textPositions[total];

    for (int i = 0; i < total; i++)
    {    
        textPositions[i].x = static_cast<float>(getXPosCredits(texts[i]));
        textPositions[i].y = static_cast<float>(100 + i * 100);

        DrawText(texts[i].c_str(), static_cast<int>(textPositions[i].x), static_cast<int>(textPositions[i].y), fontSize, textColor);
        checkMouseHoverCredits(textPositions[i], texts[i], urls[i]);
    }
}

void checkMouseHoverCredits(Vector2 textPos, std::string text, std::string url)
{
    Vector2 mousePos = GetMousePosition();

    if (mousePos.x >= textPos.x &&
        mousePos.x <= textPos.x + MeasureText(text.c_str(), fontSize) &&
        mousePos.y >= textPos.y &&
        mousePos.y <= textPos.y + MeasureTextEx(GetFontDefault(), text.c_str(), static_cast<float>(fontSize), 0).y)
    {
        DrawText(text.c_str(), static_cast<int>(textPos.x), static_cast<int>(textPos.y), fontSize, secondTextColor);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            OpenURL(url.c_str());
        }
    }
}

int getXPosCredits(std::string text)
{
    return (GetScreenWidth() - MeasureText(text.c_str(), fontSize)) / 2;
}
}