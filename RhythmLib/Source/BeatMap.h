#pragma once
#include "GameClock.h"
#include <vector>
#include "BeatEvent.h"

class BeatMap
{
public:
	BeatMap();
	BeatMap(int difficultyRating);
	~BeatMap();
	//returns a vector of beats as timestamps
	std::vector<eventpoint> getTimeEvents();
	void addEvent(eventpoint e);
	



	
private:
	
	std::vector<eventpoint> beatTimes;
	int difficulty = 0;
	
};