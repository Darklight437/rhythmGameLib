#pragma once
#include <chrono>

//class basically copied from andrew https://github.com/andrewthenintendrone
//edited to be a singleton
//returns time in various increments
class GameClock
{
public:
	
	int64_t getTimeSeconds();
	int64_t getTimeMilliseconds();
	int64_t getTimeMicroseconds();



	void update();

	float getDeltaTime();
	static GameClock& getInstance();

private:
	//singleton tools
	static bool instanceflag;
	GameClock();
	GameClock(GameClock const&);
	void operator=(GameClock const&);


	//functional elements
	std::chrono::high_resolution_clock m_timer;

	//the time that this clock was created at
	std::chrono::time_point<std::chrono::high_resolution_clock> m_createTime;

	std::chrono::time_point<std::chrono::high_resolution_clock> m_lastTime;

	float deltaTime = 0.0f;

};

