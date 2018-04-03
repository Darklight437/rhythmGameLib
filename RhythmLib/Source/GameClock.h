#pragma once
#include <chrono>

//class basically copied from andrew https://github.com/andrewthenintendrone
class GameClock
{
public:
	GameClock();
	~GameClock();

	int64_t getTimeSeconds();
	int64_t getTimeMilliseconds();
	int64_t getTimeMicroseconds();

	void update();

	float getDeltaTime();

private:

	std::chrono::high_resolution_clock m_timer;

	//the time that this clock was created at
	std::chrono::time_point<std::chrono::high_resolution_clock> m_createTime;

	std::chrono::time_point<std::chrono::high_resolution_clock> m_lastTime;

	float deltaTime = 0.0f;

};

