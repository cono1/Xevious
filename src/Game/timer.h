#pragma once

#include <iostream>
#include <time.h>

namespace game
{
struct Timer
{
	std::clock_t start;
	std::clock_t end;
};

void startTimer(Timer& timer);
void stopTimer(Timer& timer);
double getTimeElapsed(Timer timer);
}