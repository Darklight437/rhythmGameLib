#pragma once
#include <chrono>

//class basically copied from andrew https://github.com/andrewthenintendrone
//edited to be a singleton
class GameClock
{
public:
	
	~GameClock()
	{
		instanceflag = false;
	}

	
	int64_t getTimeSeconds();
	int64_t getTimeMilliseconds();
	int64_t getTimeMicroseconds();

	void update();

	float getDeltaTime();
	static GameClock* getInstance();

private:

	static bool instanceflag;
	static GameClock* clock;
	GameClock();
	std::chrono::high_resolution_clock m_timer;

	//the time that this clock was created at
	std::chrono::time_point<std::chrono::high_resolution_clock> m_createTime;

	std::chrono::time_point<std::chrono::high_resolution_clock> m_lastTime;

	float deltaTime = 0.0f;

};

