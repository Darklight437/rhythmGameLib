#include "GameClock.h"



GameClock::GameClock()
{
	m_createTime = m_timer.now();
	m_lastTime = m_createTime;
}






int64_t GameClock::getTimeSeconds()
{
	return std::chrono::duration_cast<std::chrono::seconds>(m_timer.now() - m_createTime).count();
}

int64_t GameClock::getTimeMilliseconds()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(m_timer.now() - m_createTime).count();
}

int64_t GameClock::getTimeMicroseconds()
{
	return std::chrono::duration_cast<std::chrono::microseconds>(m_timer.now() - m_createTime).count();
}

void GameClock::resetClock()
{
	m_createTime = m_timer.now();
}

void GameClock::update()
{
	deltaTime = std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(m_timer.now() - m_lastTime).count() / 1000.0f;
	m_lastTime = m_timer.now();
}

float GameClock::getDeltaTime()
{
	return deltaTime;
}

GameClock& GameClock::getInstance()
{
	
	static GameClock clock;
	return clock;

}



