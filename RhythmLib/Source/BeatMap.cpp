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

void BeatMap::addEvent(eventpoint e)
{
	beatTimes.push_back(e);
}




