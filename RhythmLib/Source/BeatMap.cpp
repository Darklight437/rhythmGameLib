#include "BeatMap.h"

BeatMap::BeatMap()
{
}

BeatMap::~BeatMap()
{
}

std::vector<eventpoint> BeatMap::getTimeEvents()
{
	return std::vector<eventpoint>();
}

void BeatMap::recordEvent()
{
	eventpoint beat;
	beat.timeEvent = GameClock::getInstance()->getTimeMilliseconds();

		beatEvents.push_back(beat);
}


