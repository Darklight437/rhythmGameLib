#pragma once
#include "GameClock.h"
#include <vector>
#include "BeatEvent.h"

class BeatMap
{
public:
	
	BeatMap();
	~BeatMap();
	std::vector<eventpoint> getTimeEvents();




	
private:

	std::vector<eventpoint> beatEvents;

	
};