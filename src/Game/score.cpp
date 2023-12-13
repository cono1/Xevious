#include "score.h"

#include <fstream>
#include <iostream>
#include <string>

#include "raylib.h"

namespace game
{
static int score;
static int hiScore;
static int globalScore;

static std::string filePath = "res/score.bin";

static std::ofstream outputStream;
static std::ifstream inputStream;

void readScoreFile();

void initScore()
{
	score = 0;
	hiScore = 0;
	globalScore = 0;

	inputStream.open(filePath, std::ios::in | std::ios::binary);

	if (inputStream.good())
	{
		inputStream.read(reinterpret_cast<char*>(&globalScore), sizeof(globalScore));
		inputStream.close();
	}
}
	
void updateScore()
{
	if (score > hiScore)
	{
		hiScore = score;
	}

	if (hiScore > globalScore)
	{
		globalScore = hiScore;

		outputStream.open(filePath, std::ios::out | std::ios::binary);

		if (outputStream.good())
		{
			outputStream.write(reinterpret_cast<char*>(&globalScore), sizeof(globalScore));
			outputStream.close();
		}
		else
		{
			std::cout << "The file could not be written." << std::endl;
		}
	}

	readScoreFile();
}

void readScoreFile()
{
	inputStream.open("score.bin", std::ios::in | std::ios::binary);

	if (inputStream.good())
	{
		inputStream.read(reinterpret_cast<char*>(&globalScore), sizeof(globalScore));
		inputStream.close();
	}
}

void addScore()
{
	score += 5;
}

void resetScore()
{
	score = 0;
}

void drawScore()
{
	Vector2 scoreTextPos;
	int scoreSize = 30;
	Color colorScore = WHITE;
	scoreTextPos.x = static_cast<float>(GetScreenWidth()) - static_cast<float>((MeasureTextEx(GetFontDefault(), "SCORE:  000000", static_cast<float>(scoreSize), 0).x));
	scoreTextPos.y = 10;

	std::string scoreText = "Score: " + std::to_string(score);
	DrawText(scoreText.c_str(), static_cast<int>(scoreTextPos.x), static_cast<int>(scoreTextPos.y), scoreSize, colorScore);
}

int getScore()
{
	return score;
}

int getHiScore()
{
	return hiScore;
}

int getGlobalScore()
{
	return globalScore;
}
}