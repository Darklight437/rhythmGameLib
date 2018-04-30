#include "BeatMap.h"

BeatMap::BeatMap()
{
}

BeatMap::~BeatMap()
{
}

std::vector<int64_t> BeatMap::getTimeEvents()
{
	return std::vector<int64_t>();
}

void BeatMap::recordEvent()
{
	int64_t beat;
	beat = GameClock::getInstance().getTimeMilliseconds();

	beatTimes.push_back(beat);
}


