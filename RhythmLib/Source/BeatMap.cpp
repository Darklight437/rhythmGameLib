#include "BeatMap.h"
//difficulty between 0 and 2
BeatMap::BeatMap(int difficultyRating)
{

}
BeatMap::BeatMap()
{

}

BeatMap::~BeatMap()
{
}

std::vector<eventpoint> BeatMap::getTimeEvents()
{
	return beatTimes;
}

void BeatMap::recordEvent()
{
	int64_t beat;
	beat = GameClock::getInstance().getTimeMilliseconds();
	eventpoint event1;
	event1.timeEvent = beat;
	beatTimes.push_back(event1);
}


