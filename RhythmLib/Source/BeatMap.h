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
	void recordEvent();
	



	
private:
	
	std::vector<eventpoint> beatTimes;
	int difficulty = 0;
	
};