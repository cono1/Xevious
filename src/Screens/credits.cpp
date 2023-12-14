#include "credits.h"

#include <string>

#include "raylib.h"

#include "Menu/backButton.h"
#include "gameManager.h"

namespace game
{
static const int total = 7;
static std::string texts[total];
static std::string urls[total];
static Vector2 textPositions[total];

static int fontSize = 40;
static Color textColor = WHITE;
static Color secondTextColor = BLUE;

bool checkMouseHoverCredits(Vector2 textPos, std::string text);
int getXPosCredits(std::string text);

void initCredits()
{
    texts[0] = "Game developed by Daniela Gonzalez";
    texts[1] = "Player spritesheet by Snappery";
    texts[2] = "Enemies spritesheet by Fulas";
    texts[3] = "Unkown Dungeon PixelArt Parallax by Arrie";
    texts[4] = "music 8-bit Gabber Piece by RutgerMuller";
    texts[5] = "Sci-fi Sounds laserSmall001 by Kenney";
    texts[6] = "Menu music by Pixabay";

    urls[0] = "https://danui.itch.io";
    urls[1] = "https://www.gamedevmarket.net/asset/animated-emojis";
    urls[2] = "https://www.gamedevmarket.net/asset/mobs-creatures-animals";
    urls[3] = "https://www.gamedevmarket.net/asset/unkown-dungeon-pixelart-parallax-background";
    urls[4] = "https://freesound.org/people/RutgerMuller/sounds/51241/";
    urls[5] = "https://kenney.nl/assets/sci-fi-sounds";
    urls[6] = "https://pixabay.com/sound-effects/026491-pixel-song-8-72675/";

    for (int i = 0; i < total; i++)
    {
        textPositions[i].x = static_cast<float>(getXPosCredits(texts[i]));
        textPositions[i].y = static_cast<float>(100 + i * 100);
    }
}

void updateCredits()
{
    for (int i = 0; i < total; i++)
    {
        if (checkMouseHoverCredits(textPositions[i], texts[i]))
        {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                OpenURL(urls[i].c_str());
            }
        }
    }

    checkGoBack();
}

void printCredits()
{
    for (int i = 0; i < total; i++)
    {    
        DrawText(texts[i].c_str(), static_cast<int>(textPositions[i].x), static_cast<int>(textPositions[i].y), fontSize, textColor);

        if (checkMouseHoverCredits(textPositions[i], texts[i]))
        {
            DrawText(texts[i].c_str(), static_cast<int>(textPositions[i].x), static_cast<int>(textPositions[i].y), fontSize, secondTextColor);
        }
    }

    printBackButton(false);
}

bool checkMouseHoverCredits(Vector2 textPos, std::string text)
{
    Vector2 mousePos = GetMousePosition();

    return (mousePos.x >= textPos.x &&
        mousePos.x <= textPos.x + MeasureText(text.c_str(), fontSize) &&
        mousePos.y >= textPos.y &&
        mousePos.y <= textPos.y + MeasureTextEx(GetFontDefault(), text.c_str(), static_cast<float>(fontSize), 0).y);
}

int getXPosCredits(std::string text)
{
    return (GetScreenWidth() - MeasureText(text.c_str(), fontSize)) / 2;
}
}