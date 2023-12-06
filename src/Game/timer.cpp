#include "timer.h"

namespace game
{
void startTimer(Timer& timer)
{
    timer.start = std::clock();
}

void stopTimer(Timer& timer)
{
    timer.end = std::clock();
}

double getTimeElapsed(Timer timer)
{
    return 1000 * (timer.end - timer.start) / CLOCKS_PER_SEC;
}
}