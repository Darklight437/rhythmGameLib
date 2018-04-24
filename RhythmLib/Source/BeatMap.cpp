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
	//beat.timeEvent = (needs int64 from clock) 

		beatEvents.push_back(beat);
}


