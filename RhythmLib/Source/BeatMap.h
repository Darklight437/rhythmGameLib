#pragma once
#include "GameClock.h"
#include <vector>
class BeatMap
{
public:
	BeatMap();
	~BeatMap();



	struct map
	{
		std::vector<int64_t> timeEvent;
	};
	
};

