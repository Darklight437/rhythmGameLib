#pragma once
#include "GameClock.h"
#include <vector>


class BeatMap
{
public:
	struct map;
	BeatMap();
	~BeatMap();
	map getTimeEvents(int i);


private:

	struct map
	{
		std::vector<int64_t> timeEvent;
	}	songTest;
	
};