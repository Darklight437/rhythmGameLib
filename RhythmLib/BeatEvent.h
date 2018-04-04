#pragma once
#include <cstdint>

//event struct
struct eventpoint
{
	char KeyCode = 'a'; //pressed key
	int64_t timeEvent; // the time the event occured
};