#pragma once
#include "GameClock.h"
#include <vector>
#include "BeatEvent.h"

class BeatMap
{
public:
	struct map;
	BeatMap();
	~BeatMap();
	map getTimeEvents();


	private:

	struct map
	{

		std::vector<eventpoint> beatEvents;

	}songTest;
	
};