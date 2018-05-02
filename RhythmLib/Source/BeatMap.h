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
	std::vector<int64_t> getTimeEvents();
	void recordEvent();
	



	
private:
	
	std::vector<int64_t> beatTimes;
	int difficulty = 0;
	
};